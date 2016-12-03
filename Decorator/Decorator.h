#ifndef DECORATOR_H
#define DECORATOR_H

// ��װ���ߵĳ������
class IComponent {
public:
	IComponent() { }
	virtual ~IComponent() { }

	// ��װ���ߵĳ�����Ϊ�ӿ�
	virtual void operation() = 0;
};

// װ���ߵĳ���ӿ�, װ����ͬ��Ҳ���Ա�װ�Σ�����ͬʱҲ��һ�ֱ�װ���ߣ����Լ̳�Component�ӿ���
class IDecorator : public IComponent {
public:
	IDecorator(IComponent *p_component) : m_component_ptr(p_component) { }
	virtual ~IDecorator() { }
protected:
	IComponent *m_component_ptr;
};

// ��ԭʼ�ı�װ���ߣ�ֻ�ṩһ����Ĺ��ܣ�û�и��ӹ���
class CConcreteComponent : public IComponent {
public:
	CConcreteComponent() { }
	~CConcreteComponent() { }
	void operation();
};

// װ����ʵ����1
class CConcreteDecorator1 : public IDecorator {
public:
	CConcreteDecorator1(IComponent *p_component) : IDecorator(p_component) { }
	~CConcreteDecorator1() { }
	void operation();			// װ���ߵ���Ϊ����̬���ñ�װ���ߵ���Ϊ,ͬʱ���ṩ�����װ���ߵ���
	void add_operation();		// װ���ߵĸ�����Ϊ���ͱ�װ���ߵ���Ϊһ�𹹳ɵ�ǰװ���ߵ���Ϊ
};

// װ����ʵ����2
class CConcreteDecorator2 : public IDecorator {
public:
	CConcreteDecorator2(IComponent *p_component) : IDecorator(p_component) { }
	~CConcreteDecorator2() { }
	void operation();			// װ���ߵ���Ϊ����̬���ñ�װ���ߵ���Ϊ,ͬʱ���ṩ�����װ���ߵ���
	void add_operation();		// װ���ߵĸ�����Ϊ���ͱ�װ���ߵ���Ϊһ�𹹳ɵ�ǰװ���ߵ���Ϊ
};

// װ����ʵ����3
class CConcreteDecorator3 : public IDecorator {
public:
	CConcreteDecorator3(IComponent *p_component) : IDecorator(p_component) { }
	~CConcreteDecorator3() { }
	void operation();			// װ���ߵ���Ϊ����̬���ñ�װ���ߵ���Ϊ,ͬʱ���ṩ�����װ���ߵ���
	void add_operation();		// װ���ߵĸ�����Ϊ���ͱ�װ���ߵ���Ϊһ�𹹳ɵ�ǰװ���ߵ���Ϊ
};

#endif