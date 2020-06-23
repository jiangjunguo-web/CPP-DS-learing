#include <iostream>
#include <vector>
#include <list>
using namespace std;

//正向打印
void printList(const list<int>& l) {
	list<int>::const_iterator it = l.begin();
	while(it != l.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

//反向打印
void printList_reverse(list<int>& l) {
	list<int>::reverse_iterator it = l.rbegin();
	for(; it != l.rend(); it++) 
		cout << *it << " ";
	cout << endl;
}


void test() {
	list<int> l1;
	for(auto x : l1) 
		cout << x << " ";
	cout << endl;
	list<int> l2(4, 100);
	for(auto x : l2) 
		cout << x << " ";
	cout << endl;
	list<int> l3(l2.begin(), l2.end());
	for(auto x : l3) 
		cout << x << " ";
	cout << endl;
	list<int> l4(l2);
	for(auto x : l4) 
		cout << x << " ";
	cout << endl;
	
	int arr[] = {16, 2, 77, 29};
	list<int> l5(arr, arr + sizeof(arr) / sizeof(int));
	printList(l5);
	printList_reverse(l5);
}

//use the fun interface
void test1() {
	int arr[] = {1, 2, 3};
	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
	printList(l); 
	l.push_back(4);  
	printList(l); 
	l.push_front(0);
	printList(l); 
	l.pop_back();
	printList(l); 
	l.pop_front();
	printList(l); 
}

void test2() {
	int arr[] = {1, 2, 3};
	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
	printList(l); 
	auto pos = ++l.begin();
	cout << *pos << endl;

	l.insert(pos, 4);
	printList(l); 

	l.insert(pos, 5, 5);
	printList(l); 

	vector<int> v{7, 8, 9};
	l.insert(pos, v.begin(), v.end());
	printList(l); 

	l.erase(pos);
	printList(l); 
	
	l.erase(l.begin(), l.end());
	printList(l); 
}

void test3() {
	int arr[] = {1, 2, 3};
	list<int> l(arr, arr + sizeof(arr) / sizeof(int));
	printList(l); 
	cout << l.size() << endl;
	list<int> l2;
	l2.swap(l);
	printList(l); 
	printList(l2); 
	
	


}

int main() {
	test3();
	return 0;

}
