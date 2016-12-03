#include "Builder.h"

int main(void) {
	CDirector* p_director = new CDirector();
	IBuilder* p_builder1 = new CBuilder1();
	IBuilder* p_builder2 = new CBuilder2();

	// 使用第一种构建者进行构建
	p_director->set_builder(p_builder1);
	p_director->construct();

	// 使用第二种构建者进行构建
	p_director->set_builder(p_builder2);
	p_director->construct();

	delete p_director;
	delete p_builder1;
	delete p_builder2;
	return 0;
}