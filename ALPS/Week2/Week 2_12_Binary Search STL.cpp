#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 39, 102};
    int target = 39;
    binary_search(v.begin(), v.end(), target) ? cout << "target is in the vector" : cout << "target is not in the vector";
    target =40;
    binary_search(v.begin(), v.end(), target) ? cout << "target is in the vector" : cout << "target is not in the vector";
    return 0;
}