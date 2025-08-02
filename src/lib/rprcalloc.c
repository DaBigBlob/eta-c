#ifndef SRC_LIB_RPRCALLOC_C
#define SRC_LIB_RPRCALLOC_C

/*
An arena allocator that uses reverse pointers to check reference existence.
Is actually very dumb.
*/

#include "./prelude.c"

/*
Every "block" of allocation begins with two things:
    - reference to its own reference
    - size of the block excluding these two things
The sentinal block is one with size set to 0
*/
typedef struct {
    memp* refp;
    memsz size;
} rprc_block_desc;

#ifndef RPRC_TOLERANCE
    /// max number of extra bytes the allocator may freely assign
    #define RPRC_TOLERANCE 4
#endif // RPRC_TOLERANCE

/*
In the act of allocating a new block with reference R and size S,
    - for each block already present with reference aR and size aS,
        - check if &aR == aR i.e. reverse pointer check
            - alive -> repeat for next block
            - dead -> check size of the block for aS >= S && aS <= S + RPRC_TOLERANCE
                - true -> re-assign block
                - fale -> set remember block as has_potetial,
                  check subsequent blocks' sizes to see if aS >= S && aS <= S + RPRC_TOLERANCE
                  and &aR != aR criteria is met
                    - yes -> re-assign the first block descriptor with total
                             size calculated and reference reference replaced
                    - no -> check next block as regular
    - if not block present i.e. end sentinal,
        - allocate new
*/

/*
rprcalloc usage:
something* new_ptr;
rprcalloc(&(memp)new_ptr, sizeof(something), arena);
*/

void rprcalloc(memp* refp, memsz size, memp arena) {
}

#endif //SRC_LIB_RPRCALLOC_C
