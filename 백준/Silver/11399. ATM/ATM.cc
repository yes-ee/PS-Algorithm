#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;
int t[MAX];
int sum;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	
	sort(t, t + n);
	for (int i = 0; i < n; i++) {
		sum += t[i] * (n - i);
	}

	cout << sum;
	return 0;
}