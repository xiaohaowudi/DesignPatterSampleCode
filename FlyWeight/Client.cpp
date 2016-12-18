#include "FlyWeight.h"

int main(void) {
	FlyWeightFactory *factory = new FlyWeightFactory();
	IFlyWeight *p_flyweight;

	p_flyweight = factory->get_flyweight(100);
	p_flyweight->operation();
	p_flyweight = factory->get_flyweight(200);
	p_flyweight->operation();
	p_flyweight = factory->get_flyweight(300);
	p_flyweight->operation();

	delete factory;
	return 0;
}