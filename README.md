## ✔️ push_swap

c언어로 구현한 정렬 알고리즘입니다. 일명 모래시계 알고리즘을 사용했습니다.

## ✔️ 목표

두 개의 stack (or queue or deque) 를 사용해서 최소한의 횟수로 정렬을 할 수 있도록 알고리즘을 만듭니다.

정렬을 해야 하는 숫자는 stack A 에 있습니다. 이 것을 stack B 를 사용해서 정렬하고 stack A로 보냅니다.

## ✔️ 사용 알고리즘

**모래시계** 알고리즘을 사용했습니다. 실제 예시를 가지고 설명해봅니다.

- stack A = [13, 9, 20, 40, 5, 33, 21, 5, 4, 3]

<br>

### 1. 먼저 stackA로 들어오는 모든 숫자들을 인덱싱합니다.

- 이전 stack A = [13, 9, 20, 40, 5, 33, 21, 5, 4, 3]
- 이후 stack A = [6, 5, 7, 10, 4, 9, 8, 2, 1, 0]

<br>

### 2. chuck 를 구해둡니다. chunck 는 아래의 식으로 구합니다.

<img width="681" alt="image" src="https://user-images.githubusercontent.com/79993356/186873556-4739cbf1-604b-4d2d-9319-6e21fc074833.png">

x가 정렬해야 하는 수의 개수이며, y가 chunk 입니다.

<br>

### 3. A를 순회합니다. 

#### index와 chunk를 이용해, stack A 의 크기를 기준으로 세 부분으로 나눕니다.

### 1) a_top ≤ index

- a의 top이 index 보다 작은 상황
- b의 맨 상단으로 옮김 (pb 1회)
- index++

### 2) iter < a_top ≤ index + chunk

- a의 top이 chunk 범위 안에 있는 상황
- b로 넘기고 넘긴값을 바닥으로 돌립니다
  - pb 1회
  - rb를 1회 (b의 맨 하단으로 옮김)
- index++

### 3) index + chunk < a_top

- a의 top이 너무너무 큰 상황
- 일단 거릅니다. (a의 맨 밑으로 넣습니다)
  - ra 1회 (a데크의 맨뒤로 보냄)
