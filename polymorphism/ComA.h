#ifndef COMA_H_
#define  COMA_H_

#include "Command.h"

typedef struct {
  Command base;
} ComA;

void ComA_construct(ComA* , Port leftPort, Port rightPort);
#endif // COMA_H_

