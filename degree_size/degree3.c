#include <stdio.h>


/*degree conversion program with function*/

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
float conv_to_fah(_degree degree){
    
    if(degree.unit == 'c'){
        degree.value = degree.value * (9.0/5) + 32;
        return degree.value;
    }
    else if(degree.unit == 'k'){
        return  degree.value * (9.0/5 ) - 459.67;
    }
    return degree.value;   //return the original value if the same unit is passed
}

/**
* This function converts the value of a degree struct to celcius equivalent.It also changes the unit
* @param degree The degree structure pointer.
* @return The converted value in celcius
*/
float conv_to_cel(_degree degree){
    
    if(degree.unit == 'f'){
        degree.value = (degree.value - 32) * (5.0/9);
        return degree.value;
    }
    else if(degree.unit == 'k'){
        return  degree.value - 273.15;     
    }
    return degree.value;
}

/**
* This function converts the value of a degree struct to kelvin equivalent.It also changes the unit
* @param degree The degree structure pointer.
* @return The converted value in kelvin
*/
float conv_to_kel(_degree degree){
    
    if(degree.unit == 'c'){
        degree.value = degree.value + 273.15; 
        return degree.value;
    }
    else if(degree.unit == 'f'){
        degree.value = (degree.value - 32)/1.800 + 273.15;
        return degree.value;    //(degree->value + 459.67) * 5.0/9;
    }
    return degree.value;
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
   degree4.value = 54;
   degree4.unit = 'f';
   
  
   double temp = degree1.value;
   printf("%0.1f° in celcius is %0.1f° in fahrenheit\n",temp, conv_to_fah(degree1));
   temp = degree2.value;
   printf("%0.1f° in fahrenheit is %0.1f° in celcius\n",temp, conv_to_cel(degree2));
   temp = degree3.value;
   printf("%0.1f° in kelvin is %0.1f° in celcius\n",temp, conv_to_cel(degree3));
   temp = degree4.value;
   printf("%0.1f° in fahrenheit is %0.1f° in kelvin\n", temp, conv_to_kel(degree4));
   
    
   
   

    return 0;
}