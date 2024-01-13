#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n;
int in[MAX];	//왼 가운데 오
int post[MAX];	//왼 오 가운데
int pre[MAX];	//가운데 왼 오

void re(int len, int left, int right, int idx)	//post의 마지막 인덱스 - 가운데
{
	// for (int i = 0; i < n; i++) {
	// 	if (in[i] == root)
	// 		idx = i;	//왼쪽 트리 나누기
	// }

	//왼쪽 트리
	re()
	//루트

	//오른쪽 트리

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> in[i];
	for (int i = 1; i <= n; i++)
		cin >> post[i];

	pre[1] = post[n];
}