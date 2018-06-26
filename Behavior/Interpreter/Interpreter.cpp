#include<iostream>
#include<string>

using namespace std;
using std::cout;
using std::endl;

/* 包含解释器之外的一些全局信息
 */
class Context {
public:
    virtual ~Context() {}
};

/* 声明一个抽象的解释操作，这个接口为抽象语法树中的所有的节点所共享。
 */
class AbstractExpression {
public:
    virtual void Interpret(const Context &c) = 0;
};

/* 实现与文法中的终结符相关联的解释操作。
 * 一个句子中的每个终结符需要该类的一个实例。
 */
class TerminalExpression:public AbstractExpression {
public:
    TerminalExpression(const string &statement)
    {
        m_statement = statement;   
    }
    void Interpret(const Context &c)
    {
        cout<<this->m_statement<<" TerminalExpression"<<endl;
    }
private:
    string m_statement;
};

/* 非终结符表达式。
 * 对文法中的每一条规则都需要一个NonterminalExpression类。
 * 为文法中的非终结符实现解释操作。
 */
class NonterminalExpression:public AbstractExpression {
public:
    NonterminalExpression(AbstractExpression *pExpression):m_pExpression(pExpression) {}
    void Interpret(const Context &c)
    {
        this->m_pExpression->Interpret(c);
    }
private:
    AbstractExpression *m_pExpression;
};

/* Client 构建一个句子，它是NonterminalExpression和TerminalExpression的实例的一个
 * 抽象语法树，然后初始化上下文并调用解释操作。
 * 每一个非终结符表达式节点定义相应字表达式的解释操作。而各终结符表达式的解释操作构成了
 * 递归的基础。
 * 每一节点的解释操作用上下文来存储和访问解释器的状态。
 */
int main(int argc, char *argv[])
{
    Context *c = new Context();
    AbstractExpression *te = new TerminalExpression("hello");
    AbstractExpression *nte = new NonterminalExpression(te);
    nte->Interpret(*c);
    return 0;
}
