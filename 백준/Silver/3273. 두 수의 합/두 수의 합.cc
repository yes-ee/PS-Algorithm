#include <iostream>
#include <algorithm>

using namespace std;

int n, x, cnt;
int arr[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    sort(arr, arr + n);

    int st = 0;
    int end = n - 1;

    while (st < end) {
        int sum = arr[st] + arr[end];
        if (sum == x)
            cnt++;
        if (sum > x) {
            end--;
        } else {
            st++;
        }
    }

    cout << cnt;

    return 0;
}