#include <iostream>
#include <algorithm>
#define MAX 100

using namespace std;

int main() {
	int n, m;
	int arr[MAX];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		swap(arr[a-1], arr[b-1]);
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

		return 0;
}