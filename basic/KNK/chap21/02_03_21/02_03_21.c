#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// A macro hides a function
// A function prototype comes first, followed by macro definition.
extern void __assert (const char *__assertion, const char *__file, int __line)


#define assert(expr)							\
     (static_cast <bool> (expr)						\
      ? void (0)							\
      : __assert_fail (#expr, __FILE__, __LINE__, __ASSERT_FUNCTION))
