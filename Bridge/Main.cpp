#include "Bridge.h"
#include <iostream>
using namespace std;

int main(void) {
    IImplementior *p_impl1 = new ConcreteImplementor1();
    IImplementior *p_impl2 = new ConcreteImplementor2();

    // 互相组合功能
    IAbstraction *p_abstract1 = new RefinedAbstraction1(p_impl1);
    IAbstraction *p_abstract2 = new RefinedAbstraction2(p_impl1);
    IAbstraction *p_abstract3 = new RefinedAbstraction1(p_impl2);
    IAbstraction *p_abstract4 = new RefinedAbstraction2(p_impl2);

    cout << "############################## 1 start ##################################" << endl;
    p_abstract1->operation();
    cout << "############################## 1 end ##################################" << endl << endl;

    cout << "############################## 2 start ##################################" << endl;
    p_abstract2->operation();
    cout << "############################## 2 end ##################################" << endl << endl;

    cout << "############################## 3 start ##################################" << endl;
    p_abstract3->operation();
    cout << "############################## 3 end ##################################" << endl << endl;

    cout << "############################## 4 start ##################################" << endl;
    p_abstract4->operation();
    cout << "############################## 4 end ##################################" << endl << endl;
    
    delete p_impl1;
    delete p_impl2;
    delete p_abstract1;
    delete p_abstract2;
    delete p_abstract3;
    delete p_abstract4;
}