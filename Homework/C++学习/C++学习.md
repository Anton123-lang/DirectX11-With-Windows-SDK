## C++学习

1. 构造函数：
   * 在类中为成员变量统一初始化，名称与类一致，且可以接受参数，在初始化时赋给相应的类成员变量。
   * 如果把构造函数设置为`private`，那么该类无法创造实例，因为实例找不到构造函数。

2. 析构函数（构造函数的**邪恶**孪生兄弟）：
   - 当某个类消失时（比如说离开函数时候，或者整个程序运行结束时）会自动调用该函数。
   - 在类名称前面加上`~`，里面可以打印信息（比如玩家死亡提示），或者释放内存（少用）。
   
3. 虚函数:

   - 虚函数是C++中实现多态（Polymorphism）的关键机制之一。它允许派生类（子类）重写（Override）继承自基类（父类）的函数，从而在运行时根据对象的**实际类型**调用相应的函数版本。虚函数的核心特性是**动态绑定**（Dynamic Binding），即函数调用的解析发生在运行时，而不是编译时。

   - Example:

     - 当`Entity`的指针`ptr`指向一个Player的类时，如果`Entity`类中的函数和`Player`类中的函数有相同名称时（例如叫做`func`），调用该指针的`func`，结果输出的是`Entity`的`func`（因为该指针的类型是`Entity`型），如果想用`Player`的`func`去覆写`Entity`，可以在`Entity`的`func`前加上`virtual`，在`Player`的`func`中间加上`override`

     * Entity:
       `virtual std::string func() {return "Entity"};`

     * Player:

       `std::string func() override {return "Player"};`

   - 纯虚函数：如果在一个类中（假设为`PrintName`）具有其他类的通性，那么在这个类中可以定义许多函数接口，这些函数都是虚函数，且都没有具体的函数实现，例如可以写

     ``` 
     class PrintName
     {
     	virtual std::string GetClassName() = 0;
     }
     ```

     这样这个类无法实例化（无法创建对象），但是后面继承这个父类的子类都必须写一个`override`函数来覆写这个虚函数，这样我们看到这个`PrintName`父类就知道其子类都有什么共性，同时也提示我们子类都要重写一个函数来覆盖掉虚函数。

4. 可见性

   * `public`: 所有人均可访问
   * `protected`: 子类可以访问
   * `private`: 只有类本身可以访问

5. new函数与delete的使用

   * `int* a = new int(5);`表示分配一段int大小的内存，并赋予初始值5
   * `int* b = new int[5];`表示创建一个长度为5的数组，b指向数组的首地址

   * 删除方法：

     ```C++
     delete a;
     delete[] b;
     ```

     前者表示删除单个对象，后者是删除整个数组

6. 多字节的字符型

   * `wchar_t`
   * `char16_t`
   * `char32_t`

