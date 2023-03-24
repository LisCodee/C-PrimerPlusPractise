# C++-PrimerPlusPractise
C++PP练习题，包含部分笔记

# Chapter3 简单变量

## 整型
- short:至少16位
- int:至少与short一样长
- long:至少32位，并且至少与int一样长
- long long:至少64位，且至少与long一样长
> 在Windows XP/Vista/7，Macintosh OSX、VAX和其他很多实现中，int长32位。各限制可在climits中查看。 
> Win10下：short bit:16; int bit:32; long bit:32; long long bit:64

# chapter4 复合类型
## 4.1 数组
**初始化：**

```c++
// 1. 只能在定义数组时初始化
int card[4] = {1,2,3,4};
//int card[4];
//card = {1,2,3,4}; //not allowed
//2. C++11可以省略=：
double earnings[4] {1.2e4, 1.5e2, 1.1e4, 1.6e3};
//3. 大括号内可以没有元素，会把所有元素置零
int arr[4] {};
//4. 列表初始化禁止缩窄转换
```

## 4.2 字符串
> cin使用空白（空格、制表符、换行符）来确定字符串的结束位置。
> 1. 面向行的输入：getline(char*, len) //每次读取一行，将行尾换行符替换为空白
> 2. 面向行的输入:get(char*, len) //读取一行，不读取换行符，可以使用cin.get()单独处理换行符

## 4.3 结构体
**指定位字段**
```C++
struct reg{
    unsigned int SN : 4;
    bool goodIn : 1;
};
```

## 4.6 枚举
枚举是整型，可以被提升为int类型，但是int不能自动转换为枚举类型。

## 4.7 数组
数组名对应数组第一个元素地址，对数组名取地址得到的为整个数组的地址，对数组指针应用sizeof得到的为指针的大小。
```C++
int arr[10];
int* parr = arr;
sizeof(parr) //4
sizeof(arr) //10
//&arr为整个数组地址，arr为第一个元素地址。 
```
# Chapter7 函数和二维数组

## 7.1 const修饰符

- 指向const 变量的指针：
```C++
    const double * fdb;
    //指针执行的double类型为const double，不可以通过指针修改变量值，但可以修改指针指向的地址。
```
- 指针类型为const类型的指针：
```C++
    double * const fdb;
    //指针类型为const，不可以修改指针指向的地址，但可以通过指针修改变量值
```
- 指向const变量的const指针：
```C++
    const double * const fdb;
    //既不可以修改指针地址，又不可以修改变量值
```
> 可以将const或非const类型数据的地址赋值给指向const的指针，但只能将非const数据地址赋值给非const指针。
> 在函数参数中尽可能的使用const修饰符，第一可以避免间接修改数据引发的错误；第二const修饰后可以接受const和非const实参，否则只能接受非const实参。

## 7.2 函数模板
> 模板函数很可能无法处理某些类型。对于给定的函数名可以有非模板函数、模板函数和具体化模板函数。
> 具体化优先于常规模板，非模板函数优先于模板函数。

**重载解析**
1. 创建候选函数列表。其中包含与被调用函数的名称相同的函数和模板函数
2. 使用候选函数创建可行函数列表。这些都是参数数目正确的函数，为此有一个隐式转换序列，其中包括实参类型与相应的形参类型完全匹配的情况。例如，使用float参数的函数调用可将该参数转换为double，从而与double形参匹配，而模板可以为float生成一个实例。
3. 确定是否有最佳的可行函数。
   1. 完全匹配，但常规函数优先于模板
   2. 提升转换(char, short -> int; float->double)
   3. 标准转换(int -> char, long -> double)
   4. 用户定义的转换(如类声明中定义的转换)

**完全匹配允许的无关紧要转换**

| 从实参    | 到形参    |
|--------|--------|
| Type   | Type & |
| Type&  | Type   |
| Type[] | *Type |
| Type(argument-list)|Type(*)(argument-list)|
|Type|const Type|
|Type|volatile Type|
|Type*|const Type|
|Type*|volatile Type*|


**C++11新增decltype:decltype(expression) var;**
- 如果expression是一个没有用括号括起的标识符，则var的类型与函数的返回类型相同

```C++
double x = 5.5;
double y = 7.9;
double &rx = x;
const double* pd;
decltype(x) w;  //w is type double
decltype(rx) u; //u is type double &
decltype(pd) v; //v is type double *
```

- 如果expression是一个函数调用，则var类型与函数返回类型同

```C++
long indeed(int);
decltype(indeed(3)) m;  // m is type long
```

