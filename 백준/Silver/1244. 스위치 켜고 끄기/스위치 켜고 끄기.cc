#include <bits/stdc++.h>

using namespace std;
using pii=pair<int, int>;
using ll=long long;

int n;
int arr[101];
int p;
int gen, num;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cin >> p;
    while (p--) {
        cin >> gen >> num;
        if (gen == 1) { // 남자
            for (int i = num; i <= n; i += num) {
                arr[i] = 1 - arr[i];
            }
        } else { // 여자
            arr[num] = 1 - arr[num];
            int a = num - 1;
            int b = num + 1;
            while (a >= 1 && b <= n) {
                if (arr[a] != arr[b]) break;
                arr[a] = 1 - arr[a];
                arr[b] = 1 - arr[b];
                a--;
                b++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }

    return 0;
}