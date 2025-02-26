#include <iostream>

using namespace std;
using ll = long long;

ll presum[250001];
ll arr[250001];
int n, x;
ll mx, cnt;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) presum[i] = presum[i-1] + arr[i];

    ll res;
    mx = presum[x];
    cnt = 1;
    for (int i = x + 1; i <= n; i++) {
        res = presum[i] - presum[i - x];
        if (res == mx) cnt++;
        else if (res > mx) {
            mx = res;
            cnt = 1;
        }
    }

    if (mx == 0) cout << "SAD";
    else {
        cout << mx << "\n";
        cout << cnt;
    }

    return 0;
}