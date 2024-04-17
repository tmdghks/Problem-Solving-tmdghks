#include <bits/stdc++.h>
using namespace std;
int main() {
    // 최대 우선순위 큐
    priority_queue<int> max_pq;
    // 최소 우선순위 큐
    priority_queue<int, queue<int>, greater<int>> min_pq;

    max_pq.push(1); max_pq.push(2); max_pq.push(3);
    cout << max_pq.top() << '\n';  // 3
    max_pq.push(1); max_pq.push(2); max_pq.push(3);
    cout << max_pq.top() << '\n';  // 1
    cout << max_pq.empty() << '\n';  // false

    max_pq.pop();
    cout << max_pq.top() << '\n';  // 2
}