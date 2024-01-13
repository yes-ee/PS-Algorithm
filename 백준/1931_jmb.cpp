// n개의 회의, 겹치지 않으면서 사용할 수 있는 회의 최대 개수 구하기
// 1. 전체 탐색
// - 탐색 개수 2^n -> n이 31 넘어가면 시간 초과
// 2. 그리디
// - 제일 먼저 끝나는 것부터 선택
// 증명
// (1) 탐욕적 선택 속성
//  - 각 단계에서 선택한 방법을 포함하는 최적해가 있음을 증명
//  - 최적해 중 smin(종료 시간이 가장 빠른 회의)를 포함하지 않는 최적해가 있다고 가정
//  - 이 목록에서 제일 빨리 끝나는 회의 대신 smin을 넣어도 최적해가 됨
//  - 성립
// (2) 최적 부분 구조
//  - 항상 최선의 선택을 내리는 방식으로 전체 문제의 최적해를 얻을 수 있음을 증명
//  - 첫 번째 회의를 선택했으면 남은 회의에서도 가장 많이 할 수 있는 회의를 선택해야 함
// 3. dp

//그리디
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000

using namespace std;

int n, cnt, etime;
vector<pair<int, int>> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr.push_back(make_pair(e, s));	//(끝나는 시간, 시작 시간) 순으로 입력
	}

	sort(arr.begin(), arr.end());	//끝나는 시간 기준 정렬

	etime = arr[0].first;
	cnt++;

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].second < etime)
			continue;
		etime = arr[i].first;
		cnt++;
	}

	cout << cnt;

	return 0;
}

//dp
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #define MAX 100000

// using namespace std;

// int n;
// vector<pair<int, int>> arr;
// int before[MAX];	//idx번 회의 시작 전에 끝나는 마지막 회의의 번호
// int dp[MAX];	//각 idx별 최대 회의 수

// int schedule(int idx) {
// 	if (idx == -1)
// 		return 0;
// 	if (dp[idx])	//이전에 계산한 값이 존재하는 경우 저장된 값 리턴
// 		return dp[idx];

// 	return dp[idx] = max(schedule(idx - 1), 1 + schedule(before[idx]));
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		int s, e;
// 		cin >> s >> e;
// 		arr.push_back(make_pair(e, s));	//(끝나는 시간, 시작 시간) 순으로 입력
// 	}

// 	sort(arr.begin(), arr.end());	//끝나는 시간 기준 정렬

// 	//before 배열 설정
// 	for (int i = 0; i < n; i++)
// 		before[i] = -1;

// 	for (int i = 1; i < n; i++) {
// 		for (int j = i - 1; j >= 0; j--) {
// 			if (arr[j].first > arr[i].second)
// 				continue;
// 			before[i] = j;
// 			break;
// 		}
// 	}

// 	dp[0] = 1;
// 	cout << schedule(n - 1);

// 	return 0;
// }