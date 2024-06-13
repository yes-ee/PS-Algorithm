#include <iostream>
#include <string>

using namespace std;

int dice[7];
int ans, type;

string input;

int main() {
    cin >> input;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        if (!dice[a]) type++;
        dice[a]++;
    }
    
    for (int i = 0; i < 12; i++) {
        if (input[i] == 'N') continue;
        
        if (i < 6) {
            int cnt = dice[i + 1];
            ans = max(ans, (cnt + 2) * (i + 1));
        } else if (i == 6) {
            for (int j = 6; j > 0; j--) {
                if (dice[j] >= 2) {
                    ans = max(ans, j * 4);
                    break;
                }
            }
        } else if (i == 7) {
            int a = 0;
            int b = 0;
            
            if (type != 1 && type != 2) continue;
            
            for (int j = 6; j > 0; j--) {
                if (dice[j]) {
                    if (!a) {
                        a = j;
                    } else if (!b) {
                        b = j;
                    }
                }
            }
            if (type == 2) {
                ans = max(ans, a * 3 + b * 2);
            } else {
                ans = max(ans, a == 6 ? a * 3 + 10 : a * 3 + 12);
            }
        } else if (i == 8) {
            if (type != 3) continue;
            if (dice[6] == 0) ans = max(ans, 30);
        } else if (i == 9) {
            if (type != 3) continue;
            if (dice[1] == 0) ans = max(ans, 30);
        } else if (i == 10) {
            if (type != 1) continue;
            
            for (int j = 1; j < 7; j++) {
                if (dice[j] == 3) {
                    ans = 50;
                    break;
                }
            }
        } else {
            int sum = 0;
            for (int j = 1; j < 7; j++)
                sum += dice[j] * j;
            ans = max(ans, sum + 12);
        }
    }
    
    cout << ans;
    
    return 0;
}