#include <stdio.h>
#include "APrivate.h"


static AVtbl vtbl =
{
  0,        // foo() は純粋仮想関数(pure virtual)
  A_barImpl // 仮想関数のデフォルト実装
};

void A_construct(A* this, int p){
  printf("A_construct(A* this, int %d)\n", p);
  this->pVtbl = &vtbl;
  this->m_p = p;
}

void A_barImpl(A* this){
  printf("<<defImpl>> A_barImpl():m_p=%d\n", this->m_p);
}

// foo() は純粋仮想関数なので、ここでの this は
// A* 型だが A のインスタンスではなく、派生クラスのインスタンス
void A_foo( A* this){
  puts("A_foo( A* this)");
  if(0 != this->pVtbl->foo){
    this->pVtbl->foo(this);
  }
}

void A_bar( A* this){
  puts("A_bar( A* this)");
    this->pVtbl->bar(this);
}
