#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[1000001];
vector<int> v;
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        auto iter = lower_bound(v.begin(), v.end(), arr[i]);
        
        if (iter == v.end()) {
            v.push_back(arr[i]);
        } else {
            v[iter - v.begin()] = arr[i];
        }
    }

    cout << v.size();
    return 0;
}