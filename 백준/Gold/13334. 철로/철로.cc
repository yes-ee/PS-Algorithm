#include <iostream>
#include <algorithm>

using namespace std;
using pii=pair<int, int>;
using ll = long long;

ll n, d;
int s[100001];
int e[100001];
pii arr[100001];
pii earr[100001];
int sidx, eidx, pre, st;
int cnt, ans;
ll l, r;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        arr[i] = {a, b};
    }
    cin >> d;

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        earr[i] = {arr[i].second, i};
    }

    sort(earr, earr + n);

    for (int i = 0; i < n; i++) {
        while (pre < i) {
            s[pre] = 0;
            if (e[pre]) cnt--;
            pre++;
        }
        st = pre;
        while (i < n - 1) {
            if (arr[i + 1].first != arr[st].first) break;
            s[i] = 1; i++;
        }

        l = arr[i].first;
        r = l + d;
        while (sidx < n) {
            if (arr[sidx].first > r) break;
            s[sidx] = 1; sidx++;
        }
        while (eidx < n) {
            if (earr[eidx].first > r) break;
            int idx = earr[eidx].second;
            if (s[idx]) cnt++;
            e[idx] = 1; eidx++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}