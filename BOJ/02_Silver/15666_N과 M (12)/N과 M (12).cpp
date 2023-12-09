// 15666 N과 M (12)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void backTracking(int n, int m, vector<int> v, vector<int> input, int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    int last = 0;
    if (depth > 0)
        last = v[depth - 1];
    for (auto n : input) {
        if (n >= last) {
            v.push_back(n);
            backTracking(n, m, v, input, depth + 1);
            v.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> input(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    stable_sort(input.begin(), input.end());
    auto newEnd = unique(input.begin(), input.end());
    input.erase(newEnd, input.end());

    vector<int> v;
    backTracking(input.size(), m, v, input, 0);
}