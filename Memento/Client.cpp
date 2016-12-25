#include "Memento.h"
#include <iostream>
using namespace std;

int main(void) {
	COriginator originator;

	originator.print_state();
	CMemento memento = originator.create_memento();
	originator.change_state();
	originator.print_state();
	originator.change_state();
	originator.print_state();
	originator.change_state();
	originator.print_state();

	// �ָ�״̬
	originator.restore_state(memento);
	originator.print_state();

	return 0;
}