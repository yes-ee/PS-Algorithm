#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, ans;
vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, 0});
    }

    sort(v.begin(), v.end());
    int cnt = 0;

    for (auto i : v) {
        int lo = i.first;
        int cond = i.second;

        if (cond) cnt++;
        else cnt--;

        ans = max(cnt, ans);
    }

    cout << ans;
    return 0;
}