- 如果expression是一个左值，则var为指向其类型的引用。要进入这一步，expression不能是未用括号括起来的标识符。
  
```C++
double xx = 4.4;
decltype((xx)) r2 = xx; //r2 is double &
decltype(xx) w = xx;    //w is double(Stage 1 match)
```
- 如果前面的条件都不满足，则var的类型与expression类型相同
```C++
int j = 3;
int &k = j;
int &n = j;
decltype(j+6) i1;   //i1 type int
decltype(100L) i2;  //i2 long
decltpe(k + n) i3;  //i3 type int
//如果需要多次声明可以结合typedef和decltype

template<class T1, class T2>
void ft(T1 x, T2 y){
    typedef decltype(x + y) xytype;
    xytype xpy = x + y;
    xytype arr[10];
    xytype & rxy = arr[2];
    //...
}
```

**后置返回类型**
```C++
?type? gt(T1 x, T2 y)
```
以上类型是decltype本身无法解决的，可以使用新增的语法：
```C++
template<class T1, class T2>
auto f(T1 x, T2 y) -> decltype(x + y)
{
    //...
}

```

# 第9章 内存模型和命名空间

**头文件常包含的内容：**
- 函数原型
- 使用#define或const定义的符号常量
- 结构声明
- 类声明
- 模版声明
- 内联函数

## 9.1 存储持续性、作用于和链接性
### 存储持续性
- 自动存储持续性：在函数定义中声明的变量（包括函数参数），C++有两种此类变量
- 静态存储持续性：函数定义外定义的变量和使用关键字static定义的变量，在整个程序执行过程都存在，C++有3种此类变量。
- 线程存储持续性：使用thread_local声明的变量，与线程声明周期一样长
- 动态存储持续性：使用new运算符分配的内存，在使用delete时释放，也就是堆内存。

### 静态持续变量
```C++
int global = 1000; // static duration, external linkage
static int one_file = 10; // static duration, internal linkage

void func1()
{
    static int count = 0; // static duration, no linkage
}
```
没有被显示初始化的静态变量都会被编译器设置为0（每一位），以上三种静态变量的生命周期是整个函数执行期间，但是其作用域和链接性不同，分别为外部链接性、内部链接性和无链接性。

**静态变量初始化**
- 零初始化
- 常量表达式初始化
- 动态初始化（函数被链接且程序执行时）

```C++
#include <cmath>
int x;                  //zero-initialization
int y = 100 * 100;      //constant-expression initialization
const double pi = 4.0 * atan(1.0);  //dynamic initialization
```
对于静态局部变量，只会在函数首次调用时时进行一次初始化。

**说明符**
- auto(C++11后不再是说明符)
- register（C++11后说明变量为自动的）
- static
- extern（引用外部变量）
- thread_local(C++11新增)，可以与static或extern结合使用
- mutable

**cv-限定符**
- const
- volatile

mutable用来指出，即使结构、类变量为const，其某个成员也可以被修改：
```C++
struct data{
    char name[20];
    mutable int accesses;
};
const data veep = {"aaaa", 0};
strcpy(veep.name, "bbb");       //not allowed
veep.accesses = 1;      //allowed
```

const全局变量的链接性是内部的，和static一样，如果希望某个常量的链接性为外部的，可以使用extern关键字来覆盖默认的内部链接性：
```C++
extern const int states = 20;
```

默认情况下，函数的链接性为外部的，可以使用static将其链接性设置为内部，必须同时在声明和定义中同时使用该关键字。内联函数不适用单定义规则，C++要求同一个函数的所有内联定义都相同。

**C和C++的链接性问题**
```C++
extern "C" void spiff(int);
extern "C++" void spoff(int);
extern void spaff(int); // use c++ protocol for name look-up
```

**使用new运算符初始化**
- 内置标量类型

```C++
int* pi = new int(6);
double* pd = new double(1.2);
//初始化常规结构和数组，需要C++11支持
struct point{
    double x;
    double y;
};
point* pp = new point {2.0, 1.2};
int* iarr = new int[4] {1,2,3,4};
//C++11还可将列表初始化用于单值变量
int* pi = new int{};
double* pd = new double{1.2};
```
**定位new运算符**
```C++
#include<new>
struct chaff{
    char dross[20];
    int slag;
};
char buffer1[50];
char buffer2[500];
int main(){
    chaff *p1, *p2;
    int *p3, *p4;
    //regular forms of new, allocate memory in heap
    p1 = new chaff;
    p3 = new int[20];
    //placement new
    p2 = new (buffer1) chaff;
    p4 = new (buffer2) int[20];
}
```
定位new运算符使用传给他的地址，不跟踪那些内存单元已被使用，也不查找未使用的内存块，需要程序员手动维护。delete智能用于指向常规new运算符分配的堆内存。

