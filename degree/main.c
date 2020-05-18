#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include "degree.h"

void test_degeeconv(void){
  CU_ASSERT(cel_to_far(28) == 82);
  CU_ASSERT(far_to_cel(82) == 28);
  CU_ASSERT(cel_to_far(0) == 32);
  CU_ASSERT(far_to_cel(32) == 0);
  CU_ASSERT(cel_to_far(100) == 212);
  CU_ASSERT(far_to_cel(212) == 100);
}

int main()
{
    //int c_degree = 28;
    //int f_degree = 85;
    
    //#printf("%d° celcius is equal to %d° fahrenheit\n", c_degree, cel_to_far(c_degree));
    //#printf("%d° fahrenheit is equal to %d° celcius\n", f_degree, far_to_cel(f_degree));
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("conversion test suite",0,0);
  CU_add_test(suite, "conversion test", test_degeeconv);
  CU_basic_run_tests();
  CU_cleanup_registry();

    return 0;
}
