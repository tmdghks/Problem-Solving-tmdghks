// BOJ 15649 N과 M (1)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void backTracking(int depth, int n, int m, vector<bool> &v1, vector<int> &v2) {
    if (depth == m) {
        for (auto num : v2) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (v1[i] == true) continue;

        v1[i] = true;
        v2.push_back(i);
        backTracking(depth + 1, n, m, v1, v2);
        v1[i] = false;
        v2.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bool> v1(n + 1, false);
    vector<int> v2;
    
    backTracking(0, n, m, v1, v2);
}   