## 9.3 名称空间namespace
在默认情况下，在名称空间中声明的名称的链接性为外部的（除非引用了常量）。名称空间有用户定义的名称空间和全局名称空间。using声明使特定标识符可用，using编译指令使整个名称空间可用。
```C++
//using编译指令：
using namespace std;
//using 声明：
using std::cout;
//可以为namespace起别名：
namespace my_favourite_fruits;
namespace mff = my_favourite_fruits;
```

**指导原则**
- 使用在已命名的空间中声明的变量，而不是使用外部全局变量或静态变量
- 将开发的函数库或类库放在一个名称空间中
- 不要再头文件中使用using编译指令，如非要使用，应放在所有#include之后
- 首先使用using声明而不是using编译指令

# 第10章 面向对象编程

## 类和对象
OOP最重要的特性：
- 抽象
- 封装和数据隐藏
- 多态
- 继承
- 可重用性


> 结构的默认访问类型是public，而类成员的默认访问类型是private。位于类声明中的函数都将自动成为内联函数。
>所创建的每个新对象都有自己的存储空间，用于存储其内部变量和类成员，但是同一个类的所有对象共享同一组类方法，即每种方法只有一个副本。

使用构造函数：
```C++
Stock::Stock(const string& company, long shares, double share_val);
// 1.
Stock food = Stock("aaa", 111, 1.2);
//2.
Stock garment("bbb", 120, 1.23);
//3.
Stock* pstock = new Stock("ccc", 112, 2.1);
//4.C++11，列表初始化
Stock s {"ddd", 10, 2.1};
Stock s2 = {"eee", 20, 3.1};
```

无法使用对象来调用构造函数，因为对象还没有构造出来。如果没有定义任何构造函数，编译器会提供默认构造函数，如果程序员定义了非默认构造函数，则编译器不会再提供默认构造函数。**在设计类时，通常应该提供对所有类成员作隐式初始化的默认构造函数。**


### const成员函数

为了保证函数不会修改调用对象，C++的规定将const关键字放在函数的括号后面：
```C++
void Stock::show() const;
const Stock land = {"aaa", 12, 2};
land.show();
```
***只要类方法不修改调用对象，就应该将其声明为const。***

### 作用域为类的常量
```C++
class Bakery
{
    private:
    const int Months = 12;      //fail，不能这样声明
    static const int Months = 12;   //success
    enum {Months = 12};         //success
}
```
使用关键字static定义常量，该常量与其他变量存储在一起，而不是存储在对象中，因此所有对象共享同一个常量。

### 作用域内枚举（C++11）
```C++
enum class egg_old {Small, Medium, Large, Jumbo};
enum class t_shirt {Small, Medium, Large, Jumbo};
egg choice = egg::Large;
t_shirt floyd = t_shirt::Large;
// underlying type for pizza is short
enum class : short pizza {Small, Medium, Large}
```
> 枚举量的作用域为类后，不同枚举定义的枚举量就不会发生命名冲突了。C++11提高了作用域内枚举的类型安全，**在有些情况下，常规枚举将自动转换为整型，如将其赋值给int变量或者用于表达式时，但是作用域内枚举不能隐式得转化为整型，必要时可以进行显式转化。**
> 
> 枚举用某种底层整数类型表示，在98中如何选择取决于实现，因此包含枚举的结构的长度可能随系统而异。11消除了这种依赖性，默认情况下，11作用域内枚举的底层类型为int，也可以根据以上代码指定。

### 运算符重载

operatorop(argument-list)

```C++
class Time
{
private:
//...
public:
Time operator+(const Time& t) const;
// t1 + t2 被转换为 t1.operator+(t2)
Time operator*(double x) const;     //成员函数
//...
}
Time operator*(double m, const Time& t);  //非成员函数，不能访问不能访问类的私有成员，因此需要友元函数
```
**运算符重载限制：**
- 重载后的运算符必须至少有一个操作数是用户自定义的类型，这防止了用户为标准类型重载运算符。
- 不能违反运算符原来的句法规则，不能改变运算符的优先级。
- 不能创造新运算符
- 不能重载下面的运算符：
  - sizeof
  - .
  - \*
  - ::
  - ?:
  - typeid
  - const_cast
  - dynamic_cast
  - reinterpret_cast
  - static_cast
