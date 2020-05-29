/*
 * This program prints alphabet characters using multithreading
 * each thread is responsible for one character
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_ALPH 26

/*structure definition
* It will store threads information
*/
typedef struct{
  int tid;
  char* alphabet;        
} thread_info;

/*function prototypes*/
char* initialize(char* alphabet);  
void* char_print(void* arg);

pthread_mutex_t lock;   //mutex lock
int i = 0;      //will increment in order to access next alphabet character

int main()
{
    
    
    pthread_mutex_init(&lock, NULL);    //intitialize mutex lock
    pthread_t threads[NUM_ALPH];    //array of threads. one thread for each letter
    thread_info arg[NUM_ALPH];  //thread info structure for each thread
    
  
  
    char* alphabet = initialize(alphabet); //initialize the pointer, assign each index with a character
    for(int i=0;i<NUM_ALPH;i++){
        arg[i].tid = i;
        arg[i].alphabet = alphabet;    //each thread will have its own char pointer pointing to same array of alphabet [a,b,c,d,...,z]
        pthread_create(&threads[i], NULL, char_print, &arg[i]); //create the threads
    }    
    
    for (i = 0; i < NUM_ALPH; i++) 
        pthread_join(threads[i], NULL);
        
    free(alphabet); // deallocate memory
    alphabet = NULL;
    
    return 0;
   
    
}


/**
* This function is to initialize the pointer array
* @param alphabet The char pointer that needs to be initialized
* @return The pointer that points to the array of alphabet
*/
char*initialize(char * alphabet){
    
    char current = 'a';
    alphabet = (char *) malloc(NUM_ALPH*sizeof(char));
    for(int i = 0;i<NUM_ALPH;i++){
        alphabet[i] = (char)current+i; //next character in ascii table
    }
    return alphabet;
    
}

/*function to print elements in the array*/

/**
* This function is to print elements in the array. Each thread will execute this function
* @param arg The arg passed by the running thread
*/
void * char_print(void * arg){
    thread_info* thr_arg = (thread_info*) arg;
    int tid = thr_arg->tid;
    char* alphabet = thr_arg->alphabet;
    /* get mutex before modifying and printing*/
    pthread_mutex_lock(&lock);
    printf("Thread %d is printing %c\n",tid, alphabet[i%26]);
    i++;
    pthread_mutex_unlock(&lock);
    
    
}


