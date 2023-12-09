// 1167 트리의 지름
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
    int n;
    int w;
};

void dfs(int n, int distance, vector<int>& visited, vector<vector<edge>>& g) {
    if (visited[n] != -1) return;
    visited[n] = distance;
    for (auto node : g[n]) {
        dfs(node.n, distance + node.w, visited, g);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i, j;
    int a, b, c;
    int n;
    cin >> n;

    vector<vector<edge>> g(n);

    int v, tmp1, tmp2;
    for (i = 0; i < n; i++) {
        cin >> v;
        while (true) {
            cin >> tmp1;
            if (tmp1 == -1) break;
            cin >> tmp2;
            g[v - 1].push_back({tmp1 - 1, tmp2});
            g[tmp1 - 1].push_back({v - 1, tmp2});
        }
    }

    vector<int> visited(n, -1);
    dfs(0, 0, visited, g);

    int max_index = 0;
    int max_distance = 0;
    for (int i = 0; i < n; i++) {
        if (max_distance < visited[i]) {
            max_distance = visited[i];
            max_index = i;
        }
    }

    vector<int> visited2(n, -1);
    dfs(max_index, 0, visited2, g);

    max_distance = 0;
    for (int i = 0; i < n; i++) {
        if (max_distance < visited2[i]) {
            max_distance = visited2[i];
        }
    }

    cout << max_distance;

    return 0;
}