#ifndef A_PRIVATE_H_
#define A_PRIVATE_H_

#include "A.h"

typedef struct {
    void (*foo)();
    void (*bar)();
} AVtbl;

struct A_ {
   AVtbl* pVtbl;
   int m_p;
};

void A_construct(A* , int p);

#endif // A_PRIVATE_H_
