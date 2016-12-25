#include "State.h"

int main(void) {
	CContext* p_context = new CContext();

	for (int i = 0; i < 10; i++) {
		p_context->request();
	}

	delete p_context;
	return 0;
}