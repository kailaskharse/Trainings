/* memlock.c

   Demonstrate the use of mlock(), to place memory locks, and mincore(), to
   retrieve memory-residence information about the calling processes virtual
   memory pages.

   Note: some UNIX implementations do not provide mincore().

   The madvise() system call is upported on Linux since kernel 2.4.
*/
#define _BSD_SOURCE             /* Get mincore() declaration and MAP_ANONYMOUS
                                   definition from <sys/mman.h> */
#include <sys/mman.h>
#include <stdio.h>
#define errExit(str) perror(str)
/* Display residency of pages in range [addr .. (addr + length - 1)] */

static void
displayMincore(char *addr, size_t length)
{
    unsigned char *vec;
    long pageSize, numPages, j;
	printf("\n %s: \n",__func__);

#ifndef _SC_PAGESIZE
    pageSize = getpagesize();   /* Some systems don't have _SC_PAGESIZE */
#else
    pageSize = sysconf(_SC_PAGESIZE);
#endif

    numPages = (length + pageSize - 1) / pageSize;
    vec = malloc(numPages);
    if (vec == NULL)
        errExit("malloc");

    if (mincore(addr, length, vec) == -1)
        errExit("mincore");

    for (j = 0; j < numPages; j++) {
        if (j % 64 == 0)
            printf("%s%10p: ", (j == 0) ? "" : "\n", addr + (j * pageSize));
        printf("%c", (vec[j] & 1) ? '*' : '.');
    }
    printf("\n");

    free(vec);
}

int
main(int argc, char *argv[])
{
    char *addr;
    size_t len, lockLen;
    long pageSize, stepSize, j;

    if (argc != 4 || strcmp(argv[1], "--help") == 0)
        printf("%s num-pages lock-page-step lock-page-len\n", argv[0]),exit(10);

#ifndef _SC_PAGESIZE
    pageSize = getpagesize();
    if (pageSize == -1)
        errExit("getpagesize");
#else
    pageSize = sysconf(_SC_PAGESIZE);
    if (pageSize == -1)
        errExit("sysconf(_SC_PAGESIZE)");
#endif

    len =      atoi(argv[1]) * pageSize;
    stepSize = atoi(argv[2]) * pageSize;
    lockLen =  atoi(argv[3]) * pageSize;

    addr = mmap(NULL, len, PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED)
        errExit("mmap");

    printf("Allocated %ld (%#lx) bytes starting at %p\n",
            (long) len, (unsigned long) len, addr);

    printf("Before mlock:\n");
    displayMincore(addr, len);

    /* Lock pages specified by command-line arguments into memory */

    for (j = 0; j + lockLen <= len; j += stepSize)
        if (mlock(addr + j, lockLen) == -1)
            errExit("mlock");

    printf("After mlock:\n");
    displayMincore(addr, len);

    exit(0);
}
