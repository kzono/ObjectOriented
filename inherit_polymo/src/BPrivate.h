#ifndef B_PRIVATE_H_
#define B_PRIVATE_H_

#include "APrivate.h"
#include "B.h"

typedef struct {
    AVtbl baseTbl;
    void (*hoge)(B*);
    void (*fuga)(B*);
} BVtbl;


struct B_ {
    A base;
    AVtbl* pVtbl;
    int m_q;
};


#endif // B_PRIVATE_H_
