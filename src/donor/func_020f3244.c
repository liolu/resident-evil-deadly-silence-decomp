/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02068a1c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/fnd/fnd_allocator.c (license: none),
 * reused by tools/donor_match.py */
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;
typedef int s32;
typedef short s16;
typedef char s8;
typedef float f32;
typedef double f64;
typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef volatile u8 vu8;
typedef volatile s64 vs64;
typedef volatile s32 vs32;
typedef volatile s16 vs16;
typedef volatile s8 vs8;
typedef volatile f32 vf32;
typedef volatile f64 vf64;
typedef s32 BOOL;
typedef struct UnkFndLink {
    void *unk_00;
    void *unk_04;
} UnkFndLink;
typedef struct UnkFndList {
    void *unk_00;
    void *unk_04;
    u16 unk_08;
    u16 unk_0a;
} UnkFndList;
typedef struct UnkFndHeapHead {
    u32 unk_00;
    UnkFndLink unk_04;
    UnkFndList unk_0c;
    void *unk_18;
    void *unk_1c;
    u32 unk_20;
} UnkFndHeapHead;
extern void func_02067dec(UnkFndList *list, u16 offset);
extern void func_02067e30(UnkFndList *list, void *obj);
extern void func_02067f38(UnkFndList *list, void *obj);
extern void *func_02067f98(UnkFndList *list, void *obj);
extern void func_02068054(UnkFndHeapHead *heap, u32 signature, void *start, void *end, u16 option);
extern void func_020680d0(UnkFndHeapHead *heap);
extern void func_0206785c(u32 value, void *dest, u32 size);
struct UnkFndAllocator;
typedef void *(*UnkFndAllocFunc)(struct UnkFndAllocator *allocator, u32 size);
typedef void (*UnkFndFreeFunc)(struct UnkFndAllocator *allocator, void *memBlock);
typedef struct UnkFndAllocatorFunc {
    UnkFndAllocFunc unk_00;
    UnkFndFreeFunc unk_04;
} UnkFndAllocatorFunc;
typedef struct UnkFndAllocator {
    const UnkFndAllocatorFunc *unk_00;
    void *unk_04;
    u32 unk_08;
    u32 unk_0c;
} UnkFndAllocator;
extern void *func_02068618(void *heap, u32 size, int alignment);
extern void func_02068648(void *heap, void *memBlock);
extern void *func_020688b0(void *heap, u32 size, int alignment);
extern void *func_02068928(void *heap);
extern void func_02068968(void *heap, void *memBlock);
extern void *OS_AllocFromHeap(int arena, int heap, u32 size);
extern void OS_FreeFromHeap(int arena, int heap, void *ptr);
typedef struct UnkUnitHeapView {
    UnkFndHeapHead unk_00;
    void *unk_24;
    u32 unk_28;
} UnkUnitHeapView;
void *func_02068978(UnkFndAllocator *allocator, u32 size);
void func_0206898c(UnkFndAllocator *allocator, void *memBlock);
void *func_0206899c(UnkFndAllocator *allocator, u32 size);
void func_020689b0(UnkFndAllocator *allocator, void *memBlock);
void *func_020689b4(UnkFndAllocator *allocator, u32 size);
void func_020689d4(UnkFndAllocator *allocator, void *memBlock);
void *func_020689e4(UnkFndAllocator *allocator, u32 size);
void func_02068a00(UnkFndAllocator *allocator, void *memBlock);
extern const UnkFndAllocatorFunc data_020ba510;
extern const UnkFndAllocatorFunc data_020ba508;
extern const UnkFndAllocatorFunc data_020ba500;
extern const UnkFndAllocatorFunc data_020ba518;
void *func_020f3244(UnkFndAllocator *allocator, u32 size) {
    return allocator->unk_00->unk_00(allocator, size);
}
void func_02068a30(UnkFndAllocator *allocator, void *memBlock);
void func_02068a44(UnkFndAllocator *allocator, void *heap, int alignment);
void unkfunc_unused_18(UnkFndAllocator *allocator, void *heap, int alignment);
void unkfunc_unused_17(UnkFndAllocator *allocator, void *heap);
void unkfunc_unused_19(UnkFndAllocator *allocator, int arena, int heap);
