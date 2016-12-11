#ifndef SINGLETON_H
#define SINGLETON_H

class SingletonSample {
private:
	static SingletonSample* m_instance_ptr;

private:
	// 构造函数私有
	SingletonSample();
public:
	static SingletonSample* get_instance();
	// 类的功能函数
	void operation();
};

#endif