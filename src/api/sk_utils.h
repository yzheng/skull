#ifndef SK_UTILS_H
#define SK_UTILS_H

#include <stdio.h>
#include <stdarg.h>

#include "api/sk_core.h"
#include "flibs/compiler.h"

// INTERNALs
// NOTE: DO NOT USE THESE DIRECTLY!
#define SK_TO_STR(x) #x
#define SK_EXTRACT_STR(x) SK_TO_STR(x)
void sk_assert_exit(const char* expr, const char* file, int lineno);
void sk_assert_exit_with_msg(const char* format, ...);


// APIs

// ASSERTIONS
#define SK_ASSERT(expr) \
    if (unlikely(!(expr))) { \
        sk_assert_exit(#expr, __FILE__, __LINE__); \
    }

#define SK_ASSERT_MSG(expr, ...) \
    if (unlikely(!(expr))) { \
        sk_assert_exit_with_msg("FATAL: assert [" #expr "] failed, " \
                                __FILE__ ":" SK_EXTRACT_STR(__LINE__) " - " \
                                __VA_ARGS__); \
    }


// debug print
#ifdef SK_DEBUG
# define sk_print(...) \
    do { \
        printf(__FILE__ ":" SK_EXTRACT_STR(__LINE__) " - " __VA_ARGS__); \
    } while (0)

# define sk_print_err(...) \
    do { \
        fprintf(stderr, __FILE__ ":" SK_EXTRACT_STR(__LINE__) " - " \
                __VA_ARGS__); \
    } while (0)

# define sk_rawprint(...) \
    do { \
        printf(__VA_ARGS__); \
    } while (0)

#else
# define sk_print(...)
# define sk_print_err(...)
# define sk_rawprint(...)
#endif

/**
 * Dump backtrace to stderr
 */
void sk_backtrace_print();

/**
 * Fill up the core info
 */
void sk_util_setup_coreinfo(sk_core_t* core);

#endif // end of SK_UTILS_H

