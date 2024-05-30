#include <iostream>
#include <algorithm>

using namespace std;
using ll=long long;

int n, cnt;
ll arr[2000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int st = 0;
        int end = n - 1;
        int x = arr[i];

        while (st < end) {
            if (st == i) {
                st++;
                continue;
            } else if (end == i) {
                end--;
                continue;
            }

            ll sum = arr[st] + arr[end];

            if (sum == x) {
                cnt++;
                break;
            } else if (sum < x) {
                st++;
            } else {
                end--;
            }
        }
    }

    cout << cnt;

    return 0;
}