#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();

	while (N--) {
		string s = "";
		getline(cin, s);
		s += ' ';
		stack<char> stk;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				while (!stk.empty()) {
					cout << stk.top();
					stk.pop();
				}
				cout << s[i];
			}
			else stk.push(s[i]);
		}

	}
}



/* 큐를 사용한 풀이 */
/*
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

int N;

int main(void) {
	cin >> N;
	cin.ignore();
	stack<char> stk;
	queue<char> q;

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);// 문장 입력받기

		for (int j = 0; j <= str.size(); j++) {

			//str 검사하면서 스택에 하나씩 넣기
			if ((65 <= str[j] && str[j] <= 90) || (97 <= str[j] && str[j] <= 122)) {
				stk.push(str[j]);
				continue;
			}
			while (!stk.empty()) { // 단어가 끝나면 스택을 비우면서 큐를 채우기
				q.push(stk.top());
				stk.pop();
			}
			q.push(' ');
		}
		q.push('\n');

		//큐에 한 문장을 다 넣었으면 이제 출력하기
		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
	}
}*/