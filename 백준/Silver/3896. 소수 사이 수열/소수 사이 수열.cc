#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int prime[1300000];
vector<int> v;
int t, k;

// 소수 집합 구하기
void getPrime() {
    for (int i = 2; i < 1299709; i++) {
        if (prime[i]) continue;
        for (int j = i * 2; j < 1299709; j+= i) {
            prime[j] = 1;
        }
    }

    for (int i = 2; i <= 1299709; i++) {
        if (!prime[i]) v.push_back(i);
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    getPrime();
    while (t--) {
        // get length
        cin >> k;
        if (!prime[k]) {
            cout << "0\n";
            continue;
        }
        
        auto it = lower_bound(v.begin(), v.end(), k);
        cout << *(it) - *(it - 1) << "\n";
    }

    return 0;
}