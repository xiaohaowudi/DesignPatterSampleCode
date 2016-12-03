#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
using namespace std;

// �ϲ������ϣ��ʹ�õĹ��ܽӿ�
class ITarget {
public:
	ITarget() {}
	virtual ~ITarget() {}

	// �ϲ������ϣ��ʹ�õĺ����ӿ�
	virtual void request() = 0;
};

// �Ѿ�ʵ����ĳ�ֹ��ܵ��࣬����Ĺ����ܹ������ã�����ʹ�÷�ʽ�͵�����ϣ���Ľӿڲ�ͬ
class Adaptee {
public:
	// ʵ����ĳ�ֹ��ܵĲ����ݽӿ�
	void special_request();
};

// ��������ʵ���࣬���ú͵�����ϣ��ʹ�õĽӿڲ����ݵ����й���ʵ�ֵ�����ϣ��ʹ�õ���ʽ�Ľӿ�
class CAdapter : public ITarget {
public:
	CAdapter(Adaptee *p_adapter) : m_adaptee_ptr(p_adapter) { cout << "CAdapter::CAdapter" << endl; }
	~CAdapter() { cout << "CAdapter::~CAdapter" << endl; }

	// �Ե�����ϣ����request�ӿڵ�ʵ��
	void request();
private:
	Adaptee* m_adaptee_ptr;
};

#endif