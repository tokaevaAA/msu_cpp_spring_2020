#ifndef ALLOCATOR_H
#define ALLOCATOR_H

void makeAllocator(size_t maxSize);
char* alloc(size_t size);
void reset();

#endif