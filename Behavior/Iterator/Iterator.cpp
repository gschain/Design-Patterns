#include<iostream>

using namespace std;
using std::cout;
using std::endl;

/* 迭代器定义访问和遍历元素的接口
 */
class Iterator {
public:
    virtual ~Iterator() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual int CurrentItem() = 0;
protected:
    Iterator() {}
};

/* 聚合定义创建相应迭代器对象接口
 */
class Aggregate {
public:
    virtual ~Aggregate() {}
    virtual Iterator *CreateIterator() = 0; 
    virtual int GetItem(int idx) = 0; 
    virtual int GetSize() = 0;
protected:
    Aggregate() {}
};

/* 具体迭代器实现迭代器接口。
 * 对该聚合遍历时跟踪当前位置。
 */
class ConcreteIterator:public Iterator {
public:
    ConcreteIterator(Aggregate *pAg, int idx = 0):m_pAg(pAg), m_idx(idx) {}
    void First() 
    {
        m_idx = 0;
    }
    void Next() 
    {
        if (m_idx < m_pAg->GetSize()) {
            m_idx++;
        }
    }
    bool IsDone() 
    {
        return (m_idx == m_pAg->GetSize());
    }
     int CurrentItem()
     {
        return m_pAg->GetItem(m_idx);
     }
private:
    Aggregate *m_pAg;
    int m_idx;
};

/* 具体聚合实现创建相应迭代器的接口，该操作返回ConcreteIterator的
 * 一个适当的实例。
 */
class ConcreteAggregate:public Aggregate {
public:
    enum {SIZE = 3};
    ConcreteAggregate()
    {
        for (int i = 0; i < SIZE; i++) {
            m_obj[i] = i;
        }
    }
    Iterator *CreateIterator()
    {
        return new ConcreteIterator(this);
    }
    int GetItem(int idx)
    {
        if (idx < this->GetSize()) {
            return m_obj[idx];
        } else {
            return -1;
        }
    }
    int GetSize()
    {
        return SIZE;
    }
protected:
    int m_obj[SIZE];
};

int main(int argc, char *argv[])
{
    Aggregate *pAg = new ConcreteAggregate();
    Iterator *it = new ConcreteIterator(pAg);
    for (; !(it->IsDone()); it->Next()) {
        cout<<it->CurrentItem()<<endl;
    }

    return 0;
}
