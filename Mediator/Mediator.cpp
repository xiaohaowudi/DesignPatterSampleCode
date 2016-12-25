#include "Mediator.h"
#include <iostream>
using namespace std;

void CColleague1::operation1() {
	cout << "CColleague1::operation1" << endl;
}

void CColleague1::operation2() {
	cout << "CColleague1::operation2" << endl;
}

void CColleague1::function() {
	// 利用中介者进行间接调用，而不是直接耦合实现类
	if (m_mediator_ptr != NULL) {
		m_mediator_ptr->call_colleague2_oper1();
		m_mediator_ptr->call_colleague2_oper2();
	}
	operation1();
	operation2();
}

void CColleague2::operation1() {
	cout << "CColleague2::operation1" << endl;
}

void CColleague2::operation2() {
	cout << "CColleague2::operation2" << endl;
}

void CColleague2::function() {
	// 利用中介者进行间接调用，而不是直接耦合实现类
	if (m_mediator_ptr != NULL) {
		m_mediator_ptr->call_colleague1_oper1();
		m_mediator_ptr->call_colleague1_oper2();
	}
	operation1();
	operation2();
}

void CMediator::call_colleague1_oper1() {
	if (m_colleague_ptr1) {
		m_colleague_ptr1->operation1();
	}
}

void CMediator::call_colleague1_oper2() {
	if (m_colleague_ptr1) {
		m_colleague_ptr1->operation2();
	}
}

void CMediator::call_colleague2_oper1() {
	if (m_colleague_ptr2) {
		m_colleague_ptr2->operation1();
	}
}

void CMediator::call_colleague2_oper2() {
	if (m_colleague_ptr2) {
		m_colleague_ptr2->operation2();
	}
}


