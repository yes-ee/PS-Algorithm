#include <iostream>
#include <string>

using namespace std;

int arr[1001][5001];
int n,m, k;
int ans;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)  {
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    int st = 0;
    int cnt = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            st = j;
            idx = j;
            if (arr[i][j] == 1) continue;
            while (idx < m) {
                if (arr[i][idx] == 1) break;
                idx++;
            }
            j = idx - 1;
            cnt = (idx - st + 1 - k);
            if (cnt > 0) ans += cnt;
        }
    }

    cout << ans;
    return 0;
}
