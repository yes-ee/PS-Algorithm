#include <iostream>

using namespace std;
int n, st;
int arr[50];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    st = arr[0];
    int midx = 1;
    while (1) {
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[midx]) {
                midx = i;
            }
        }
        if (arr[0] > arr[midx]) break;
        arr[0]++;
        arr[midx]--;
    }
    cout << arr[0] - st;

    return 0;
}