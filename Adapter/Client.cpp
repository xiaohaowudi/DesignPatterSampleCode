#include "Adapter.h"
#include <assert.h>

void main_function(ITarget* p_target) {
	assert(p_target != NULL);

	// ������ֻ����ITarget�ӿ��ṩ�Ĺ��ܣ�����֪�ײ���ͨ��Adaptee��Ĺ���ʵ�ֵģ���Adaptee�͵�����֮�����
	p_target->request();
}

int main(void) {
	// ---------- ʹ��ǰ��ʼ������   start  ------------
	Adaptee* p_adaptee = new Adaptee();
	assert(p_adaptee != NULL);
	ITarget* p_target = new CAdapter(p_adaptee);
	assert(p_target != NULL);
	// ---------- ʹ��ǰ��ʼ������   end  ------------

	// -------------������ʹ�ýӿڵ�סҵ���߼�   start --------------------
	main_function(p_target);
	// -------------������ʹ�ýӿڵ�סҵ���߼�   end --------------------

	delete p_adaptee;
	delete p_target;	
}