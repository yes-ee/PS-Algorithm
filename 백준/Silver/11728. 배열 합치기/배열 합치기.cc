#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a;

	cin >> n >> m;
	while (n--) {
		cin >> a;
		v.push_back(a);
	}

	while(m--) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}