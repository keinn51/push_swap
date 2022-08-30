## ✔️ push_swap

c언어로 구현한 정렬 알고리즘입니다. 일명 모래시계 알고리즘을 사용했습니다.

## ✔️ 목표

두 개의 stack (or queue or deque) 를 사용해서 최소한의 횟수로 정렬을 할 수 있도록 알고리즘을 만듭니다.

정렬을 해야 하는 숫자는 stack A 에 있습니다. 이 것을 stack B 를 사용해서 정렬하고 stack A로 보냅니다.

## ✔️ 할 수 있는 행동

- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

## ✔️ 사용 알고리즘

**모래시계** 알고리즘을 사용했습니다. 이 알고리즘은 아래와 같이 행동합니다.

- a스택에서 특정 범위보다 작은 숫자는 b의 first로 보냅니다.
- 범위 안에 있는 숫자는 b의 last로 보냅니다. 
- 범위 보다 큰 숫자는 a의 first에서 last로 보냅니다.

실제 예시를 가지고 설명해봅니다.

**stack A = [13, 9, 20, 40, 5, 33, 21, 5, 4, 3]**

<br>

### 1. 먼저 stackA로 들어오는 모든 숫자들을 인덱싱합니다.

- 이전 stack A = [13, 9, 20, 40, 5, 33, 21, 5, 4, 3]
- 이후 stack A = [6, 5, 7, 10, 4, 9, 8, 2, 1, 0]

<br>

### 2. chuck 를 구해둡니다. chunck 는 아래의 식으로 구합니다.

chunk는 a스택에서 b스택으로 넘길 때 기준이 되는 **범위의 폭**입니다.

<img width="681" alt="image" src="https://user-images.githubusercontent.com/79993356/186873556-4739cbf1-604b-4d2d-9319-6e21fc074833.png">

x가 정렬해야 하는 수의 개수이며, y가 chunk 입니다.

<br>

### 3. A를 순회합니다. 

#### index와 chunk를 이용해, stack A 의 크기를 기준으로 세 부분으로 나눕니다. 이 때 범위는, **(index) ~ (index + chunk)** 가 됩니다.

### 1) a_first ≤ index

- a의 first가 index 보다 작은 상황
- b의 맨 상단으로 옮김 (pb 1회)
- index++

### 2) iter < a_first ≤ index + chunk

- a의 first이 chunk 범위 안에 있는 상황
- b로 넘기고 넘긴값을 바닥으로 돌립니다
  - pb 1회
  - rb를 1회 (b의 맨 하단으로 옮김)
- index++

### 3) index + chunk < a_first

- a의 first이 너무너무 큰 상황
- 일단 거릅니다. (a의 맨 밑으로 넣습니다)
  - ra 1회 (a데크의 맨뒤로 보냄)

이 모든 것을 한 후에는 b스택에 마치 모래시계처럼 값이 쌓여 있습니다.

## ✔️ 정렬 결과

a에서 b스택으로 넘어갈 때 모래시계처럼 생겼다고 해서 모래시계 알고리즘입니다.

이제 b스택에서 a스택으로 넘어갈 때에는, b스택의 first와 last를 비교해갑니다.

두 값중 큰 값부터 a에 차곡차곡 쌓아주면 a스택의 정렬이 완성됩니다.

https://user-images.githubusercontent.com/79993356/187332226-bc07dbd2-0054-43ea-87d9-51639459ed22.mp4

