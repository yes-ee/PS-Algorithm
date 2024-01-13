#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void re(int st, int end) {
	int idx = st + 1;

	// 잘못된 서브 트리일 경우 리턴
	if (st > end)
		return;

	// 오른쪽 서브 트리 시작 지점 찾기
	while (1) {
		if (idx > end)
			break;
		if (v[idx] > v[st])
			break;
		idx++;
	}

	re(st + 1, idx - 1);	// 왼쪽 서브 트리 탐색
	re(idx, end);	// 오른쪽 서브 트리 탐색

	cout << v[st] << "\n";	// 루트 값 출력
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a;

	while (cin >> a) {
		v.push_back(a);
	}

	re(0, v.size() - 1);

	return 0;
}