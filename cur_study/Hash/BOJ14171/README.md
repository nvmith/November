## 사석훈
해시 문제,,, 딕셔너리로 풀면 쉽겠지 ㅎㅎ 라고 만만하게 봤다가 큰코 다쳤다.   
처음에 말도 안되게 3중 for문을 써보기도 했고 중복 값 처리에도 애를 먹었다.   
해시 문제의 중점은 키:값 을 어떤 것으로 정하는냐가 정말 중요하다고 생각하게 되었다.

## 지용주
기존에는 모든 쌍의 개수를 중복으로 계산한 뒤 마지막에 2로 나누어 보정했다.   
그러나, `k1 < k2` 조건을 추가하여 각 쌍이 오직 한 번만 계산되도록 로직을 개선했다.   
이를 통해 불필요한 중복 연산을 제거하고 코드를 더 명확하고 효율적으로 만들었다.

## 박강현
- 해시를 이용한 쌍 추적 방식 활용
   
도시와 코드를 조합하여 해시맵에 카운트를 기록하고, 이를 역방향으로 추적하는 방식으로 문제를 해결했다.   
처음에는 이 접근 자체가 굉장히 어렵게 느껴졌고, 문제를 푼 이후에도 입력과 동시에 처리하는 효율적인 방법을 고민했다.   
그 과정에서 더 나은 구현 방식을 발견해 코드를 리팩토링할 수 있었고, 이를 통해 해시 기반 사고의 중요성을 다시 한번 느꼈다.   

## 최이승우
기존에는 unordered_map<string, unordered_map<string, int>> 구조를 사용해 복잡하게 관리했지만, 2글자를 이어 붙인 문자열을 key로 사용하면 양방향 탐색도 간단해지고, 중복 카운트 없이 효율적으로 정답을 계산할 수 있어 단일 unordered_map<string, int>로 최적화했다.
