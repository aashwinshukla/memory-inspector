# Memory Inspector

A lightweight, interactive command-line tool written in C that lets you store a sequence of integers and inspect them at the memory level — viewing raw addresses, navigating element by element, modifying values, and swapping elements in place.

Built as a learning project to understand how arrays are laid out in memory and how pointer arithmetic works in practice.

---

## Features

| Feature | Description |
|---|---|
| **Store integers** | Load up to 100 integers at startup; type `q` to finish |
| **Navigate** | Walk forward and backward through the array one index at a time |
| **Jump to index** | Go directly to any valid index and see its value and address |
| **Modify value** | Overwrite the value at any index |
| **Swap elements** | Swap the values at any two indices |
| **Memory view** | Every operation shows the element's index, value, and raw memory address |

---

## Project Structure

```
memory-inspector/
├── memory/
│   ├── main.c       # Entry point — menu loop and all operations
│   ├── utils.h      # Struct definitions, constants, and function prototypes
│   └── utils.c      # Input collection, menu helpers, display utilities
├── LICENSE
└── README.md
```

---

## Getting Started

### Prerequisites

- A C compiler: [GCC](https://gcc.gnu.org/) (Linux/macOS/MinGW) or MSVC (Windows)
- No external libraries required — standard C only

### Build

**GCC (Linux / macOS / MinGW on Windows)**

> Both source files must be passed together — `utils.c` contains the implementations that `main.c` calls.

```bash
# From the repo root
gcc memory/main.c memory/utils.c -o memory-inspector

# Or from inside the memory/ folder
gcc main.c utils.c -o memory-inspector
```

**MSVC (Windows Developer Command Prompt)**
```cmd
cl memory\main.c memory\utils.c /Fe:memory-inspector.exe
```

### Run

```bash
./memory-inspector        # Linux / macOS
memory-inspector.exe      # Windows
```

---

## Usage

When the program starts, enter your integers one by one (press Enter after each). Type `q` when you are done.

```
Enter integers into storage (type 'q' to stop):
42 7 19 3 q
```

You are then dropped into the main menu:

```
========== Memory Inspector Menu ==========
  1. Current Position Info
  2. Jump to an Index
  3. Modify Value at Index
  4. Swap Two Elements
  5. Exit
-------------------------------------------
```

### Example session

```
Enter integers into storage (type 'q' to stop):
10 20 30 q

3 element(s) stored successfully.

========== Memory Inspector Menu ==========
Enter choice: 2

Enter the index to jump to (0 - 2): 1
  Index   : 1
  Value   : 20
  Address : 0x7ffee4b5c3a4

========== Memory Inspector Menu ==========
Enter choice: 3

Enter the index to modify (0 - 2): 1
  Current value at index 1: 20
  Enter new value: 99
  Updated — index 1 is now: 99
```

---

## Safety & Input Handling

- All index inputs are bounds-checked before any array access
- Non-integer input is flushed and re-prompted instead of causing an infinite loop
- Non-numeric tokens entered during the initial load phase are skipped with a warning
- Swapping an index with itself is detected and reported cleanly
- If no elements are entered at startup, the program exits gracefully

---

## License

This project is licensed under the terms of the [LICENSE](LICENSE) file included in the repository.
