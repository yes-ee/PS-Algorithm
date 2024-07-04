#include <iostream>
#include <vector>
#include <string>

using namespace std;

int c, n, m, sl;
string s, l;
vector<pair<int, int>> v[26];
int arr[26];
int idx[26];
int x, y;

void move(int nx, int ny) {
	while (ny > y) {
		y++;
		l += 'D';
	}
	while (ny < y) {
		y--;
		l += 'U';
	}

	while (nx > x) {
		x++;
		l += 'R';
	}
	while (nx < x) {
		x--;
		l += 'L';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> sl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			v[c-'a'].push_back({j, i});
		}
	}

	cin >> s;

	for (char c : s) {
		arr[c - 'a']++;
	}

	c = 9999;

	for (int i = 0; i < 26; i++) {
		if (arr[i]) {
			c = min((int) v[i].size() / arr[i], c);
		}
	}

	for (int i = 0; i < c; i++) {
		for (char c : s) {
			int ci = c - 'a';
			// next visit
			int nx = v[ci][idx[ci]].first;
			int ny = v[ci][idx[ci]].second;

			// move until same
			move(nx, ny);

			// pick
			l+= 'P';

			// after visit
			idx[ci]++;
		}
	}

	int nx = m - 1;
	int ny = n - 1;

	// move until same
	move(nx, ny);

	cout << c << " " << l.length() << "\n";
	cout << l;

	return 0;
}