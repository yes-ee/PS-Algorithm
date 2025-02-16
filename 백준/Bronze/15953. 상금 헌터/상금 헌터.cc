#include <iostream>

using namespace std;

int t;
int pa[101];
int pb[65];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    int a, b;
    pa[1] = 5000000;
    for (int i = 2; i < 4; i++) pa[i] = 3000000;
    for (int i = 4; i < 7; i++) pa[i] = 2000000;
    for (int i = 7; i < 11; i++) pa[i] = 500000;
    for (int i = 11; i < 16; i++) pa[i] = 300000;    
    for (int i = 16; i < 22; i++) pa[i] = 100000;
    pb[1] = 5120000;
    for (int i = 2; i < 4; i++) pb[i] = 2560000;
    for (int i = 4; i < 8; i++) pb[i] = 1280000;
    for (int i = 8; i < 16; i++) pb[i] = 640000;
    for (int i = 16; i < 32; i++) pb[i] = 320000;
    while (t--) {
        cin >> a >> b;
        cout << pa[a] + pb[b] << "\n";
    }
    return 0;
}