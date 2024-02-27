#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int st, en;
	int sum = 0;
	int i, tmp;
	vector<int> v;

	cin >> n >> m;

	v.push_back(0);
	for (i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		v.push_back(sum);
	}

	for (i = 0; i < m; i++) {
		cin >> st >> en;
		cout << v[en] - v[st - 1] << "\n";
	}
}