#include <bits/stdc++.h>

using namespace std;

int n;
int arr[50][50];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	if (arr[0][0] < arr[0][n - 1]) {
		if (arr[0][0] < arr[n - 1][0]) cout << "0";
		else cout << "3";
	} else {
		if (arr[0][0] < arr[n - 1][0]) cout << "1";
		else cout << "2";
	}

	return 0;
}