#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    cout << dq.back() << '\n'; // 2
    dq.pop_back();
    cout << dq.back() << '\n'; // 1
    cout << dq.size() << '\n'; // 1
    cout << (dq.empty() ? "Deque is empty" : "Deque is not empty") << '\n'; // Deque is not empty

    dq.push_front(3);
    dq.push_front(4);
    cout << dq.front() << '\n'; // 4
    dq.pop_front();
    cout << dq.front() << '\n'; // 3
    return 0;
}