- 下面的运算符只能通过成员函数进行重载
  - =
  - ()
  - []
  - ->

### 友元
- 友元函数
- 友元类
- 友元成员函数

通过让函数称为类的友元，可以赋予该函数与类的成员函数相同的访问权限。

> 创建友元函数的第一步是将其原型放在类声明中，并在原型前面加上关键字friend：
> friend Time operator*(double m, const Time& t);
> 第二步是编写函数定义，因为其不是成员函数，所以不需要使用类限定符，并且不要在定义中使用关键字friend
> 友元函数常用来重载<<运算符：
> ostream & operator<<(ostream& os, const Time& t);

## 类的自动类型转换和强制类型转换

只接受一个参数的构造函数才能作为转换函数,除非其他参数有默认值，这会导致意外的类型转换，因此**可以使用explict关键字来禁止隐式转换。** 关闭后仍然允许强制类型转换。

```C++
class Stonew
{

public:
    Stonew(double lbs);     
    //...
}
Stonew myCat;
myCat = 19.6;   //use Stonew(19.6) to convert double to Stonewt
```

隐式转换发生的情况：
- 将Stonewt对象初始化为double值时；
- 将double值赋值给Stonewt对象时；
- 将double值传递给接受Stonewt参数的函数时；
- 返回值被声明为Stonewt的函数试图返回double时。

初始化对象：
```C++
Stonewt a = 275;
Stonewt a(275);
Stonewt a = Stonewt(275);
//以上三种方式等价,第一种只适用于构造函数只接受一个参数，后两种不限制
```

### 转换函数

要进行相反的转换必须使用转换函数，C++11后explict也可以作用于转换函数。

- 转换函数必须是类方法
- 转换函数不能指定返回类型，但需要有返回值
- 转换函数不能有参数


```C++
//operator typeName()
operator int() const
{
    return 1;
}
```

## 动态内存和类

静态数据成员在类声明中声明，在包含类方法的文件中初始化。初始化时使用作用域解析运算符来指出静态成员所属的类，但如果静态成员是const整形或者枚举，则可以在类声明中初始化。

### 特殊成员函数

C++自动提供一下成员函数（如果本身未定义）：

- 默认构造函数，如果没有定义构造函数
- 默认析构函数
- 复制构造函数：用于将一个对象复制到新创建的对象中，形式为ClassName (const ClassName&)
- 赋值运算符
- 地址运算符

#### 何时调用复制构造函数


每当程序生成了对象副本时，编译器都将使用复制构造函数，例如当函数按值传递对象或返回对象时。**按值传递将创建原始变量的一个副本。** 另外，编译器生成临时对象时，也将调用复制构造函数。

如果类中包含使用new初始化的指针成员，应当定义一个复制构造函数，以复制指向的数据，而不是指针。初始化时总是会调用复制构造函数，使用=运算符时也允许调用复制运算符。

#### 赋值运算符

- 由于目标对象可能引用了以前分配的数据，所以应该释放这些数据
- 函数应当避免将对象赋值给自身；否则，给对象重新赋值前，释放内存操作可能删除对象的内容
- 函数返回一个指向调用对象的引用

```C++
StringBad & StringBad::operator=(const StringBad& st)
{
    if(this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}
```

赋值操作并不创建新的对象。

#### 静态类成员函数

- 不能通过对象调用静态成员函数
- 只能使用静态数据成员
- 可以使用静态成员函数设置类级标志，以控制某些类接口的行为。例如控制显示类内容的方法所使用的格式。

#### 返回对象or引用

- 如果方法或函数要返回局部对象，则应返回对象，而不是引用。在这种情况下将使用复制构造函数生成返回的对象。
- 如果方法或函数要返回一个没有公有复制构造函数的类（如ostream），它必须返回一个指向这个对象的引用
- 有些两者都可返回，优先使用引用提高效率。

#### 定位new运算符

将delete[]用于缓冲区时，不会为使用定位new运算符创建的对象调用析构函数。因此程序员必须负责管理定位new运算符用从中使用的缓冲区内存单元。并且，如果使用定位new运算符为对象分配内存，必须确保其析构函数被调用。delete可与常规new运算符配合使用，但不能与定位new运算符配合使用。**在这种情况下，就需要显式的为对象调用析构函数，这是需要显式调用析构函数的少数几种情形之一。**

#### 嵌套结构和类

在类声明中声明的结构、类或枚举被称为是被嵌套在类中，其作用域为整个类。

#### 成员初始化列表

C++提供一种特殊语法来完成创建对象时的成员初始化：

