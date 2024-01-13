#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> x;
vector<int> w;
double s, e, m;
double sum;

double fn(double m) {
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (x[i] - m) * w[i];
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		x.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		w.push_back(a);
	}

	s = 0;
	e = l;

	for (int i = 0; i < 1000; i++) {
		m = (s + e) / 2;

		double res = fn(m);

		if (res == 0)
			break;
		// 오른쪽이 더 무거움
		else if (res > 0)
			s = m;
		else
			e = m;
	}

	cout << fixed;
	cout.precision(15);

	cout << m;

	return 0;
}