#include <iostream>
#include <algorithm>

using namespace std;
using pii=pair<int, int>;

int n, l;
int a, b;
pii arr[10001];
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = {a, b - 1};
    }

    sort(arr, arr + n);

    int st = arr[0].first;
    int ed, len;

    for (int i = 0; i < n; i++) {
        if (arr[i].second < st) continue;
        if (arr[i].first > st) st = arr[i].first;
        len = (arr[i].second - st + 1);
        ans += len / l;
        st = arr[i].second + 1;
        if (len % l) {
            ans++;
            st += (l - len % l);
        }
    }

    cout << ans;
    return 0;
}