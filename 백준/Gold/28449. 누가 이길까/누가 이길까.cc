// two pointer

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
ll asum, bsum, sm, total;
vector<ll> a, b;
map<ll, ll> mb;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	ll num;
	total = n * m;

	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (mb.count(num) == 0)
			b.push_back(num);
		mb[num]++;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


	ll aidx = 0;
	ll bidx = 0;
	ll blen = mb.size();
	ll awin = 0;

	for (; aidx < n; aidx++) {
		while (bidx < blen && b[bidx] < a[aidx]) {
			awin += mb[b[bidx]];
			bidx++;
		}

		if (a[aidx] == b[bidx]) {
			asum += awin;
			sm += mb[b[bidx]];
		} else { // b > a
			asum += awin;
		}
	}

	cout << asum << " " << total - asum - sm << " " << sm;

	return 0;
}


