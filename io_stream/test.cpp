#include <sstream>
#include <iostream>
using namespace std;
//#include <string>

int main() {
	int a = 12345678; 
	string sa;

	//将一个整形变量转化为字符串
	stringstream s;
	s << a;
	s >> sa;
	
	//将stringstream底层管理string对象设置为“”;
	//否则多次转换时，会将结果全部积累在底层string对象中
	//s.str("");
	s.clear(); //清空s,不清空会导致转换失败
	double d = 12.34;
	s << d;
	s >> sa;
	
	string sValue;
	sValue = s.str(); 	//str()方法： 返回stringsteam中管理的string类型
	cout << sValue << endl;
	return 0;
}
