#include <set>
#include <iostream>

using namespace std;

set<int> s;
int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	int input;

	while (n--) {
		cin >> input;
		s.insert(input);
	}

	cin >> m;

	while (m--) {
		cin >> input;
		if (s.find(input) != s.end())
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}
