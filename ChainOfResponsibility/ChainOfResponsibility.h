#ifndef RESPONSIBILITY_H
#define RESPONSIBILITY_H

#include <stdio.h>

enum REQUEST_TYPE {
	TYPE0,
	TYPE1,
	TYPE2,
	TYPE3,
};

// �������ߵĳ���ӿ�
class IHandler {
public:
	IHandler(IHandler* p_handler = NULL) : m_successor_ptr(p_handler) { }
	virtual ~IHandler() { }

	// ����ʵ�ֵĴ���ӿ�
	virtual void call_handle_func(REQUEST_TYPE req_type);				// ��Ĭ�ϵ�ʵ�֣����಻һ��Ҫ����
	virtual bool can_handle_request(REQUEST_TYPE req_type) = 0;		// ��������ṩ�˽ӿ������ж��Լ��ܲ��ܴ�������
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