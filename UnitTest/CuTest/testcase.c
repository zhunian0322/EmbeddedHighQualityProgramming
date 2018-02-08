
/**
	测试实例
*/



#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CuTest.h"

#include "strformat.h"

void test_string_lenth(CuTest *tc){
//	m_string test = "Hello";
	m_string test = "Hello ";
	CuAssertIntEquals(tc, 5, string_lenth(test));
}

void test_to_upper(CuTest *tc){
	char test[] = "hello";
	CuAssertStrEquals(tc, "HELLO", to_upper(test));
}

void test_append_str(CuTest *tc){
	char test1[20] = "Hello ";
	char test2[] = "Linux";
		
	CuAssertStrEquals(tc, "Hello Linux",append_str(test1, test2));	
}

CuSuite * strUtilGetSuite(){
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite,test_string_lenth);
	SUITE_ADD_TEST(suite,test_to_upper);
	SUITE_ADD_TEST(suite,test_append_str);
	
	return suite;
}

