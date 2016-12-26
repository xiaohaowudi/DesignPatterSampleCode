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

	virtual void operation() = 0;									// 子类实现功能接口
	virtual void add(IComponent* p_component) { }					// 增加子节点接口
	virtual void remove(INDEX index) { }							// 删除子节点接口
	virtual IComponent* get_child(INDEX index) { return NULL; }		// 查找子节点接口
	virtual INDEX get_name() { return m_name; }						// 获取自己名字接口
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
	map<INDEX, IComponent*> m_name2component;	// 保存子对象结构
};

class CLeaf : public IComponent {
public:
	CLeaf(const char* p_name) : IComponent(p_name) { }
	~CLeaf() { cout << "Leaf::~Leaf name = " << m_name << endl; }

	// 叶子节点默认只实现operation接口
	void operation();
};

#endif