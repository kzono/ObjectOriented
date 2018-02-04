#ifndef MOTOR_H_
#define  MOTOR_H_

#include "Port.h"

typedef struct {

  Port m_port;
} Motor;

void Motor_construct(Motor* , Port a_port);
void Motor_forward(Motor* ,int speed);
void Motor_backward(Motor* ,int speed);
void Motor_stop(Motor* );


#endif // MOTOR_H_

