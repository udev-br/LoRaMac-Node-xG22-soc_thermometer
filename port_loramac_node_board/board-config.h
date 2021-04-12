#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * Defines the time required for the TCXO to wakeup [ms].
 */
#if defined( SX1262MBXDAS )
#define BOARD_TCXO_WAKEUP_TIME                      5
#else
#define BOARD_TCXO_WAKEUP_TIME                      0
#endif

/*!
 * Board MCU pins definitions
 */
#define RADIO_RESET                                 PB_1

#define RADIO_MOSI                                  PC_0
#define RADIO_MISO                                  PC_1
#define RADIO_SCLK                                  PC_2

#if defined( SX1261MBXBAS ) || defined( SX1262MBXCAS ) || defined( SX1262MBXDAS )

#define RADIO_NSS                                   PC_3
#define RADIO_BUSY                                  PB_0
#define RADIO_DIO_1                                 PD_3

#define RADIO_ANT_SWITCH_POWER                      PD_2

#elif defined( LR1110MB1XXS )

#define RADIO_NSS                                   PA_8
#define RADIO_BUSY                                  PB_3
#define RADIO_DIO_1                                 PB_4

#define LED_1                                       PC_1
#define LED_2                                       PC_0

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PB_6
#define RADIO_DBG_PIN_RX                            PC_7

#elif defined( SX1272MB2DAS) || defined( SX1276MB1LAS ) || defined( SX1276MB1MAS )

#define RADIO_NSS                                   PB_6

#define RADIO_DIO_0                                 PA_10
#define RADIO_DIO_1                                 PB_3
#define RADIO_DIO_2                                 PB_5
#define RADIO_DIO_3                                 PB_4
#define RADIO_DIO_4                                 PA_9
#define RADIO_DIO_5                                 PC_7

#define RADIO_ANT_SWITCH                            PC_1

#define LED_1                                       NC
#define LED_2                                       NC

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PB_0
#define RADIO_DBG_PIN_RX                            PA_4

#endif


#ifdef __cplusplus
}
#endif

#endif // __BOARD_CONFIG_H__
