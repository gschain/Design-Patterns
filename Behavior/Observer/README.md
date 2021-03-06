
观察者模式(observer)
意图：
定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。

适用性：
在以下任一种情况下可以使用观察者模式：
1、当一个抽象模型有两个方面，其中一个方面依赖于另一个方面。将这二者封装在独立的对象中已使它们可以各自独立地改变和复用。
2、当对一个对象的改变需要同时改变其它对象，而不知道具体有多少对象有待改变。
3、当一个对象必须通知其它对象，而它又不能假定其它对象是谁。换言之，你不希望这些对象是紧密耦合的。

结构:
Subject（抽象目标）：又称为主题，是被观察的对象。
ConcreteSubject（具体目标）：抽象目标的子类，通常包含有经常发生改变的数据，当它的状态发生改变时，向其各个观察者发出通知。
Observer（抽象观察者）：观察者将对观察目标的改变做出反应。
ConcreteObserver（具体观察者）：具体观察者中维持一个指向具体目标对象的引用，它用于存储具体观察者的有关状态，这些状态需要和具体目标地状态保持一致。

类图：
Observer.jpg

优点:
可以实现表示层和数据逻辑层的分离，观察者和目标是松耦合的
支持广播通信，观察目标会向已注册的观察者对象发送通知
增加新的观察者无须修改原有系统代码

缺点:
如果一个观察目标有很多直接和间接的观察者，所有观察者收到通知会花费大量时间
如果观察者和观察目标之间存在循环依赖，可能导致系统崩溃
如果忘记删除不必要的订阅者，那么容易误发送消息

总结：
最常见的一个例子就是:对同一组数据进行统计分析时候，我们希望能够提供多种形式的表示(例如以表格进行统计显示、柱状图统计显示、
百分比统计显示等)。 这些表示都依赖于同一组数据，我们当然需要当数据改变的时候，所有的统计的显示都能够同时改变。
Observer 模式也称为发布-订阅(publish-subscribe)，目标就是通知的发布者，观察者 则是通知的订阅者(接受通知)。
