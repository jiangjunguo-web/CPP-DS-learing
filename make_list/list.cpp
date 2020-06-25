#include <iostream>
using namespace std;

//创建一个节点
template <class T>
struct listNode {
	T _value;
	listNode<T>* _next;
	listNode<T>* _prev;

	listNode(const T& val = T()) 
		:_value(val)
		,_next(nullptr)
		,_prev(nullptr)
	{}
};

//模拟实现list类的迭代器
template <class T, class Ref, class Ptr> 
struct listIterator {
	typedef listNode<T> Node;
	typedef listIterator<T, Ref, Ptr> Self;

	listIterator(Node* node)
		:_node(node)
	{}
	
	//重载解引用
	Ref operator*() {
		return _node->_value;
	}
	
	Ptr operator->() {
		return &_node->_value;
	}

	Self& operator++() {
		_node = _node->_next;
		return *this;
	}
	
	Self& operator--() {
		_node = _node->_prev;
		return *this;
	}

	bool operator!=(const Self& it) {
		return _node != it._node;
	}
	Node* _node;
};

template <class T>
class List {
public:
	typedef listNode<T> Node;
	typedef listIterator<T, T&, T*> iterator;
	typedef listIterator<T, const T&, const T*> const_iterator;

	iterator begin() {
		return iterator(_header->_next);
	}

	iterator end() {
		return iterator(_header);
	}
	
	const_iterator begin() const{
		return const_iterator(_header->_next);
	}
	
	const_iterator end() const{
		return const_iterator(_header);
	}

	List() 
		:_header(new Node)
	{
		_header->_next = _header->_prev = _header;
	}

	void pushBack(const T& val) {
		Node* cur = new Node(val);
		Node* prev = _header->_prev;
		prev->_next = cur;	
		cur->_prev = prev;
		cur->_next = _header;
		_header->_prev = cur;
	}

	void insert(iterator pos, const T& val) {
		Node* cur = new Node(val);
		Node* node = pos._node;
		Node* prev = node->_prev;
		
		prev->_next = cur;
		cur->_prev = prev;
		
		cur->_next = node;
		node->_prev = cur;
	}

	iterator erase(iterator pos) {
		if(pos != end()) {
			Node* node = pos._node;
			Node* prev = node->_prev;
			Node* next = node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete node;
			return iterator(next);
		}
		return pos;
	}

	void pushFront(const T& val) {
		insert(begin(), val);
	}

	void popBack() {
		erase(--end());
	}

	void popFront() {
		erase(begin());
	}


	size_t size() const{
		size_t count = 0;
		for(const auto& e : *this)
			++count;
		return count;
	}

	~List() {
		if(_header) {
			clear();
			delete _header;
			_header = nullptr;
		}
	}
	
	void clear() {
		Node* cur = _header->_next;
		while(cur != _header) {
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_header->_next = _header->_prev = _header;
	}

	//拷贝构造
	List(const List<T>& l) 
		:_header(new Node)

	{
		_header->_next = _header->_prev	= _header;
		for(const auto& e : l)
			pushBack(e);
	}
	
	//现代写法：代码复用
	List<T>& operator=(List<T> l) {
		swap(_header, l._header);
		return *this;
	}

private: 
	Node* _header;
};

template <class T> 
void printList(const List<T>& l) {
	typename List<T>::const_iterator it = l.begin();
	while(it != l.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test() {
	List<int> l;
	l.pushBack(1);
	l.pushFront(0);
	l.pushBack(2);
	l.pushBack(3);
	l.pushBack(4);
	printList(l);
	size_t size = l.size();
	cout << size << endl;
	List<int> l1 = l;
	printList(l1);
	List<int> l2(l);
	printList(l2);
	
}


int main() {
	test();
	return 0;
}
















