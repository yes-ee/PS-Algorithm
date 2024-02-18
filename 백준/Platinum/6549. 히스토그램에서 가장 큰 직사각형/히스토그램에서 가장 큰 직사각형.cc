#include <iostream>
#include <stack>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

stack<pii> st;
int n;
ll arr[100001];
ll ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		arr[n] = 0;
		ans = 0;
		while (!st.empty()) st.pop();

		for (int i = 0; i <= n; i++) {
			int idx = i;

			while (!st.empty() && st.top().second >= arr[i]) {
				idx = st.top().first;
				long long h = st.top().second;
				ans = max(ans, (i - idx) * h);
				st.pop();
			}

			st.push({idx, arr[i]});
		}

		cout << ans << "\n";
	}

	return 0;
}