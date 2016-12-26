#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;

typedef string INDEX;

class IComponent {
public:
	IComponent(const char* p_name) : m_name(p_name) { }
	virtual ~IComponent() { }

	virtual void operation() = 0;									// ����ʵ�ֹ��ܽӿ�
	virtual void add(IComponent* p_component) { }					// �����ӽڵ�ӿ�
	virtual void remove(INDEX index) { }							// ɾ���ӽڵ�ӿ�
	virtual IComponent* get_child(INDEX index) { return NULL; }		// �����ӽڵ�ӿ�
	virtual INDEX get_name() { return m_name; }						// ��ȡ�Լ����ֽӿ�
protected:
	INDEX m_name;
};

class CComposite : public IComponent {
public:
	CComposite(const char* p_name) : IComponent(p_name) { m_name2component.clear(); }
	~CComposite();

	void operation();
	void add(IComponent* p_component);
	virtual void remove(INDEX index);
	IComponent* get_child(INDEX index);

private:
	map<INDEX, IComponent*> m_name2component;	// �����Ӷ���ṹ
};

class CLeaf : public IComponent {
public:
	CLeaf(const char* p_name) : IComponent(p_name) { }
	~CLeaf() { cout << "Leaf::~Leaf name = " << m_name << endl; }

	// Ҷ�ӽڵ�Ĭ��ֻʵ��operation�ӿ�
	void operation();
};

#endif