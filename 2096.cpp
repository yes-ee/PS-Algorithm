// dp
// iostream 헤더 사용 시 2mb 정도 사용
// -> dp[100000][3] 으로 선언하면 메모리 초과

#include <iostream>

using namespace std;

int maxdp[3];
int mindp[3];
int pre[3];
int graph[3];
int n, maxsum, minsum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> graph[0] >> graph[1] >> graph[2];

		// 최대 구하기
		pre[0] = maxdp[0];
		pre[1] = maxdp[1];
		pre[2] = maxdp[2];

		maxdp[0] = max(pre[0], pre[1]) + graph[0];
		maxdp[1] = max(max(pre[0], pre[1]), pre[2]) + graph[1];
		maxdp[2] = max(pre[1], pre[2]) + graph[2];

		// 최소 구하기
		pre[0] = mindp[0];
		pre[1] = mindp[1];
		pre[2] = mindp[2];

		mindp[0] = min(pre[0], pre[1]) + graph[0];
		mindp[1] = min(min(pre[0], pre[1]), pre[2]) + graph[1];
		mindp[2] = min(pre[1], pre[2]) + graph[2];
	}

	cout << max(max(maxdp[0], maxdp[1]), maxdp[2]) << " " << min(min(mindp[0], mindp[1]), mindp[2]);

	return 0;
}