#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while(n--) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (auto i:v)
		cout << i << "\n";

	return 0;
}