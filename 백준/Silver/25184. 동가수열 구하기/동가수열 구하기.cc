#include <bits/stdc++.h>

using namespace std;

int n;
int arr[5000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int num = (n + 1) / 2;

	for (int i = 0; i < n; i +=  2) {
		arr[i] = num;
		num--;
	}
	num = n;
	for (int i = 1; i < n; i += 2) {
		arr[i] = num;
		num--;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}