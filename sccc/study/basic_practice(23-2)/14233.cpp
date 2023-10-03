// 각 업무에 투자할 수 있는 시간의 최댓값을 구하기 k
// k 가 만족해야 하는 조건은
// 각 업무를 k일 씩 했을 때, 마감 기한을 모두 맞춰야 함

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
int s, e, m;
vector<int> v;

bool fn(int m) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < (i + 1) * m)
			return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	s = 1;
	e = v[n - 1];

	while (s <= e) {
		m = (s + e) / 2;

		if (fn(m)) {
			ans = m;
			s = m + 1;
		}
		else
			e = m - 1;
	}

	cout << ans;

	return 0;
}