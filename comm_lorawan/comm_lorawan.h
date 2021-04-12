#ifndef COMM_LORAWAN_H_
#define COMM_LORAWAN_H_


void comm_lorawan_init ( void );
void comm_lorawan_loop ( void );
void comm_lorawan_request_tx ( uint8_t * p_data, uint8_t size, uint8_t port );


#endif /* COMM_LORAWAN_H_ */
