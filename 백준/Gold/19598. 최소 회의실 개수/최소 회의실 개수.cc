// 스위핑
// 겹치는 최대 회의실 개수 구하기

#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
pii arr[200001];
int ans, cnt;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = {a, 1};
        arr[n + i] = {b, -1};
    }

    sort(arr, arr + 2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cnt += arr[i].second;
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}