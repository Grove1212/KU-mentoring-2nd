#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, i;
	int sum = 0;
	int* arr;

	cin >> n;

	arr = new int[n];

	for (i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (i = 0; i < n; i++)
		sum += arr[i] * (n - i);

	cout << sum;
}