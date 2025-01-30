#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n;
int sum;
pii arr[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr, arr + n);

    int l = arr[0].first;
    int r = arr[0].second;

    for (int i = 1; i < n; i++) {
        x = arr[i].first;
        y = arr[i].second;

        if (x <= r) r = max(r, y);
        else {
            sum += (r - l);
            l = x;
            r = y;
        }
    }
    sum += (r - l);

    cout << sum;

    return 0;
}