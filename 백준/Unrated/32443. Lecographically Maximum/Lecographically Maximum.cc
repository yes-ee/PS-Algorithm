#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> v;
int cnt[100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		int idx = 0;
		while (a) {
			int num = a % 2;
			a = a / 2;
			if (num) cnt[idx]++;
			idx++;
		}
	}

	int mx = 99;
	for (int i = 0; i < n; i++) {
		int num = 0;
		for (int j = mx; j >= 0; j--) {
			if (cnt[j]) {
				mx = j;
				break;
			}
		}

		for (int j = mx; j >= 0; j--) {
			num = num << 1;
			if (cnt[j]) {
				num++;
				cnt[j]--;
			}
		}
		cout << num << " ";
	}

	return 0;
}