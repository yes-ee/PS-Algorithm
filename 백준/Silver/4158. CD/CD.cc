#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt, input;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0)
			return 0;

		cnt = 0;
		v.clear();

		for (int i = 0; i < n; i++) {
			cin >> input;
			v.push_back(input);
		}

		int aidx = 0;

		for (int bidx = 0; bidx < m; bidx++) {
			cin >> input;
			while (aidx < n && input > v[aidx]) {
				aidx++;
			}

			if (aidx < n && input == v[aidx])
				cnt++;
		}

		cout << cnt << "\n";
	}


	return 0;
}