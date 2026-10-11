#ifndef M2C_H
#define M2C_H

/* Types used by raw m2c output (src/auto/). Remove the include once a function is cleaned up. */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef long s32;
typedef unsigned long u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

typedef s32 M2C_UNK;

#ifndef NULL
    #define NULL ((void *) 0)
#endif

/* Access to a struct field whose type is not reconstructed yet. */
#define M2C_FIELD(base, type, offset) (*(type) ((s8 *) (base) + (offset)))

#endif
