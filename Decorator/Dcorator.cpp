#include "Decorator.h"
#include <iostream>
using namespace std;

// ԭʼComponentʵ�������Ϊ����
void CConcreteComponent::operation() {
	cout << "CConcreteComponent::operation" << endl;
}

// װ����1��Ϊ
void CConcreteDecorator1::operation() {
	m_component_ptr->operation();
	add_operation();
}

// װ����1������Ϊ
void CConcreteDecorator1::add_operation() {
	cout << "CConcreteDecorator1::add_operation" << endl;
}

// װ����2��Ϊ
void CConcreteDecorator2::operation() {
	m_component_ptr->operation();
	add_operation();
}

// װ����2������Ϊ
void CConcreteDecorator2::add_operation() {
	cout << "CConcreteDecorator2::add_operation" << endl;
}

// װ����3��Ϊ
void CConcreteDecorator3::operation() {
	m_component_ptr->operation();
	add_operation();
}

// װ����3������Ϊ
void CConcreteDecorator3::add_operation() {
	cout << "CConcreteDecorator3::add_operation" << endl;
}

