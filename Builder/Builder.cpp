#include "Builder.h"
#include <iostream>
using namespace std;

// ��������������IBuilder�������ṩ�Ĺ���ÿ�����ֵķ���
void CDirector::construct() {
	if (m_builder_ptr == NULL) {
		return;
	}

	// ����˳����Director����
	m_builder_ptr->build_part_a();
	m_builder_ptr->build_part_b();
}

// ����builder����
void CDirector::set_builder(IBuilder* p_builder) {
	m_builder_ptr = p_builder;
}

// ����IBuilderʵ�������ÿ����������Ĳ�ͬ��ʵ��
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

