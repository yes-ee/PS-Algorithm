#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000

using namespace std;

int t, n, ans, beginTime;
vector<pair<int, int>> arr;
int m[MAX], e[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int j = 0; j < t; j++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> e[i];
        }

        for (int i = 0; i < n; i++)
            arr.push_back(make_pair(-e[i], m[i]));

        sort(arr.begin(), arr.end());   //먹는 시간 역순으로 정렬

        for (int i = 0; i < n; i++) {
            beginTime += arr[i].second;  //시작 시간 = 앞에 거 데우는 시간 + 지금 거 데우는 시간
            ans = max(ans, beginTime - arr[i].first);   //먹는 데까지 걸리는 시간의 최대 구하기
        }
        
        cout << ans << "\n";
        arr.clear();
        ans = 0;
        beginTime = 0;
        for(int i = 0; i < n; i++) {
            m[i] = 0;
            e[i] = 0;
        }
    }
    return 0;
}
