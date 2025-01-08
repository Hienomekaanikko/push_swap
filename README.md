# 🔢 Push Swap Project

## 🚀 Overview

Push Swap is an algorithmic challenge focused on sorting data with a limited set of operations, designed to test your skills in data manipulation, algorithm design, and efficient problem-solving.

## 📋 Project Objectives

- Sort a random set of integers using the minimum number of operations
- Implement a sorting algorithm with strict constraints
- Demonstrate mastery of linked list manipulation
- Optimize sorting strategy for different input scenarios

## 🛠️ Allowed Operations

### Stack Manipulation Commands

| Command | Description | Stack Impact |
|---------|-------------|--------------|
| `sa`    | Swap first two elements of stack A | A: [2, 1, 3] → [1, 2, 3] |
| `sb`    | Swap first two elements of stack B | B: [5, 3, 1] → [3, 5, 1] |
| `ss`    | Swap first two elements of both stacks | Simultaneous sa and sb |
| `pa`    | Push top element from B to A | B: [1, 2, 3] → [], A: [] → [1, 2, 3] |
| `pb`    | Push top element from A to B | A: [1, 2, 3] → [], B: [] → [1, 2, 3] |
| `ra`    | Rotate stack A up | A: [1, 2, 3] → [2, 3, 1] |
| `rb`    | Rotate stack B up | B: [1, 2, 3] → [2, 3, 1] |
| `rr`    | Rotate both stacks up | Simultaneous ra and rb |
| `rra`   | Reverse rotate stack A | A: [1, 2, 3] → [3, 1, 2] |
| `rrb`   | Reverse rotate stack B | B: [1, 2, 3] → [3, 1, 2] |
| `rrr`   | Reverse rotate both stacks | Simultaneous rra and rrb |

## 🧠 Key Challenges

- Implement an efficient sorting algorithm
- Minimize the number of operations
- Handle various input sizes and scenarios
- Optimize time and space complexity

## 📊 Performance Metrics

| Input Size | Maximum Allowed Operations |
|-----------|----------------------------|
| 3 numbers | ≤ 3 moves |
| 5 numbers | ≤ 12 moves |
| 100 numbers | ≤ 700 moves |
| 500 numbers | ≤ 5500 moves |

## 💡 Recommended Strategies

1. **Simple Sort** (3 numbers)
   - Direct comparison and swapping
   - Constant time complexity

2. **Radix Sort**
   - Efficient for larger datasets
   - O(d * (n + k)) complexity

3. **Quick Sort Variant**
   - Divide and conquer approach
   - Adaptive to input distribution

## 🛡️ Error Handling

- Validate input integers
- Check for duplicates
- Handle edge cases
- Provide clear error messages
