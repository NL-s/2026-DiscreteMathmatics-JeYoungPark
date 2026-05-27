# 04 · 부울 대수 (Boolean Algebra)

> **부울 대수**는 **명제 논리(Week 1)**를 *대수 시스템*으로 다시 본 것입니다. 같은 내용을 다른 옷을 입혀 본다고 생각하세요. 이 옷이 더 잘 어울리는 곳은 **디지털 회로 설계**입니다.

---

## 4.1 왜 부울 대수인가? — 컴퓨터 회로의 수학

### 핵심 관찰
컴퓨터의 모든 연산은 결국 **0과 1**의 조작입니다. CPU의 ALU(산술 논리 장치), 메모리 셀, 캐시 컨트롤러 — 전부 **두 값만** 처리.

여기에 대한 **수학적 도구**가 필요합니다. George Boole(1854)이 처음 제안, Claude Shannon(1937, 석사 논문!)이 **"전기 회로는 부울 대수로 모델링할 수 있다"**고 밝히면서 디지털 컴퓨터의 이론적 기반이 됩니다.

> Shannon의 석사 논문 *"A Symbolic Analysis of Relay and Switching Circuits"*는 **인류 역사상 가장 영향력 있는 석사 논문**으로 평가됩니다.

---

## 4.2 부울 대수의 정의

