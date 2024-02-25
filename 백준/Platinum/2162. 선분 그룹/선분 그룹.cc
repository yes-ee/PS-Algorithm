// 선분 교차 판정

#include <iostream>
#include <set>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct line {
	pll a;
	pll b;
};

pll a, b;
int n;
line g[3000];
int p[3000];
int cnt[3000];
int ans = 0;
set<int> s;

int ccw(pll x, pll y, pll z)
{
	ll ret = (x.first * y.second + y.first * z.second + z.first * x.second) - (y.first * x.second + z.first * y.second + x.first * z.second);

	if (ret > 0)
		return -1;
	else if (ret < 0)
		return 1;
	else
		return 0;
}

int isIntersect(pll a, pll b, pll c, pll d)
{
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0)
	{ // 일직선인 경우
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);

		return c <= b && a <= d;
	}

	return ab <= 0 && cd <= 0;
}

int find(int a) {
	if (p[a] == a) return a;

	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	p[b] = a;

	cnt[a]+= cnt[b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		p[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		cin >> a.first >> a.second >> b.first >> b.second;

		g[i] = {a, b};

		for (int j = 0; j < i; j++) {
			if (isIntersect(g[j].a, g[j].b, a, b)) {
				merge(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		s.insert(find(i));
		ans = max(ans, cnt[find(i)]);
	}

	cout << s.size() << "\n" << ans;

	return 0;
}