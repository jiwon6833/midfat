#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static __attribute__((noinline)) char **strarrcopy(char **arr) {
    int count = 0, i;
    char **newarr;

    if (!arr) return NULL;

    while (arr[count]) count++;

    newarr = malloc(sizeof(char *) * (count + 1));
    if (!newarr) {
	printf("argvcopy: malloc failed");
	exit(-1);
    }
    for (i = 0; i < count; i++) {
	if (!(newarr[i] = strdup(arr[i]))) {
	    printf("argvcopy: strdup failed");
	    exit(-1);
	}
    }
    return newarr;
}

void  __attribute__((noinline)) argvcopy(char ***argvptr, char ***envpptr){
    extern char **environ;

    if (argvptr) *argvptr = strarrcopy(*argvptr);
    //assert(!envpptr || !*envpptr || environ == *envpptr);
    //environ = strarrcopy(environ);
    //if (envpptr) *envpptr = environ;
}
