#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

class bignum {
	public:
	string num = "1";

	bignum operator*(const bignum& b) {
		bignum res;
		res.num = "";

		string n1 = num;
		string n2 = b.num;

		vector<int> v(n1.size() + n2.size(), 0);

		int len1 = n1.size();
		int len2 = n2.size();

		if (len1 < len2) {
			swap(n1, n2);
			swap(len1, len2);
		}

		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len1; j++) {
				int a = n1[len1 - j - 1]- '0';
				int b = n2[len2 - i - 1] - '0';
				int idx = len1 + len2 - 1 - i - j;

				int mul = a * b;
				int n = mul + v[idx];
				int carry = n / 10;
				v[idx] = n % 10;
				v[idx - 1] += carry;
			}
		}

		int st = 0;
		while (st < v.size() && v[st] == 0) st++;

		for (int i = st; i < v.size(); i++) {
			res.num += (v[i] + '0');
		}

		return res;
	}

	bignum operator/(const bignum& b) {
		bignum res;
		res.num = "";

		string n1 = num;
		string n2 = b.num;

		queue<int> q;

		int len1 = n1.size();
		int len2 = n2.size();
		int rem = 0;

		for (int i = 0; i < len1; i++) {
			int a = n1[i] - '0' + rem * 10;
			int b = stoi(n2);

			int div = a / b;
			q.push(div);
			rem = a % b;
		}

		while (!q.empty() && q.front() == 0) q.pop();

		while (!q.empty()) {
			res.num += (q.front() + '0');
			q.pop();
		}

		return res;
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	if (m > n / 2) m = n - m;

	bignum ans;
	bignum a;

	for (int i = n; i > n - m; i--) {
		a.num = to_string(i);
		ans = ans * a;
	}

	for (int i = m; i > 1; i--) {
		a.num = to_string(i);
		ans = ans / a;
	}

	cout << ans.num;

	return 0;
}