#include "Bridge.h"
#include <stdio.h>
#include <iostream>
using namespace std;

// ����ӿ�ʵ�����ʵ�ַ�ʽ1
void RefinedAbstraction1::operation() {
    if (m_impl_ptr == NULL) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        m_impl_ptr->operation_impl();
    }
}

// ����ӿ�ʵ�����ʵ�ַ�ʽ2, �� RefinedAbstraction1 ��һ��
void RefinedAbstraction2::operation() {
    if (m_impl_ptr == NULL) {
        return;
    }

    for (int i = 0; i < 5; i++) {
        m_impl_ptr->operation_impl();
    }
}

// IImplementor�ӿ�ʵ�����һ��ʵ�ַ���1
void ConcreteImplementor1::operation_impl() {
    cout << "ConcreteImplementor1::operation_impl" << endl;
}

// IImplementor�ӿ�ʵ�����һ��ʵ�ַ���2
void ConcreteImplementor2::operation_impl() {
    cout << "ConcreteImplementor2::operation_impl" << endl;
}


