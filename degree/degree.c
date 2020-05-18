#include"degree.h"

int cel_to_far(int cel_degree){
    return cel_degree * (9.0/5) + 32;
}

int far_to_cel(int far_degree){
    return (far_degree) - 32 * (5.0/9);
}