// 우선순위 큐
// 최대 힙으로 구현되어 있음
// 최대 힙 : 부모 노드가 자식 노드보다 값이 큰 완전 이진 트리
// -> 삽입, 삭제 O(logn)에 해결 가능

#include <iostream>
#include <queue>

using namespace std;

int c, n, ret;

int main() {
    cin >> c;
    while (c--) {
        ret = 0;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>>pq;

        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            pq.push(input);
        }

        while (pq.size() > 1) {
            int min1, min2;
            
            min1 = pq.top();
            pq.pop();
            min2 = pq.top();
            pq.pop();

            pq.push(min1 + min2);
            ret += min1 + min2;
        }
        pq.pop();
        cout << ret << "\n";
    }
    return 0;
}