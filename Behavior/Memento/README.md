
备忘录模式（Memento）
意图：
在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后可将该对象恢复到原先保存的状态。

适用性：
在下列情况下使用备忘录模式：
1、必须保存一个对象在某个时刻的（部分）状态，这样以后需要时它才能恢复到先前的状态。
2、如果一个用接口来让其它对象直接得到这些状态，将会暴露对象的实现细节并破坏对象的封装性。

结构:
Originator（原发器）：它是一个普通类，可以创建一个备忘录，并存储其当前内部状态，也可以使用备忘录来恢复其内部状态，一般需要保存内部状态的类设计为原发器。
Memento（备忘录）：存储原发器的状态，根据原发器来决定保存哪些内部状态。
Caretaker（负责任）：负责任又称为管理者，它负责保存备忘录，但是不能对备忘录的内容进行操作或检查。

类图：
Memento.jpg

优点:
提供了一种状态恢复的实现机制，使得用户可以方便地回到一个特定的历史步骤。
实现了对信息的封装，一个备忘录对象是一种原发器对象状态的表示，不会被其他代码所改动。

缺点:
资源消耗过大，每保存一次对象状态都需要消耗一定系统资源。

总结：
1、备忘录模式的功能可谓是非常的专一的，就是用来记录历史状态的
2、当我们需要记录历史状态，并需要返回这个历史状态的时候可以使用
3、当然这个模式重点就在历史状态的存储方式上面了，你可以使用你所需需要的数据结构进行存储
也可以控制存储的容量或者是存储的方式等等
