#ifndef SINGLETON_H
#define SINGLETON_H

class SingletonSample {
private:
	static SingletonSample* m_instance_ptr;

private:
	// ���캯��˽��
	SingletonSample();
public:
	static SingletonSample* get_instance();
	// ��Ĺ��ܺ���
	void operation();
};

#endif