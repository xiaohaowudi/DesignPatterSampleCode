#include "Composite.h"
#include <iostream>
using namespace std;

void CComposite::add(IComponent* p_component) {
	if (p_component == NULL) {
		return;
	}

	if (m_name2component.find(p_component->get_name()) == m_name2component.end()) {
		m_name2component[p_component->get_name()] = p_component;
	}
}

void CComposite::remove(INDEX name) {
	if (m_name2component.find(name) != m_name2component.end()) {
		IComponent* p_component = m_name2component[name];
		delete p_component;
		m_name2component.erase(name);
	}
}

void CComposite::operation() {
	cout << "CComposite::operation name = " << m_name << endl;
	// 多态方式调用所有子节点的功能接口
	for (auto itr = m_name2component.begin(); itr != m_name2component.end(); itr++) {
		if (itr->second != NULL)
		itr->second->operation();
	}
}

IComponent* CComposite::get_child(INDEX index) {
	if (m_name2component.find(index) != m_name2component.end()) {
		return m_name2component[index];
	}
	return NULL;
}

CComposite::~CComposite() {
	cout << "CComposite::~CComposite name = " << m_name << endl;
	// 删除所有子对象
	for (auto itr = m_name2component.begin(); itr != m_name2component.end(); itr++) {
		if (itr->second != NULL) {
			delete (itr->second);
		}
	}
}

void CLeaf::operation() {
	cout << "CLeaf::operation name = " << m_name << endl;
}
