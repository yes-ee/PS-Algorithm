#include <bits/stdc++.h>

using namespace std;

int n;
set<int> a;
set<int> b;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		v.push_back(in);
		a.insert(in);
	}

	sort(v.begin(), v.end());

	int nb = 1;

	for (auto num : v) {
		while (nb < num) {
			b.insert(nb);
			nb++;
		}
		nb =  num + 1;
	}

	while (nb <= 2 * n) {
		b.insert(nb);
		nb++;
	}

	int turn = 1;
	int cur = 0;

	while (1) {
		if (turn == 1) {
			// find min element 
			for (auto i : a) {

				if (cur < i) {
					cur = i;
					a.erase(i);
					turn = 2;
					break;
				}
			}
			if (turn == 1) {
				turn = 2;
				cur = 0;
			}
		} else {
			for (auto i : b) {
				if (cur < i) {
					cur = i;
					b.erase(i);
					turn = 1;
					break;
				}
			}
			if (turn == 2) {
				turn = 1;
				cur = 0;
			}
		}
		if (!a.size() || !b.size()) break;
	}

	if (!a.size()) cout << b.size() << "\n0";
	else cout << "0\n" << a.size();

	return 0;	
}