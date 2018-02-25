#ifndef C_H_
#define C_H_

#include "A.h"
#include "B.h"

typedef struct C_ C;

void C_construct(C* , int p, int q, int r);
void C_foo(A* );
void C_bar(A* );
void C_hoge(B* );
void C_fuga(B* );

#endif // C_H_

