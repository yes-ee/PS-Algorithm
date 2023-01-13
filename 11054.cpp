#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int arr[MAX];
int inc[MAX];
int des[MAX];
int n, max_len, min_len, sum;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

//왼쪽 증가 수열 최대 길이 구하기
	for (int i = 0; i < n; i++) {
		max_len = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && inc[j] > max_len)
				max_len = inc[j];
		}
		inc[i] = max_len + 1;
	}

//오른쪽 증가 수열 최대 길이 구하기
	for (int i = n - 1; i >= 0; i--) {
		min_len = 0;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j] && des[j] > min_len)
				min_len = des[j];
		}
		des[i] = min_len + 1;
	}

	for (int i = 0; i < n; i++) {
		sum = max(sum, inc[i] + des[i] - 1);
	}

	cout << sum;

	return 0;
}