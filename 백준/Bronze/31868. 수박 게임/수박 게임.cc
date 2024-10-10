#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	cout << k / (int)pow(2, n - 1);

	return 0;
}