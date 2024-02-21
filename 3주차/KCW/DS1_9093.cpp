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



/* ť�� ����� Ǯ�� */
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
		getline(cin, str);// ���� �Է¹ޱ�

		for (int j = 0; j <= str.size(); j++) {

			//str �˻��ϸ鼭 ���ÿ� �ϳ��� �ֱ�
			if ((65 <= str[j] && str[j] <= 90) || (97 <= str[j] && str[j] <= 122)) {
				stk.push(str[j]);
				continue;
			}
			while (!stk.empty()) { // �ܾ ������ ������ ���鼭 ť�� ä���
				q.push(stk.top());
				stk.pop();
			}
			q.push(' ');
		}
		q.push('\n');

		//ť�� �� ������ �� �־����� ���� ����ϱ�
		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
	}
}*/