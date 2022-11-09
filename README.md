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