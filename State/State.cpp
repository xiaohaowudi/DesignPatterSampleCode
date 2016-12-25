#include "State.h"
#include <iostream>
using namespace std;


CContext::CContext() {
	m_state2impl.clear();
	m_state2impl[STATE_INIT] = new CStateInit();
	m_state2impl[STATE1] = new CState1();
	m_state2impl[STATE2] = new CState2();
	m_state2impl[STATE3] = new CState3();

	m_state = STATE_INIT;
	m_state_ptr = m_state2impl[m_state];
}

CContext::~CContext() {
	for (auto itr = m_state2impl.begin(); itr != m_state2impl.end(); itr++) {
		delete (itr->second);
	}
	m_state2impl.clear();
}

void CContext::request() {
	m_state_ptr->handle();
	m_state = m_state_ptr->get_next_state();
	m_state_ptr = m_state2impl[m_state];
}

void CStateInit::handle() {
	cout << "CStateInit::handle" << endl;
}

STATE CStateInit::get_next_state() {
	return STATE1;
}

void CState1::handle() {
	cout << "CState1::handle" << endl;
}

STATE CState1::get_next_state() {
	return STATE2;
}

void CState2::handle() {
	cout << "CState2::handle" << endl;
}

STATE CState2::get_next_state() {
	return STATE3;
}

void CState3::handle() {
	cout << "CState3::handle" << endl;
}

STATE CState3::get_next_state() {
	return STATE_INIT;
}