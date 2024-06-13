
#include <iostream>

using namespace std;

int t;
int sum[51];
int arr[4001];

int main() {
    cin >> t;
    
    for (int i = 1; i < 51; i++)
        sum[i] = sum[i - 1] + i;
        
    for (int i = 1; i < 51; i++) {
        for (int j = i; j < 51; j++) {
            for (int k = j; k < 51; k++) {
                arr[sum[i] + sum[j] + sum[k]] = 1;
            }
        }
    }
    
    while (t--) {
        int n;
        cin >> n;
        if (arr[n]) cout << "1\n";
        else cout << "0\n";
    }
    
    return 0;
}