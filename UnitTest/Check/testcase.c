#include <stdio.h>
#include <stdlib.h>

#include "check.h"

#include "strformat.h"

START_TEST(test_string_lenth)
{
	m_string test = "Hello";
	//m_string test = "Hello ";
	ck_assert_int_eq(string_lenth(test), 5);
}
END_TEST

START_TEST(test_to_upper)
{
	char test[] = "hello";
	ck_assert_str_eq(to_upper(test), "HELLO");
}
END_TEST

START_TEST(test_append_str)
{
	char test1[20] = "Hello ";
	char test2[] = "Linux";	
	ck_assert_str_eq(append_str(test1, test2), "Hello Linux");
}
END_TEST


Suite * string_test_suite(void)
{
	Suite *s = suite_create("m_string");					// 建立测试包
	TCase *tc_test_case = tcase_create("m_string");			// 建立测试用例集
	
	suite_add_tcase(s, tc_test_case);					    // 将测试用例集加入到测试包
	
	// 将测试用例添加到测试集中
	tcase_add_test(tc_test_case,test_string_lenth);
	tcase_add_test(tc_test_case,test_to_upper);
	tcase_add_test(tc_test_case,test_append_str);
	
	return s;
}
