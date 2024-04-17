#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    queue<int> q;
    q.push(1);
    q.push(2);
    cout << "Queue size: " << q.size() << '\n';    // 2
    cout << "Queue front: " << q.front() << '\n';  // 1
    q.pop();
    cout << "Queue size: " << q.size() << '\n';    // 1
    cout << "Queue front: " << q.front() << '\n';  // 2
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << '\n'; // Queue is not empty
}