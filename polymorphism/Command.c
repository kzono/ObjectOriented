#include "Command.h"
#include <stdio.h>
#include "Motor.h"

static void* CommandVfTable[] = {
    (void*)0
};


void Command_construct( Command* this, Port leftPort, Port rightPort){
    printf("void Command_construct( Command* this, Port leftPort, Port rightPort )\n");
    this->vfTable = CommandVfTable;
    Motor_construct( &(this->left), leftPort );
    Motor_construct( &(this->right), rightPort );
}



void Command_exec(Command* this){
    printf("void Command_exec(Command* this)\n"); 
    // ポリモフィズムを実現するため、サブクラスのコンストラクタで
    // 関数ポインタに有効な関数アドレスを事前に設定しておく
   CMDFUNC func = (CMDFUNC)(this->vfTable[0]);
   (*func)(this);
}
