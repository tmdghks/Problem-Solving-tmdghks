# [GOLD V] BOJ 11401 - 이항 계수 3

[문제 링크](https://boj.kr/11401)

### 분류

수학 (Mathematics), 정수론 (Number Theory), 조합론 (Combinatorics), 분할정복을 이용한 거듭제곱, 분할 정복을 이용한 거듭제곱 (Power by Divide and Conquer), 모듈로 곱셈 역원 (Modulo Inverse), 페르마의 소정리 (Fermat's Little Theorem)

### 풀이

조합을 순전히 전부 다 계산하게 되면 $O(n^2)$의 시간복잡도인데, $n<=4,000,000$이므로 시간 안에 해결이 불가능하다. 따라서, 팩토리얼과 그 역원을 구해 해결해야 한다. 팩토리얼을 구하는 데에는 $O(n)$이 소요되고, 모듈로 역원을 구하는 데에는 $O(logp)$가 소요된다. 또한, 나머지 모듈로 역원은 $(n - 1)!^{-1} = n * n!^{-1} \pmod p$를 이용하여 $O(n)$만에 구할 수 있다. 즉 $O(n + logp)$ 안에 해결 가능하다.