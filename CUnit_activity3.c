#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>

/*structure definition
* It will store the value and the unit 
*/
typedef struct{
  float value;
  char unit;        //'f' 'c' 'k' -> fahrenheit, celius and kelvin
} _degree;


 /*hard coded input*/
   _degree degree1;
   _degree degree2;
   _degree degree3;
   _degree degree4;
   _degree degree5;
   _degree degree6;
   _degree degree7;
   _degree degree8;
   _degree degree9;


/**
* This function prints the value of a degree and its unit.
* @param degree The degree structure pointer.
*/
void display_degree(_degree *degree){
    printf("%d° %c\n",(int)degree->value, degree->unit);
}

/**
* This function converts the value of a degree struct to fahrenheit equivalent.It also changes the unit
* @param degree The degree structure pointer.
* @return The converted value in fahrenheit
*/
float conv_to_fah(_degree *degree){
    
    if(degree -> unit == 'c'){
        degree -> value = degree->value * (9.0/5) + 32;
        return degree->value;
    }
    else if(degree -> unit == 'k'){
        return  degree->value * (9.0/5 ) - 459.67;
    }
    return degree->value;   //return the original value if the same unit is passed
}

/**
* This function converts the value of a degree struct to celcius equivalent.It also changes the unit
* @param degree The degree structure pointer.
* @return The converted value in celcius
*/
float conv_to_cel(_degree *degree){
    
    if(degree -> unit == 'f'){
        degree -> value = (degree->value - 32) * (5.0/9);
        return degree->value;
    }
    else if(degree -> unit = 'k'){
        return  degree->value - 273.15;     
    }
    return degree->value;
}

/**
* This function converts the value of a degree struct to kelvin equivalent.It also changes the unit
* @param degree The degree structure pointer.
* @return The converted value in kelvin
*/
float conv_to_kel(_degree *degree){
    
    if(degree -> unit == 'c'){
        degree -> value = degree->value + 273.15; 
        return degree->value;
    }
    else if(degree -> unit == 'f'){
        return  (degree->value + 459.67) * 5.0/9;
    }
    return degree->value;
}

void test_degeeconv(void){
  CU_ASSERT((int)conv_to_fah(&degree1) == 93); //34°c to f
  CU_ASSERT((int)conv_to_cel(&degree2) == 36); //98°f to cel
  CU_ASSERT((int)conv_to_cel(&degree3) == -68.15); //205°k to cel
  CU_ASSERT((int)conv_to_kel(&degree4) == 291);   //18°c to kel
  CU_ASSERT((int)conv_to_kel(&degree5) == 269);  //25°f to kel
  CU_ASSERT((int)conv_to_fah(&degree6) == -249);  //117°k to fah
  CU_ASSERT((int)conv_to_fah(&degree7) == 134);  //57°c to fah
  CU_ASSERT((int)conv_to_kel(&degree8) == 280);  //46°f to kel
  CU_ASSERT((int)conv_to_cel(&degree9) == 182);  //91°k to cel
  
}


int main()
{ 
  /*hard coded input*/
   degree1.value = 34;
   degree1.unit = 'c';
   
   degree2.value = 98;
   degree2.unit = 'f';
   
   degree3.value = 205;
   degree3.unit = 'k';
   
   degree4.value = 18;
   degree4.unit = 'c';
   
   degree5.value = 25;
   degree5.unit = 'f';
   
   degree6.value = 117;
   degree6.unit = 'k';
   
   degree7.value = 57;
   degree7.unit = 'c';
  
   degree8.value = 46;
   degree8.unit = 'f';
   
   degree9.value = 91;
   degree9.unit = 'k';
  
  
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("conversion test suite",0,0);
  CU_add_test(suite, "conversion test", test_degeeconv);
  CU_basic_run_tests();
  CU_cleanup_registry();
   
  return 0;
}
