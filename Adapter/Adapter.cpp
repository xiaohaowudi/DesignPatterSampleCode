#include "Adapter.h"


void Adaptee::special_request() {
	cout << "Adaptee::special_request" << endl;
}

void CAdapter::request() {
	// ������ʹ���˱��������Ĺ��ܣ�ʵ���˷��ϵ�����Ҫ��Ķ���ӿ�
	m_adaptee_ptr->special_request();
}

