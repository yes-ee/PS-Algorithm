#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dis[500001];
int idx[500001];
int arr[500001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		idx[a] = i; // 숫자 별 idx 저장
		arr[i] = a;
	}

	for (int i = 1; i < n; i++) {
		int minidx = idx[i]; // 바꿔야 하는 숫자의 인덱스
		int mv = abs(minidx - i); // 바꿀 숫자의 인덱스 - 현재 인덱스

		int num = arr[i];

		dis[i] += mv;
		dis[num] += mv;

		idx[num] = minidx;
		arr[minidx] = num; 
	}

	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}

	return 0;
}