#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v) {
	vector<int>::const_iterator it = v.begin();
	while(it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test() {
	int myints[] = {16,2,77,29};
	vector<int>fifth(myints, myints + sizeof(myints) / sizeof(int));
	PrintVector(fifth);
}

void test2() {
	//use the function : push_back()
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	PrintVector(v);
	//使用迭代器进行打印
	vector<int>::iterator it = v.begin();
	while(it != v.end()) {
		cout << *it << ' ';
		++it;
	}
	cout << endl;
	//使用迭代器进行修改
	it = v.begin();
	while(it != v.end()) {
		*it = 11;
		++it;
	}
	PrintVector(v);
	//使用反向迭代器输出
	vector<int>::reverse_iterator r_it = v.rbegin();
	while(r_it != v.rend()) {
		cout << *r_it << " ";
		++r_it;
	}
	cout << endl;
}

//容量函数的使用
//在PJ版本的STL中，增容以1.5倍实现，在SGI版本的STL中增容以2倍实现
void test3() {
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	int i;
	for(i = 0; i < 100; i++) {
		foo.push_back(i);
		if(sz != foo.capacity()) {
			sz = foo.capacity();
			cout << "the new capacity is" << sz;
			cout << endl;
		}
	}
}

//reverse 的使用
void test4() {
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	int i;
	v.reserve(120);
	for(i = 0; i < 100; ++i) {
		v.push_back(i);
		if(sz != v.capacity()) {
			sz = v.capacity();
			cout << "the new capacity is " << sz << endl;
		}
	}
}

//resize 的使用
void test5() {
	vector<int> v;
	for(int i = 0; i < 10; ++i) 
		v.push_back(i);
	PrintVector(v);	
	v.resize(5);
	PrintVector(v);	
	v.resize(8, 100);
	PrintVector(v);	
	v.resize(12);
	PrintVector(v);	
	for(int i = 0; i < v.size(); ++i) {
		cout << ' ' << v[i];
	}
	cout << endl;
}

//增删改查
void test6() {
	int a[] = {1, 2, 3, 4, 5};
	vector<int> v(a, a+sizeof(a)/sizeof(int));
	vector<int>::iterator it = v.begin();
	while(it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	v.pop_back();
	v.pop_back();
	
	it = v.begin();
	while(it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//查找,插入,删除
//vector里没有find成员函数
void test7() {
	int a[] = {1, 2, 3, 4, 5, 6};
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 3);
	vector<int>::iterator it = v.begin();
	while(it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	
	it = v.begin();
	while(it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//遍历方式
void test8() {
	int a[] = {1 , 2, 3, 4, 5, 6};
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	v[0] = 10;
	cout << v[0] << endl;
	for(size_t i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	vector<int>swapv;
	swapv.swap(v);
	
	for(size_t i = 0; i < swapv.size(); ++i) 
		cout << swapv[i];
	cout << endl;
	
	for(auto x : v)
		cout << x << " ";
	cout << endl;

}

int main() {
	test8();
}
