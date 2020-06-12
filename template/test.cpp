#include <iostream>
using namespace std;

//交换函数模板化
template <class T>
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}

//加法函数模板化：
template <class T1, class T2>
T1 Add(T1& a_one, T2& a_two) {
	return a_one + a_two;
}

int main() {
	char a = 'x'; 
	char b = 'h'; 
	int c = 1;
	int d = 11;
	Swap(a, b);
	cout << a << ' ' << b << endl;
	Swap(c, d);
	cout << c << ' ' << d << endl;
	int sum1 = Add(c, d);
	cout << sum1 << endl;
}
