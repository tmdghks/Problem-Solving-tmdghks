# [GOLD V] BOJ 5430 - AC [CLASS 3]

[문제 링크](https://boj.kr/5430)

### 분류

구현(Implementation), 자료 구조 (Data Structure), 문자열(String), 파싱(Parsing), 덱(Deque)

### 풀이

명령어의 경우 문자열로 입력받아 각각의 알파벳마다 명령을 수행하는 방식을 사용한다.
다만, Reverse 명령어의 경우 Reverse 명령어를 입력받을 때마다 리스트 원소의 실제 위치를 바꾸면, 각 연산당 O(n)의 시간복잡도의 연산이 필요하다. 하지만, 단순히 Reverse bool을 통해 앞, 뒤에서 볼지 결정하기만 하면, O(1)의 시간복잡도로 문제를 해결할 수 있다.