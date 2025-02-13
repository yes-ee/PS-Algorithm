#include <iostream>

using namespace std;

int a, b;
int arr[21];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 20; i++) arr[i] = i;
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        int len = (b - a + 1);
        for (int i = 0; i < len / 2; i++) {
            swap(arr[a+i], arr[b-i]);
        }
    }
    for (int i = 1; i <= 20; i++) cout << arr[i] << " ";
    return 0;
}