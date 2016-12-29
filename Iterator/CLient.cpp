#include "Iterator.h"
#include <iostream>
using namespace std;

int main(void) {
	IAggregate* p_aggregate = new CAggregate();
	IIterator* p_iterator = p_aggregate->get_iterator();
	
	/*
		真正使用容器中的数据成员的时候不感知实际的数据组织方式，
		用迭代器隔绝使用者和数据具体的组织形式
	*/
	DATA data = 0;
	p_iterator->first();
	while (p_iterator->is_done() == false) {
		data = p_iterator->current();
		cout << "data = " << data << endl;
		p_iterator->next();
	}

	delete p_aggregate;
	delete p_iterator;

	return 0;
}