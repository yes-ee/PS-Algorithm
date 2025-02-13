#include <iostream>

using namespace std;

int n, k;
int arr[7][2];
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s, y;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s >> y;
        arr[y][s]++;
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            ans += (arr[i][j] + k - 1) / k;
        }
    }
    cout << ans;

    return 0;
}