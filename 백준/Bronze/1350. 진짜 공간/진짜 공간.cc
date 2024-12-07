#include <bits/stdc++.h>

using namespace std;

int n, sz;
int arr[50];
long long cnt;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> sz;

	for (int i = 0; i < n; i++) {
		cnt += arr[i] / sz;
		if (arr[i] % sz != 0) cnt++;
	}

	cout << (long long)cnt * sz;

	return 0;
}