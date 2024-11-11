#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[300001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int a;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		arr[a] = i;
	}

	int idx = n;

	for (; idx > 0; idx--) {
		if (arr[idx] < arr[idx - 1]) break;
	}

	cout << (idx == 0 ? 0 : idx - 1);

	return 0;
}