```C++
classname::classname(type param): m_data(param), m_data1(NULL)
{
    //...
}
```

**只有构造函数可以使用这种初始化列表语法，并且对于const类成员、被声明为引用的类成员也必须使用这种语法。** 这是因为引用与const数据类似，只能在被创建时进行初始化，对于简单数据来说，这两种方法没有什么区别，但是对于本身就是类对象的成员来说，使用成员初始化列表的效率更高。

- 这种格式只能用于构造函数
- 必须用这种格式来初始化非静态const数据成员（C++11之前）
- 必须用这种格式来初始化引用数据成员
- 数据成员的初始化顺序与他们出现在类声明中的顺序相同，与初始化器中的顺序无关
- 从概念上说，这样的初始化工作是在对象创建时完成的，此时还未执行构造函数内的任何代码

**C++11的类内初始化**

```C++
//C++11允许你这样进行初始化：
class Classy{
int mem1 = 10;
const int mem2 = 20;
}
```

# 第11章 继承

## 11.1 简单的继承关系

```C++
class ChildClass: public BaseClass
{
    //...
public:
    ChildClass();
    ~ChildClass();
}

ChildClass::ChildClass():BaseClass()
{

}
```

上述方法为公有派生，派生类对象包含基类对象，使用公有派生，基类的公有成员将成为派生类的公有成员；基类的私有成员也将成为派生类的一部分，但只能通过基类的公有方法和保护方法访问。

**关于派生类构造函数**

- 首先创建基类对象
- 派生类构造函数应通过成员初始化列表将基类信息传递给基类构造函数
- 派生类构造函数应初始化派生类新增的数据成员

释放对象的顺序与创建对象相反，先调用派生类的析构函数，然后自动调用基类构造函数。

### 11.1.1 基类和派生类之间的关系

- 派生类可以使用基类方法，条件时方法不是私有的
- 基类指针可以在不进行显示类型转换的情况下指向派生类对象；
- 基类引用可以在不进行显示类型转换的情况下引用派生类对象
- 基类指针或引用只能调用基类方法
- 不能将基类对象和地址赋值给派生类引用和指针
- 引用兼容性属性允许你将基类对象初始化为派生类对象

每当程序生成了对象副本时，编译器都将使用复制构造函数，例如当函数按值传递对象或返回对象时。**按值传递将创建原始变量的一个副本。** 另外，编译器生成临时对象时，也将调用复制构造函数。

#### 关键字virtual

如果没有使用关键字virtual，程序将根据引用类型或者指针类型选择方法，如果使用了virtual，程序将根据引用或者指针指向的对象类型来选择方法。

声明虚析构函数是为了确保释放派生类对象时，按正确的顺序调用析构函数。**如果析构函数不是虚的，则将只调用对应于指针类型的析构函数。如果析构函数是虚的，则将调用相应对象类型的析构函数，然后自动调用基类的虚构函数。**

**virtual只用于类声明的原型中，不需要用于定义中。**

## 11.4 静态联编(static binding)和动态联编(dynamic binding)

在编译过程中进行binding为静态binding/早期binding。程序运行时选择正确的虚方法称为动态binding/晚期binding。

子类对象指向父类指针或引用被称为向上转型，不需要显示类型转换。父类对象指向子类指针或引用称为向下转型，需要显示类型转换。

> **编译器对非虚方法使用静态绑定，对虚方法使用动态绑定。** 如果要在派生类中重新定义基类方法，则将其设置为虚方法。否则设置为非虚方法。

### 虚函数工作原理

给每个对象增加一个隐藏成员。隐藏成员中保存了一个指向函数地址数组的指针，这个数组称为**虚函数表(virtual function table)**。   
例如，基类对象包含一个指针，该指针指向基类中的虚函数表，派生类对象也包含一个指向独立地址表的指针。如果派生类重写了基类虚函数，该虚函数表将保存新函数的地址，否则，该vtbl将保存原始函数版本的地址。

缺点：

- 每个对象都将增大，增大量为存储地址的空间
- 对于每个类，编译器都创建一个虚函数表
- 对于每个调用，都需要执行一项额外的操作：到表中查地址

**NOTES**

- 构造函数不能是虚函数
- 析构函数应当是虚函数，除非类不用作基类，保证析构函数的调用顺序正确
- 友元不能是虚函数，因为友元不是类成员。**只有类成员才能是虚函数。**
- 重新定义将隐藏方法

