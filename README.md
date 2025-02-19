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

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/ca17d500afcea7afbcf1ded3e9e5712282da7a95/exec_times/c_time.png" alt="image alt" width="500"/>

**CUDA Execution Time**  

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/ca17d500afcea7afbcf1ded3e9e5712282da7a95/exec_times/cuda_time.png" alt="image alt" width="500"/>

---
### **iii.) Screenshot of the Program Output with correctness check (C)**

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/9324767d17656cb57332c09564ae6e22a9b3edfb/exec_times/c_code.png" alt="image alt" width="500"/>

---
### **iv.) Screenshot of the Program Output, including correctness check (CUDA)**

<img src="https://github.com/MichaelGelo/GRP2_DeepDive__CUDA/blob/9324767d17656cb57332c09564ae6e22a9b3edfb/exec_times/cuda_code.png" alt="image alt" width="500"/>

---
### **v.) Comparative Table of Execution Time and Analysis of the Performance of the Kernel**

---
### **vi.) Discussion**
