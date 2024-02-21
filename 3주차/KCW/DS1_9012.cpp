#include <iostream>
#include <stack>

using namespace std;

int N;

string isVPS(string str) {
// 초기화를 안시켜서 오류가 났었음. 어디 블록에 넣어야되는지 생각 필요
	stack<char> stk;
	string result = "NO";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') stk.push(str[i]);
		else 
		{
			if (stk.empty()) return result;
			stk.pop();
		}
	}
	if (stk.empty()) result = "YES";
	return result;
}

int main() {
	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		cout << isVPS(str) << '\n';
	}
}