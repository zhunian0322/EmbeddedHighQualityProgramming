#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"

extern CuSuite * strUtilGetSuite();


void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, strUtilGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void)
{
    RunAllTests();
	return 0;
}
