#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int t;
int n, m;
int arr[1001][1001];
int sumrow[1001];
int sumcol[1001];
int a, b, c, d, v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];
        
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += arr[i][j];
            }
            sumrow[i] = sum;
        }

        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += arr[j][i];
            }
            sumcol[i] = sum;
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c >> d >> v;
            int rsum = (d - b + 1) * v;
            int csum = (c - a + 1) * v;
            for (int j = a; j <= c; j++) {
                sumrow[j] += rsum;
            }
            for (int j = b; j <= d; j++) {
                sumcol[j] += csum;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << sumrow[i] << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            cout << sumcol[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}