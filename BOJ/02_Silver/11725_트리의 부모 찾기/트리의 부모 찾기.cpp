// 11725 트리의 부모 찾기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i, j, a, b, f;
    int n;
    cin >> n;
    vector<vector<int>> g(n);

    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    vector<int> parent(n, -1);    
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
        f = que.front();
        for (auto s : g[f]) {
            if (parent[s] != -1) {
                continue;
            }
            parent[s] = f;
            que.push(s);
        }
        que.pop();
    }

    for (i = 1; i < n; i++) {
        cout << parent[i] + 1 << '\n';
    }

    return 0;
}