```C++
class Dwelling
{
public:
    virtual void showperks(int a) const;
};
class Hovel: public Dwellinig
{
public:
    virtual void showperks() const;
};
//warning: Hovel::showperks(void) hides Dwelling::showperks(int)

Hovel trump;
trump.showperks();      //valid
trump.showperks(1);     //invalid
```

对于以上的例子，重新定义不会生成函数的两个重载版本，而是隐藏了基类版本。**重新定义继承的方法并不是重载。如果重新定义派生类中的函数，将不只是使用相同的函数参数列表覆盖基类声明，无论参数列表是否相同，该操作将隐藏所有的同名基类方法。**

**NOTES**

- 如果重新定义继承的方法，应确保与原来的原型完全相同，但如果返回类型是基类引用或指针，则可以修改为指向派生类的引用或指针。**这种特性被称为返回类型协变（covariance of return type）** ，因为允许返回类型随类类型的变化而变化。这种例外只适用于返回值，不适用于参数。

```C++
class Dwelling
{
public:
    virtual Dwelling& build(int n);
};
class Hovel: public Dwelling
{
public:
    virtual Hovel& build(int n);//same function signature
}
```

- 如果基类声明被重载了，则应在派生类中重新定义所有的基类版本。如果只重新定义一个版本，则另外两个版本将隐藏，派生类对象将无法使用他们。

```C++
class Dwelling
{
public:
    virtual void show(int a) const;
    virtual void show(char a) const;
    virtual void show() const;
};

class Hovel:public Dwelling
{
public:
    virtual void show(int a) const;
    virtual void show(char a) const;
    virtual void show() const;
};
```

## 11.6 抽象基类(abstract base class, ABC)

在虚函数声明的结尾处加上=0即可使其变为纯虚函数，纯虚函数可以在这个基类中没有实现。但是C++甚至允许纯虚函数有定义，只需要在声明后加上=0，不是virtual即可。含有纯虚函数的类为抽象类。

> **当基类和派生类都采用动态内存分配时，派生类的析构函数、复制构造函数、复制运算符都必须使用相应的基类方法来处理基类元素。对于析构函数，这是自动完成的；对于复制构造函数，是通过在初始化成员列表中调用基类的复制构造函数来完成的（如果不这样做将自动调用基类默认构造函数）；对于复制运算符，是通过作用域解析运算符显示调用基类的赋值运算符来完成的。**

### 友元

由于友元函数不是成员函数，所以不能使用作用域解析运算符来指出要使用哪个函数，所以需要通过使用强制类型转换来使匹配原型时能够选择正确的函数。

```C++
std::ostream& operator<<(std::ostream os, const hasDMA& hs)
{
    //type cast to match operator<<(ostream&, const baseDMA&)
    os << (const baseDMA&) hs;
    os << "Style" << hs.style;
    return os;
}
```

## Summary

编译器生成的成员函数：

- 默认构造函数
- 复制构造函数
  - 将新对象初始化为一个同类对象
  - 按值将对象传递给函数
  - 函数按值返回对象
  - 编译器生成临时对象
- 赋值运算符（处理同类对象间的赋值）

什么不能被继承

- 构造函数不能被继承
- 析构函数也不能被继承
- 赋值运算符不能被继承：派生类继承的方法的特征标与基类完全相同，但复制运算符的特征标随类而异，这是因为它包含一个类型为其所属类型的星灿。

**约束**

C++包含让程序员能够限制程序结构的特性：使用explicit防止单参构造函数的隐式转换；使用const限制方法修改数据；使用=delete防止生成默认方法等。这样做的根本原因是：在编译阶段出现的错误优于在运行阶段出现错误。

## 11.7 私有继承

> **使用私有继承，基类的公有成员和保护成员都将成为派生类的私有成员。这意味着基类方法将不会称为派生类公有接口的一部分，但是在派生类的成员函数中可以使用。**

### 私有继承访问基类对象或友元函数

使用强制转换。由于派生类是从基类派生而来，因此可以通过强制类型转换，将派生类对象转换为基类对象。对于友元函数的访问也通过强制转换完成。 **在私有继承中，未进行显示类型转换的派生类引用或指针，无法复制给基类的引用或指针。**

## 11.8 保护继承

> **使用保护继承，类的公有成员和保护成员都称为派生类的保护成员。** 使用私有继承，第三代类将不能使用基类的接口；而保护继承可以。


|特征|公有继承|保护继承|私有继承|
|---|---|---|---|
|公有成员变成|派生类公有成员|派生类保护成员|派生类私有成员|
|保护成员变成|派生类保护成员|派生类保护成员|派生类私有成员|
|私有成员变成|只能通过基类接口访问|只能通过基类接口访问|只能通过基类接口访问|
|能否隐式向上转型|是|是（只能在派生类中)|否|


