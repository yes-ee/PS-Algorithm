#include <iostream>

using namespace std;

int n;
char arr[201][201];

int main() {
    cin >> n;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            arr[j][i] = ' ';
    
    for (int j = 0; j < n; j++) {
        int st = n - j - 1;
        for (int i = 0; i < 2 * j + 1; i++) {
            arr[j][st + i] = '*';
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 2 * n - 1; i++)
            if (arr[j][i])
                cout << arr[j][i];
        cout << "\n";
    }

    return 0;
}