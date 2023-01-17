#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 1000001
using namespace std;

int n;
pair<int, int> dp[MAX];	//최솟값, 현재 인덱스
int pre[MAX];	//최솟값일 때 전 인덱스
stack<int> st;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

void solve(void)
{
	int idx;

	dp[1] = {0, 1};

	for (int i = 2; i <= n; i++)
	{
		if (i % 6 == 0)
			dp[i] = min({dp[i / 3], dp[i / 2], dp[i - 1]}, cmp);
		else if (i % 3 == 0)
			dp[i] = min(dp[i / 3], dp[i - 1], cmp);
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2], dp[i - 1], cmp);
		else
			dp[i] = dp[i - 1];
		pre[i] = dp[i].second;
		dp[i].second = i;
		dp[i].first++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	solve();

	cout << dp[n].first << "\n";

	int idx = n;
	for (int i = 0; i <= dp[n].first; i++)
	{
		cout << idx << " ";
		idx = pre[idx];
	}

	return 0;
}