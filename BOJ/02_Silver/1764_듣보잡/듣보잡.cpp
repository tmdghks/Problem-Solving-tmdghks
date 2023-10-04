#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    string tmp;
    cin >> n >> m;
    vector<string> v1, v2;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        v2.push_back(tmp);
    }

    stable_sort(v1.begin(), v1.end());
    stable_sort(v2.begin(), v2.end());

    vector<string> intersection;

    if (n > m) {
        for (int i = 0; i < n; i++) {
            if (binary_search(v2.begin(), v2.end(), v1[i])) intersection.push_back(v1[i]);
        }
    }
    else {
        for (int i = 0; i < m; i++) {
            if (binary_search(v1.begin(), v1.end(), v2[i])) intersection.push_back(v2[i]);
        }
    }

    cout << intersection.size() << '\n';
    stable_sort(intersection.begin(), intersection.end());
    for (int i = 0; i < intersection.size(); i++) {
        cout << intersection[i] << '\n';
    }
}