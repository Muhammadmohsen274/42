*This project has been created as part of the 42 curriculum by muali and adarabi.*

# Push_swap - Sorting Stack Data Efficiently

## Description
Push_swap is a custom sorting project that challenges students to sort a stack of integers using a limited set of stack operations and two stacks (`A` and `B`). The goal is to produce the shortest possible sequence of operations to sort the input in ascending order. 

This implementation includes four distinct sorting strategies selectable at runtime:
1. **Simple Sort ($O(n^2)$)**: A cost-efficient adaptation of Selection/Insertion Sort designed for small stacks (sizes $\le 5$) and low-disorder configurations.
2. **Medium Sort ($O(n\sqrt{n})$)**: A chunk-based partitioning sort that groups elements into $\sqrt{n}$ chunks, pushing them dynamically to Stack B and rotating to keep the stack semi-sorted.
3. **Complex Sort ($O(n \log n)$)**: A bitwise LSD (Least Significant Digit) Radix Sort adaptation designed for large or highly disordered inputs.
4. **Adaptive Sort (Default)**: Dispatches the sorting task to one of the above strategies based on the measured disorder metric of the initial stack.

---

## Group Contributions
This project was completed as a group project by the following contributors:

* **muali** (Login: `muali`):
  * Designed and implemented the circular doubly-linked stack data structures.
  * Coded the basic stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
  * Implemented the **Simple Sort ($O(n^2)$)** strategy and small stack sorting optimization.
  * Designed the **Disorder Metric** calculation and the **Adaptive Sort** strategy dispatcher.

* **adarabi** (Login: `adarabi`):
  * Designed and implemented the **Medium Sort ($O(n\sqrt{n})$)** chunk sort algorithm.
  * Coded the **Complex Sort ($O(n \log n)$)** bitwise Radix sort algorithm.
  * Created the argument parsing logic and input validation checks (for duplicates, formatting, and overflows).
  * Set up the Makefile compilation targets and the automated testing script.

---

## Instructions

### Compilation
Compile the program using the provided `Makefile`:
```bash
make
```

### Execution
Run the executable with a list of integers:
```bash
./push_swap 2 1 3 6 5 8
```

You can force a specific sorting strategy using the following selector flags:
* `--simple`: Force the $O(n^2)$ strategy.
* `--medium`: Force the $O(n\sqrt{n})$ strategy.
* `--complex`: Force the $O(n \log n)$ strategy.
* `--adaptive`: Force the default adaptive strategy.

### Benchmark Mode
Enable benchmark mode by adding the `--bench` flag:
```bash
./push_swap --bench 2 1 3 6 5 8
```
This prints operations to `stdout` and outputs key performance metrics to `stderr`:
* Computed disorder percentage.
* Dispatched strategy and complexity class.
* Total operation counts and a detailed breakdown of each instruction type.

---

## Sorting Algorithms

### 1. Simple Sort ($O(n^2)$)
* **Design**: Uses Selection Sort adaptation for stacks larger than 5, and hardcoded optimized sorts for sizes $\le 5$. It repeatedly extracts the minimum element of Stack A, rotates the stack using the shortest path to bring it to the top, and pushes it to Stack B.
* **Complexity**: Takes $O(n)$ pushes and up to $O(n^2)$ rotations, making it strictly $O(n^2)$ operations.

### 2. Medium Sort ($O(n\sqrt{n})$)
* **Design**: Splitting the $n$ elements into $\approx \sqrt{n}$ chunks allows pushing elements to Stack B in grouped ranges. Inside Stack B, we partition the chunk into two halves (smaller elements at the top, larger elements at the bottom) to keep it semi-sorted, minimizing the cost of finding the maximum element and rotating it back to Stack A.
* **Complexity**: Pushing to B takes $O(n)$ steps. Retrieving elements from B takes $O(n \sqrt{n})$ operations on average due to the semi-sorted structure.

### 3. Complex Sort ($O(n \log n)$)
* **Design**: A bitwise LSD Radix Sort. Numbers are mapped to their sorted rank indices ($0$ to $n-1$). For each bit position from $0$ to $\log_2(n)$, elements with a `0` at that bit are pushed to Stack B, and elements with a `1` are rotated. Stack B is then pushed back to Stack A.
* **Complexity**: Strictly $\log_2(n)$ passes, each doing $2n$ operations, resulting in a deterministic complexity of $O(n \log n)$ operations.

### 4. Adaptive Thresholds
The program calculates the **disorder metric** first:
$$\text{disorder} = \frac{\text{mistakes}}{\text{total\_pairs}}$$
Where a mistake is any pair $(i, j)$ such that $i < j$ and $a[i] > a[j]$.
* **Disorder < 0.2**: Uses Simple Sort ($O(n^2)$).
* **0.2 $\le$ Disorder < 0.5**: Uses Medium Sort ($O(n\sqrt{n})$).
* **Disorder $\ge$ 0.5**: Uses Complex Sort ($O(n \log n)$).

---

## Resources & AI Usage
* *Introduction to Algorithms* (CLRS) for complexity classes.
* AI was utilized as a pair programming assistant to implement Stack operations, debug stack rotation edge cases, and design the automated verification test script.
