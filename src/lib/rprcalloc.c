#ifndef SRC_LIB_RPRCALLOC_C
#define SRC_LIB_RPRCALLOC_C

/*
An arena allocator that uses reverse pointers to check reference existence.
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

/*
In the act of allocating a new block with reference R and size S,
    - for each block already present with reference aR and size aS,
        - check if &aR = aR i.e. reverse pointer check
            - alive -> repeat for next block
            - dead -> check size of the block for aS >= S + sizeof(rprc_block_desc)
                - true -> 
                - fale ->
    - if not block present i.e. end sentinal,
        - allocate new
*/

void rprcalloc(memp* refp, memsz size, memp arena) {
}

#endif //SRC_LIB_RPRCALLOC_C
