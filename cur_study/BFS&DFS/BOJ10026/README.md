## 박강현
- bfs 함수화 및 메모리 구조 개선
- 코드의 가독성 향상<br><br>
실행했을 때 시간 자체는 0ms로 성능에 문제는 없었다. 다만, 적록색약을 구분하기 위해 두 개의 배열을 사용했는데,
이는 메모리 사용 측면에서 비효율적이라 판단하여 하나의 배열로 통합을 진행하였다.<br>
또한 int가 아닌 char 타입으로도 무리가 없다 판단하여 자료형을 변경하여 메모리 사용을 절감<br>
기존에는 일반과 적록색약 BFS를 따로 구현했으나 하나의 char 배열을 이용하여 BFS도 함수를 재사용하여 코드의 중복을 줄이고 개선함
