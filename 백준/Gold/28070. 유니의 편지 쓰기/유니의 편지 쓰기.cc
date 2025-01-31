// 스위핑
// 최대로 겹치는 수 구하기

#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
pii arr[200001];
int ans, cnt;
int mdate;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b;
    int y, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> y >> m;
        a = y * 100 - m;
        cin >> y >> m;
        m--;
        if (m == -13) {
            y++;
            m = -1;
        }
        b = y * 100 - m;
        arr[i] = {a, 1};
        arr[n + i] = {b, -1};
    }

    sort(arr, arr + 2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cnt += arr[i].second;
        if (cnt > ans) {
            mdate = arr[i].first;
            ans = cnt;
        }
    }

    cout << mdate / 100 << "-";
    if (mdate % 100 < 10) cout << "0";
    cout << mdate % 100;
    return 0;
}