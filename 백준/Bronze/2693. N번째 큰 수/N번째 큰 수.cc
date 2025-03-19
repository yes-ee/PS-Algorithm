#include <bits/stdc++.h>

using namespace std;

int t;
int arr[10];

int main() {
    cin >> t;
    while (t--) {
        for (int i = 0; i < 10; i++) cin >> arr[i];
        sort(arr, arr + 10);
        cout << arr[7] << "\n";
    }
    return 0;
}