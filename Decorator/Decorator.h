#ifndef DECORATOR_H
#define DECORATOR_H

// 被装饰者的抽象基类
class IComponent {
public:
	IComponent() { }
	virtual ~IComponent() { }

	// 被装饰者的抽象行为接口
	virtual void operation() = 0;
};

// 装饰者的抽象接口, 装饰者同样也可以被装饰，所以同时也是一种被装饰者，所以继承Component接口类
class IDecorator : public IComponent {
public:
	IDecorator(IComponent *p_component) : m_component_ptr(p_component) { }
	virtual ~IDecorator() { }
protected:
	IComponent *m_component_ptr;
};

// 最原始的被装饰者，只提供一项核心功能，没有附加功能
class CConcreteComponent : public IComponent {
public:
	CConcreteComponent() { }
	~CConcreteComponent() { }
	void operation();
};

// 装饰者实现类1
class CConcreteDecorator1 : public IDecorator {
public:
	CConcreteDecorator1(IComponent *p_component) : IDecorator(p_component) { }
	~CConcreteDecorator1() { }
	void operation();			// 装饰者的行为，动态调用被装饰者的行为,同时又提供给别的装饰者调用
	void add_operation();		// 装饰者的附加行为，和被装饰者的行为一起构成当前装饰者的行为
};

// 装饰者实现类2
class CConcreteDecorator2 : public IDecorator {
public:
	CConcreteDecorator2(IComponent *p_component) : IDecorator(p_component) { }
	~CConcreteDecorator2() { }
	void operation();			// 装饰者的行为，动态调用被装饰者的行为,同时又提供给别的装饰者调用
	void add_operation();		// 装饰者的附加行为，和被装饰者的行为一起构成当前装饰者的行为
};

// 装饰者实现类3
class CConcreteDecorator3 : public IDecorator {
public:
	CConcreteDecorator3(IComponent *p_component) : IDecorator(p_component) { }
	~CConcreteDecorator3() { }
	void operation();			// 装饰者的行为，动态调用被装饰者的行为,同时又提供给别的装饰者调用
	void add_operation();		// 装饰者的附加行为，和被装饰者的行为一起构成当前装饰者的行为
};

#endif