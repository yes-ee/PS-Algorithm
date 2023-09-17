#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<int> v;

void re(int cnt, int s) {
	if (cnt == m) {
		for (auto i:v) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = s; i < n; i++) {
		v.push_back(i + 1);

		re(cnt + 1, i + 1);

		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	re(0, 0);
}