# OpenMP Image Negative Converter

## Project Overview
This project demonstrates the application of parallel computing using OpenMP in C. It reads a grayscale `.pgm` image, computes its negative (using the formula: `maxval - pixel_value`), and compares the performance between a sequential implementation and a parallelized implementation.

## Features
- **Sequential Implementation:** Baseline calculation of the image negative.
- **Parallel Implementation:** Uses `#pragma omp parallel for` to distribute the workload across multiple threads.
- **Performance Analysis:** Calculates and reports T_seq (sequential time), T_par (parallel time), and the overall Speedup (T_seq / T_par).
- **Memory Management:** Properly allocates and frees dynamically allocated memory using a custom `pgm` library.

## Compilation and Execution
To compile the program, run:
`gcc -fopenmp main.c pgm.o -o image_negative`

To execute:
`./image_negative`

## Output
The program generates two output files to verify correctness:
1. `negative-apple_seq.pgm` (Sequential output)
2. `negative-apple_para.pgm` (Parallel output)

It also prints the performance metrics (Time and Speedup) to the console.
