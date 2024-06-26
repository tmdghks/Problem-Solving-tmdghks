# [GOLD II] BOJ 7453 - 합이 0인 네 정수 [CLASS 5]

[문제 링크](https://boj.kr/7576)

### 분류

정렬, 투 포인터

### 풀이

시간 제한이 12초이고, 메모리 제한이 1024MB이므로, 조금 널널하게 풀어보자.

일단 투 포인터를 이용하기 위해 4개 배열 형태를 2개 배열 형태로 만들어보자.
A, B 배열과 C, D 배열에서 가능한 모든 합에 대한 배열을 새로 만든다.
그리고 이 배열에 대해 투포인터를 진행해주면 된다.

여기서 유의해아 하는 점은 문제에서 인덱스에 대한 순서쌍의 개수를 구하라고 했으므로, 중복을 포함한다는 점이다.
그렇기 때문에 0이 되는 경우에서 단순히 투 포인터를 조작하는 것이 아니라, 0이 될 수 있는 모든 경우의 수를 찾은 다음에 다음 포인터로 이동해야 한다.

이 부분은 투포인터 구현 부분에서 자세히 확인할 수 있다.

