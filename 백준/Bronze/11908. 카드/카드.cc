#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int arr[2222];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans += arr[i];
    }

    sort(arr, arr + n);
    cout << ans - arr[n-1];
    return 0;
}