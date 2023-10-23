// BOJ 15650 N과 M (2)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(int depth, int n, int m, int max, vector<int> v) {
    if (depth == m) {
        for (auto num : v) {
            cout << num << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = max + 1; i <= n; i++) {
        v.push_back(i);
        dfs(depth + 1, n, m, i, v);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v;
    dfs(0, n, m, 0, v);
}