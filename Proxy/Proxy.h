#ifndef PROXY_H
#define PROXY_H

// 具体实现类和代理类的公共接口
class ISubject {
public:
	ISubject() { }
	virtual ~ISubject() { }

	// 具体的功能接口
	virtual void request() = 0;
};


class CRealSubject : public ISubject {
public:
	CRealSubject() { }
	~CRealSubject() { }
	void request();
};

class CProxy : public ISubject {
public:
	CProxy(CRealSubject* p_real_request) : m_real_request_ptr(p_real_request) { }
	~CProxy() { }
	void request();
private:
	CRealSubject* m_real_request_ptr;
};

#endif