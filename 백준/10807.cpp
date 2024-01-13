#include <iostream>
#define MAX 100
using namespace std;

int arr[MAX];

int main(void) {
	int n, v;
	int result = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> v;

	for (int i = 0; i < n; i++) {
		if (arr[i] == v)
			result++;
	}
	cout << result;

	return 0;
}