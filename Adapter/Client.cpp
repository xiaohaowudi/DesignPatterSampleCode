#include "Adapter.h"
#include <assert.h>

void main_function(ITarget* p_target) {
	assert(p_target != NULL);

	// 调用者只关心ITarget接口提供的功能，不感知底层是通过Adaptee类的功能实现的，将Adaptee和调用者之间解耦
	p_target->request();
}

int main(void) {
	// ---------- 使用前初始化动作   start  ------------
	Adaptee* p_adaptee = new Adaptee();
	assert(p_adaptee != NULL);
	ITarget* p_target = new CAdapter(p_adaptee);
	assert(p_target != NULL);
	// ---------- 使用前初始化动作   end  ------------

	// -------------真正的使用接口的住业务逻辑   start --------------------
	main_function(p_target);
	// -------------真正的使用接口的住业务逻辑   end --------------------

	delete p_adaptee;
	delete p_target;	
}