// 17478: 재귀 함수가 뭔가요?
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<ll>>;
using ld = long double;
const ll mod = 1000000007;

void coutWithStuff(string& stuff, string toPrint) {
    cout << stuff << toPrint << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << "\n";
    for (ll i = 0; i < N; ++i) {
        string stuff((char) 4 * (char) i, '_');
        coutWithStuff(stuff, "\"재귀함수가 뭔가요?\"");
        coutWithStuff(stuff, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
        coutWithStuff(stuff, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
        coutWithStuff(stuff, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
    }

    string stuff(4 * N, '_');
    coutWithStuff(stuff, "\"재귀함수가 뭔가요?\"");
    coutWithStuff(stuff, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");

    for (int i = N; i >= 0; --i) {
        string stuff(4 * i, '_');
        coutWithStuff(stuff, "라고 답변하였지.");
    }
}