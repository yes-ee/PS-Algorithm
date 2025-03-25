#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int n;
int sarr[1000001];
int earr[1000001];
int chg[1000001];
int ed, ans = -1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;

    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        sarr[i] = s[i] - '0';
    }
    cin >> s;
    for (int i = 0; i < n; i++) {
        earr[i] = s[i] - '0';
    }

    // 0번 전구 누르는 경우
    for (int i = 0; i < n; i++) chg[i] = sarr[i];
    chg[0] = 1 - chg[0];
    chg[1] = 1 - chg[1];
    int cnt = 1;

    for (int i = 0; i < n - 2; i++) {
        if (earr[i] != chg[i]) {
            chg[i] = 1 - chg[i];
            chg[i+1] = 1 - chg[i+1];
            chg[i+2] = 1 - chg[i+2];
            cnt++;
        }
    }
    if (earr[n-2] != chg[n-2]) {
        chg[n-2] = 1 - chg[n-2];
        chg[n-1] = 1 - chg[n-1];
        cnt++;
    }
    if (chg[n-1] == earr[n-1]) {
        ed = 1;
        ans = cnt;
    }

    // 0번 전구 안 누르는 경우
    for (int i = 0; i < n; i++) chg[i] = sarr[i];
    cnt = 0;

    for (int i = 0; i < n - 2; i++) {
        if (earr[i] != chg[i]) {
            chg[i] = 1 - chg[i];
            chg[i+1] = 1 - chg[i+1];
            chg[i+2] = 1 - chg[i+2];
            cnt++;
        }
    }
    if (earr[n-2] != chg[n-2]) {
        chg[n-2] = 1 - chg[n-2];
        chg[n-1] = 1 - chg[n-1];
        cnt++;
    }

    if (chg[n-1] == earr[n-1]) {
        if (ed) ans = min(ans, cnt);
        else ans = cnt;
    }
    cout << ans;

    return 0;
}