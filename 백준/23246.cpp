#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<int, pair<int, int>> m;

static bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
	if (a.second.first == b.second.first)	//곱한 값이 같은 경우
	{
		if (a.second.second == b.second.second)	//더한 값이 같은 경우 등번호 낮은 사람 앞으로
			return a.first < b.first;
		return a.second.second < b.second.second;
	}
	return a.second.first < b.second.first;
}

int main(void)
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int b, p, q, r;
		cin >> b >> p >> q >> r;
		m.insert({b, {p * q * r, p + q + r}});
	}
	vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < 3; i++)
	{
		cout << v[i].first << " ";
	}
		return (0);
}
