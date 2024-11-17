#include <bits/stdc++.h>

using namespace std;

struct result {
	int x;
	int y; 
	int z;
};

int a, b, c, n;
int ans[1001];
vector<result> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> a >> b >> c >> n;

	int x, y, z, res;

	for (int i = 1; i <= a + b + c; i++) ans[i] =2;

	while (n--) {
		cin >> x >> y >> z >> res;
		if (res == 1)
			ans[x] = ans[y] = ans[z] = 1;
		else {
			result input;
			input.x = x;
			input.y = y;
			input.z = z;
			v.push_back(input);
		}
	}

	for (auto i : v) {
		int cnt = 0;
		if (ans[i.x] == 1) cnt++;
		if (ans[i.y] == 1) cnt++;
		if (ans[i.z] == 1) cnt++;

		if (cnt == 2) {
			if (ans[i.x] != 1)
				ans[i.x] = 0;
			if (ans[i.y] != 1)
				ans[i.y] = 0;
			if (ans[i.z] != 1)
				ans[i.z] = 0;
		}
	}
	for (int i = 1; i <= a + b + c; i++)
		cout << ans[i] << "\n";
	return 0;
}