#include<iostream>
#include<map>
#include<list>
using namespace std;

int fun(int a) {
	return a;
}

void test() {

	//��ֵ�����Գ����ڡ�=�� ����
	//��ֵ�����Գ����ڡ�=�� �ұ�

	//��ֵ������ȡ��ַ
	//��ֵ������ȡ��ַ
	
	//�������ַ��಻����ȫ��ȷ

	int a = 10;
	int b = a;    //a Ϊ��ֵ
	//10 = a;  ����ֵ  ����10λ��ֵ��

	int* pa = &a;  //����ȡ��ַ
	//int* pb = &10;  ������ȡ��ַ

	//c++ �е�����
	//��ֵ��  ��������ʱ����/��������������ֵ��
	//��ֵ��������Ϊ��ֵ��

	b = fun(a);//����ֵ��fun�����еı���a��������
	//��ʱ����/��������:fun����ֵ��a��ʱ����������a�Ѿ������٣�
	//fun(a)=a;  ���󣺲��ܷ������  
	//int pa2=&fun(a);  ������ֵ����ȡ��ַ 


	//��ֵ����& ������������ֵ
	int a = 10;
	int& ra = a;
	const int& ri = 10;
	const int& ri2 = fun(a);

	//��ֵ����&&��ֻ��������ֵ              
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