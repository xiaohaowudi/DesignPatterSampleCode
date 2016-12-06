#ifndef BRIDGE_H
#define BRIDGE_H



class IImplementior {
public:
    IImplementior() { }
    ~IImplementior() { }
    // Implementor类的虚接口，由子类进行实现，提供给IAbstraction的实现类进行调用
    virtual void operation_impl() = 0;
};

class IAbstraction {
public:
    IAbstraction(IImplementior *p_impl) : m_impl_ptr(p_impl) { }
    virtual ~IAbstraction() { }
    // 功能函数，子类进行实现
    virtual void operation() = 0;
protected:
    IImplementior *m_impl_ptr;
};

// 抽象类的实现类1
class RefinedAbstraction1 : public IAbstraction {
public:
    RefinedAbstraction1(IImplementior *p_impl) : IAbstraction(p_impl) { }
    ~RefinedAbstraction1() { }
    void operation();
};



// 抽象类的实现类2
class RefinedAbstraction2 : public IAbstraction {
public:
    RefinedAbstraction2(IImplementior *p_impl) : IAbstraction(p_impl) { }
    ~RefinedAbstraction2() { }
    void operation();
};

// Implementor的实现类1
class ConcreteImplementor1 : public IImplementior {
public:
    ConcreteImplementor1() { }
    ~ConcreteImplementor1() { }
    void operation_impl();
};

// Implementor的实现类2
class ConcreteImplementor2 : public IImplementior {
public:
    ConcreteImplementor2() { }
    ~ConcreteImplementor2() { }
    void operation_impl();
};

#endif