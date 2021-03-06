
建造者模式（Builder）
意图：
将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。

适用性：
在下面情况可以使用Builder模式：
1、当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式。
2、当构建过程必须允许被构造的对象有不同的表示时。

结构：
Builder（抽象建造者）：为创建一个产品对象的各个部件指定抽象接口，在其接口中一般包含两类方法：一类是BuildPartX()，用于创建复杂对象的各个部件；
另一类是GetResult()，用于返回生成好的复杂对象。它就可以是抽象类，也可以是接口。
ConcreteBuilder（具体建造者）：实现了Builder接口，即实现了各个部件的具体构造和装配方法，定义并明确其所创建的复杂对象。
Product（产品角色）：被构建的复杂对象，包含多个组成部件。
Director（指挥者）：负责安排复杂对象的建造次序，指挥者与抽象建造者之间存在关联关系，可以在其Construct()方法中调用建造者对象的部件构造和装配方法，完成复杂对象的建造。
因此，客户端只需要和指挥者进行交互，这也确保了单一职责。

类图：
Builder.jpg

优点:
客户端不需要知道产品内部的组成细节，将产品本身与产品的创建过程解耦，使得
相同的创建过程可以创建不同的产品对象。具体建造者相对独立，增加新的具体建
造者无需修改原有类库的代码，系统扩展比较方便，符合开闭原则。可以更加精细
地控制产品的创建过程，将复杂产品的创建步骤分解在不同的方法中，使得创建过
程更加清晰，也更方便使用程序来控制创建过程。

缺点:
对于所创建的产品有一定限制：一般这些产品都具有一些较多的共同点，其组成部
分相似。如果差异性很大，那么则不适合使用建造者模式。如果产品的内部结构复
杂多变，可能会需要定义很多具体构建者来实现这些变化，会导致系统变得庞大，
增加系统的理解难度和运行成本。

总结：
1、建造者模式是用来生产对象的，告诉指挥者你需要什么样的对象，他就给你建造
什么样的对象。
2、建造者的任务是组装一个个零件，最终建造出一个你所需要的对象。就如例子中，
我们需要建造一个大人和一个小孩对象我们只要告诉指挥者我们需要什么样的对象就
可以了，他就会帮我们建造好一个完整的对象。
3、建造者模式一个重点是向客户隐藏了产品的内部表现。
4、建造者模式与抽象工厂模式有点相似，但是建造者模式返回一个完整的复杂产品，
而抽象工厂模式则返回一系列相关的产品。
如果将抽象工厂模式看成一个汽车配件生产厂，生成不同类型的汽车配件;
那么建造者模式则是一个汽车组装厂，通过对配件进行组成返回一辆完整的汽车。

Builder 模式和AbstractFactory模式在功能上很相似，因为都是用来创建大的复杂
的对象，它们的区别是:Builder 模式强调的是一步步创建对象，并通过相同的创建过
程可以获得不同的结果对象，一般来说Builder模式中对象不是直接返回的。而在 
AbstractFactory模式中对象是直接返回的,AbstractFactory模式强调的是为创建
多个相互依赖的对象提供一个同一的接口。
