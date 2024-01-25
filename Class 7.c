int *f() // returns pointer
{
  int arr[20];
  arr[0] = 42;
  return arr;
}

int *make_block_int(int sz)
{
  int *p = (int *)malloc(sz * sizeof(int));
  if (p == NULL){ // malloc returns 0 if there is no memory / error
    // use malloc to create something in local then use it / keep it outside of it back in global
    // You can't change size of arrays, but you can change size of mallocs using re-alloc

    printf("out of memory\n");
    exit(1);
  }
  return p;
}





int main()
{
  int *p = f();
  p[0]; // undefined behavior
        // might crash, because no guarantee of memory
        // might sometimes print 42
        // AVOID
  int *q = make_block_int(20);
  q[7] = 50; // works
}

/*
Free function

Good practice to free() memory blocks to you allocated
C cannot use a malloc-ed block for something new until its freed
For continuously running programs, you might run out of memory (if you keep mallocing and not freeing)
On a modern OS, everything will be freed fater the program terminates
On less modern OS (older operating systems), or on very light OSs, it might not be the case
Memory leak: a situation where memory is allocated but never freed

*/
  