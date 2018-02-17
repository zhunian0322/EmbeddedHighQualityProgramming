#include <stdio.h>
#include <stdlib.h>

#include "check.h"


extern Suite * string_test_suite(void);

int main(){
	int number_failed;
	
	SRunner *sr = srunner_create(string_test_suite());		// 为测试包创建测试任务
		
	srunner_run_all(sr, CK_NORMAL);							// 运行测试包中测试用例
	
	number_failed = srunner_ntests_failed(sr);				// 记录失败条目数量
	
	srunner_free(sr);										// 释放测试任务资源
	
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
	
}