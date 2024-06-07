#include <iostream>

using namespace std;

int n, m, t;
int sum[5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while (t--) {
        cin >> n >> m;

        int a;
        for (int i = 0; i < n; i++)
            sum[i] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a;
                sum[j] += a;
            }
        }

        int win = 0;

        for (int i = 1; i < n; i++) {
            win = sum[i] > sum[win] ? i : win;
        }

        cout << win + 1 << "\n";
    }

    return 0;
}