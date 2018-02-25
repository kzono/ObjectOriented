#ifndef B_H_
#define B_H_
#include "A.h"

typedef struct B_ B; 

void B_construct(B* , int p, int q);

void B_foo(A* );
void B_bar(A* );
void B_hoge(B* );
void B_fuga(B* );


#endif // B_H_

