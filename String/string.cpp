#include <iostream>
#include <string.h>
using namespace std;

void TestString() {
	string s1;
	cout << s1 << endl;
	string s2("hello world");
	cout << s2 << endl;
	string s3(s2);
	cout << s3 << endl;
}

void TestString1() {
	string s("hello world!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << endl;
	//清空字符串
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << endl;
	//将有效字符个数增加到10个，多出的位置使用字符进行填充
	s.resize(20, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << endl;
	//将有效的字符个数增加到25个，多余的使用‘\0’,进行填充；
	s.resize(25);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	cout << endl;
	//将有效字符个数，减小至5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void TestString2() {
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}

void TestPushBack() {
	string s;
	int i;
	size_t sz = s.capacity();
	cout << "making s grow: \n";
	for(i = 0; i < 100; ++i) {
		s.push_back('c');
		cout << s << endl;
		if(sz != s.capacity()) {
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}

	}

}

void TestPushBackReserve() {
	string s;
	int i;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow: \n";
	for(i = 0; i < 100; ++i) {
		s.push_back('c');
		if(sz != s.capacity()) {
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	} 
}

void Test() {
	string s1("hello world");
	const string s2("hello world");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;
}

void Test1() {
	string s("hello world!");
	size_t i;
	//遍历方式：三种
	//遍历过程：可读可写
	//1：for + operator[]
	/*
	for(i = 0; i < s.size(); ++i)
		cout << s[i] << endl;
	
	
	//2.迭代器实现
	string::iterator it = s.begin(); 
	while(it != s.end()) {
		cout << *it << endl;
		++it;
	}
	
	*/
	string::reverse_iterator rit = s.rbegin();
	while(rit != s.rend()) {
		cout << *rit << endl;
		++rit; 
	}
	

	//范围for
	//for(auto ch:s)
	//	cout << ch << endl;
}


void Test2() {
	string str;
	str.push_back(' ');
	str.append("hello");
	str += 'b';
	str += "it";
	cout << str << endl;
	cout << str.c_str() << endl;
	string file1("string.cpp");
	
	size_t pos = file1.rfind('.');
	cout << "pos = " << pos << endl;
	string suffix(file1.substr(pos, file1.size()-pos)); 
	cout << suffix << endl;

	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if(start == string::npos) {
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	cout << "finish = " << finish << endl;
	string address = url.substr(start, finish - start);
	cout << address << endl;
	
	pos = url.find("://");
	url.erase(0, pos+3);
	cout << url << endl;
}

int main() {
	Test2();
}
