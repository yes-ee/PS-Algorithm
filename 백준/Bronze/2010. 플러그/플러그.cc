#include <iostream>

using namespace std;

int n;
int sum;

int main() {
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum+=a;
	}
	cout << sum - (n-1);
	return 0;
}