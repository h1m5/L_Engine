//
//  MemoryManager.h
//  L_Engine
//
//  Created by Imhoisili Otokhagua on 25/03/15.
//  Copyright (c) 2015 TriKomand. All rights reserved.
//

#include <iostream>

#ifndef __L_Engine__MemoryManager__
#define __L_Engine__MemoryManager__


struct BlockHeader
{
    // union-ed with data
    BlockHeader *Next;
};

struct PageHeader
{
    // followed by blocks in this page
    PageHeader  *Next;
    
    // helper function that gives the first block
    BlockHeader *Blocks(void)
    { return reinterpret_cast<BlockHeader *>(this + 1); }
};

class Allocator
{
public:
    
    // debug patterns
    static const unsigned char PATTERN_ALIGNMENT = 0xFC;
    static const unsigned char PATTERN_ALLOCATED = 0xFD;
    static const unsigned char PATTERN_FREE  = 0xFE;
    
    // constructor
    Allocator
    (
     unsigned dataSize,
     unsigned pageSize,
     unsigned alignment
     );
    
    Allocator();
    
    // destructor
    ~Allocator(void);
    
    // resets the allocator to a new configuration
    void Reset
    (
     unsigned dataSize,
     unsigned pageSize,
     unsigned alignment
     );
    
    // allocates a block of memory
    void *Allocate(void);
    
    // deallocates a block of memory
    void Free(void *p);
    
    // deallocates all memory
    void FreeAll(void);
    
private:
    
    // fill a free page with debug patterns
    void FillFreePage(PageHeader  *p);
    
    // fill a free block with debug patterns
    void FillFreeBlock(BlockHeader *p);
    
    // fill an allocated block with debug patterns
    void FillAllocatedBlock(BlockHeader *p);
    
    // gets the next block
    BlockHeader *NextBlock(BlockHeader *p);
    
    // the page list
    PageHeader *m_pageList;
    
    // the free list
    BlockHeader *m_freeList;
    
    // size-related data
    unsigned m_dataSize     ;
    unsigned m_pageSize     ;
    unsigned m_alignmentSize;
    unsigned m_blockSize    ;
    unsigned m_blocksPerPage;
    
    // statistics
    unsigned m_numPages     ;
    unsigned m_numBlocks    ;
    unsigned m_numFreeBlocks;
    
    // disable copy & assignment
    Allocator(const Allocator &clone);
    Allocator &operator=(const Allocator &rhs);
};

class MemoryManager {
    Allocator *m_alloc;
    static MemoryManager *m_instance;
    MemoryManager();
public:
//    ~MemoryManager();
    void startUp();
    void shutDown();
    Allocator* getAllocator(){ return m_alloc; }
    
    static MemoryManager *get()
    {
        if (!m_instance){}
            m_instance = new MemoryManager();
        return m_instance;
    }
};

#endif /* defined(__L_Engine__MemoryManager__) */
