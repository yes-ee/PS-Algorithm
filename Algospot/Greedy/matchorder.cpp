// multiset erase할 때 erase(*iter) 과 erase(iter)의 차이점이 뭘까..?

#include <iostream>
#include <algorithm>
#include <set>
#define MAX 100

using namespace std;

int c, n;

int main() {
	cin >> c;
	for (int i = 0; i < c; i++) {
		int cnt = 0;
		int r[MAX];
		multiset<int> k;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> r[i];
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			k.insert(input);
		}
		for (int i = 0; i < n; i++)
		{
			auto it = k.lower_bound(r[i]);
			if (it != k.end())
			{ // 상대 선수의 레이팅보다 높은 레이팅이 있으면
				k.erase(it);
				cnt++;
			}
			else // 상대 선수의 레이팅보다 높은 선수가 없으면 제일 작은 값 삭제
			{
				k.erase(k.begin());
			}
		}
		cout << cnt << "\n";
	}
}