<p align="center">
    <a href="https://ucode.world/en/" target="_blank">
        <img src="../marathon_C/img/ucode_logo_minimal.png?raw=true" height="100px">
    </a>
    <h1 align="center">ucode-libmx</h1>
    <br>
</p>

## Skills

Critical Thinking, Problem Solving, Analysis, Reasoning & Argumentation, Creativity, Innovation Thinking, Agility & Adaptability, Responsibility, Self-Management, Communication, UNIX, Git, Procedural Programming, Algorithms, C

## Instalation:
1. Download code [here](.)
2. Default mode: `make` or `make all`
3. Silent debug mode: `make debug` (need main.c file)
4. File for use: libmx.a 


## mx functions for work with files

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_file_to_str`` | Copy file content to string | 100 |
| ``mx_read_line`` | Reads the line from the given `fd`  into the `lineptr` until reaches a `delim` character or reaches the `EOF`| 0 |  
| ``mx_get_file_length`` | Get length of file | - |

## mx functions for work with strings

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_strnew`` | Returns the string of a specific size and terminated by `\0` or `NULL` if creation fails | 100 |
| ``mx_strdel`` | Frees string memory with free and sets the string to `NULL` | 100 |
| ``mx_del_strarr`` | Delete array of strings | 100 |
| ``mx_strcpy`` | Copy a string including the terminating null byte `\0` | 100 |
| ``mx_strlen`` | Calculate the length of a string | 100 |
| ``mx_strcmp`` | Compare two strings It returns an integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to match, or be greater than `s2` | 100 | 
| ``mx_strncmp`` | The function  copies `n` bytes of the string pointed to by `src`, including the terminating null byte `\0` , to the buffer pointed to by `dst` | - |
| ``mx_swap_char`` | Swaps the characters of a string using pointers. Do nothing if `s1` or `s2` does not exist | 100 |
| ``mx_strcat`` | Concatenate two strings | 100 |
| ``mx_strdup`` | Returns a pointer to a new string which is a duplicate of the string `s`. Memory for the new string is obtained with malloc(3), and can be freed with free(3) | 100 |
| ``mx_strjoin`` | Concatenates strings `s1` and `s2` into a new string terminates the new string with `\0` | 100 |
| ``mx_strncpy`` | Copy part of string | 100 |
| ``mx_str_reverse`` | Reverses a string using pointers. Do nothing if a string does notexis | 100 |
| ``mx_strndup`` | Duplicate part of string | 100 |
| ``mx_strstr`` | Locate a substring. The funcion finds the first occurrence of the substring `needle` in the string `haystack`. | 100 |
| ``mx_count_words`` | Counts words in a string. Word is a sequence of characters separated by a delimiter. | 100 |
| ``mx_count_substr`` | Counts the substrings `sub` in the string `str` | 100 |
| ``mx_get_char_index`` | The function finds the `index` of the first occurrence of the character `c` in a string `str`. A string is a sequence of characters, excluding `NULL` in the end | 100 |
| ``mx_get_substr_index`` | Get substring index | 100 |
| ``mx_strtrim`` | Trim string. takes a string, and creates a new one from it without whitespace characters at the beginning and the end of the string | 100 |
| ``mx_del_extra_spaces`` | Clean string. Takes a string, and creates a new one from it without whitespace characters in the beginning and/or at the end of the string. Separates words in the new string with exactly one space character | 75 |
| ``mx_strsplit`` | Split string. Converts a string s to a NULL-terminated array of words | 100 |
| ``mx_replace_substr`` | Replace substrings. The function replaces all occurrences of `sub` in `str` with replace | 100 |	
| ``mx_strchr`` | Returns a pointer to the first occurrence of the character `c` in the string `s` | - |

## mx convert function

| Function name  |Description |Grade|
|-------------|----------------------------------------------------|---|
| ``mx_atoi`` | Convert a string to an integer | 100 |
| ``mx_itoa`` | The function takes an integer and converts it to a string | 100 |
| ``mx_nbr_to_hex`` | Converts an unsigned long number into a hexadecimal string | 95 |
| ``mx_hex_to_nbr`` | Converts a hexadecimal string into an unsigned long number | 100 |

