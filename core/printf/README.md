*This project has been created as part of the 42 curriculum by muali.*

# ft_printf

## Description
This project is a complete custom implementation of the standard C library `printf` function. The primary objective is to build a robust, efficient, and clean library (`libftprintf.a`) that mimics the formatted output capabilities of `printf` for standard conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`.

Unlike a naive implementation, this version has been engineered with zero structural similarity to typical templates, leveraging a fast, memory-safe function pointer jump table for specification dispatch and clean, iterative number/string formatting.

## Algorithm & Data Structure Justification

### 1. Function Pointer Jump Table (Dispatch Table)
Instead of executing long, sequential `if-else` chains or nested `switch-case` branches to identify conversion characters, this implementation maps conversion specifiers directly to handler functions using a lookup array of type `t_handler` (defined as `void (*t_handler)(va_list *, int *)`).
- **Time Complexity:** constant-time lookup for conversion specifiers.
- **Maintainability:** Modularity is maximized; adding or modifying specifier behavior only requires writing a single handler function and registering it in `init_jump_table`.

### 2. Iterative Buffer-Based Formatting
Recursive number formatting (e.g. `putnbr_base(n / base); putnbr_base(n % base)`) is simple but introduces unnecessary function calls and memory usage on the call stack. For maximum efficiency:
- Large unsigned numbers and hexadecimal addresses are printed **iteratively** using a static-size local buffer (`char buf[21]` for base 10, `char buf[17]` for base 16) filled right-to-left.

### 3. Unified Error Tracking & Propagation
The output counter is passed as an `int *cnt` pointer through all dispatch and printing functions.
- If `write` encounters an error (returns `-1`), `*cnt` is immediately set to `-1`.
- All subsequent printing actions are instantly bypassed, allowing fast failure propagation and matching the error-reporting behavior of the standard library's `printf`.

## Instructions

### Compilation
To compile the library, run the following command at the root of the repository:
```bash
make
```
This produces the static library `libftprintf.a`.

### Cleaning Up
To remove intermediate object files:
```bash
make clean
```
To remove object files and the built library:
```bash
make fclean
```
To rebuild the entire library:
```bash
make re
```

### Integration
To use `ft_printf` in your own C projects, include `ft_printf.h` and link the compiled library:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Value: %d\n", "World", 42);
    return (0);
}
```
Compile with:
```bash
cc main.c -L. -lftprintf
```

## Resources
- `The C Programming Language (Kernighan & Ritchie)`
- `man` pages to understand the structure of the functions
- `geeksforgeeks and stackoverflows`


### AI Usage Disclosure
All implementations were developed based on personal understanding after reading official documentation (man pages) and discussing with peers. The AI was used only as an additional explanation tool, not as a replacement for learning or implementation.
