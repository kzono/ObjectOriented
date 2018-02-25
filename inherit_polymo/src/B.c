#include <stdio.h>
#include "APrivate.h"
#include "BPrivate.h"

// 仮想関数のデフォルト実装のプロトタイプ宣言
static void B_fugaImpl(B*);


// B用仮想関数テーブル
static BVtbl vtbl =
{
  {// A用仮想関数テーブル
    B_foo,  // pure virtual の impl
    B_bar   // override
  },       
  0,        // hoge() は純粋仮想関数(pure virtual)
  B_fugaImpl // fuga() のデフォルト実装
};



void B_construct(B* this, int p, int q){
  printf("B_construct(B* this, int %d, int %d)\n", p, q);
  A_construct( &(this->base), p );
  this->pVtbl = this->base.pVtbl;   // Aの仮想関数テーブルへのポインタを退避
  this->base.pVtbl = (AVtbl*)&vtbl; // 仮想関数テーブルへのポインタを B用に上書きする
  this->m_q = q;
}

void B_foo(A* this){
  printf("B_foo():m_p=%d, m_q=%d\n", this->m_p, ((B*)(this))->m_q);
}

void B_bar(A* this){
  B* pB = (B*)this;
  printf("<<override>> B_bar():m_q=%d\n", pB->m_q);
  puts("call A_bar()");
  pB->pVtbl->bar( this );
}

void B_hoge(B* this){
  puts("B_hoge(B* this)");
    ((BVtbl*)(this->base.pVtbl))->hoge(this);
}

void B_fuga(B* this){
  puts("B_fuga(B* this)");
    ((BVtbl*)(this->base.pVtbl))->fuga(this);
}

// 仮想関数のデフォルト実装の定義
void B_fugaImpl(B* this){
    printf("<<impl>>B_fugaImpl():m_q=%d\n", this->m_q);
}
