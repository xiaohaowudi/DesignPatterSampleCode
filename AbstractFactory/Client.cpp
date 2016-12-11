#include <stdio.h>
#include "Product.h"
#include "Factory.h"

void func(IFactory *p_factory) {
	if (p_factory == NULL) {
		return;
	}

	IProductA* p_product_a = NULL;
	IProductB* p_product_b = NULL;

	/*
		构建一系列相关的功能对象，生产一个家族的对象，具体哪些实现类被组合到了一起，
		由IFactory来决定工厂的使用者不关心具体构建出了哪些功能上相关的类的实例，
		产品类的组合关系有变化，只需要增加工厂类的实现，func函数中的所有代码不用修改一行
	*/
	p_product_a = p_factory->create_product_a();
	p_product_b = p_factory->create_product_b();

	for (int i = 0; i < 3; i++) {
		p_product_a->operation_a();
		p_product_b->operation_b();
	}

	delete p_product_a;
	delete p_product_b;
}


int main(void) {
    IFactory* p_factory = NULL;
    
	cout << "##################### process 1 start ###########################" << endl;
	// 第1种类家族的组合
    p_factory = new CFactory1();
	func(p_factory);
	delete p_factory;
	p_factory = NULL;
	cout << "##################### process 1 end ###########################" << endl << endl;

	cout << "##################### process 2 start ###########################" << endl;
	// 第2种类家族的组合
	p_factory = new CFactory2();
	func(p_factory);
	delete p_factory;
	p_factory = NULL;
	cout << "##################### process 2 start ###########################" << endl << endl;

    return 0;
}