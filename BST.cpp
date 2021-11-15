#include<iostream>
#include<vector>
using namespace std;

template<class _Ty>
class BSTree;

template<class _Ty>
class BSTNode {
public:
	friend class BSTree<_Ty>;
	BSTNode()
		:_data(_Ty()),_liftChild(nullptr),_rightChild(nullptr)
	{}
	BSTNode(_Ty& val, BSTNode* liftChild = nullptr, BSTNode* rightChild = nullptr) {
		_data = val;
		_liftChild = liftChild;
		_rightChild = rightChild;
	}
	~BSTNode() {
	}
private:
	_Ty _data;
	BSTNode* _liftChild;
	BSTNode* _rightChild;
};

template<class _Ty>
class BSTree {
public:
	BSTree()
		:_root(nullptr)
	{}
	~BSTree()
	{}
	BSTree(vector<_Ty> &nums):_root(nullptr) {
		for (const auto &e : nums) {
			Insert(e);
		}
	}

	bool Insert(const _Ty &val) {
		return Insert(_root, val);
	}
	BSTNode<_Ty>* Min()const{
		return Min(_root);
	}
protected:
	BSTNode<_Ty>* Min(BSTNode<_Ty> *root)const {
		while (root && root->_liftChild != nullptr)
			root = root->_leftChild;
		return root;
	}
	bool Insert(BSTNode<_Ty> *&root, int val) {
		if (root == nullptr) {
			root = new BSTNode<_Ty>(val);
			return true;
		}
		if (val < root->_data) {
			return Insert(root->_liftChild, val);
		}
		else if (val > root->_data) {
			return Insert(root->_rightChild, val);
		}
		return false;
	}
private:
	BSTNode<_Ty> *_root;
};
void test() {
	//BSTree<int> bst;
	vector<int> v{ 5,3,4,1,7,8,2,6,0,9 };
	/*for (auto& e : v) 
		bst.Insert(e);*/
	BSTree<int> bst(v);
	

	BSTNode<int>* p = bst.Min();


}

int main() {
	test();
	return 0;
}
