# MakaCoder

A personal development environment for competitive programming.

MakaCoder automates repetitive parts of the competitive programming workflow: initializing solution files, building and running programs, generating submission-ready code, and testing solutions against brute-force references.

The goal is simple: spend less time managing the development environment and more time solving problems.


[![Rating](https://badgen.org/img/atcoder/TrueRyoB/rating/algorithm?style=for-the-badge&label=Algorithm)](https://atcoder.jp/users/TrueRyoB?contestType=algo)

## Features

### Solution Management

Initialize a solution from a reusable template:

```bash
rst
```

This resets `main.cs` from the active template.

### Build & Run

Build and execute the current solution:

```bash
run
```

Input can also be provided from a file:

```bash
run input.txt
```

### Submission Code Generation

Generate a submission-ready `main.cs` containing only the libraries actually used by the solution:

```bash
wind
```

The generated code is copied to the clipboard for submission.

### Stress Testing

Compare the solution against a brute-force reference implementation using randomly generated test cases:

```bash
stress
```

By default, 300 test cases are generated and execution stops at the first mismatch.

Run a custom number of cases:

```bash
stress 1000
```

Continue running after mismatches:

```bash
stress -k
```

Create the generator and brute-force solution templates automatically:

```bash
stress --init
```

## Stress Testing Workflow

A typical stress-testing setup consists of three programs:

```text
           Random Input
                |
                v
          +-----------+
          | Generator |
          +-----------+
                |
                v
        +-------+-------+
        |               |
        v               v
   main.cs          brute.cs
   solution         reference
        |               |
        +-------+-------+
                |
                v
         Compare Outputs
                |
          +-----+-----+
          |           |
        Match      Mismatch
                      |
                      v
             Print seed,
             input,
             expected,
             actual
```

The generator produces small random test cases. The brute-force implementation provides a trusted reference answer, and `main.cs` is tested against it.

When a mismatch occurs, MakaCoder reports the random seed, input, expected output, and actual output, making the failing case reproducible.

## File Conventions

The stress-testing workflow uses:

```text
gen.cs / gen.py      # random test generator
brute.cs / brute.py  # reference solution
main.cs              # solution under test
```

C# and Python files are detected automatically.

Generated build artifacts and stress-testing files are kept out of Git so that running tests does not modify the working tree.

## Technology

| Component          | Technology                |
| ------------------ | ------------------------- |
| Primary language   | C#                        |
| Additional tooling | Python                    |
| Shell environment  | zsh                       |
| Editor integration | VS Code                   |
| Testing            | Randomized stress testing |
| Reference testing  | Brute-force solutions     |

## Repository Structure

```text
MakaCoder/
├── active/       # active templates
├── archive/      # archived templates
├── rst            # reset solution
├── run            # build & run
├── wind           # generate submission code
├── stress         # randomized differential testing
├── setup.sh       # environment setup
└── wind.py        # submission-code generation
```

## Design Philosophy

Competitive programming requires repeatedly solving problems under time constraints. The development environment therefore has a significant effect on iteration speed.

MakaCoder focuses on automating tasks that are repetitive but error-prone:

* resetting a solution to a known template
* compiling and running code
* preparing submission code
* checking optimized solutions against brute-force references
* reproducing incorrect cases through deterministic random seeds

The stress-testing workflow is particularly useful for algorithmic problems where the optimized solution is difficult to verify manually. Instead of relying only on manually constructed test cases, a brute-force implementation can serve as an executable specification for small inputs.

## Getting Started

Clone the repository and run the setup script:

```bash
./setup.sh
```

After setup, the commands become available when working inside the repository.

For example:

```bash
rst
run
stress --init
stress
wind
```

## Example Development Workflow

```text
1. Initialize solution
       ↓
2. Implement algorithm
       ↓
3. Write brute-force reference
       ↓
4. Generate random tests
       ↓
5. Compare optimized solution
       ↓
6. Investigate mismatches
       ↓
7. Fix implementation
       ↓
8. Generate submission-ready code
```

MakaCoder is primarily a personal tool, but the workflow is designed around reproducible and systematic verification rather than ad-hoc testing.
