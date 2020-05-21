#include <stdio.h>

/*program to calculate add integers with functions*/

int add(int *a, int *b){
    return *a + *b;
}

int main()
{   
    printf("Add program with function pointers\n");
    int(*add_ptr)(int *,int *) = add;
    int a = 10;
    int b = 5;
    int sum = add_ptr(&a,&b);
    printf("sum of a + b = %d\n", sum);
    
    int c = 14;
    int d = 6;
    sum = add_ptr(&c,&d);
    printf("sum of c + d = %d\n", sum);
    
    int e = 11;
    int f = 44;
    sum = add_ptr(&e,&f);
    printf("sum of e + f = %d\n", sum);
    
    

    return 0;
}