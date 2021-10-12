#pragma once

#if defined(__APPLE__)
#include <malloc/malloc.h>
#define MX_MALLOC_SIZE(x) malloc_size(x)
#elif defined(_WIN64) || defined(_WIN32)
#include <malloc.h>
#define MX_MALLOC_SIZE(x) _msize(x)
#elif defined(__linux__)
#include <malloc.h>
#define MX_MALLOC_SIZE(x) malloc_usable_size(x)
#endif

#define MX_MIN(x, y, type) (((type)x) < ((type)y) ? (x) : (y))
#define MX_MAX(x, y, type) (((type)x) > ((type)y) ? (x) : (y))

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct s_list {
	void *data;
    char operator;
	struct s_list *next;
}			   t_list;


/*************************  mx functions for work with files **********************************************************************************/
char *mx_file_to_str(const char *file);				//  Copy file content to string
int mx_read_line(char **lineptr,					// Reads the line from the given fd  into the lineptr  
				 char delim, const int fd); 		// until reaches a delim character or reaches the End Of File (EOF)
int64_t mx_get_file_length(const char *filename); 	// Get length of file 


/************************* mx functions for work with strings *********************************************************************************/
char *mx_strnew(const int size);  // Returns the string of a specific size and terminated by '\0' NULL if creation fails
void mx_strdel(char **str);  // Frees string memory with free and sets the string to NULL
void mx_del_strarr(char ***arr); // Delete array of strings
char *mx_strcpy(char* dst, const char* src); // Copy a string including the terminating null byte ('\0')
int mx_strlen(const char *s); 		// Calculate the length of a string
int mx_strcmp(const char *s1, const char *s2); 	// Compare two strings It returns an integer less than, equal to, or greater than zero 
												// if s1 is found, respectively, to be less than, to match, or be greater than s2.
int mx_strncmp(const char *s1, const char *s2, int n); 	// The function  copies n bytes of the string pointed to by src, including the 
														// terminating null byte ('\0') , to the buffer pointed to by dest.
void mx_swap_char(char *s1, char *s2); // Swaps the characters of a string using pointers. Do nothing if s1 or s2 does not exist
char *mx_strcat(char *s1, const char *s2); // Concatenate two strings
char *mx_strdup(const char *str); 	// The function returns a pointer to a new string which is a duplicate of the string s.  
									// Memory for the new string is obtained with malloc(3), and can be freed with free(3).
char *mx_strjoin(char const *s1, char const *s2); //Concatenates strings s1 and s2 into a new string terminates the new string with `\0`
char *mx_strncpy(char *dst, const char *src, int len); // Copy part of string 
void mx_str_reverse(char *s); 	// Reverses a string using pointers. Do nothing if a string does notexis
char *mx_strndup(const char *str, size_t n);	// Duplicate part of string
char *mx_strstr(const char *haystack, const char *needle); // Locate a substring. The funcion finds the first occurrence of the substring needle in the string haystack.
int mx_count_words(const char *str, char c); // Counts words in a string. Word is a sequence of characters separated by a delimiter.
int mx_count_substr(const char *str, const char *sub); 	// Counts the substrings sub in the string str 
int mx_get_char_index(const char *str, char c);	// The function finds the index of the first occurrence of the character c in a string str. 
												// A string is a sequence of characters, excluding NULL in the end.
int mx_get_substr_index(const char *str, const char *sub);		// Get substring index
char *mx_strtrim(const char *str);	// Trim string. takes a string, and creates a new one from it without whitespace characters at the beginning and the end of the string
char *mx_strtrim_char(const char *str, char c);
char *mx_del_extra_spaces(const char *str); // Clean string. Takes a string, and creates a new one from it without whitespace characters in the beginning and/or at the end 
											// of the string. Separates words in the new string with exactly one space character
char **mx_strsplit(const char *s, char c);	// Split string. Converts a string s to a NULL-terminated array of words
char *mx_replace_substr(const char *str, const char *sub,	// Replace substrings.
						const char *replace);	// The function replaces all occurrences of sub in str with replace. 											
char *mx_strchr(const char *s, int c);			// Returns a pointer to the first occurrence of the character c in the string s.
char *mx_substr(const char *str, int a, int b); // Returns a pointer to the new string as substring from a to b symbol

/************************* mx convert function ************************************************************************************************/
int mx_atoi(const char *str);					// Convert a string to an integer
char *mx_itoa(int number);						// The function takes an integer and converts it to a string
char *mx_nbr_to_hex(unsigned long nbr);  		// Converts an unsigned long number into a hexadecimal strin
unsigned long mx_hex_to_nbr(const char *hex); 	// Converts a hexadecimal string into an unsigned long number
int mx_tolower(int c);							// Change higher char to lower char

