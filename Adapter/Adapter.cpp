#include "Adapter.h"


void Adaptee::special_request() {
	cout << "Adaptee::special_request" << endl;
}

void CAdapter::request() {
	// 适配器使用了被适配的类的功能，实现了符合调用者要求的对外接口
	m_adaptee_ptr->special_request();
}

