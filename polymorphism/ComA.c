#include "ComA.h"
#include <stdio.h>

// private function declear
void ComA_exec_impl(Command* this);

static void* ComA_VF_Table[] = { ComA_exec_impl  };

// private function define
void ComA_exec_impl(Command* this){
  printf("void ComA_exec_impl()\n");
  Motor_forward( &(this->left), 75 );
  Motor_backward( &(this->right), 75 );
}


void ComA_construct(ComA* this, Port leftPort, Port rightPort){
  printf("void ComA_construct(ComA* this, Port leftPort, Port rightPort)\n");
  Command_construct((Command*)(this), leftPort, rightPort);
  this->base.vfTable = ComA_VF_Table;
}
