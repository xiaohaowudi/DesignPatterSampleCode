#ifndef VISITOR_H
#define VISITOR_H

#include <string>
using namespace std;

class IVisitor;

class IElement {
public:
	IElement() { }
	virtual ~IElement() { }

	// 注入visitor的接口
	virtual void accept(IVisitor* p_visitor) = 0;
};

class CElement1 : public IElement {
public:
	CElement1(unsigned int value) : m_value(value) { }
	virtual ~CElement1() { }
	void accept(IVisitor* p_visitor);
	unsigned int get_value() { return m_value; }

private:
	unsigned int m_value;
};

class CElement2 : public IElement {
public:
	CElement2(double value) : m_value(value) { }
	virtual ~CElement2() { }
	void accept(IVisitor* p_visitor);
	double get_value() { return m_value; }

private:
	double m_value;
};

class CElement3 : public IElement {
public:
	CElement3(const char *p_str) : m_value(p_str) { }
	virtual ~CElement3() { }
	void accept(IVisitor* p_visitor);
	string get_value() { return m_value; }

private:
	string m_value;
};

class IVisitor {
public:
	IVisitor() { }
	virtual ~IVisitor() { }

	// 针对每一个具体类的操作接口, visitor模式的使用前提是visitor子类的个数不变
	virtual void visit_element1(CElement1* p_element) = 0;
	virtual void visit_element2(CElement2* p_element) = 0;
	virtual void visit_element3(CElement3* p_element) = 0;
};

// 假设对于element有A B 两种操作
class CVisitorA : public IVisitor {
public:
	CVisitorA() { }
	~CVisitorA() { }

	void visit_element1(CElement1* p_element);
	void visit_element2(CElement2* p_element);
	void visit_element3(CElement3* p_element);
};

class CVisitorB : public IVisitor {
public:
	CVisitorB() { }
	~CVisitorB() { }

	void visit_element1(CElement1* p_element);
	void visit_element2(CElement2* p_element);
	void visit_element3(CElement3* p_element);
};

#endif