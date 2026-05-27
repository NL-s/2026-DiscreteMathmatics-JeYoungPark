# 05 · 논리 게이트 · 회로 · 카르노 맵 (K-map)

> 부울 함수는 종이 위의 수식이 아니라 **실리콘 위의 트랜지스터**입니다. 이 챕터에선 부울 식을 **회로**로 옮기는 법, 그리고 **K-map**으로 회로를 작게 만드는 법을 배웁니다.

---

## 5.1 논리 게이트 (Logic Gates)

각 부울 연산자는 회로에서 **게이트(gate)**라는 물리 소자로 구현됩니다.

### 5.1.1 기본 게이트

| 게이트 | 기호 (식) | 진리표 | 회로 기호 |
|:--|:--:|:--|:--|
| **AND** | $x \cdot y$ | 둘 다 1일 때만 1 | `─D─` (D 모양) |
| **OR** | $x + y$ | 하나라도 1이면 1 | `─))─` (반달) |
| **NOT** | $x'$ | 반전 | `─▷○` (삼각형+버블) |

### 5.1.2 파생 게이트

| 게이트 | 식 | 의미 |
|:--|:--|:--|
| **NAND** | $(xy)'$ | NOT AND |
| **NOR** | $(x+y)'$ | NOT OR |
| **XOR** | $x \oplus y = x'y + xy'$ | Exclusive OR |
| **XNOR** | $(x \oplus y)' = xy + x'y'$ | XOR의 반전 (= "같으면 1") |

### 진리표 한 장 정리

| $x$ | $y$ | AND | OR | NAND | NOR | XOR | XNOR |
|:---:|:---:|:---:|:--:|:----:|:---:|:---:|:----:|
| 0 | 0 | 0 | 0 | 1 | 1 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 | 0 | 1 | 0 |
| 1 | 0 | 0 | 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 | 1 |

### 5.1.3 NAND·NOR의 **functional completeness**

놀라운 사실: **NAND 하나만으로 모든 부울 함수를 만들 수 있습니다.** (NOR도 마찬가지.)

증명 스케치:
- $x' = (x \cdot x)' = $ NAND$(x, x)$
- $x + y = (x'y')' = $ NAND$(x', y') = $ NAND(NAND$(x,x)$, NAND$(y,y))$
- $xy = (xy)'' = $ NOT(NAND$(x,y)$)

이 성질 덕에 **반도체 제조 시 NAND 게이트만 깔아도 모든 디지털 회로를 만들 수 있어** 제조 비용이 절감됩니다. 실제로 메모리 칩(SSD의 NAND 플래시)은 NAND를 활용합니다.

---

## 5.2 조합 논리 회로 (Combinational Circuits)

### 정의 5.1
**입력 → 게이트들의 그래프 → 출력**으로 구성된 회로. 출력이 현재 입력에만 의존 (메모리 없음). → 이게 **순차 회로(sequential)**와의 차이점.

### 예 — 반가산기(Half Adder)

두 1비트 수를 더하면? 결과는 $\{0,1,2\}$ → 2비트로 표현해야 함.
- **Sum bit** $S$: 결과의 LSB
- **Carry bit** $C$: 결과의 MSB (= 자리올림)

| $A$ | $B$ | $S$ | $C$ |
|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |

관찰:
- $S = A \oplus B$ (XOR)
- $C = AB$ (AND)

```
       A ─┬───── XOR ──── S
          │       │
       B ─┼───────┘
          │
          └─ AND ──── C
       B ────┘
```

### 예 — 전가산기(Full Adder)

3개 입력 (이전 carry $C_{in}$ 포함):

| $A$ | $B$ | $C_{in}$ | $S$ | $C_{out}$ |
|:---:|:---:|:--:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 |

식:
- $S = A \oplus B \oplus C_{in}$
- $C_{out} = AB + (A \oplus B) C_{in}$

n비트 가산기는 이걸 **체인으로 연결**하면 됩니다(ripple-carry adder). 현대 CPU는 carry-lookahead, prefix tree로 더 빠르게 만듭니다.

---

## 5.3 카르노 맵 (Karnaugh Map, K-map)

### 5.3.1 무엇인가?
부울 함수를 **2차원 격자**로 시각화 → **인접 1들을 묶어** 식을 단순화하는 그래픽 도구. Maurice Karnaugh(1953) 고안. 변수가 2~5개일 때 효과적, 그 이상은 컴퓨터 알고리즘 사용.

### 5.3.2 핵심 아이디어 — Gray Code 순서

K-map의 행과 열은 **인접 셀이 정확히 한 비트만 다른** 순서로 배치합니다 (Gray code).

3변수 K-map 레이아웃 ($f(x,y,z)$, $yz$가 열, $x$가 행):

| $x \backslash yz$ | 00 | 01 | 11 | 10 |
|:--:|:--:|:--:|:--:|:--:|
| **0** | $f(0,0,0)$ | $f(0,0,1)$ | $f(0,1,1)$ | $f(0,1,0)$ |
| **1** | $f(1,0,0)$ | $f(1,0,1)$ | $f(1,1,1)$ | $f(1,1,0)$ |

