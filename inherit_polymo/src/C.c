#include <stdio.h>
#include "CPrivate.h"

// 仮想関数テーブルの初期化
static BVtbl vtbl =
{
    {
      C_foo,    // override
      C_bar     // override
    },
    C_hoge,     // impl
    C_fuga      // override
};


// 公開関数の定義

void C_construct(C* this, int p, int q, int r){
  printf("C_construct(C* this, int %d, int %d, int %d)\n", p, q, r);
  // 基底クラスのコンストラクタを呼び出す
  B_construct( &(this->base), p, q );

  // 仮想関数テーブルへのポインタを退避
  this->pVtbl = (BVtbl*)(this->base.base.pVtbl);

  // 仮想関数テーブルへのポインタをC用に上書きする
  this->base.base.pVtbl = (AVtbl*)&vtbl;

  this->m_r = r;
}


void C_foo(A* this){
  printf("<<override>> C_foo():m_r=%d\n",  ((C*)this)->m_r );
}

void C_bar(A* this){
  printf("<<override>> C_bar():m_r=%d\n",  ((C*)this)->m_r );
}

void C_hoge(B* this){
  printf("<<impl>> C_hoge():m_r=%d\n",  ((C*)this)->m_r );
}

void C_fuga(B* this){
  printf("<<override>> C_fuga():m_r=%d\n",  ((C*)this)->m_r );
}
