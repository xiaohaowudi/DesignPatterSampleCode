#include "Memento.h"
#include <iostream>
using namespace std;

CMemento COriginator::create_memento() {
	return CMemento(m_state);
}

void COriginator::restore_state(const CMemento& memento) {
	m_state = memento.get_state();
}

void COriginator::print_state() {
	cout << "state = " << m_state << endl;
}

void COriginator::change_state() {
	m_state++;
}




