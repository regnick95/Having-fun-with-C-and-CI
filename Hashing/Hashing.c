/*
 * Hashing.c
 * Hashing data structure with heap
 *
 *  Created on: May 20, 2020
 *      Author: Reginald
 */
#include <stdio.h>
#include <string.h>


#define CAPACITY 100

typedef struct{
	char key[10];	//the key at a particular index;for this program it will be a name
	int value;		//the value for that particular key; it will use age

}Hash_table; 		//the data structure

Hash_table table[CAPACITY];	//declare an array of of elements as a hash table structure
int size = 0;		//how many elements in the table

/**
* This function initialize the hashtable
*/
void init_table(){


	/*initialize by setting values to -1*/
	for(int i = 0; i < CAPACITY; i++){
		table[i].value = -1;
	}
}


/**
* This function is to calculate the index of a given key
* @param key The key for which the index needs to be determined
* @return The index of the key in the hash table
*/
int hashcode(char *key){
	int len = strlen(key);
	int sum = 0;
	for(int i = 0; i < len; i++){
		sum += key[i];
	}
	return sum % CAPACITY;	//return the index of that key
}

/**
* This function is to insert a key in the hash table
* @param key The key to be inserted
* @param value The value to be inserted
* @return 1 if the key has been sucessfully inserted. 0 if not
*/
int insert(char *key, int value){
	int index = hashcode(key);
	if(table[index].value != -1){
		return -1;	//return -1 means, index is occupied
	}
	strcpy(table[index].key, key); //update the key of the element of that index
	table[index].value = value;	//update the value of the element of that index
	size++; //increase the size of the hash table

	return 1; //returns 1 ; element has been inserted
}

/**
* This function is to find a key in the hash table
* @param key The key for which the index needs to be determined
* @return The index of the key in the hash table
*/
int find(char *key){
	int index = hashcode(key);
	if(table[index].value == -1){
		return -1;
	}
	return index;
}

/**
* This function is to display the inserted keys with their respective value and index
*/
void display(){
	for(int i = 0; i < CAPACITY; i++){
		if(table[i].value != -1){
			printf("%s with age : %d is found at index %d\n", table[i].key,table[i].value,i);
		}
	}
}


int main(){
	/*Hard coded input*/
	char name1[] = {"Harry"};
	int age1 = 15;
	char name2[] = {"Bob"};
	int age2 = 35;
	char name3[] = {"Mira"};
	int age3 = 23;
	char name4[] = {"Alyssa"};
	int age4 = 28;
	char name5[] = {"Alonso"};
	int age5 = 19;

	/*intialize table*/
	init_table();
	/*inserting the inputs*/
	insert(name1,age1);
	insert(name2,age2);
	insert(name3,age3);
	insert(name4,age4);
	insert(name5,age5);
	/*displaying elements of the table*/
	display();

	return 0;
}










