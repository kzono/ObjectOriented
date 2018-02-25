#include "APrivate.h"
#include "BPrivate.h"
#include "CPrivate.h"
#include <stdio.h>

int main(){
  A a1;
  A_construct(&a1, 3);

  A_bar(&a1);        // A_barImpl()


  B b1;
  B_construct( &b1, 3, 5 );
  A* pA1 = (A*)&b1;  // アップキャスト
  A_foo( pA1 );      // B_foo()
  A_bar( pA1 );      // B_bar()

  printf("   pA1->m_p = %d\n", pA1->m_p);
  printf("b1.base.m_p = %d, b1.m_q= %d\n", b1.base.m_p, b1.m_q);


  C c1;
  C_construct( &c1, 1, 3, 5);
  A* pA2 = (A*)&c1;

  A_foo( pA2 );       // C_foo() オーバーライド
  A_bar( pA2 );       // C_bar() オーバーライド
  
  B* pB1 = (B*)&c1;
  B_hoge( pB1 );      // C_hoge() インターフェースの実装
  B_fuga( pB1 );      // C_fuga() オーバーライド

  printf("pA2->m_p = %d\n", pA2->m_p);
  printf("pB1->m_q = %d\n", pB1->m_q);
  printf("c1.base.base.m_p = %d, c1.base.m_q = %d, c1.m_r = %d\n", c1.base.base.m_p, c1.base.m_q, c1.m_r);
  return 0;
}
