#include "Iterator.h"
#include <iostream>
using namespace std;

int main(void) {
	IAggregate* p_aggregate = new CAggregate();
	IIterator* p_iterator = p_aggregate->get_iterator();
	
	/*
		����ʹ�������е����ݳ�Ա��ʱ�򲻸�֪ʵ�ʵ�������֯��ʽ��
		�õ���������ʹ���ߺ����ݾ������֯��ʽ
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