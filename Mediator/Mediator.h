#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <stdio.h>

// 中介者接口，完成IColeague实现类之间的交互和合作
class IMediator {
public:
	IMediator() { }
	virtual ~IMediator() { }

	// 假设中介者只完成两个同事类之间的交互
	virtual void call_colleague1_oper1() = 0;
	virtual void call_colleague1_oper2() = 0;
	virtual void call_colleague2_oper1() = 0;
	virtual void call_colleague2_oper2() = 0;
};

// 同事类接口，各个合作者之间共同的接口规范
class IColleague {
public:
	IColleague() : m_mediator_ptr(NULL) { }
	virtual ~IColleague() { }

	// 假设每个同事实现类都实现下面的功能接口
	virtual void operation1() = 0;		// 子功能1
	virtual void operation2() = 0;		// 子功能2

	// 同时类之间相互调用实现的核心功能
	virtual void function() = 0;

	// 设置中介者成员
	void set_mediator(IMediator* p_mediator) { m_mediator_ptr = p_mediator; }
protected:
	// 每个同事类组合一个中介者实例
	IMediator* m_mediator_ptr;
};

class CColleague1;
class CColleague2;

// 中介者实现类
class CMediator : public IMediator {
public:
	CMediator(CColleague1* p_colleague1, CColleague2* p_colleague2) : m_colleague_ptr1(p_colleague1), m_colleague_ptr2(p_colleague2) { }
	CMediator() : m_colleague_ptr1(NULL), m_colleague_ptr2(NULL) { }
	~CMediator() { }

	void call_colleague1_oper1();
	void call_colleague1_oper2();
	void call_colleague2_oper1();
	void call_colleague2_oper2();

private:
	// 中介者内部实际组合同事实现类的实例
	CColleague1* m_colleague_ptr1;
	CColleague2* m_colleague_ptr2;
};

class CColleague1 : public IColleague {
public:
	CColleague1() { }
	~CColleague1() { }

	void operation1();
	void operation2();
	void function();
};

class CColleague2 : public IColleague {
public:
	CColleague2() { }
	~CColleague2() { }

	void operation1();
	void operation2();
	void function();
};

#endif