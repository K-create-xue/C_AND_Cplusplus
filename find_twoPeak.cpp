#include<iostream>
using namespace std;
#define NUMBER 50
bool decrease(int data1,int data2,int data3,int data4){
	return data1 > data2 
		&& data2 > data3 
		&& data3 > data4;
}
bool increase(int data1, int data2, int data3, int data4){
	return data1 < data2
		&& data2 < data3
		&& data3 < data4;
}
int main()
{
	int arry[NUMBER];
	int data1,data2;
	string
	for (int i = 4; i < NUMBER-4; ++i) {
		if(increase(arry[i-4],arry[i-3],arry[i-2],arry[i-1])
			&&decrease(arry[i + 1], arry[i + 2], arry[i + 3], arry[i + 4])) {
			cout << arry[i]<< endl;
		}
	}
	return 0;;
}