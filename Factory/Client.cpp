#include "Product.h"
#include "Factory.h"
#include <stdio.h>


/*
	产品类使用者不感知具体的产品类的构造方式和具体是什么产品类，只关心某种特定的工厂类
	能够返回实现了某种功能的产品类实例即可，产品的构造方式变化了，产品使用者的代码不用
	做任何修改，关于产品构造方式的变更修改都封闭到了具体工厂类的实现里面,产品的行为有了
	变化，下面func函数中的代码一行都不用改
*/
void func(IFactory *p_factory) {
	if (p_factory == NULL) {
		return;
	}

	IProduct *p_product = p_factory->create_product();
	if (p_product == NULL) {
		return;
	}
	
	for (int i = 3; i < 10; i++) {
		p_product->operation();
	}

	p_factory->destroy_product(p_product);
}


int main(void) {
    IFactory *p_factory1 = new CFactory1();
    IFactory *p_factory2 = new CFactory2();

	func(p_factory1);
	func(p_factory2);
    /*
        产品类使用者不感知具体的产品类的构造方式和具体是什么产品类，只关心某种特定的工厂类
        能够返回实现了某种功能的产品类实例即可，产品的构造方式变化了，产品使用者的代码不用
        做任何修改，关于产品构造方式的变更修改都封闭到了具体工厂类的实现里面
    */
	return 0;
}