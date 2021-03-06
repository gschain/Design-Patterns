
命令模式（Command）
意图：
将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可
撤销操作。

适用性：
以下条件使用Command模式：
1、你可用过程语言中的回调函数表达这种参数化机制。
2、在不同的时刻指定、排列和执行请求。
3、支持取消操作。
4、支持修改日志，这样当系统崩溃时，这些修改可以被重做一遍。
5、用构建在原语操作上的高层操作构造一个系统。

结构:
Command（抽象命令类）：一个抽象类或接口，声明了执行请求的Execute()方法，通过这些方法可以调用请求接收者的相关操作。
ConcreteCommand（具体命令类）：具体命令类是抽象命令类的子类，实现了抽象命令类中声明的方法。在实现Execute()方法时，将调用接收者对象的相关操作（Action）。
Invoker（调用者）：请求发送者，通过命令对象来执行请求。
Receiver（接收者）：接收者执行与请求相关的操作，它具体实现对请求的业务处理。

类图：
Command.jpg

优点:
降低了系统的耦合度，请求发送者与接受者不存在直接引用
方便地增加新的命令到系统中，无须修改源代码，从而符合开闭原则

缺点:
使用命令模式可能会导致某些系统有过多的具体命令类。
因为针对每一个对请求接收者的调用操作都需要设计一个具体命令，因此在某些系统中可能需要提供大量的具体命令类

总结：
Command 模式通过将请求封装到一个对象(Command)中，并将请求的接受者存放到具体的ConcreteCommand类中(Receiver)中，
从而实现调用操作的对象和操作的具体实现者之间的解耦。
举例来说还是画图板吧，我们把每次操作都生成一个对象，每执行一次就把操作储存在一个数据结构中，如果需要我们可以就行撤销和恢复操作，这就是命令模式的典型例子。

