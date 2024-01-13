#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int n, max_weight, res;
int arr[MAX];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < n; i++) {
		res = arr[i] * (i + 1);
		if (res > max_weight) {
			max_weight = res;
		}
	}
	cout << max_weight;

	return 0;
}