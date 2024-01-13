#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 300000

using namespace std;
int n, num, ans;
double sum;
int score[MAX];

int main() {
	cin >> n;
	if (n == 0) {
		cout << "0";
		return 0;
	}
	num = floor(n * 0.15 + 0.5);

	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}

	sort(score, score + n);
	for (int i = num; i < n - num; i++) {
		sum += score[i];
	}

	ans = floor((sum / (n - 2 * num)) + 0.5);
	cout << ans;
	return 0;
}