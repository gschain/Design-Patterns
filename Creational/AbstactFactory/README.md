
抽象工厂模式（Abstract Factory)
意图：
提供一个创建一系列相关或相互依赖的接口，而无需指定它们的具体的类。

适用性：
在下面情况可以使用Abstract Factory模式：
1、一个系统要独立于它的产品的创建、组合和表示时；
2、一个系统要由多个产品系列中的一个来配置时；
3、当你要强调一系列相关的产品对象的设计以便进行联合使用时；
4、当你提供一个产品类库，而只想显示它们的接口而不是实现时；

结构：
AbstractFactory.jpg

优点
隔离了具体类的生成，使得客户并不需要知道什么被创建。因为这种
隔离，因此更换一个具体工厂就变得相对容易。当一个产品族中的多
个对象被设计称一起工作时，它能够保证客户端始终只使用同一个产
品族中的对象。增加新的产品族很方便，无需修改已有系统，符合开
闭原则。

缺点
增加新的产品等级结构很麻烦，因为需要对原有系统进行较大的修改，
甚至需要修改抽象层代码，这必然会带来较大的不便。在这个角度，
它违背了开闭（对扩展开放，对修改封闭）原则。

AbstractFactory 模式是为创建一组(有多类)相关或依赖的对象提供创建接口，
而Factory 模式正如我在相应的文档中分析的是为一类对象提供创建接口或延 
迟对象的创建到子类中实现。并且可以看到，AbstractFactory模式通常都是使
用Factory模式实现。