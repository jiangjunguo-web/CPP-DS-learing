#include <iostream>
#include <sstream>
using namespace std;

int main() {
	stringstream sstream;

	//将多个字符串放入到sstream中
	sstream << "first" << " " << "string";
	sstream << " second string";
	cout << "strResult is " << sstream.str() << endl;
	
	//清空sstream 
	sstream.str("");
	sstream << "third string";
	cout << "After clear, strResult is: " << sstream.str() << endl;

	return 0;
}
