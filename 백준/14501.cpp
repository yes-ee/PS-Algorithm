//tag: bruteforce

#include <iostream>

using namespace std;

int n, ret, sum;
int t[16], p[16];

//다음 시작 날짜를 선택하는 재귀함수
void pick(int start) {
	//상담 완료 날짜 > 퇴사 날짜 -> 리턴
	if (start + t[start] > n + 1)
		return;

	sum += p[start];
	if (sum > ret) {
		ret = sum;
	}

	for (int i = start + t[start]; i <= n; i++) {
		pick(i);
	}
	sum -= p[start];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		pick(i);
	}
	cout << ret;
	return 0;
}