`00 → 01 → 11 → 10`은 Gray code. 인접한 두 칸이 변수 하나만 차이.

### 5.3.3 단순화 절차

1. 진리표로부터 K-map에 0/1을 채움
2. **1들을 사각형으로 묶기**: 크기는 1, 2, 4, 8, ... (2의 거듭제곱), 가로/세로/모서리(wrap) 모두 가능
3. 각 사각형이 **변수 하나를 제거**: 그룹 내에서 어떤 변수가 0/1 둘 다 나오면 그 변수는 사라짐
4. 그룹들을 OR로 묶음 → 최소 SOP

### 5.3.4 예제 — 3변수 함수

$f(x,y,z) = \sum m(1, 3, 6, 7)$ (출력 1인 minterm 번호)

K-map:

| $x \backslash yz$ | 00 | 01 | 11 | 10 |
|:--:|:--:|:--:|:--:|:--:|
| **0** | 0 | **1** | **1** | 0 |
| **1** | 0 | 0 | **1** | **1** |

그룹:
- **(0,01), (0,11)** = $x=0, z=1$ → $x'z$
- **(1,11), (1,10)** = $x=1, y=1$ → $xy$

결과: $f = x'z + xy$

이건 4.7절에서 손으로 풀었던 것과 정확히 같은 결과 ✓

### 5.3.5 4변수 K-map

| $wx \backslash yz$ | 00 | 01 | 11 | 10 |
|:--:|:--:|:--:|:--:|:--:|
| **00** | $m_0$ | $m_1$ | $m_3$ | $m_2$ |
| **01** | $m_4$ | $m_5$ | $m_7$ | $m_6$ |
| **11** | $m_{12}$ | $m_{13}$ | $m_{15}$ | $m_{14}$ |
| **10** | $m_8$ | $m_9$ | $m_{11}$ | $m_{10}$ |

**Wraparound**: 가장 왼쪽 열과 가장 오른쪽 열은 인접(원통처럼). 위쪽 행과 아래쪽 행도 인접.

### 5.3.6 Don't-care 조건

어떤 입력 조합이 **실제로는 발생하지 않는다**고 보장된다면, 그 셀에 `d` 또는 `X`를 적고 **편한 대로 0 또는 1로 사용**하여 더 큰 그룹을 만들 수 있습니다. → 더 작은 회로.

---

## 5.4 회로 단순화의 실용적 가치

| 지표 | 단순화 전 | 단순화 후 |
|:--|:--|:--|
| 게이트 수 | 많음 | 적음 |
| 칩 면적 | 큼 | 작음 |
| 소비 전력 | 큼 | 작음 |
| 전파 지연 | 김 | 짧음 |
| 비용 | 비쌈 | 쌈 |

> **K-map 단순화는 칩 설계 비용을 직접 줄입니다.** 1990년대까지는 손으로 했고, 지금은 EDA 소프트웨어(Synopsys, Cadence)가 자동으로 해줍니다 — 하지만 그 안에 K-map의 후예인 알고리즘이 돌아갑니다.

---

## 5.5 다중 출력 회로 — 디코더, 멀티플렉서

### 5.5.1 디코더 (Decoder)
$n$비트 입력 → $2^n$개 출력 중 정확히 하나만 1. 메모리 주소 디코딩에 필수.

```
입력 (x1, x0):
  00 -> Y0=1, Y1=0, Y2=0, Y3=0
  01 -> Y0=0, Y1=1, Y2=0, Y3=0
  10 -> Y0=0, Y1=0, Y2=1, Y3=0
  11 -> Y0=0, Y1=0, Y2=0, Y3=1
```

### 5.5.2 멀티플렉서 (MUX)
$2^n$개 데이터 입력과 $n$개 선택 입력 → 출력 1개. 선택 신호에 따라 그 데이터를 통과.

`if-else`의 회로 버전. CPU의 데이터 경로 곳곳에 있습니다.

---

## 5.6 부울 대수 ↔ 프로그래밍 — 한 줄로 정리

| 부울 대수 | C/Python |
|:--|:--|
| $x \cdot y$ | `x & y` (비트), `x and y` (논리) |
| $x + y$ | `x \| y` (비트), `x or y` (논리) |
| $x'$ | `~x` (비트), `not x` (논리) |
| $x \oplus y$ | `x ^ y` |
| $(xy)'$ | `~(x & y)` |
| if 조건 단순화 | 같은 작업! |

### 코드 단순화 예시 (Week 1 PDF 재방문)

```python
# BEFORE — 복잡한 조건
if ((isAdmin and isActive) or
    (not isAdmin and isActive and isPremium) or
    (isActive and not isPremium)):
    grant_access()

# AFTER — K-map / 부울 항등식으로 단순화
if isActive:
    grant_access()
```

