#include <algorithm>
#include <iostream>
#define MAX 50

using namespace std;

int n, s;
int a[MAX];
int b[MAX];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a, a + n, greater<int>());
    sort(b, b + n, [](int c, int d){
        return c < d;
    });

    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }

    cout << s;

    return 0;
}
