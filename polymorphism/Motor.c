#include "Motor.h"
#include <stdio.h>

// private function
void printPort(Motor* this);

void Motor_construct(Motor* this, Port a_port){
  printf("void Motor_construct(Motor* this, Port a_port)\n");
  this->m_port = a_port;
  printPort(this);


}
void Motor_forward(Motor* this, int speed){
  printf("void Motor_forward(int speed = %d)\n", speed);
  printPort(this);

}
void Motor_backward(Motor* this, int speed){
  printf("void Motor_backward(int speed = %d)\n", speed);
  printPort(this);

}

void Motor_stop(Motor* this){
  printf("void Motor_stop(Motor* this)\n");
  printPort(this);


}
void printPort(Motor* this){
    switch(this->m_port){
    case PORT_A:
      puts("PORT_A");
      break;

    case PORT_B:
      puts("PORT_B");
      break;

    case PORT_C:
      puts("PORT_C");
      break;

    case PORT_D:
      puts("PORT_D");
      break;
    default:
        ;
    }
}
