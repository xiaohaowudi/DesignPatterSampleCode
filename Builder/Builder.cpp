#include "Builder.h"
#include <iostream>
using namespace std;

// 构建函数，调用IBuilder衍生类提供的构造每个部分的方法
void CDirector::construct() {
	if (m_builder_ptr == NULL) {
		return;
	}

	// 构建顺序由Director决定
	m_builder_ptr->build_part_a();
	m_builder_ptr->build_part_b();
}

// 设置builder函数
void CDirector::set_builder(IBuilder* p_builder) {
	m_builder_ptr = p_builder;
}

// 两种IBuilder实现类对于每个构建步骤的不同的实现
void CBuilder1::build_part_a() {
	cout << "CBuilder1::build_part_a" << endl;
}

void CBuilder1::build_part_b() {
	cout << "CBuilder1::build_part_b" << endl;
}

void CBuilder2::build_part_a() {
	cout << "CBuilder2::build_part_a" << endl;
}

void CBuilder2::build_part_b() {
	cout << "CBuilder2::build_part_b" << endl;
}

