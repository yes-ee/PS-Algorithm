// 순열

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[7];
int ans[7];

void re(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        ans[cnt] = arr[i];
        re(i, cnt + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    re(0, 0);

    return 0;
}