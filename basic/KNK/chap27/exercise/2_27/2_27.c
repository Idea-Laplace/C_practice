/*
   Write the parametrized macros INT_32C(n), UINT_32C(n),
   INT_64C(n) and UINT_64C(n), assuming that the int type
   and long int types are 32 bits wide and the long long int
   type is 64 bits wide.

   Hint> Use the ## preprocessor operator to attach a suffix
   to n containing a combination of L and/or U characters.
*/


/* Copy from <stdint.h>
// Signed.  
# define INT8_C(c)	c
# define INT16_C(c)	c
# define INT32_C(c)	c
# if __WORDSIZE == 64
#  define INT64_C(c)	c ## L
# else
#  define INT64_C(c)	c ## LL
# endif

// Unsigned.
# define UINT8_C(c)	c
# define UINT16_C(c)	c
# define UINT32_C(c)	c ## U
# if __WORDSIZE == 64
#  define UINT64_C(c)	c ## UL
# else
#  define UINT64_C(c)	c ## ULL
# endif
# if __WORDSIZE == 64
#  define __INT64_C(c)	c ## L
#  define __UINT64_C(c)	c ## UL
# else
#  define __INT64_C(c)	c ## LL
#  define __UINT64_C(c)	c ## ULL
*/

#define INT32_C(n) n 
#define INT64_C(n) n ## LL
#define UINT32_C(n) n ## U
#define UINT64_C(n) n ## ULL
