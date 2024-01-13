#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int sum;

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9, greater<int>());

	for (int i = 0; i < 8; i++) {
		sum -= arr[i];
		for (int j = i + 1; j < 9; j++) {
			sum -= arr[j];
			if (sum == 100) {
				for (int k = 8; k >= 0; k--) {
					if (k != i && k != j) {
						cout << arr[k] << "\n";
					}
				}
				return 0;
			}
			sum += arr[j];
		}
		sum += arr[i];
	}
	return 0;
}