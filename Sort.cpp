/*

	八大排序复习

	1.冒泡：0
	2.
*/
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

namespace My {
	class sort {
	public:
		sort() :AC(0) { 
			cout << "start sort" << endl;
		}
		~sort() { 
			if (AC == 8)
				cout << "All Pass " << endl;
			else
				cout << "Having Error" << endl;
		}

		void pass() {
			++AC;
			cout << AC << endl;
		}
		//1.冒泡
		void bubbleSort(vector<int> &v) {
			for (int i = 0; i < v.size(); ++i) {
				int flag = 1;
				for (int j = 1; j < v.size(); ++j) {
					if (v[j] < v[j-1]) {
						std::swap(v[j], v[j-1]);
						flag = 0;
					}
				}
				if (flag == 1)
					break;
			}
		}

		//2.插入排序
		void insertSort(vector<int>& v) {
			for (int i = 1; i < v.size(); ++i) {
				int flag = 1;
				int j = i;
				for (int j = i; j > 0; --j) {
					if (v[j] < v[j - 1]) {
						swap(v[j], v[j - 1]);
						flag = 0;
					}
					if (flag == 1)
						break;
				}
			}
		}

		//3.希尔排序
		void shellSort(vector<int> &v) {
			int gap = v.size();
			while (gap > 1) {
				gap = gap / 3 + 1;
				for (int i = gap; i < v.size();++i) {
					int flag = 1;
					for (int j = i; j-gap >= 0; j -= gap) {
						if (v[j] < v[j-gap]) {
							swap(v[j], v[j - gap]);
							flag = 0;
						}
						if (flag == 1)
							break;
					}
				}
			}
		}
		//4.堆排
		void heapSort(vector<int> v) {
      //向下调整
void shiftDown(int* arr, int n, int cur){
	int child = cur * 2 + 1;
	while (child < n){
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		if (arr[cur]<arr[child]){
			swap(arr[child], arr[cur]);
			cur = child;
			child = cur * 2 + 1;
		}
		else
			break;
	}
}
//堆排序
void heapSort(int* arr, int n){
	for (int i = (n - 2) / 2; i >= 0; --i){
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0){
		swap(arr[end], arr[0]);
		shiftDown(arr, end, 0);
		--end;
	}
}


		}
		//5.快排
		int partion(vector<int>& v, int begin, int end) {
			int flag = v[begin];
			int l = begin, r = end;
			while (l < r) {
				//从后向前先找（必须）升序降序都是
				while (l<r && v[r] >= flag)
					--r;
				while (l < r && v[l] <= flag)
					++l;
				std::swap(v[l], v[r]);
			}
			swap(v[begin], v[l]);
			return l;
		}
		void quickSort(vector<int> &v,int i,int j) {
			if (i >= j)
				return;
			int divide = partion(v, i, j);
			quickSort(v, i, divide-1);
			quickSort(v, divide + 1, j);
		}

	private:
		int AC;
	};
}

time_t begin = clock();
time_t end = clock();

void print(vector<int> v) {
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
}
void test() {
	My::sort A;
	vector<int> start = { 2,1,5,5,9,5,3,0,4 };
	vector<int> v;
	
	//冒泡
	cout << "冒泡" << endl;
	v = start;
	print(v);
	A.bubbleSort(v);
	print(v);
	//插入
	cout << "插入" << endl;
	v = start;
	print(v);
	A.insertSort(v);
	print(v);
	//3.希尔排序
	cout << "希尔排序" << endl;
	v = start;
	print(v);
	A.shellSort(v);
	print(v);
	//4.堆排
	cout << "堆排" << endl;
	v = start;
	print(v);
	A.heapSort(v);
	print(v);
	//5.快排
	cout << "快排" << endl;
	v = start;
	print(v);
	A.quickSort(v,0,v.size()-1);
	print(v);	
}
int main() {
	test();
	return 0;
}
