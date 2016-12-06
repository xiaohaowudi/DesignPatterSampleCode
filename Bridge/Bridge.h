#ifndef BRIDGE_H
#define BRIDGE_H



class IImplementior {
public:
    IImplementior() { }
    ~IImplementior() { }
    // Implementor�����ӿڣ����������ʵ�֣��ṩ��IAbstraction��ʵ������е���
    virtual void operation_impl() = 0;
};

class IAbstraction {
public:
    IAbstraction(IImplementior *p_impl) : m_impl_ptr(p_impl) { }
    virtual ~IAbstraction() { }
    // ���ܺ������������ʵ��
    virtual void operation() = 0;
protected:
    IImplementior *m_impl_ptr;
};

// �������ʵ����1
class RefinedAbstraction1 : public IAbstraction {
public:
    RefinedAbstraction1(IImplementior *p_impl) : IAbstraction(p_impl) { }
    ~RefinedAbstraction1() { }
    void operation();
};



// �������ʵ����2
class RefinedAbstraction2 : public IAbstraction {
public:
    RefinedAbstraction2(IImplementior *p_impl) : IAbstraction(p_impl) { }
    ~RefinedAbstraction2() { }
    void operation();
};

// Implementor��ʵ����1
class ConcreteImplementor1 : public IImplementior {
public:
    ConcreteImplementor1() { }
    ~ConcreteImplementor1() { }
    void operation_impl();
};

// Implementor��ʵ����2
class ConcreteImplementor2 : public IImplementior {
public:
    ConcreteImplementor2() { }
    ~ConcreteImplementor2() { }
    void operation_impl();
};

#endif