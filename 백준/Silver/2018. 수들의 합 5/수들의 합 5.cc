#include <iostream>

using namespace std;

int n, cnt = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int st = 1;
    int end = 2;
    int len = 2;

    while (end < n) {
        int sum = (st + end) * len / 2;

        if (sum == n) {
            cnt++;
            end++;
            len++;
        } else if (sum > n) {
            st++;
            len--;
        } else {
            end++;
            len++;
        }
    }

    cout << cnt;

    return 0;
}