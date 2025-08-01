## 박강현
- 2차원 누적합
   
2차원 누적합이 등장해서 어떻게 접근해야 할지 고민을 많이 했다. 처음 문제를 풀었을 때는 중복된 계산을 제거하지 못해 시간이 오래 걸렸다.   
이후 관점을 바꿔 x, y, i, j로 구간을 나누고, x, y와 i, j 사이의 관계를 활용해 -1을 적용하는 방식으로 누적합을 계산하여 문제를 해결할 수 있었다.


## 사석훈
파이썬으로 풀었더니 시간초과 말고는 안나와서 pypy로 넣었더니 풀렸다.   
이에 관련해서 찾아보니 파이썬으로 풀 때는 카데인 알고리즘을 이용해서 풀지 않으면 안되는 것 같았다.   
그래서 잠깐 카데인 알고리즘에 대해서 공부를 했다.   
2차원 리스트에서 1차원 간격으로 최댓값을 구해 1차원 리스트로 만들어 둔 뒤 그 리스트 안에서 다시 최댓값을 구하는 방식 같았다.   
아직 잠깐 공부한 거라 완벽하지 않아 나중에 더 공부해 보아야겠다.


## 지용주
누적합만을 이용해서 풀면 파이썬으로는 시간초과가 났다.   
이를 해결하기 위해서는 카데인 알고리즘을 사용하여 차원압축하는 작업이 필요했다. 


## 최이승우
2차원으로 확장된 문제지만, 본질은 이전의 1차원 문제와 크게 다르지 않았다.   
처음에는 4중 for문을 이용해 완전탐색 방식으로 해결했지만, 실제로는 시간 복잡도를 줄이기 위해 카데인 알고리즘을 활용한 최적화가 가능하다.   
다만 이번 문제의 주제와는 맞지 않아 적용하지 않았으며, 추후 DP 주제에서 다시 등장한다면 그때 더 깊이 공부해볼 예정이다.
