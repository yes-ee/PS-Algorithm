#include <iostream>
#include <math.h>

using namespace std;

int l;
string s;
long long ans;

int main() {
	cin >> l >> s;

	for (int i = 0; i < l; i++) {
		ans += ((s[i] - 96) * ((long long)powl(31, i) % 1234567891)) % 1234567891;
	}

	cout << ans;

	return 0;
}