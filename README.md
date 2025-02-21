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
The CUDA implementation with atomic operations is significantly faster than the raw C implementation, attaining a speedup from 11720.4 ms to 63.63 ms due to the GPU's ability to handle parallel tasks efficiently. Atomic operations manage efficient simultaneous updates, Unified memory eliminates pesky data transfers. Prefetching optimizes data access by loading needed memory in advance, and memory advising helps optimize placement for faster execution. 

---
### **vi.) Discussion**
