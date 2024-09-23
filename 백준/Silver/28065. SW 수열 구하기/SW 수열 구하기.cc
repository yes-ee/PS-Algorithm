#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int num = n - 1;
	int flag = -1;
	int pre = n;

	cout << n << " ";

	for (int i = 0; i < n - 1; i++) {
		pre = pre + num * flag;
		cout << pre << " ";
		num--;
		flag *= -1;
	}

	return 0;
}