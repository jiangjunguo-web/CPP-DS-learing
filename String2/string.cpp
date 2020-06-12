#include <iostream>
#include <string>
using namespace std;

template <class T>
void Swap(T& begin, T& end) {
	T temp = begin;
	begin = end;
	end = temp;
}

//翻转字母
class Solution {
public: 
	string reverseOnlyLetters(string s) {
		char* pLeft = (char*)s.c_str();
		char* pRight = pLeft + (s.size() - 1);
		while(pLeft < pRight) {
			while(pLeft < pRight) {
				if(isalpha(*pLeft))
					break;
				++pLeft;
			}

			while(pLeft < pRight) {
				if(isalpha(*pRight))
					break;
				--pRight;
			}
			if(pLeft < pRight) {
				swap(*pLeft, *pRight);
				++pLeft;
				--pRight;
			}

		}
	return s;
	}
	
	//找到第一个出现一次的字符
	int firstUniqChar(string s) {
		int count[256] = {0};
		int size = s.size();
		int i, j;
		for(i = 0; i < size; ++i) 
			count[s[i]]++;
		for(j = 0; j < size; ++j)
			if(count[s[j]] == 1)
				return j;
		return -1;

	}
	
	//返回最后一个单词的长度
	size_t lastWordLength(string s) {
		size_t pos = s.rfind(' ');
		return s.size() - pos - 1;
	}
	

	//判断是否是回文串
	bool isLetterOrNumber(char ch) {
		return (ch >= '0' && ch <= '9') 
			|| (ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z');
	}
		
	bool isPalindrome(string s) {
		size_t i;	
		for(i = 0; i < s.size(); ++i) 
			if(s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		int begin = 0, end = s.size() - 1;
		while(begin < end) {
			while(begin < end && !isLetterOrNumber(s[begin]))
				++begin;
			while(begin < end && !isLetterOrNumber(s[end]))
				--end;
			if(s[begin] != s[end])
				return false;
			++begin, --end;
		}
		return true;
	}
	
	void reverse(string::iterator begin, string::iterator end) {
		while(begin < end) {
			Swap(*begin, *end);
			++begin;
			--end;
		}
	}
	
	string addstrings(string num1, string num2) {
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int value1 = 0, value2 = 0, next = 0; 
		string addret;
		while(end1 >= 0 || end2 >= 0) {
			if(end1 >= 0)
				value1 = num1[end1--] - '0';
			else 
				value1 = 0;
			if(end2 >= 0)
				value2 = num2[end2--] - '0';
			else 
				value2 = 0;
			int  valueret = value1 + value2 + next;
			if(valueret > 9) {
				next = 1;
				valueret -= 10;
			}
			else {
				next = 0;
			}
			addret += (valueret + '0');
		}
		if(next == 1)
			addret += 1;
		cout << addret << endl;
		reverse(addret.begin(), addret.end() - 1);
		return addret;
	}
};

int main() {
	string s("aabbddsbbddll haha"); 
	cout << s << endl;
	Solution res;
	res.reverseOnlyLetters(s);
	cout << s << endl;
	int count = res.firstUniqChar(s);
	cout << count << endl;
	size_t lenth = res.lastWordLength(s);
	cout << lenth << endl;
	string s1("1234321");
	cout << res.isPalindrome(s1) << endl;
	string num1("12345");
	string num2("12345");
	s = res.addstrings(num1, num2);
	cout << s << endl;
}
