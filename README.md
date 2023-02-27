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