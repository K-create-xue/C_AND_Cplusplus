int main(){

	int a = (3, 2,4,5,6);
	return 0;
}



//#include<stdio.h>
//#include<stdlib.h>
//#include<algorithm>
//#include<string.h>
//#include<iostream>
//using namespace std;
//
//int my_comp(const void*a, const void*b)//用来做比较的函数。
//{
//	return *(int*)a -*(int*)b;
//}
//
//void my_qsort(void* base, size_t num, size_t width, 
//	int(*cmp)(const void* ele1, const void* ele2)){
//	for (int i = 0; i < num - 1; ++i){
//		for (int j = 0; j < num - 1; ++j){
//			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
//				swap((char*)base + j*width, (char*)base + (j + 1)*width);
//		}
//	}
//}
//
//int main()
//{
//	int a[10] = { 2, 4, 1, 5, 5, 3, 7, 4, 1, 5 };//乱序的数组。
//	int n=sizeof(a)/sizeof(a[0]);
//	my_qsort(a, n, sizeof(int), my_comp);//调用qsort排序
//	
//	return 0;
//}
//
//
//
///*int cmp(int a, int b){
//	return a >b;
//}
//
//int main(){
//	int a[10] = { 2, 4, 1, 5, 5, 3, 7, 4, 1, 5 };
//	std::sort(a,a+10,cmp);
//	return 0;
//}
//*/
//
//
//
////#include<stdio.h>
////#include<stdlib.h>
////int fun(int a, int b){
////	return a + b;
////}
////typedef struct Student{
////	int id;
////	char* name;
////}Student;
////int comp_stu(const void* a, const void* b){
////	Student *pa = (Student*)a;
////	Student* pb = (Student*)b;
////	return (pb->id - pa->id);
////}
////int main(){
////	Student stu[] = { { 20, "大s" }, 
////	{ 5, "大三" },
////	{ 8, "非d" } };
////	int a=comp_stu(&stu[0], &stu[1]);
////	qsort(stu, 3, sizeof(Student), comp_stu);
////	/*
////	int (*pfun)(int, int)=&fun;
////	int a = 0;
////	int* p = &a;
////	(*(void(*)())0)();
////	*/
////	return 0;
////}
////
//////int (*fun_table[10])(int a, int b);
