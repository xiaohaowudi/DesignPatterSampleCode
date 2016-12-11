#include "Builder.h"
#include <iostream>
using namespace std;

// 构建函数，调用IBuilder衍生类提供的构造每个部分的方法
IProduct* CDirector::construct() {
	if (m_builder_ptr == NULL) {
		return NULL;
	}

	IProduct *p_product = m_builder_ptr->init_instance();
	/*
		具体的构建流程实现，要求此段实现是稳定的，才能够使用builder模式,
		每个构建步骤的实现可能有变化，但是构建步骤的调用顺序以及组织方式
		不变，下面的一段构造流程就可以抽象出来，不断被复用
	*/
	for (int i = 0; i < 3; i++) {
		m_builder_ptr->build_part_a(p_product);
	}
	m_builder_ptr->build_part_b(p_product);

	return p_product;
}

// 设置builder函数
void CDirector::set_builder(IBuilder* p_builder) {
	m_builder_ptr = p_builder;
}

// 两种IBuilder实现类对于每个构建步骤的不同的实现
void CBuilder1::build_part_a(IProduct *p_product) {
	p_product->set_a(10);
	cout << "CBuilder1::build_part_a" << endl;
}

void CBuilder1::build_part_b(IProduct *p_product) {
	p_product->set_b(10.56);
	cout << "CBuilder1::build_part_b" << endl;
}

IProduct* CBuilder1::init_instance() {
	return new CProduct1();
}

void CBuilder2::build_part_a(IProduct *p_product) {
	p_product->set_a(20);
	cout << "CBuilder2::build_part_a" << endl;
}

void CBuilder2::build_part_b(IProduct *p_product) {
	p_product->set_b(10.564);
	cout << "CBuilder2::build_part_b" << endl;
}

IProduct* CBuilder2::init_instance() {
	return new CProduct2();
}

 // 具体产品行为的实现
void CProduct1::operation() {
	cout << "CProduct1::operation," << "a = " << a << ", b = " << b << endl;
}

// 具体产品行为的实现
void CProduct2::operation() {
	cout << "CProduct2::operation," << "a = " << a << ", b = " << b << endl;
}


