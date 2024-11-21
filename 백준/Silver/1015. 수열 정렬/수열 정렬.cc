#include <iostream>

using namespace std;

int n;
int arr[51];
int ans[51];
int idx;
int mx = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j] == i) {
				ans[j] = idx++;
			}
		}
	}

		for (int i = 0; i < n; i++) cout << ans[i] << " ";

}