
组合模式（Composite）
意图：
将对象组合成树形结构以表示“部分-整体”的层次结构。Composite使得用户对单个对象和组合对象的使用具有
一致性。

适用性：
以下情况时有Compostie模式：
1、你想表示对象的部分-整体层次结构。
2、你希望用户忽略组合对象与单个对象的不同，用户将统一地使用组合结构中的所有对象。

结构
Component（抽象构件）：它是接口或抽象类，为叶子构件和容器构件对象声明接口，在该角色中可以包含所有子类共有行为的声明和实现。
在抽象构件中定义了访问及管理它的子构件的方法，例如增加子构件、删除子构件、获取子构件等。
Leaf（叶子构件）：它在组合模式中表示叶子结点对象，叶子结点没有子节点，它实现了在抽象构件中定义的行为。
Composite（容器构件）：它在组合模式中表示容器节点对象，容器节点包含子节点，其子节点可以使叶子结点，也可以是容器节点，它提供一个集合用于存储子节点，实现了在抽象构件中定义的行为。

类图：
Composite.jpg

优点:
可以清楚地定义分层次的复杂对象，表示对象的全部或部分层次，使客户忽略了层次的差异，方便对整个层次结构进行控制。
增加新的容器构件和叶子构件都十分方便，无需对现有类库代码进行任何修改，符合开闭原则。
为树形结构的面向对象实现提供了灵活地解决方案，可以形成复杂的树形结构，但对树形结构的控制却很简单。

缺点:
增加新构件时很难对容器中的构建类型进行限制。

总结：
Composite 模式在实现中有一个问题就是要提供对于子节点(Leaf)的管理策略，这里
使用的是STL中的 vector，可以提供其他的实现方式，如数组、链表、Hash 表等。
Composite 模式通过和 Decorator模式有着类似的结构图，但是Composite模式旨在构造类，而Decorator模式重在
不生成子类即可给对象添加职责。Decorator模式重在修饰，而Composite模式重在表示。

