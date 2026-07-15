*This project has been created as part of the 42 curriculum by muali.*

# Get Next Line

## Description
The goal of this project is to create a function, `get_next_line`, that reads and returns a single line from a file descriptor each time it is called. The project teaches students how to properly manage memory in C, specifically introducing the concept and usage of `static` variables, which persist across function calls to keep track of remaining data read from the file.

## Instructions
**Compilation:**
To compile the project and test it, include the `get_next_line.c`, `get_next_line_utils.c` and a program containing a `main` function (e.g., `main.c`). You must define the `BUFFER_SIZE` macro at compilation time:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
You can change `42` to any positive integer to test the code with different buffer sizes.

**Usage:**
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Resources
- This implementation was designed from the ground up relying on standard 42 curriculum knowledge.
- The use of AI tools was limited to formatting this documentation and ensuring structural guidelines were met, keeping coding logic authentic to peer-learning methodology. 
- You can refer to manual pages for `read(2)`, `malloc(3)`, and `free(3)`.

## Algorithm Explanation
The algorithm relies heavily on a single `static char *remainder` variable to preserve string data between calls. 
1. **Reading**: The function calls `read()` with `BUFFER_SIZE` continuously, appending the read chunk (`buffer`) onto the `remainder` string. This loops until a newline `\n` character is found in `remainder` or the file terminates (0 bytes read).
2. **Extraction**: Once a newline is detected (or EOF is reached), the function iterates through `remainder` to isolate everything up to and including the first `\n`. It dynamically allocates memory, copies this segment into a new string, and null-terminates it to return to the user.
3. **Updating state**: The `remainder` variable is then dynamically updated. We find the substring starting *after* the extracted `\n` character, copy it over into a fresh heap allocation, free the old `remainder`, and reassign the `static` pointer to the newly shortened string for the next function call.
