//开散列

#include<iostream>
#include<vector>
using namespace std;

//单链表节点
template<class V>
struct Node {
	V _val;
	Node<V>* _next;

	Node(const V& val)
		:_val(val)
		, _next(nullptr) {
	}
};

template<class K,class V,class KeyOfValue>
class HTable {
public:
	typedef HashNode<V> Node;
	HTable(int n = 10)
	:_ht(n)
		,_size(0)
		{
	}
	bool insert(const V& val) {
		//0.检查容量
		checkCapacity();
		//1.计算hash位置
		KeyOfValue kov;
		int idx = kov(val) % _ht.size();
		//2.查找
		Node* cur = _ht[idx];
		while (cur) {
			if ((kov(cur->val)) == kov(val)) {
			//key重复
				
				return false;
			}
			cur = cur->_next;
		}
	}
	void checkCapacity() {
		if (_size == _ht.size()) {
			int newC = _size == 0 ? 10 : 2 * _size;

			//创建新的指针数组对象
			vector<Node*> newHt(newC);
			KeyOfValue kov;
			//遍历旧表
			for (int i = 0; i < _ht.size(); ++i) {
				Node* cur = _ht[i];
				//遍历单链表
				while (cur) {
					Node* next = cur->_next;;
					//计算新位置
					int idx = kov(cur->_val) % newHt.size();
					//头插
					cur->_next = newHt[idx];
					newHt[idx] = cur;
					cur = next;
				}
				//旧表指针置空
				_ht[i] = nullptr;
			}
			//新旧表交换
			swap(_ht, newHt);
		}
	}
private:
	//指针数组
	vector<Node*> _ht;
	int _size;
};
template<class K>
class Set {
public:
	bool insert(const K& key) {
		_ht.insert(key);
	}
private:
	HashTable<K，K, SetKeyOfValue> _ht;
};
void test() {

}
int mian() {
	test();
	return 0;
}