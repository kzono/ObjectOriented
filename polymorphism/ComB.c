#include "ComB.h"
#include <stdio.h>

// private function declear
void ComB_exec_impl(Command*);

static void* ComB_VF_Table[] = { ComB_exec_impl  };

// private function define
void ComB_exec_impl(Command* this){
  printf("void ComB_exec_impl()\n");
  Motor_forward( &(this->right), 75 );
  Motor_backward( &(this->left), 75 );
}


void ComB_construct(ComB* this, Port leftPort, Port rightPort){
  printf("void ComB_construct(ComB* this), Port leftPort, Port rightPort\n");
  Command_construct((Command*)(this), leftPort, rightPort);
  this->base.vfTable = ComB_VF_Table;
}
