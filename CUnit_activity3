/******************************************************************************


#include <stdio.h>

/*structure definition
* It will store the value and the unit 
*/
typedef struct{
  double value;
  char unit;        //'f' 'c' 'k' -> fahrenheit, celius and kelvin
} _degree;


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
double conv_to_fah(_degree *degree){
    
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
double conv_to_cel(_degree *degree){
    
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
double conv_to_kel(_degree *degree){
    
    if(degree -> unit == 'c'){
        degree -> value = degree->value + 273.15; 
        return degree->value;
    }
    else if(degree -> unit == 'f'){
        return  (degree->value + 459.67) * 5.0/9;
    }
    return degree->value;
}





int main()
{
    /*hard coded input*/
   _degree degree1;
   degree1.value = 34;
   degree1.unit = 'c';
   
   _degree degree2;
   degree2.value = 98;
   degree2.unit = 'f';
   
   _degree degree3;
   degree3.value = 205;
   degree3.unit = 'k';
   
    _degree degree4;
   degree1.value = 18;
   degree1.unit = 'c';
   
   _degree degree5;
   degree2.value = 25;
   degree2.unit = 'f';
   
   _degree degree6;
   degree3.value = 117;
   degree3.unit = 'k';
   
    _degree degree7;
   degree1.value = 34;
   degree1.unit = 'c';
   
   _degree degree8;
   degree2.value = 98;
   degree2.unit = 'f';
   
   _degree degree9;
   degree3.value = 205;
   degree3.unit = 'k';
   
   //conv_to_fah(&degree1);
   display_degree(&degree1);
   printf("%d° in celcius is %d° in fahrenheit\n",34, (int)conv_to_fah(&degree1));
   printf("%d° in fahrenheit is %d° in celcius\n",98, (int)conv_to_cel(&degree2));
   printf("%d° in kelvin is %d° in celcius\n",205, (int)conv_to_cel(&degree3));
   
   

    return 0;
}
