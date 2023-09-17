#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt;
vector<int> v;
int visited[8];

void re(int cnt) {
	if (cnt == m) {
		for (auto i:v) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		v.push_back(i + 1);
		visited[i] = 1;

		re(cnt + 1);
		
		v.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	re(0);
}