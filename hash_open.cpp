//��ɢ��

#include<iostream>
#include<vector>
using namespace std;

//������ڵ�
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
		//0.�������
		checkCapacity();
		//1.����hashλ��
		KeyOfValue kov;
		int idx = kov(val) % _ht.size();
		//2.����
		Node* cur = _ht[idx];
		while (cur) {
			if ((kov(cur->val)) == kov(val)) {
			//key�ظ�
				
				return false;
			}
			cur = cur->_next;
		}
	}
	void checkCapacity() {
		if (_size == _ht.size()) {
			int newC = _size == 0 ? 10 : 2 * _size;

			//�����µ�ָ���������
			vector<Node*> newHt(newC);
			KeyOfValue kov;
			//�����ɱ�
			for (int i = 0; i < _ht.size(); ++i) {
				Node* cur = _ht[i];
				//����������
				while (cur) {
					Node* next = cur->_next;;
					//������λ��
					int idx = kov(cur->_val) % newHt.size();
					//ͷ��
					cur->_next = newHt[idx];
					newHt[idx] = cur;
					cur = next;
				}
				//�ɱ�ָ���ÿ�
				_ht[i] = nullptr;
			}
			//�¾ɱ���
			swap(_ht, newHt);
		}
	}
private:
	//ָ������
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
	HashTable<K��K, SetKeyOfValue> _ht;
};
void test() {

}
int mian() {
	test();
	return 0;
}