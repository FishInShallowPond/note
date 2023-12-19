#include <stdio.h>
#include <stdlib.h>

static void before(void) __attribute__((constructor));

static void before3(void) __attribute__((constructor(103)));
static void before2(void) __attribute__((constructor(102)));
static void before1(void) __attribute__((constructor(101)));

static void before2()
{
	printf("before  102\n");
}

static void before1()
{
	printf("before  101\n");
}

static void before3()
{
	printf("before  103\n");
}

static void before()
{
	printf("before main\n");
}


int main()
{
	printf("main\n");
	return 0;
}
