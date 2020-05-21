#include <stdio.h>


/*degree conversion program without function*/

/*structure definition
* It will store the value and the unit 
*/
typedef struct{
  double value;
  char unit;        //'f' 'c' 'k' -> fahrenheit, celius and kelvin
} _degree;

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
   
   /*convert degree1 to fahrenheit*/
   double temp = degree1.value;
   degree1.value = degree1.value * (9.0/5) + 32;
   degree1.unit = 'f';
   printf("%0.1f° in celcius is %0.1f° in fahrenheit\n",temp, degree1.value);
   
   /*convert degree2 to celcius*/
   temp = degree2.value;
   degree2.value = (degree2.value - 32) * (5.0/9);
   degree2.unit = 'c';
   printf("%0.1f° in fahrenheit is %0.1f° in celcius\n", temp, degree2.value);
   
   /*convert degree3 to celius*/
   temp = degree3.value;
   degree3.value = degree3.value - 273.15;
   degree3.unit = 'c';
   printf("%0.1f° in kelvin is %0.1f° in celcius\n", temp, degree3.value);
   
   /*convert degree4 to kelvin*/
   temp = degree4.value;
   degree4.value = (degree4.value - 32)/1.800 + 273.15;
   degree4.unit = 'k';
   printf("%0.1f° in fahrenheit is %0.1f° in kelvin\n", temp, degree4.value);
   
    return 0;
}