### 使用using重新定义访问权限

将函数调用包装在另一个函数调用中，即使用using声明来指出派生类可以使用特定的基类成员，即使采用的是私有派生。

```C++
class Student:private std::string, private std::valarray<double>
{
public:
    using std::valarray<double>::min;
    using std::valarray<double>::max;
    //上述声明使std::valarray<double>::min()和max()可用，就像是Student的公有方法一样
}
```

## 11.9 多重继承

### 11.9.1 几个对象

#### 虚基类

虚基类使得从多个类（基类相同）派生出的对象只继承一个基类对象。

```C++
class Singer:virtual public Worker{};
class Waiter:public virtual Worker{};
class SingerWaiter:public Singer, public Waiter{};
```

对于以上代码，SingerWaiter对象将只包含Worker对象的一个副本。从本质上说，继承的Singer和Waiter共享一个Worker对象，而不是引入个字的Worker对象副本。**现在的SingerWaiter只包含一个Worker子对象，可以使用多态。**

- C++在基类是虚的时，禁止信息通过中间类自动传递给基类

```C++
SingerWaiter(const Worker& wk, int p = 0, int v = 0): Worker(wk), Singer(wk, p), Waiter(wk, p){};
```

因此编译器会调用虚基类的默认构造函数，如果不想使用默认构造函数，则需要显示调用虚基类的构造函数。这种做法对虚基类合法，但是对于非虚基类则是非法的。

### 11.9.2 哪个方法

> 多重继承可能导致函数调用的二义性，例如子类可能从两个父类中都继承了一个show方法。在这种情况下，可以使用作用域解析运算符来指明具体调用的方法；更好的方法则是在子类中重新定义show方法，并指出要使用哪个show。

```C++
void SingerWaiter::show()
{
    Singer::show();
}
```

### 11.9.3 总结

#### 混合使用虚基类和非虚基类

> 如果基类是虚基类，派生类将包含基类的一个子对象；如果基类不是虚基类，派生类将包含多个字对象。当类通过多条虚途径和非虚途径继承某个特定的基类时，该类将包含一个表示所有的虚途径的基类子对象和分别表示各条非虚途径的多个基类字对象。

## 11.10 模版类

模版类一般以下面代码开头：

```C++
template <class Type>
template <typename Type>

//一个模版类函数的例子：
template <typename T>
bool Stack<T>::push(const T& item){};
```

> 不能将模版成员函数放在独立文件中，由于模版不是函数，他们不能单独编译。模版必须与特定的模版实例化请求一起使用。为此，最简单的方法是**将所有信息放在一个头文件中，并在要使用这些模版的文件中包含该头文件。**

### 模版的具体化

类模版与函数模版相似，可以有隐式实例化、显示实例化和显示具体化。

- 隐式实例化
编译器在需要对象之前，不会生成类的隐式实例化。

```C++
ArrayTp<double, 30> *pt;    //a pointer, no object needed yet
pt = new ArrayTP<double, 30>;   //now an object is needed
```

以上第二条语句会导致编译器生成类定义，并根据该定义创建一个对象。
- 显示实例化

通过使用关键字template并指出所需类型来声明类，编译器将生成类声明的显示实例化(explicit instantiation)。声明必须位于模版定义所在的命名空间中。

```C++
template class ArrayTp<string, 100>;
```

- 显示具体化

显示具体化(explicit specializaion)是特定类型（用于替换模版中的范型）的定义。当具体化模版和通用模版与实例化请求匹配时，编译器将使用具体化版本。

```C++
template<> class Classname<specialized-type-name>{...};
class Classname<spceialized-type-name>{...};
```

- 部分具体化

C++允许部分具体化(partial specialization)，即部分限制模版的通用性。

```C++
template <class T1, class T2> class Pair{...};
//specialization with T2 set to int
template <class T1> class Pair<T1, int>{...};
```

> 如果有多个模版可供选择，编译器将使用具体化程度高的模版。

```C++
template <typename T>

class beta
{
private:
    template <typename V>
    class hold
    {
    private:
        V val;

    public:
        hold(V v = 0): val(v){}
        void show() const {cout << val << endl;}
        V Value() const {return val;}
    };
    hold<T> q;  //template object
    hold<int> n;    //template object
public:
    beta(T t, int i):q(t), n(i){}
    template<typename U>    //template method
    U blab(U u, T t) {return (n.Value() + q.Value()) * u / t;}
    void Show() const {q.show();n.show();}
};
```

