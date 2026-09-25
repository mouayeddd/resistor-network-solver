# Resistor Network Solver

A simple C program that reads a list of resistors from a text file, computes the equivalent resistance for series and parallel configurations, and outputs the results both to the terminal and to a report file.

## Overview

This project was built as a hands-on way to combine core C fundamentals — structs, file I/O, functions, and arithmetic logic — into a single working tool, inspired by basic circuit analysis relevant to electronics and nanoelectronics.

## Features

- Reads resistor data (id, resistance value, group, and connection type) from a text file
- Stores each resistor as a struct
- Computes total resistance for:
  - **Series** resistors (sum of values)
  - **Parallel** resistors (reciprocal sum formula)
- Prints results to the terminal
- Writes a formatted report to `results.txt`

## Input Format

Each line in `components.txt` represents one resistor:

```
id value group_id type
```

Example:
```
1 100 1 S
2 200 1 S
3 50 2 P
4 75 2 P
```

- `id`: resistor identifier (integer)
- `value`: resistance in ohms (decimal)
- `group_id`: group the resistor belongs to (integer)
- `type`: `S` for series, `P` for parallel

## How to Build and Run

```bash
gcc resistor.c -o resistor
./resistor        # on Linux/Mac
.\resistor.exe     # on Windows
```

Make sure `components.txt` is in the same folder as the compiled program.

## Output

The program prints each resistor's details, then the computed series and parallel totals, and writes the same results to `results.txt`:

```
==== Resistor Network Report ====
Series result: 300.00 ohms
Parallel result: 30.00 ohms
```

## Skills Practiced

- Structs and functions
- File reading (`fscanf`) and file writing (`fprintf`)
- Arrays and loops
- Basic arithmetic logic (series/parallel resistance formulas)
- Debugging real compiler and runtime errors

## Possible Future Improvements

- Support arbitrary circuit topology using node-based analysis
- Separate calculations per resistor group
- Input validation for malformed data
- Split into multiple files (`.h` / `.c` / `main.c`)

## Author

Mouayed
