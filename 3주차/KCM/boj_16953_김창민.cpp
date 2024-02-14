#include <iostream>
#include <queue>

using namespace std;

int main() {
	int a, b;
	queue<long long int> q;
	int min = 1;
	int n, i;
	bool flag = false;
	long long int tmp, x;
	
	cin >> a >> b;

	q.push(a);
	while (!q.empty() && !flag) {
		min++;
		n = q.size();

		for (i = 0; i < n; i++) {
			x = q.front();
			q.pop();

			tmp = x << 1;
			if (tmp < b) {
				q.push(tmp);
			}
			else if (tmp == b) {
				flag = true;
				break;
			}

			tmp = x * 10 + 1;
			if (tmp < b) {
				q.push(tmp);
			}
			else if (tmp == b) {
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		cout << min;
	}
	else {
		cout << -1;
	}
}