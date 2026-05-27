# Week 4–5 통합 강의: Trees & Boolean Algebra + Automata

> **이산수학(Discrete Mathematics) — 트리·부울대수·오토마타 통합 정리**
> 작성자: 박제영 (SeoulTech CS&CE) · 2026 봄학기

본 문서는 오프라인 강의를 대체하여, **트리(Trees)**, **부울 대수(Boolean Algebra)**, **오토마타(Automata)** 세 주제를 한 번에 학습할 수 있도록 묶은 자료입니다. 1~3주차에서 다뤘던 명제·집합·관계·그래프의 언어가 **어떻게 컴퓨터 과학의 핵심 추상기계로 발전하는지** 그 흐름을 따라가는 것이 목표입니다.

---

## 📚 학습 흐름 (Big Picture)

```
Week 1 ─ Logic ──┐
Week 2 ─ Sets ───┤
Week 3 ─ Relations ──┐
Week 5 ─ Graphs ─────┤
                     ▼
Week 4-5 ── Trees ──→ Boolean Algebra ──→ Automata
              (구조)        (계산)              (기계)
```

- **트리**: 그래프 중 가장 제약이 강하지만, 가장 자주 쓰이는 구조
- **부울 대수**: 명제 논리를 *대수* 시스템으로 일반화 → 디지털 회로의 수학적 기반
- **오토마타**: 부울/논리/집합/그래프가 모두 결합된 *추상 계산 기계*

---

## 🗂️ 목차

### Part 1 · Trees (트리)
| # | 파일 | 주제 |
|:--:|:--|:--|
| 01 | [01-trees-basics.md](./01-trees-basics.md) | 트리의 정의, 용어, 순회(traversal) |
| 02 | [02-bst-and-heap.md](./02-bst-and-heap.md) | 이진 탐색 트리(BST), 힙(Heap), Trie |
| 03 | [03-spanning-tree-mst.md](./03-spanning-tree-mst.md) | 신장 트리, 최소 신장 트리(Kruskal, Prim) |

### Part 2 · Boolean Algebra (부울 대수)
| # | 파일 | 주제 |
|:--:|:--|:--|
| 04 | [04-boolean-algebra.md](./04-boolean-algebra.md) | 부울 변수, 연산, 항등식, SOP/POS |
| 05 | [05-logic-circuits-kmap.md](./05-logic-circuits-kmap.md) | 논리 게이트, 회로, 카르노 맵(K-map) |

### Part 3 · Automata (오토마타)
| # | 파일 | 주제 |
|:--:|:--|:--|
| 06 | [06-automata-and-languages.md](./06-automata-and-languages.md) | 알파벳·문자열·언어, 형식 언어란? |
| 07 | [07-dfa.md](./07-dfa.md) | 결정적 유한 오토마타(DFA) |
| 08 | [08-nfa-equivalence.md](./08-nfa-equivalence.md) | 비결정적 유한 오토마타(NFA)와 DFA 변환 |
| 09 | [09-regex.md](./09-regex.md) | 정규 표현식과 Kleene 정리 |
| 10 | [10-pumping-lemma-chomsky.md](./10-pumping-lemma-chomsky.md) | 펌핑 보조정리, 촘스키 계층 |

### Part 4 · 실습 & 마무리
| # | 파일 | 주제 |
|:--:|:--|:--|
| 11 | [11-practice.md](./11-practice.md) | LeetCode 종합 실습 (해설 포함) |

---

## 🔧 학습 도구 안내

- **수식**: LaTeX 형식. 인라인은 `$...$`, 블록은 `$$...$$`로 작성되어 있어 GitHub에서 그대로 렌더링됩니다.
- **다이어그램**: Mermaid 사용 (GitHub 네이티브 지원).
- **코드**: Python 위주(LeetCode 친화), 일부 C++.
- **실습 정답**: 모든 해설은 `<details>` 토글로 감춰져 있습니다. 클릭해서 펼치세요.

<details>
<summary>📌 펼침 해설 예시 (클릭하여 열기)</summary>

이런 식으로 정답·풀이가 숨겨져 있습니다.  
**먼저 스스로 풀어본 뒤** 펼쳐서 확인하세요.

</details>

---

## ⚠️ 백준(BOJ) 대신 LeetCode 사용 안내

원래 강의 자료는 백준 온라인 저지(BOJ) 문제를 사용하지만, **현재 BOJ 사이트 접속 이슈로 LeetCode로 대체**합니다. 모든 실습 링크는 LeetCode의 무료 문제로 연결됩니다.

LeetCode 계정이 없어도 문제는 열람 가능하지만, 코드 제출·채점을 위해선 무료 가입을 추천합니다.

---

## 💡 학습 전략 (강의 시간이 없는 만큼)

1. **순서대로** 읽으세요. 각 섹션이 이전 섹션의 개념을 빌려갑니다.
2. **수식만 보지 말고** 코드 예제를 직접 타이핑·실행해 보세요.
3. **실습은 정답 보기 전에** 30분은 고민하기.
4. 막히는 부분은 강의 자료의 1~3주차 PDF를 다시 보면 대부분 풀립니다.
5. 질문은 언제든 환영: `recognize@seoultech.ac.kr`

---

> "이산수학은 추상의 도구 상자다. 트리·논리·기계 — 이번 두 주를 마치면 자료구조와 알고리즘, 컴파일러, 회로설계가 모두 같은 언어로 보이기 시작할 것이다."
