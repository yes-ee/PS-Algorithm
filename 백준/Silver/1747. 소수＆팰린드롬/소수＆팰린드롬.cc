#include <iostream>
#include <string>

using namespace std;

int n;
int arr[1004000];

int main() {

    for (int i = 2; i <= 1004000; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 1004000; j+=i) {
                arr[j] = 1;
            }
        }
    }

    cin >> n;
    
    if (n == 1) n++;

    for (int i = n; i <= 1004000; i++) {
        if (!arr[i]) {
            string s = to_string(i);
            int len = s.length();
            int flag = 0;
            for (int j = 0; j < len / 2; j++) {
                if (s[j] != s[len - j - 1]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                cout << s;
                return 0;
            }
        }
    }

    return 0;
}