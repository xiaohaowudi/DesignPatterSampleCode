#include "Bridge.h"
#include <stdio.h>
#include <iostream>
using namespace std;

// 抽象接口实现类的实现方式1
void RefinedAbstraction1::operation() {
    if (m_impl_ptr == NULL) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        m_impl_ptr->operation_impl();
    }
}

// 抽象接口实现类的实现方式2, 和 RefinedAbstraction1 不一样
void RefinedAbstraction2::operation() {
    if (m_impl_ptr == NULL) {
        return;
    }

    for (int i = 0; i < 5; i++) {
        m_impl_ptr->operation_impl();
    }
}

// IImplementor接口实现类的一种实现方法1
void ConcreteImplementor1::operation_impl() {
    cout << "ConcreteImplementor1::operation_impl" << endl;
}

// IImplementor接口实现类的一种实现方法2
void ConcreteImplementor2::operation_impl() {
    cout << "ConcreteImplementor2::operation_impl" << endl;
}


