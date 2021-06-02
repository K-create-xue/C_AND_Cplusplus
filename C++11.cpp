#include<iostream>
#include<map>
#include<list>
using namespace std;

int fun(int a) {
	return a;
}

void test() {

	//左值：可以出现在‘=’ 两边
	//右值：可以出现在‘=’ 右边

	//左值：可以取地址
	//右值：不能取地址
	
	//上面两种分类不是完全正确

	int a = 10;
	int b = a;    //a 为左值
	//10 = a;  错误赋值  所以10位右值，

	int* pa = &a;  //可以取地址
	//int* pb = &10;  不可以取地址

	//c++ 中的区分
	//右值：  常量、临时变量/匿名变量、将亡值；
	//左值：其他都为左值；

	b = fun(a);//将亡值：fun函数中的变量a将被销毁
	//临时变量/匿名变量:fun返回值的a临时拷贝，变量a已经被销毁；
	//fun(a)=a;  错误：不能放在左边  
	//int pa2=&fun(a);  错误：右值不能取地址 


	//左值引用& ：可以引用左值
	int a = 10;
	int& ra = a;
	const int& ri = 10;
	const int& ri2 = fun(a);

	//右值引用&&：只能引用右值              
} 


//struct A {
//	A(int a=10)
//		:_a(a) {
//	}
//	int _a;
//};
//template<class T>
//class Vector {
//public:
//	Vector(size_t n)
//		:_arr(new T[n])
//		, _size(0)
//		, _capacity(n) {
//
//	}
//	Vector(const initializer_list<T>& lst)
//		:_arr(new T(lst.size()))
//		,_size(lst.size())
//		,_capacity(_size)
//	{
//		int idx = 0;
//		for (const auto e : lst) {
//			_arr[idx] = e;
//			idx++;
//		}
//	}
//	
//private:
//	T* _arr;
//	size_t _size;
//	size_t _capacity;
//};
//
//void test() {
//	
//	Vector<int> v = { 5};
//	Vector<int> v2 = { 1,2,3 };
//	//Vector v = { 1 };
//
//
//}
int main() {
	test();
	return 0;
}