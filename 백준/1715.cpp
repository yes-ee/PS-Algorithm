//greedy

#include <iostream>
#include <queue>

using namespace std;

int n, ret;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    //최소 힙으로 구현된 priority_queue에 카드 묶음 크기 추가
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }

    while (pq.size() > 1) {
        //제일 작은 크기 두 개를 합쳐서 다시 추가
        int min1, min2;
        
        min1 = pq.top();
        pq.pop();
        
        min2 = pq.top();
        pq.pop();

        pq.push(min1 + min2);
        ret += min1 + min2;
    }

    cout << ret;
    return 0;
}