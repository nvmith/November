## 지용주
재귀 조건과 종료 조건을 찾는 것이 비교적 쉬운 문제였다.
재귀 함수를 어떻게 구성하는 지에 따라 시간복잡도 차이가 천차만별이라는 것을 알았다. 최적화할 것이 딱히 없었다.

## 사석훈
처음엔 탑다운 방식으로 문자를 하나씩 더해 갔는데 시간 초과가 엄청 났었다. 그래서 바텀 업 방식으로 타겟 문자에서 빼가며 만들어갔다.   
와중에 시간초과가 계속 나서 최대한 빠르게 만들기 위해 슬라이싱을 단계별이 아니라 한번에 하는 방식으로 최적화를 진행 했다.   
아마 슬라이싱이 아니라 deque 로 만들어서 "".join 을 사용했으면 더 빠르지 않았을까?
