#include <iostream>
#include <algorithm>

using namespace std;

int m, n, cnt;
int arr[15000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int st = 0;
    int end = n - 1;

    while (st < end) {
        int sum = arr[st] + arr[end];

        if (sum == m) {
            cnt++;
            st++;
            end--;
        } else if (sum < m) {
            st++;
        } else {
            end--;
        }
    }

    cout << cnt;

    return 0;
}