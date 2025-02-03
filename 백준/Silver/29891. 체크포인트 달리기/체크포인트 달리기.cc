#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k;
ll sum;
ll arr[200001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int idx;
    for (idx = 0; idx < n; idx++) if (arr[idx] > 0) break;

    for (int i = n - 1; i >= idx; i -= k ) {
        sum += arr[i];
    }
    for (int i = 0; i < idx; i += k ) {
        sum -= arr[i];
    }

    cout << sum * 2;
    return 0;
}