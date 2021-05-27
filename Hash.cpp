//闭散列

#include<vector>
#include<iostream>
using namespace std;
enum STATE {
	EXIST,
	DELETE,
	EMPTY
};


//哈希表  ：线性探测
template<class K,class V>
struct HashNode {
	pair<K, V> _kv;
	STATE _state = EMPTY;
};

//顺序表实现


template<class K,class V>
class HashTable {
public:
	typedef HashNode<K, V> Node;

	HashTable(size_t n = 10)
	:_hTable(n)
		,_size(0)
	{
	}
	bool insert(const pair<K, V>& kv) {
		checkCapacity();
		//1.计算哈希位置
		int idx = kv.first % _hTable.size();
		//2.判断key值是否存在
		while (_hTable[idx]._state != EMPTY) {
			//如果当前位置数据有效，且key相同，插入失败
			if (_hTable[idx]._state == EXIST
				&& kv.first == _hTable[idx]._kv.first) {
				return false;
			}
			//继续搜索
			++idx;
			//下标为数据大小
			if (idx == _hTable.size())
				idx = 0;
		}
		_hTable[idx]._kv = kv;
		_hTable[idx]._state = EXIST;
		++_size;
		return true;
	}
	void checkCapacity() {
		//负载因子：< 0.6--0.8
		//          :0.7
		//if (_size / _hTable.size() >= 0.7); _size 是整数
		//if (_size*1.0 / _hTable.size() >= 0.7);  浮点数有精度损失
		if (_hTable.size() == 0 || _size * 10 / _hTable.size() >= 7) {
			//开新表
			int newC = _hTable.size() == 0 ? 10 : 2 * _hTable.size();
			HashTable<K, V> newHt(newC);
			
			//插入状态为EXIST
			//newHt._hTable = _hTable; 这样里面元素算出来的idx值会变化，被除数变化；kv.first%_hTable.size();
			for (int i = 0; i < _hTable.size(); ++i) {
				//插入状态为exist的数据
				if (_hTable[i]._state == EXIST) {
					newHt.insert(_hTable[i]._kv);
				}
			}
			Swap(newHt);
		}
	}
	
	//交换函数，
	void Swap(HashTable<K, V>& Ht) {
		swap(_hTable, Ht._hTable);
		swap(_size, Ht._size);
	}
	Node* find(const K& key) {
		int idx = key % _hTable.size();
		while (_hTable[idx]._state != EMPTY) {
			if (_hTable[idx]._state == EXIST
				&& key == _hTable[idx]._kv.first) {
				return &_hTable[idx];
			}
			++idx;
			if (idx == _hTable.size()) {
				idx = 0;
			}
		}
		return nullptr;
	}
	bool erase(const K& key) {
		Node* node = find(key);
		if (node) {
			//假删除
			--_size;
			node->_state = DELETE;
			return true;
		}
		return false;
	}
private:
	vector<Node> _hTable;
	size_t _size;//有效元素的个数

};

void test() {
	HashTable<int, int> ht;
	ht.insert(make_pair(0, 1));
	ht.insert(make_pair(1, 14));
	ht.insert(make_pair(2, 16));
	ht.insert(make_pair(3, 14));
	ht.insert(make_pair(4, 1));
	ht.insert(make_pair(5, 14));
	ht.insert(make_pair(6, 16));
	ht.insert(make_pair(7, 14));
	ht.insert(make_pair(8, 1));
	ht.insert(make_pair(9, 14));
	ht.insert(make_pair(16, 16));
	ht.insert(make_pair(14, 14));

	cout << ht.find(4) << endl;
	cout << ht.find(40) << endl;

	
}
int main() {
	test();
	return 0;
}


