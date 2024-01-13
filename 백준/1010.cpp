#include <iostream>

using namespace std;

int t, n, r;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++)
	 {
		 long long sum = 1;
		 cin >> r >> n;
		 for (int j = n; j > (n - r); j--) {
			 sum *= j;
			 sum /= n - j + 1;
		 }
		 cout << sum << "\n";
	 }
	 return 0;
}