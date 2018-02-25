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

// 仮想関数(virtual)のプロトタイプ宣言
void A_barImpl(A* );

#endif // A_PRIVATE_H_
