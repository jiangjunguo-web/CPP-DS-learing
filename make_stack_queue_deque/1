#include <iostream>
#include <deque>
#include <list>
#include <vector>
using namespace std;

template <class T, class Container = deque<T>>
class Stack {
public:
	void push(const T& val) {
		_c.push_back(val);
	}
	
	void pop() {
		_c.pop_back();
	}
	
	const T& top() {
		return _c.back();
	}

	size_t size() const {
		return _c.size();
	}
	
	bool empty() const {
		return _c.empty();
	}

private:
	Container _c;
};

void tetsStack() {
	Stack<int, vector<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

template <class T, class Container = deque<T>>
class Queue {
public:
	void  push(const T& val) {
		_c.push_back(val);
	}
	
	void pop() {
		_c.pop_front();
	}

	T& front() {
		return _c.front();
	}
		
	T& back() {
		return _c.back();
	}

	size_t size() const {
		return _c.size();
	}

	bool empty() const {
		return _c.empty();
	}
private:
	Container _c;
};

void testQueue() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while(!q.empty()) {
		cout << q.front() << " " << q.back() << " ";
		q.pop();
	}
	cout << endl;
}

template <class T>
struct Greater {
	bool operator()(const T& val1, const T& val2) {
		return val1 > val2;
	}

};

template <class T>
struct Less {
	bool operator()(const T& val1, const T& val2){
		return val1 < val2;	
	}
};

template <class T, class Container = vector<T>, class Compare = Less<T>> 
class Priority_Queue {
public: 
	void push(const T& val) {
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}
	
	void pop() {
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	T& top() {
		return _c.front();
	}


	size_t size() const {
		return _c.size();
	}

	bool empty() const {
		return _c.empty();	
	}

private:
	void shiftDown(int parent) {
		int child = 2 *  parent + 1;
		while(child < _c.size()) {
			if(child + 1 < _c.size() && _cmp(_c[child], _c[child + 1])) 
				child++;
			if(_cmp(_c[parent], _c[child])) {
				swap(_c[parent], _c[child]);
				parent = child;
				child = 2 *  parent + 1;
			}
			else 
				break;

		}

	}
	
	void shiftUp(int child) {
		int parent = (child - 1) / 2;
		while(child > 0) {
			if(_cmp(_c[parent], _c[child])) {
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else 
				break;
		}
	}

private:
	Container _c;
	Compare _cmp;
};

void testDeque() {
	Priority_Queue<int, vector<int>, Greater<int>> pq;
	pq.push(6);
	pq.push(0);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(6);

	while(!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

}

int main() {
	testDeque();
	return 0;
}
