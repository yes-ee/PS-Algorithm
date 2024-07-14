// two pointer

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll a[4000], b[4000], c[4000], d[4000];
ll ab[16000000], cd[16000000];
ll n, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i]  >> c[i] >> d[i];
	}

	int idx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[idx] = a[i] + b[j];
			cd[idx] = c[i] + d[j];
			idx++;
		}
	}

	sort(ab, ab + n * n);
	sort(cd, cd + n * n);

	int st = 0;
	int end = n * n - 1;

	while (st < n * n && end >= 0) {
		ll sum = ab[st] + cd[end];
		if (sum == 0) {
			ll sc = 1;
			ll ec = 1;
			
			// same num
			while (st < n * n - 1 && ab[st] == ab[st + 1]) {
				st++;
				sc++;
			}

			// same num
			while (end > 0 && cd[end] == cd[end - 1]) {
				end--;
				ec++;
			}

			st++;
			end--;
			ans += sc * ec;
		} else if (sum > 0) end--;
		else st++;
	}

	cout << ans;

	return 0;
}