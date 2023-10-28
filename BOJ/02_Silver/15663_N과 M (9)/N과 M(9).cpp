#include <bits/stdc++.h>

using namespace std;
using ll = long long;

set<vector<int>> ans;

void dfs(int depth, int n, int m, vector<int> v, vector<int> num_vec, vector<bool> visited) {
    if (depth == m) {
        ans.insert(v);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == true) continue;
        visited[i] = true;
        v.push_back(num_vec[i]);
        dfs(depth + 1, n, m, v, num_vec, visited);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int i, j;
    int n, m;
    cin >> n >> m;

    vector<int> v(n, 0);
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    stable_sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) {
        dfs(0, n, m, vector<int>(0, 0), v, vector<bool>(n, false));
    }

    for (auto v : ans) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << '\n';
    }
}