> **부울 대수는 코드 리팩토링의 수학적 도구입니다.**

---

## 5.7 빠른 자기 점검

1. NAND 두 개만으로 NOT을 만드는 법?  
   <details><summary>답</summary>$(x \cdot x)' = $ NAND$(x, x) = x'$. 한 개로도 됨!</details>

2. 4비트 카르노 맵의 wraparound — $m_0$과 $m_8$이 한 그룹이 될 수 있나?  
   <details><summary>답</summary>가능. 둘 다 $w=*, x=0, y=0, z=0$ → $x'y'z'$ ($w$ 제거). 첫 행과 마지막 행이 인접하기 때문.</details>

3. $f(x,y) = x'y + xy = ?$  
   <details><summary>답</summary>$y(x' + x) = y \cdot 1 = y$. 합치면 $x$가 사라지고 $y$만 남음.</details>

4. XOR 게이트의 함수 식은?  
   <details><summary>답</summary>$x \oplus y = x'y + xy'$. SOP 형태.</details>

---

## 5.8 실습 예제 — LeetCode

> 부울 연산은 LeetCode에서 **비트 연산** 문제로 자주 등장합니다.

### 🔰 [LeetCode 191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

> 정수의 이진 표현에서 1의 개수를 세시오 (popcount).

<details>
<summary>풀이 보기</summary>

```python
class Solution:
    def hammingWeight(self, n):
        count = 0
        while n:
            n &= n - 1   # 최하위 1비트 제거 트릭
            count += 1
        return count
```

**해설**: `n & (n-1)`은 가장 오른쪽의 1을 0으로 만듭니다 (부울 대수의 응용). 1의 개수만큼만 루프.
</details>

### 🔰 [LeetCode 136. Single Number](https://leetcode.com/problems/single-number/)

> 어떤 원소가 정확히 한 번, 나머지는 모두 두 번씩 나타나는 배열에서 그 원소를 찾으시오.

<details>
<summary>풀이 보기 (XOR 마법)</summary>

```python
class Solution:
    def singleNumber(self, nums):
        result = 0
        for n in nums:
            result ^= n
        return result
```

**해설**: XOR의 성질:
- $x \oplus x = 0$ (자기 자신과 XOR하면 0)
- $x \oplus 0 = x$
- 결합·교환 법칙 성립

배열 전체를 XOR하면 두 번 나오는 것들은 서로 상쇄(0이 됨), 한 번 나오는 것만 남습니다. **$O(n)$ 시간, $O(1)$ 공간**.

이 풀이는 **부울 대수 (XOR의 대수적 성질)**가 실용 알고리즘의 핵심임을 보여주는 명장면.
</details>

### 🥈 [LeetCode 137. Single Number II](https://leetcode.com/problems/single-number-ii/)

> 한 원소는 한 번, 나머지는 **세 번씩** 나타날 때. 그 원소는?

<details>
<summary>풀이 보기 (3진 부울 카운터)</summary>

```python
class Solution:
    def singleNumber(self, nums):
        ones = twos = 0
        for n in nums:
            ones = (ones ^ n) & ~twos
            twos = (twos ^ n) & ~ones
        return ones
```

**해설**: 각 비트 위치마다 "지금까지 1이 들어온 횟수 mod 3"을 추적. `ones`는 횟수가 1인 비트, `twos`는 횟수가 2인 비트. 둘 다 0이면 횟수가 0 또는 3. 카르노 맵으로 식을 유도할 수 있습니다.

이 문제는 **부울 함수 설계**의 정수입니다.
</details>

### 🥈 [LeetCode 1342. Number of Steps to Reduce a Number to Zero](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero-to-zero/)

> 짝수면 2로 나누고, 홀수면 1을 빼서 0까지 만드는 데 필요한 step 수.

<details>
<summary>풀이 보기</summary>

```python
class Solution:
    def numberOfSteps(self, num):
        steps = 0
        while num:
            if num & 1:
                num -= 1
            else:
                num >>= 1
            steps += 1
        return steps
```

**보너스**: `bin(num).count('1') + num.bit_length() - 1` (마지막 1비트는 빼기만으로 끝나기 때문에 -1).
</details>

### 🥇 [LeetCode 201. Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

> $[m, n]$ 범위의 모든 정수를 AND한 결과는?

<details>
<summary>풀이 보기 (공통 prefix)</summary>

```python
class Solution:
    def rangeBitwiseAnd(self, m, n):
        shift = 0
        while m < n:
            m >>= 1
            n >>= 1
            shift += 1
        return m << shift
```

**해설**: 범위 내 AND는 결국 $m$과 $n$의 **공통 비트 prefix**만 남습니다. 이건 부울 대수의 흡수·domination 법칙들의 결과: 범위 내에서 그 비트가 0이 되는 순간 모두 0.
</details>

---

➡️ 다음: [06-automata-and-languages.md](./06-automata-and-languages.md) — 이제 진짜 *기계*로 들어갑니다.
