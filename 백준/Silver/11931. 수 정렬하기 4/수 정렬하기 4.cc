#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;

int main() {
	cin >> n;

	int a;

	for(int i = 0; i <n; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
}