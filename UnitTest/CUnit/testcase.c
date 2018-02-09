
/**
	测试实例
*/



#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>

#include "strformat.h"

void test_string_lenth(void){
	m_string test = "Hello";
	//m_string test = "Hello ";
	CU_ASSERT_EQUAL(string_lenth(test),5);
}

void test_to_upper(void){
	char test[] = "hello";
	CU_ASSERT_STRING_EQUAL(to_upper(test), "HELLO");
}

void test_append_str(void){
	char test1[20] = "Hello ";
	char test2[] = "Linux";
		
	CU_ASSERT_STRING_EQUAL(append_str(test1, test2),"Hello Linux" );
}

/**************************************************************************
数组名称：将多个测试方法打包成组，以供指定给一个Suite
功能描述：每个suite可以有一个或多个测试方法，以CU_TestInfo数组形式指定
**************************************************************************/
// CU_TestInfo是Cunit内置的一个结构体，它包括测试方法及描述信息
CU_TestInfo testcase[] = {
    {"test_string_lenth:",test_string_lenth},
    {"test_append_str:",test_append_str},
    CU_TEST_INFO_NULL
};

CU_TestInfo testcase2[] = {
    {"test_to_upper :",test_to_upper},
    CU_TEST_INFO_NULL
};




/**************************************************************************
函数名称：suite初始化过程
功能描述：
输入参数：
返   回：
**************************************************************************/
int suite_success_init(void){
    return 0;
}

/**************************************************************************
函数名称：suite清理过程，以便恢复原状，使结果不影响到下次运行
**************************************************************************/
int suite_success_clean(void){
    return 0;
}


//定义suite数组，包括多个suite，每个suite又会包括若干个测试方法。
CU_SuiteInfo suites[] = {
    {"testSuite1",suite_success_init,suite_success_clean,NULL,NULL,testcase},
    {"testsuite2",suite_success_init,suite_success_clean,NULL,NULL,testcase2},
    CU_SUITE_INFO_NULL
};


/**************************************************************************
函数名称：测试类的调用总接口
**************************************************************************/
void AddTests(){
    assert(NULL != CU_get_registry());
    assert(!CU_is_test_running());

    if(CUE_SUCCESS != CU_register_suites(suites)){
        exit(EXIT_FAILURE);
    }
}


