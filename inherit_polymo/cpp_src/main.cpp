#include <stdio.h>
 class A{
   public:
     A(int p):m_p(p){};
     ~A(){};
     virtual void foo() = 0;
     virtual void bar(){
       puts("A::bar()");
     };
   private:
     int m_p;
 };

class B : public A{
  public:
    B(int p, int q):A(p), m_q(q){};
    ~B(){};
    void foo(){
      puts("B::foo()");
    }
    void bar(){
      puts("B::bar()");
      A::bar();
    }
  private:
    int  m_q;
};

int main(){
    B b1(3, 5);
    A* pA = &b1;
    pA->foo();
    b1.bar();
  return 0;
}