**将模版用作参数**

```C++
template<template <typename T>class Thing>
```

上面的template \<typename T>class是类型，Thing是参数。

### 模版类和友元

模版类的友元分为：

- 非模版友元,所有模版实例化后的友元
- 约束(bound)模版友元，即友元的类型取决于类被实例化时的类型
- 非约束(unbound)模版友元，即友元的所有具体化都是类的每一个具体化的友元。

```C++
template <typename T>

class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFirend(const T& i):item(i){}
    ~HasFirend(){ct--;}
    friend void counts();
    friend void reports(HasFriend<T>& );//template parameter
};

template<typename T>
int HasFriend<T>::ct = 0;
//non-template friend to all HasFriend<T> classes
void counts()
{
    cout << HasFriend<int>::ct << endl;
}
//...
```

bound template friend function:

```C++
//1. prototypes
template<typename T> void counts();
template<typename T> void report(T&);

template<typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;

public:
    HasFriendT(const TT& i):item(i){ct++;}
    ~HasFriendT(){--ct;}
    friend void counts<TT>();
    friend void reports<>(HasFriend<TT> &);
};

template<typename T>
void counts()
{
    cout << "template size:" << sizeof(HasFriendT<T>) << ";";
    cout << "template counts():" << HasFriendT<T>::ct << endl;
}

template<typename T>
void report(T& hf)
{
    cout << hf.item << endl;
}
```

通过在类内部声明模版，可以创建非约束友元函数，即每个函数具体化都是每个类具体化的友元。

```C++
template <typename T>
class ManyFriend
{
private:
    T item;
public:
    template<typename C, typename D> friend void show2(C & , D &);
}
```

### 模版别名

```C++
template<typename T>
    using arrt = std::array<T, 12>;//template to create multiple aliases
    arrt<double> a; //a is type std::array<double, 12>
```

同时C++11允许将using=用于非模版，用于非模版时，这种语法与常规typedef等价。

# 第15章 友元/异常和其他

## 15.1 友元
```C++
class TV
{
public:
    friend class Remote;    //友元类
    friend void Remote::setchannel(Tv& t, int c);   //友元成员函数
    //...
};
```

## 15.2 异常

```C++
double func(int a, int b)
{
    if(b == 0)
        throw "bad func() arguments:b = 0 is now allowed";
    return a/b;
}

int main()
{
    try
    {
        int a = 1, b =2;
    }
    catch (const char* s)
    {
        cout << s << endl;
    }
    catch (...)     //catch whatever is left
    {

    }
}
```

### 异常规范

```C++
double harm(double a) throw(bad_thing);
double marm() noexcept;     //C++11，表示这个函数不会引发异常
```

> 程序进行栈解退以回到能够捕获异常的地方时，将释放栈中的自动存储型变量，如果变量是类对象，自动为该对象调用析构函数。
> 引发异常时，编译器总是创建一个临时拷贝，即使异常规范和catch块中指定的是引用。这是因为在引发异常的函数执行后，会自动为其中的对象变量调用析构函数。但是使用引用的一个好处是：**基类引用可以指向派生类对象。**

### exception类

C++库定义了很多基于exception的异常类型

- stdexception
  - logic_error
    - domain_error
    - invalid_argument
    - length_error
    - out_of_bounds
  - runtime_error
    - range_error
    - overflow_error
    - underflow_error

对于使用new导致的内存分配问题，C++的最新处理方式是让new引发bad_alloc异常。为了处理new的变化，有些编译器提供了一个开关，可以在失败时返回空指针的new：

```C++
int* pi = new (std::nothrow) int;
```

对于意外异常和未捕获异常，程序的默认处理是终止。未捕获异常不会导致程序立刻终止，而是首先调用terminate()，默认情况下，terminate()调用abort()函数，可以通过修改terminate()调用的函数来改变行为。
如果发生意外异常，程序将调用unexpected()函数，与上面情况类似。

## 15.4 RTTI(运行时类型识别)

C++有三个支持RTTI的元素：

- 如果可能的话，dynamic_cast运算符将使用一个指向基类的指针来生成一个指向派生类的指针，否则返回0
- typeid运算符返回一个指出对象的类型的值
- type_info结构存储了有关特定类型的信息

**只能将RTTI用于包含虚函数的类层次结构，原因在于只有对于这种类层次结构，才应该将派生对象的地址赋给基类指针。**

## 15.5 类型转换运算符

- dynamic_cast
- const_cast
- static_cast
- reinterpret_cast