/************************* mx character check functions ***************************************************************************************/
bool mx_isdigit(int c);		// Checks for a digit (0 through 9).
bool mx_isspace(char c);	// Checks  for  white-space  characters. These are: space,('\f'),('\n'),('\r'),('\t'),('\v').
bool mx_isalpha(int c);		// Checks for a alpha

/************************* mx print functions *************************************************************************************************/
void mx_printstr(const char *s); //The function outputs a string of characters to the standard output.
void mx_printerr(const char *s); //The function outputs a string of characters to the error output.
void mx_printint(int n);		//The function outputs integer values to the standard output.
void mx_printchar(char c);		//The function outputs a single character to the standard output.
void mx_print_strarr(char **arr, const char *delim); /*The function outputs an array of strings arr to the standard output 
													  *with a delimiter delim between the elements of an array
													  *nothing if arr or delim do not exist
													  *a new line at the end of the output */
void mx_print_unicode(wchar_t c);  // The function outputs ASCII and multibyte characters to the standard output.


/************************ mx functions for sort array or search *******************************************************************************/
int mx_bubble_sort(int *arr, int size);  		//sorts an array of integers in place in ascending order.
												//Returns the number of swap operations.
int mx_quicksort(int *arr, int left, int right);//Sorts an array of integers uses the quick sort algorithm
int mx_binary_search(char **arr, int size, const char *s, int *count); // Searches the string s in the array arr with the given size of array
int mx_count_arr_el(char **arr);  				//Count elements of array

/************************  mx mathematical functions ******************************************************************************************/
double mx_pow(double n, unsigned int pow); 	// Computes n raised to the power of zero or a positive integer pow
int mx_sqrt(int x1); 						// Computes the non-negative square root of x 

/************************ mx memory functions *************************************************************************************************/
void mx_foreach(const int *arr, int size, void(*f) (int)); // Applies the function f for each element of the array arr given size
void *mx_memset(void *b, int c, size_t len);	// Fill memory with a constant byte. The function fills len bytes of the memory area 
												// pointed to by *b with the constant byte c.
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);	// Copies n bytes from memory area src to memory area dst. 
int mx_memcmp(const void *s1, const void *s2, size_t n);	// compares the first n bytes of the memory areas s1 and s2.
												// returns an integer less than, equal to, or greater than zero 
												// if the first n bytes of s1 is found, respectively, 
												// to be less than, to match, or be greater than the first n bytes of s2.
void *mx_realloc(void *ptr, size_t size);		// Changes the size of the memory block pointed to by ptr to size bytes.
void *mx_memmove(void *dst, const void *src, size_t len);	// Copies n bytes from memory area src to memory area dst. 
void *mx_memrchr(const void *s, int c, size_t n);	// The function is like the mx_memchr() function, except that it searches backward from 
													// the end of the n bytes pointed to by s instead of forward from the beginning.
void *mx_memccpy(void *restrict dst, const void *restrict src,	// Copies no more than n bytes from memory area src to memory area dst, 
				 int c, size_t n);								// stopping when the character c is found.
void *mx_memchr(const void *s, int c, size_t n);	// scans the initial n bytes of the memory area pointed to by s for the first instance of c.
void *mx_memmem(const void *big, size_t big_len, 		// Locate block of bytes. Returns a pointer to the beginning of the substring,
				const void *little, size_t little_len); // or NULL if the substring  is  not found.
void mx_swap(void *restrict v1, void *restrict v2, size_t size);	// Swap the contents of memory blocks of a given size 


/************************ mx linked lists functions *******************************************************************************************/
t_list *mx_create_node(void *data);	// creates a new node of a linked list t_list. 
									// The function assigns a parameter data to the list variable data and assigns next to NULL
void mx_push_front(t_list **list, void *data);	// Inserts a new node of t_list type with the given parameter data 
												// at the beginning of the linked list.
void mx_push_back(t_list **list, void *data);	// Inserts a node of t_list type with the given parameter data at the end of the linked list
void mx_pop_front(t_list **list);	// Removes the first node of the linked list and frees the memory allocated for the node.
void mx_pop_back(t_list **list);	// Removes the last node of the linked list and frees the memory allocated for the node.
int mx_list_size(t_list *list);		// Calculates the number of nodes in a linked list. Returns the amount of nodes in the linked list
t_list *mx_sort_list(t_list *list, 	// Sorts a list's contents in ascending order.
					bool (*cmp)(void *a, void *b));	// The function cmp returns true if a > b and false in other cases
void mx_clear_list(t_list **list);	// Delete list
