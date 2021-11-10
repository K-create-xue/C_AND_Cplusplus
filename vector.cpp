#include<iostream>
#include<assert.h>
using namespace std;

namespace My {
	template<class _Ty> 
	class vector {
	public:
		typedef _Ty* iterator;

		vector():_first(nullptr),_last(nullptr),_end(nullptr)
		{}

		size_t size()const {
			return _last - _first;
		}
		iterator begin() {
			return _first;
		}
		iterator end() {
			return _last;
		}
		void push_back(const _Ty &val) {
			insert(end(), val);
		}
		size_t capacity()const {
			return _end - _first;
		}
		void reserve(size_t n) {
			if (n > capacity()) {
				//
				size_t old_size = size();
				_Ty* new_first = new _Ty[n];
				memcpy(new_first, _first, old_size * sizeof(_Ty));
				delete[] _first;
				_first = new_first;
				_last = _first + old_size;
				_end = _first + n;
			}
		}
		iterator insert(iterator pos, const _Ty& val) {
			assert(pos <= _last);
			if (_last == _end) {
				size_t p_size = pos - _first;
				size_t new_size = size() == 0 ? 1 : 2 * size() * 2;
				reserve(new_size);

				pos = _first + p_size;
			}
			iterator end = _last;
			while (end > pos) {
				*end = *(end - 1);
				--end;
			}
			*end = val;
			++_last;
			return end;

		}
	private:
		iterator _first;
		iterator _last;
		iterator _end;
	};
};

int main() {
	My::vector<int> v;

	v.insert(v.begin(), 1);
	v.insert(v.begin(), 2);
	v.insert(v.begin(), 3);
	v.insert(v.end(), 7);
	v.insert(v.begin(), 1);


	for (auto& e : v) {
		cout << e << " ";
	}
	return 0;
}
