#ifndef C_PRIVATE_H_
#define C_PRIVATE_H_
#include "C.h"
#include "BPrivate.h"

// C には purevirtual も virtual も追加されないので
// 新たな仮想関数テーブル構造体の定義は不要。
//typedef struct{
//} CVtbl;


struct C_ {
    B base;
  int m_r;
};

#endif // C_PRIVATE_H_

