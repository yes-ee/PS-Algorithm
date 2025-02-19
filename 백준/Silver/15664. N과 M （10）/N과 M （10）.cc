// 순열

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int ans[8];

void re(int idx, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = idx + 1; i < n; i++) {
        if (i != 0) {
            int ac = 0;
            int same = 0;
            for (int j = 0; j < i; j++) {
                if (arr[j] == arr[i]) same++;
            }
            for (int j = 0; j < cnt; j++) {
                if (ans[j] == arr[i]) ac++;
            }
            if (same != ac) continue;
        } 
        ans[cnt] = arr[i];
        re(i, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    re(-1, 0);

    return 0;
}