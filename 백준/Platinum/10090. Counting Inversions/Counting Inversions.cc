#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> v;
int sorted[1000000];
ll cnt;

// 정렬된 두 배열 합치기
void merge(int st, int mid, int end) {
	int i = st;
	int j = mid + 1;
	int k = st;

	while (i <= mid && j <= end) {
		if (v[i] <= v[j]) {
			sorted[k] = v[i];
			i++;
		} else {
			sorted[k] = v[j];
			j++;
			cnt += (mid - i + 1);
		}
		k++;
	}

	if (i > mid) {
		while (j <= end) {
			sorted[k] = v[j];
			j++;
			k++;
		}
	} else {
		while (i <= mid) {
			sorted[k] = v[i];
			i++;
			k++;
		}
	}

	for (int i = st; i <= end; i++) {
		v[i] = sorted[i];
	}
}

// 배열 분할
void merge_sort(int st, int end) {
	if (st < end) {
		int mid = (st + end) / 2;

		merge_sort(st, mid);
		merge_sort(mid + 1, end);
		merge(st, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	merge_sort(0, n - 1);

	cout << cnt;

	return 0;
}