#include <bits/stdc++.h>

using namespace std;
int n;
int a, b;
vector<int> tp;
int dw;
int ans;

int main() {
	cin >> n >> a >> b;
	cin >> dw;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tp.push_back(x);
	}

	sort(tp.begin(), tp.end(), greater<int>());

	ans = dw / a;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += tp[i];
		ans = max(ans, (dw + sum) / (a + b * (i + 1)));
	}

	cout << ans;

	return 0;
}