#include <stdio.h>

/*program to calculate add integers with functions*/

int add(int *a, int *b){
    return *a + *b;
}

int main()
{
    printf("Add program with functions and pointers to data\n");
    int a = 10;
    int b = 5;
    int sum = add(&a,&b);
    printf("sum of a + b = %d\n", sum);
    
    int c = 14;
    int d = 6;
    sum = add(&c,&d);
    printf("sum of c + d = %d\n", sum);
    
    int e = 11;
    int f = 44;
    sum = add(&e,&f);
    printf("sum of e + f = %d\n", sum);

    int g = 17;
    int h = 25;
    sum = add(&g,&h);
    printf("sum of g + h = %d\n", sum);

    int i = 33;
    int j = 77;
    sum = add(&i,&j);
    printf("sum of i + j = %d\n", sum);

    int k = 8;
    int m = 65;
    sum = add(&k,&m);
    printf("sum of k + m = %d\n", sum);
    
    

    return 0;
}
