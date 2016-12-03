#include "SingletonSample.h"
#include <stdio.h>

int main(void) {
	SingletonSample* p_singleton1 = NULL;
	SingletonSample* p_singleton2 = NULL;
		
	p_singleton1 = SingletonSample::get_instance();
	if (p_singleton1 != NULL) {
		p_singleton1->operation();
	}

	p_singleton2 = SingletonSample::get_instance();
	if (p_singleton2 != NULL) {
		p_singleton2->operation();
	}

    return 0;
}