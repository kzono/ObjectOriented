#ifndef COMB_H_
#define  COMB_H_

#include "Command.h"

typedef struct {
  Command base;
} ComB;

void ComB_construct(ComB* , Port leftPort, Port rightPort);
#endif // COMB_H_

