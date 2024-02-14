#include <iostream>
#include <string>
using namespace std;

int N;

class Stack {
	int stk[10001] = { 0, };
	int top_idx;
public:
	Stack() { top_idx = -1;	}
	void push(int x);
	int pop();
	int size();
	int empty();
	int top();
};

void Stack::push(int x) {
	stk[++top_idx] = x;
}

int Stack::pop() {
	if (top_idx == -1) return -1;
	int i = stk[top_idx];
	stk[top_idx--] = 0;

	return i;
}

int Stack::size() {
	return top_idx + 1;
}

int Stack::empty() {
	if (top_idx == -1)
		return 1;
	return 0;
}

int Stack::top() {
	if (top_idx == -1) return -1;
	return stk[top_idx];
}

int main(void) {
	cin >> N;

	Stack stk;
	string input;

	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input == "push") {
			int i;
			cin >> i;
			stk.push(i);
		}
		else if (input == "top") {
			cout << stk.top() << '\n';
		}
		else if (input == "size") {
			cout << stk.size() << '\n';
		}
		else if (input == "empty") {
			cout << stk.empty() << '\n';
		}
		else if (input == "pop") {
			cout << stk.pop() << '\n';
		}
	}
}