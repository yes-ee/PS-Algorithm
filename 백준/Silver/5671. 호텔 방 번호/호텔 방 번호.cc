#include <iostream>
#include <set>
#include <string>

using namespace std;

int a, b, n, num, cnt, flag;
string s1, s2;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (getline(cin, s1, ' ')) {
        getline(cin, s2, '\n');
        a = stoi(s1);
        b = stoi(s2);
        cnt = 0;
        for (int i = a; i <= b; i++) {
            n = i;
            flag = 0;
            set<int> s;
            while (n) {
                num = n % 10;
                n /= 10;
                if (s.count(num)) {
                    flag = 1;
                    break;
                }
                s.insert(num);
            }
            if (!flag) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}