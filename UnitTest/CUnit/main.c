#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>


#define AUTOMATED	0
#define BASICE		0	

extern void AddTests();

/*************************************************************************
*功能描述：运行测试入口
**************************************************************************/
int RunTest(){
        if(CU_initialize_registry()){
                fprintf(stderr, " Initialization of Test Registry failed. ");
                exit(EXIT_FAILURE);
        }else{
                AddTests();
				
               #if AUTOMATED
				printf("AUTOMATED\n");
                CU_set_output_filename("TestMax");
                CU_list_tests_to_file();
                CU_automated_run_tests();
               #elif BASICE
				printf("BASICE\n");
				CU_basic_set_mode(CU_BRM_VERBOSE);
                CU_basic_run_tests();
			   #else
				printf("CONSOLE\n");
				CU_console_run_tests();   
			   #endif
				
                
                CU_cleanup_registry();
                return CU_get_error();
        }
}
/*************************************************************************
*功能描述：测试类主方法
**************************************************************************/

int main(int argc, char * argv[])
{
   return  RunTest();
    
}