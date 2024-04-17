#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 39, 102};
    int target = 40;
    auto it = lower_bound(v.begin(), v.end(), target);
    if (it != v.end() && *it == target) {
        cout << "Target found at index: " << distance(v.begin(), it) << '\n';
    } else {
        cout << "Target not found" << endl;
    }
}