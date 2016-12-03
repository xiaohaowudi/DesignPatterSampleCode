#include "Product.h"
#include "Factory.h"
#include <stdio.h>

int main(void) {
    IProduct* p_product = NULL;

    IFactory *p_factory1 = new CFactory1();
    IFactory *p_factory2 = new CFactory2();

    /*
        产品类使用者不感知具体的产品类的构造方式和具体是什么产品类，只关心某种特定的工厂类
        能够返回实现了某种功能的产品类实例即可，产品的构造方式变化了，产品使用者的代码不用
        做任何修改，关于产品构造方式的变更修改都封闭到了具体工厂类的实现里面
    */
    p_product = p_factory1->create_product();
    p_product->operation();
    delete p_product;

    p_product = p_factory2->create_product();
    p_product->operation();
    delete p_product;

    delete p_factory1;
    delete p_factory2;
}