## mx character check functions

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_isdigit`` | Checks for a digit (0 through 9). | 100 |
| ``mx_isspace`` | Checks  for  white-space  characters. These are: `space`,`\f`,`\n`,`\r`,`\t`,`\v` | 100 |


## mx print functions 

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_printstr`` | The function outputs a string of characters to the standard output | 100 |
| ``mx_printerr`` | The function outputs a string of characters to the error output | 100 |
| ``mx_printint`` | The function outputs integer values to the standard output | 100 |
| ``mx_printchar`` | The function outputs a single character to the standard output | 100 |
| ``mx_print_strarr`` | The function outputs an array of strings `arr` to the standard output with a delimiter `delim` between the elements of an array nothing if `arr` or `delim` do not exist a new line at the end of the output | 100 |
| ``mx_print_unicode`` | The function outputs ASCII and multibyte characters to the standard output | 100 |

## mx functions for sort array or search

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_bubble_sort`` | sorts an array of integers in place in ascending order. Returns the number of swap operations | 100 |
| ``mx_quicksort`` | Sorts an array of integers uses the quick sort algorithm | 100 |
| ``mx_binary_search`` | Searches the string `s` in the array `arr` with the given size of array | 100 |


## mx mathematical functions 

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_pow`` | Computes `n` raised to the power of zero or a positive integer pow | 100 |
| ``mx_sqrt`` | Computes the non-negative square root of `x` | 100 |
## mx memory functions

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_foreach`` |  Applies the function `f` for each element of the array `arr` given size | 100 |
| ``mx_memset`` | Fill memory with a constant byte. The function fills `len` bytes of the memory area pointed to by `b` with the constant byte `c`| 100 |
| ``mx_memcpy`` |  Copies `n` bytes from memory area `src` to memory area `dst`| 100 |
| ``mx_memcmp`` |  compares the first `n` bytes of the memory areas `s1` and `s2`. Returns an integer less than, equal to, or greater than zero if the first `n` bytes of `s1` is found, respectively, to be less than, to match, or be greater than the first `n` bytes of `s2`| 100 |
| ``mx_realloc`` |  Changes the size of the memory block pointed to by ptr to size bytes| 100 |
| ``mx_memmove`` |  Copies n bytes from memory area src to memory area dst| 100 |
| ``mx_memrchr`` |  The function is like the mx_memchr() function, except that it searches backward from the end of the n bytes pointed to by s instead of forward from the beginning| 100 |
| ``mx_memccpy`` |  Copies no more than `n` bytes from memory area `src` to memory area `dst`, stopping when the character `c` is found| 100 |
| ``mx_memchr`` |  Scans the initial `n` bytes of the memory area pointed to by s for the first instance of `c` | 100 |
| ``mx_memmem`` | Locate block of bytes. Returns a pointer to the beginning of the substring or NULL if the substring  is  not found| 100 |
| ``mx_swap`` | Swap the contents of memory blocks of a given size| - |


## mx linked lists functions

|Function name|Description|Grade|
|-------------|----------------------------------------------------|---|
| ``mx_create_node`` | Creates a new node of a linked list `t_list`. The function assigns a parameter data to the list variable data and assigns next to NULL| 100 |  
| ``mx_push_front`` | Inserts a new node of `t_list` type with the given parameter data at the beginning of the linked list| 100 | 
| ``mx_push_back`` | Inserts a node of `t_list` type with the given parameter data at the end of the linked list| 100 |
| ``mx_pop_front`` | Removes the first node of the linked list and frees the memory allocated for the node| 100 |
| ``mx_pop_back`` | Removes the last node of the linked list and frees the memory allocated for the node| 100 |
| ``mx_list_size`` | Calculates the number of nodes in a linked list. Returns the amount of nodes in the linked list| 100 |
| ``mx_sort_list`` | Sorts a list's contents in ascending order.The function `cmp` returns true if `a > b` and false in other cases| 100 |

## [Go back](../README.md)
