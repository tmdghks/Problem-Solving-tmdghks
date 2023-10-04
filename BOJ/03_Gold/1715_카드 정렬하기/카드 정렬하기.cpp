#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, tmp, cnt = 0, i, a, b;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pq.push(tmp);
    }

    while (pq.size() != 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        cnt += a + b;
        pq.push(a + b);
    }

    cout << cnt;

}