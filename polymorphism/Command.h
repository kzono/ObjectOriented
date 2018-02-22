#ifndef COMMAND_H_
#define  COMMAND_H_

#include "Motor.h"

typedef struct {
 void**  vfTable;
 Motor left;
 Motor right;
} Command;

//extern void* CommandVfTable[];

//void Command_construct( Command* this );   NG!!
//void Command_construct( Command* this_ );  OK!!!
void Command_construct( Command* , Port leftPort, Port rightPort);    //    OK!!
//void Command_construct( Command* self );

void Command_exec(Command* );
typedef void (*CMDFUNC)(Command* );

#endif // COMMAND_H_
