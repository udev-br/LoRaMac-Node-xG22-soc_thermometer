

#include <em_common.h>
#include "sl_bluetooth.h"
#include "sl_bt_stack_init.h"

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#ifndef SL_CATALOG_GATT_CONFIGURATION_PRESENT
#include "bg_gattdb_def.h"
const struct bg_gattdb_def bg_gattdb_data = {0};
#endif // SL_CATALOG_GATT_CONFIGURATION_PRESENT
#endif // SL_COMPONENT_CATALOG_PRESENT
#include "sl_bt_power_control_config.h"
#include "sl_ota_dfu.h"
#include "sl_health_thermometer.h"

static const sl_bt_configuration_t config = SL_BT_CONFIG_DEFAULT;

/** @brief Table of used BGAPI classes */
static const struct sli_bgapi_class * const bt_class_table[] =
{
  SL_BT_BGAPI_CLASS(system),
  SL_BT_BGAPI_CLASS(advertiser),
  SL_BT_BGAPI_CLASS(connection),
  SL_BT_BGAPI_CLASS(gatt_server),
  SL_BT_BGAPI_CLASS(sm),
  NULL
};

void sl_bt_init(void)
{
  sl_bt_init_stack(&config);
  sl_bt_init_classes(bt_class_table);
  sl_bt_init_power_control();
}

SL_WEAK void sl_bt_on_event(sl_bt_msg_t* evt)
{
  (void)(evt);
}

void sl_bt_process_event(sl_bt_msg_t *evt)
{
  sl_bt_ota_dfu_on_event(evt);
  sl_bt_ht_on_event(evt);
  sl_bt_on_event(evt);
}

SL_WEAK bool sl_bt_can_process_event(uint32_t len)
{
  (void)(len);
  return true;
}

void sl_bt_step(void)
{
  sl_bt_msg_t evt;

  // check if application can process a new event.
  if (!sl_bt_can_process_event(SL_BGAPI_MSG_HEADER_LEN + SL_BGAPI_MAX_PAYLOAD_SIZE)) {
    return;
  }

  // Pop (non-blocking) a Bluetooth stack event from event queue.
  sl_status_t status = sl_bt_pop_event(&evt);
  if(status != SL_STATUS_OK){
    return;
  }
  sl_bt_process_event(&evt);
}
