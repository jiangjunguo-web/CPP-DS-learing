#include <iostream>
#include <string.h>
#include <string>
using namespace std;

template <class T>

void swap1(T& change1, T& change2) {
	T tem = change1;
	change1 = change2;
	change2 = tem;
}

class String {
public:
	//构造函数
	String() 
		:_str(new char [16])
		,_size(0)
		,_capacity(0)
	{
		_str[_size] = 0;
		_capacity = 15;
	}	
	
	//带参构造
	String (const char* str) {
		_size = strlen(str);
		_str = new char [_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	//析构函数
	~String() {
		if(_str) {
			delete[] _str;
			_capacity = _size = 0; 
			_str =  NULL;
		}

	}

	//拷贝构造(深拷贝)
	//String(const String& str) 
	//	:_str(new char [str._capacity + 1])
	//	,_size(str._size)
	//	,_capacity(str._capacity)
	//{
	//	strcpy(_str, str._str);
	//} 

	//赋值运算符
	//String& operator=(const String& str) {
	//	if(this != &str) {
	//		//开空间
	// 		char* tmp = new char[str._capacity + 1];
	// 		//内容拷贝
	// 		strcpy(tmp, str._str);
	// 		//释放原有空间
	// 		delete[] _str;
	// 		
	// 		_str = tmp;
	// 		_size = str._size;
	// 		_capacity = str._capacity;

	//	}
	//	return *this;
	//} 
	
	//现代写法:拷贝函数
	String (const String& str) 
		:_str(NULL)
		,_size(0)
		,_capacity(0)
	{
		String temp(str._str);
		Swap(temp);
	}

	
	void Swap(String& str) {
		swap1(_str, str._str);
		swap1(_size, str._size);
		swap1(_capacity, str._capacity);
	}
	
	//赋值运算符: 现代写法
	String& operator=(String str) {
		Swap(str);
		return *this;
	}

	//尾插
	void pushBack(const char& ch) {
		if(_size == _capacity) {
			size_t newc = (_capacity == 0) ? 15 : 2 * _capacity;
			reserve(newc);
		}
		_str[_size] = ch;
		_str[++_size] = 0;
	}
	
	void reserve(size_t n)  {
		if(n > _capacity) {
			//开空间
			char* tmp = new char[n + 1];
			//拷贝
			strcpy(tmp, _str);
			_capacity = n;
			//删除原有空间
			delete[] _str;	
			_str = tmp;
		}
	}
	//迭代器实现:
	typedef char* iterator;
	typedef const char* const_iterator;
	
	iterator begin() {
		return _str;
	}
	
	iterator end() {
		return _str + _size;
	}
	
	const_iterator c_begin() const {
		return _str;
	}
	
	const_iterator c_end() const{
		return _str + _size;
	}
	
	//operator[] 实现:
	char& operator[](size_t pos) {
		if(pos < _size)
			return _str[pos];
	}
	
	const char& operator[](size_t pos) const {
		if(pos < _size)
			return _str[pos];
	}
	
	//返回String的有效长度
	size_t size() const {
		return _size;
	}

	//追加一个字符串
	void Append(const char* str) {
		int len = strlen(str);
		//检查容量
		if(_size + len > _capacity) 
			reserve(_size + len);
		strcpy(_str + _size, str);
		_size += len;
	}
	
	//+=运算符重载
	String& operator+=(const char& ch) {
		pushBack(ch);
		return *this;
	}
	
	String& operator+=(const char* str) { 
		Append(str);
		return *this;
	}

	
	//插入一个字符: 在给定位置的前方
	void insert(size_t pos, const char& ch) {
		if(pos > _size)
			return;
		if(_size == _capacity) {
			size_t newc = (_capacity == 0) ? 15 : 2 * _capacity;
			reserve(newc);
		}
		size_t end = _size + 1;
		while(end > pos) {
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = ch;
		++_size;
	}

	//重载insert,在给定位置插入一个字符串
	void insert(size_t pos, const char* str) {
		int len = strlen(str);
		//扩容
		if(_size + len > _capacity)
			reserve(_size + len);
		size_t end = _size + len;
		while(end > pos + len - 1) {
			_str[end] = _str[end - len];
			--end;
		} 
		int i;
		for(i = 0; i < len; i++) 
			_str[i + pos] = str[i];
		_size += len;
	}


private:
	char* _str;
	size_t _size;
	size_t _capacity;
};


//打印String
void printString(const String& s) {
	String::const_iterator cit = s.c_begin();
	while(cit != s.c_end()) {
		cout << *cit << ' ';
		++cit;
	}
	cout << endl;
}

void test() {
	String str("123");
	printString(str);
	String s1(str);
	printString(s1);
	String s2;
	s2 = s1;
	printString(s1);
}

void test1() {
	String str("hello world");
	printString(str);
	str.pushBack('!');
	printString(str);
	str.Append("working hard");
	printString(str);
	str += 'G';
	printString(str);
	str += "o for it!";
	printString(str);
}

void test3() {
	String str("this is a cplusplus test!");
	printString(str);
	str.insert(9, ' ');
	printString(str);
	str.insert(10, "funny");
	printString(str);
}

int main() {
	test();
	return 0;
}