### 정의 4.1 (Boolean Algebra)
다음을 모두 갖춘 시스템 $(B, +, \cdot, ', 0, 1)$:
- $B$: 원소들의 집합 (보통 $\{0, 1\}$)
- $+$: 부울 합 (OR)
- $\cdot$: 부울 곱 (AND)
- $'$: 보수 (NOT, 위 첨자로도 표기: $\bar{x}$)
- $0, 1$: 항등원 (identity elements)

다음 **공리(axioms)**를 만족:

| 공리 | 식 |
|:--|:--|
| Identity | $x + 0 = x$, $x \cdot 1 = x$ |
| Complement | $x + x' = 1$, $x \cdot x' = 0$ |
| Commutative | $x + y = y + x$, $x \cdot y = y \cdot x$ |
| Distributive | $x + (y \cdot z) = (x+y) \cdot (x+z)$, $x \cdot (y+z) = x \cdot y + x \cdot z$ |

### Week 1 명제 논리와 1:1 대응

| 부울 대수 | 명제 논리 (Week 1) |
|:--:|:--:|
| $+$ (OR) | $\lor$ |
| $\cdot$ (AND) | $\land$ |
| $'$ (NOT) | $\neg$ |
| $0$ | F (거짓) |
| $1$ | T (참) |
| $x = y$ | $p \equiv q$ |

**중요**: 부울 대수에서는 보통 $\cdot$을 생략합니다. $x \cdot y$ 대신 $xy$.

---

## 4.3 핵심 항등식 (Boolean Identities)

Week 1의 *Logical Equivalences*가 그대로 옮겨옵니다.

| 이름 | 식 |
|:--|:--|
| **Identity** | $x + 0 = x$, $\quad x \cdot 1 = x$ |
| **Null (Domination)** | $x + 1 = 1$, $\quad x \cdot 0 = 0$ |
| **Idempotent** | $x + x = x$, $\quad x \cdot x = x$ |
| **Complement** | $x + x' = 1$, $\quad x \cdot x' = 0$ |
| **Double Complement** | $(x')' = x$ |
| **Commutative** | $x + y = y + x$, $\quad xy = yx$ |
| **Associative** | $x + (y + z) = (x + y) + z$ |
| **Distributive** | $x + yz = (x+y)(x+z)$, $\quad x(y+z) = xy + xz$ |
| **De Morgan** | $(x + y)' = x' y'$, $\quad (xy)' = x' + y'$ |
| **Absorption** | $x + xy = x$, $\quad x(x + y) = x$ |

### 주의 — 일반 대수와 다른 점

부울 대수의 **distributive law의 두 방향이 모두 성립**합니다:
- 보통 대수: $a(b+c) = ab + ac$ ✓, $a + bc \neq (a+b)(a+c)$ ✗
- 부울 대수: 둘 다 ✓ !

또, **거듭제곱 같은 개념이 없습니다**. $x \cdot x = x$ (idempotent)니까요.

---

## 4.4 진리표로 항등식 증명하기

부울 변수는 0 또는 1만 가지므로, **변수가 $n$개면 진리표 행이 $2^n$개**. 모든 경우를 다 검사하면 증명 끝.

### 예제 — De Morgan의 법칙 $(x+y)' = x' y'$ 증명

| $x$ | $y$ | $x+y$ | $(x+y)'$ | $x'$ | $y'$ | $x' y'$ |
|:---:|:---:|:-----:|:--------:|:----:|:----:|:-------:|
| 0 | 0 | 0 | **1** | 1 | 1 | **1** |
| 0 | 1 | 1 | **0** | 1 | 0 | **0** |
| 1 | 0 | 1 | **0** | 0 | 1 | **0** |
| 1 | 1 | 1 | **0** | 0 | 0 | **0** |

**$(x+y)'$ 열과 $x' y'$ 열이 일치** → 항등식 ✓

---

## 4.5 부울 함수 (Boolean Function)

### 정의 4.2
$n$개의 부울 변수를 받아 0 또는 1을 출력하는 함수:
$$
f: \{0, 1\}^n \to \{0, 1\}
$$

### 부울 함수의 개수
- $n$개 변수 → 입력 조합 $2^n$개
- 각 조합에 출력 0 또는 1 → 가능한 함수 수 $2^{2^n}$
- $n=2$이면 $2^4=16$개 ($\land, \lor, \oplus, \to, \uparrow, \downarrow, \dots$)
- $n=3$이면 $2^8 = 256$개

### 예제 — $f(x,y,z) = xy + x'z$의 진리표

| $x$ | $y$ | $z$ | $xy$ | $x'$ | $x'z$ | $f$ |
|:---:|:---:|:---:|:----:|:----:|:----:|:---:|
| 0 | 0 | 0 | 0 | 1 | 0 | **0** |
| 0 | 0 | 1 | 0 | 1 | 1 | **1** |
| 0 | 1 | 0 | 0 | 1 | 0 | **0** |
| 0 | 1 | 1 | 0 | 1 | 1 | **1** |
| 1 | 0 | 0 | 0 | 0 | 0 | **0** |
| 1 | 0 | 1 | 0 | 0 | 0 | **0** |
| 1 | 1 | 0 | 1 | 0 | 0 | **1** |
| 1 | 1 | 1 | 1 | 0 | 0 | **1** |

---

## 4.6 정규형 (Canonical Forms) — SOP와 POS

부울 함수는 **두 가지 표준 형태**로 항상 쓸 수 있습니다.

### 4.6.1 SOP (Sum of Products) — "최소항의 합"

#### 정의 4.3 (Minterm, 최소항)
$n$개 변수의 minterm = 모든 변수를 정확히 한 번씩 (그대로 또는 보수로) **곱**한 것.

$n=3$일 때 가능한 minterm 8개:
$$
x'y'z',\; x'y'z,\; x'yz',\; x'yz,\; xy'z',\; xy'z,\; xyz',\; xyz
$$

**핵심 성질**: minterm $m_i$는 **정확히 하나의 입력 조합**에서만 1이고 나머지는 모두 0.

#### SOP 구성법
$f$의 진리표에서 **출력이 1인 행**을 모두 찾고, 그 행의 minterm을 OR로 묶음.

#### 예제
위 $f(x,y,z) = xy + x'z$를 진리표에서 SOP로:

출력 1인 행: $(0,0,1), (0,1,1), (1,1,0), (1,1,1)$
$$
f = x'y'z + x'yz + xyz' + xyz
$$

이것이 **canonical SOP** 형태.

### 4.6.2 POS (Product of Sums) — "최대항의 곱"

#### 정의 4.4 (Maxterm, 최대항)
$n$개 변수의 maxterm = 모든 변수를 정확히 한 번씩 **합**한 것.

$n=3$일 때 8개: $(x+y+z), (x+y+z'), \dots$

**핵심 성질**: maxterm $M_i$는 **정확히 하나의 입력 조합**에서만 0이고 나머지는 1.

#### POS 구성법
$f$의 진리표에서 **출력이 0인 행**을 모두 찾고, 그 행의 maxterm을 AND로 묶음.

각 변수에 대해 **0이면 그대로, 1이면 보수**(SOP와 반대!).

#### 예제
위 함수에서 출력 0인 행: $(0,0,0), (0,1,0), (1,0,0), (1,0,1)$
$$
f = (x+y+z)(x+y'+z)(x'+y+z)(x'+y+z')
$$

### 4.6.3 SOP vs POS — 어느 쪽이 더 효율?

진리표의 1과 0 중 **적은 쪽**을 사용하는 게 보통 더 짧은 식을 만듭니다.

> **둘 다 정규형이므로 같은 함수**. 어떤 형태가 더 간결한가는 함수마다 다릅니다.

---

## 4.7 함수 단순화 (Simplification)

원본 SOP 식은 *길고 비효율적*입니다. 항등식을 써서 단순화 가능.

### 예제 — 위 SOP를 단순화

$$
f = x'y'z + x'yz + xyz' + xyz
$$

1. 앞 두 항에서 $x'z$ 공통:
$$
x'y'z + x'yz = x'z(y' + y) = x'z \cdot 1 = x'z
$$
2. 뒤 두 항에서 $xy$ 공통:
$$
xyz' + xyz = xy(z' + z) = xy \cdot 1 = xy
$$
3. 결과: $f = x'z + xy$

진리표 8행 vs 식 두 개 — **압도적 단순화**.

### 자동화 — 카르노 맵(K-map)으로

손으로 항등식을 적용하는 건 변수가 많아지면 비현실적. → **K-map** (다음 파일 [05](./05-logic-circuits-kmap.md)에서).

### Quine-McCluskey 알고리즘
변수가 4개 이상이면 K-map도 비현실적. 컴퓨터로 자동화하는 알고리즘이 있습니다 (참고 사항).

---

## 4.8 Week 1 회상 — 같은 문제, 같은 답

Week 1 PDF 10~12쪽의 예제를 부울 대수로 재해석:

> 요구사항: $f(A, C, P) = AC + A'CP + CP'$ ⇒ 단순화하면?

$$
f = AC + A'CP + CP' = C(A + A'P + P')
$$

분배:
$$
A + A'P + P'
$$

$A + A'P$에 **absorption variant** $X + X'Y = X + Y$ 적용:
$$
A + A'P = A + P
$$

그래서:
$$
A + A'P + P' = A + P + P' = A + 1 = 1
$$

결과: $f = C \cdot 1 = C$.

**똑같이 "활성 상태 C만 보면 된다"는 결론.** 표기만 다르고 본질은 같죠.

---

## 4.9 빠른 자기 점검

1. $x + xy$를 단순화하라.  
   <details><summary>답</summary>$x(1 + y) = x \cdot 1 = x$ (Absorption).</details>

2. $(x + y')'(x' + y)'$를 De Morgan으로 풀어 단순화.  
   <details><summary>답</summary>$(x+y')' = x'y$, $(x'+y)' = xy'$. 곱하면 $x'y \cdot xy' = (xx')(yy') = 0 \cdot 0 = 0$.</details>

3. 3변수 부울 함수의 개수는?  
   <details><summary>답</summary>$2^{2^3} = 256$개.</details>

4. 함수 $f(x,y) = x \oplus y$ (XOR)의 SOP 형태는?  
   <details><summary>답</summary>XOR은 (0,1)과 (1,0)에서만 1. ⇒ $f = x'y + xy'$.</details>

---

## 4.10 Python으로 부울 함수 다루기

```python
from itertools import product

def truth_table(f, n_vars):
    """함수 f의 진리표 출력"""
    print(' '.join(f'x{i}' for i in range(n_vars)) + ' | f')
    print('-' * (3 * n_vars + 4))
    for vals in product([0, 1], repeat=n_vars):
        print(' '.join(str(v) for v in vals) + ' | ' + str(f(*vals)))

# 예: f(x,y,z) = xy + x'z
def f(x, y, z):
    return (x and y) or (not x and z)

truth_table(f, 3)
```

또는 진리표에서 SOP 식 자동 생성:

```python
def sop_from_truth(table, var_names):
    """table: list of (input_tuple, output)
       var_names: ['x', 'y', 'z', ...]"""
    terms = []
    for inp, out in table:
        if out == 1:
            lits = []
            for v, name in zip(inp, var_names):
                lits.append(name if v else name + "'")
            terms.append(''.join(lits))
    return ' + '.join(terms) if terms else '0'

table = [((x,y,z), f(x,y,z)) for x,y,z in product([0,1], repeat=3)]
print(sop_from_truth(table, ['x','y','z']))
# 출력: x'y'z + x'yz + xyz' + xyz
```

---

➡️ 다음: [05-logic-circuits-kmap.md](./05-logic-circuits-kmap.md) — 부울 함수가 회로가 되고, K-map으로 단순화하는 방법.
