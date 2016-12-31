#ifndef RESPONSIBILITY_H
#define RESPONSIBILITY_H

#include <stdio.h>

enum REQUEST_TYPE {
	TYPE0,
	TYPE1,
	TYPE2,
	TYPE3,
};

// 请求处理者的抽象接口
class IHandler {
public:
	IHandler(IHandler* p_handler = NULL) : m_successor_ptr(p_handler) { }
	virtual ~IHandler() { }

	// 子类实现的处理接口
	virtual void call_handle_func(REQUEST_TYPE req_type);				// 有默认的实现，子类不一定要重载
	virtual bool can_handle_request(REQUEST_TYPE req_type) = 0;		// 子类必须提供此接口用于判断自己能不能处理请求
	virtual void handle_request(REQUEST_TYPE req_type) = 0;

private:
	IHandler* m_successor_ptr;
};

class CConcreteHandler0 : public IHandler {
public:
	CConcreteHandler0(IHandler* p_handler = NULL) : IHandler(p_handler) { }
	~CConcreteHandler0() { }
	void handle_request(REQUEST_TYPE req_type);
	bool can_handle_request(REQUEST_TYPE req_type);
};

class CConcreteHandler1 : public IHandler {
public:
	CConcreteHandler1(IHandler* p_handler = NULL) : IHandler(p_handler) { }
	~CConcreteHandler1() { }
	void handle_request(REQUEST_TYPE req_type);
	bool can_handle_request(REQUEST_TYPE req_type);
};

class CConcreteHandler2 : public IHandler {
public:
	CConcreteHandler2(IHandler* p_handler = NULL) : IHandler(p_handler) { }
	~CConcreteHandler2() { }
	void handle_request(REQUEST_TYPE req_type);
	bool can_handle_request(REQUEST_TYPE req_type);
};

#endif