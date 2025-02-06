// 브루트포스
#include <iostream>

using namespace std;

int n;
int suma = 1, sumb;
int ans = 2e9;
int a[10];
int b[10];

void dfs(int idx) {
    for (int i = idx + 1; i < n; i++) {
        suma *= a[i];
        sumb += b[i];
        ans = min(abs(suma - sumb), ans);
        dfs(i);
        suma /= a[i];
        sumb -= b[i];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    dfs(-1);

    cout << ans;
    return 0;
}