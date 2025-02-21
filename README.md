# **Group 2 - DeepDive CUDA**
## **GROUP 2 - S11**

**MEMBERS:**

- Alfred Bastin S. Agustines
- Allan David C. De Leon
- Michael Angelo Depasucat
- Kai Hiori J. Padilla

---

## **Project Overview**
This project involves implementing and comparing the performance of two versions of a kernel:
1. **C Program**
2. **CUDA program w/ Unified memory, pre-fetching and memadvise**

The program initializes vectors of size `n = 2^28` 32-bit integers. Each kernel is executed 30 times, and the average execution time is recorded. Correctness is checked against the C program.

---
### **i.) Youtube Video**

---
### **ii.) Screenshot of the Program Output with execution time**
**C Execution Time**  

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/252feb7ff649c8556b1e3b1b5944f6ea615aef71/exec_times/c_time.png" alt="image alt" width="500"/>

**CUDA Execution Time**  

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/ca17d500afcea7afbcf1ded3e9e5712282da7a95/exec_times/cuda_time.png" alt="image alt" width="500"/>

---
### **iii.) Screenshot of the Program Output with correctness check (C)**

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/9324767d17656cb57332c09564ae6e22a9b3edfb/exec_times/c_code.png" alt="image alt" width="500"/>
This C program creates a large array of integers, groups them into 10 bins based on the remainder, and then measures the time necessary to compute the histogram.

---
### **iv.) Screenshot of the Program Output, including correctness check (CUDA)**

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/9324767d17656cb57332c09564ae6e22a9b3edfb/exec_times/cuda_code.png" alt="image alt" width="500"/>
This CUDA program uses Unified Memory, memadvise, and prefetching to build a histogram (modulo 10) using atomic operations, and then compares the output to a CPU-computed one.

---
### **v.) Comparative Table of Execution Time and Analysis of the Performance of the Kernel**

# Performance Comparison: C vs. CUDA (Atomic Operations)

| Implementation | Execution Time (ms) | Loops | Array Size |
|---------------|--------------------|-------|------------|
| **C (Raw)**   | 1172.04            | 30    | 268435456  |
| **CUDA (Atomic Operations)** | 63.63 | 30    | 268435456  |

## Analysis

When comparing raw C code with its counterpart that is implemented with atomic operations, it is clear that the raw C is significantly faster. This is expected, as atomic operations are designed to prevent race conditions, which introduces additional steps and increases execution time. We also created CUDA with no atomic operations which resulted in an error count this is due to multiple threads are accessing the same index in the resulting race condition.

Now comparing the CUDA implementation with the C implementation it's evident that the CUDA significantly outperforms both versions of C, attaining a speedup from 1172.04 and 2333.54 ms to 63.63 ms. This is because we are utilizing the GPU's strong suit, handling parallel tasks. The CUDA implementation also implements the three features: Unified Memory eliminates pesky data transfers, Prefetching improves data access by preparing necessary memory beforehand, and memory advising assists in optimizing data placement leading to a much faster execution time.

---
### **vi.) Discussion**

We had an "Aha!" moment when we compared the raw C with its atomic counterpart. We realized that the atomic operations slowed down the execution time because it is an added step that prevents race conditions.

We had another "Aha!" moment is when implemented a CUDA with no atomic operation. We could see that it was resulting in errors this is because race conditions are happening with some of the threads

And the last "Aha!" moment when we saw how CUDA's atomic operations and memory management techniques improved its performance compared to the raw C implementation. With the use atomic operations, it handled simultaneous updates to shared memory without race conditions. Unified Memory, Memory Prefetching, and Memory Advising were used, contributing to the CUDA program's reduced execution time.

We discovered that effective memory handling significantly speeds up execution. Additionally, atomic operations are essential in this specific application to utilize the GPU's parallel capabilities and prevent race conditions.


