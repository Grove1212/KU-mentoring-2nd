#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int N;
stack<int> stk;
queue<int> q;

int main() {
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		q.push(input);
	}

	if (q.back() != 1) {
		cout << "NO";
		return 0;
	}
	
	for (int s = 1; s <= N; s++) {
		stk.push(s);
		cout << '+' << '\n';
		
		while (true) {
			if (q.empty() || stk.top() != q.front()) break;

			cout << '-' << '\n';
			stk.pop();
			q.pop();
		}
	}
}