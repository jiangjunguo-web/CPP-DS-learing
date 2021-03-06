#include <iostream>
#include <string>
using namespace std;

template <class T>
class Vector {
public: 
	//构造函数
	Vector()
		: _start     (nullptr)
		, _finish    (nullptr)
		, _eos       (nullptr)
	{}

	//构造函数
	Vector(int n, const T& value = T()) 
		:_start      (nullptr)
		,_finish     (nullptr)
		,_eos        (nullptr)

	{
		reserve(n);
		while(n--) 
			pushBack(value)	;
	}
	
	size_t size() const {
		return _finish - _start;
	}
	
	size_t capacity() const {
		return _eos - _start;
	}

	void pushBack(const T& val) {
		if(_eos == _finish) {
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}
		*_finish = val;
		_finish++;
	}

	void reserve(size_t n) {
		if(n > capacity()) {
			size_t oldSize = size();
			T* tmp = new T[n];
			for(int i = 0; i < size(); ++i) 
				tmp[i] = _start[i];
			delete[] _start;
			_start = tmp;
			_finish = _start + oldSize;
			_eos = _start + n;
		}
	}

	//operator : 可读可写
	T& operator[](size_t pos) {
		if(pos < size())
			return _start[pos];
	}
	
	//operator : 只读
	const T& operator[](size_t pos) const {
		if(pos < size())
			return _start[pos];
	}

	//迭代器
	typedef T* iterator;
	typedef const T* const_iterator;
	
	iterator begin() {
		return _start;
	}
	
	iterator end() {
		return _finish;
	}

	const_iterator cbegin() const { 
		return _start;
	}
	
	const_iterator cend() const {
		return _finish;
	}

	void resize(size_t n, const T& val = T()) {
		if(n > capacity())
			reserve(n);
		if(n > size()) 
			while (_finish != _start + n)
				*_finish++ = val;
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val) {
		if(pos >= _start && pos <= _finish) {
			if(_finish == _eos) {
				int len = pos - _start;
				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newC);
				pos = _start + len;
			}
		iterator end = _finish;
		while(end > pos) {
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
		}
	}

	iterator erase(iterator pos) {
		if(pos >= _start && pos < _finish) {
			iterator begin = pos + 1;
			while(begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
		}
		return pos;
	}

	~Vector() {
		if(_start) {
			delete[] _start;
			_start = _finish = _eos = nullptr; 
		}

	}

	//拷贝构造
	Vector(const Vector<T>& v) 
	: _start(new T[v.capacity()])
	{
		for(int i = 0; i < v.size(); ++i) 
			_start[i] = v[i];
		_finish = _start + v.size();
		_eos = _start + v.capacity();
	}

	Vector<int>& operator=(Vector<T> v) {
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v) {
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_eos, v._eos);
	}

private: 
	T* _start;
	T* _finish;
	T* _eos;
};

template <class T1>

void printVector(const Vector<T1>& v) {
	Vector<int>::const_iterator it = v.cbegin();
	while(it != v.cend()) {
		cout << *it << " " ;
		++it;
	}
	cout << endl;
}

void test() {
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	size_t size = v.size();
	size_t capacity = v.capacity();
	cout << size << endl;
	cout << capacity << endl;
	Vector<int> v1 = v;
	Vector<int> v2(v1);
	printVector(v1);
	printVector(v2);
	v2.insert(v2.begin()+1, 4);
	printVector(v2);
	v2.erase(v2.begin());
	printVector(v2);

}

int main() {
	test();
	return 0;
} 

