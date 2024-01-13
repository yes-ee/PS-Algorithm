#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

int n;
int arr[MAX];
vector<int> l = {1000000};

void solve() {
	for (int i = 0; i < n; i++) {
		if (l.back() < arr[i]) {
			l.push_back(arr[i]);
		}
		else {
			int index = lower_bound(l.begin(), l.end(), arr[i])- l.begin();
			l[index] = arr[i];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve();

	cout << l.size();

	return 0;
}