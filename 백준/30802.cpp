#include <iostream>
#include <vector>

using namespace std;

int n, t, p;

vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < 6; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	cin >> t >> p;

	int tm = 0;

	for (int i = 0; i < 6; i++) {
		if (v[i] % t) {
			tm += v[i] / t + 1;
		} else {
			tm += v[i] / t;
		}
	}

	cout << tm << "\n"
		 << n / p << " " << n % p;

	return 0;
}