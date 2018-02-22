#include "ComA.h"
#include "ComB.h"

typedef enum { X_ST, Y_ST } State;

typedef struct {
    State m_state;
} CommandTest;

void CommandTest_construct(CommandTest* this){
  this->m_state = X_ST;
}

void  CommandTest_run(CommandTest* this){
    ComA a;
    ComB b;

    ComA_construct(&a, PORT_A, PORT_C);
    ComB_construct(&b, PORT_A, PORT_C);

    Command_exec((Command*)&a);

    this->m_state = Y_ST;

    Command_exec((Command*)&b);

}
    
int main(){
  CommandTest cmdTest;
  CommandTest_construct(&cmdTest);
  CommandTest_run(&cmdTest);
  return 0;
}

