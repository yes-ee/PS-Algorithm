#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> note;
int n, m;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		note[a] = b;
	}

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << note[a] << "\n";
	}
	return 0;
}