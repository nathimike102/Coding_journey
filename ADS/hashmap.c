#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//building hashmap
#define MAx 256
#define tableSize 10

typedef struct hashMap{
	char name[MAX];
	int age;
	bool is_occupied;
}hashMap;

hashMap hashTable[tableSize];

void initHashTable(){
	for(int=0;i<tableSize;i++){
		hashTable[i].is_occupied = false;
	}
}

unsigned int hash(char *name){
	unsigned int hashVal = 0;
	int length = strlen(name);
	for(int i=0;i<length;i++){
		hashVal+=name[i];
		hashVal = (hashVal * name[i])%tableSize; //Mutlipy with a prime number to reduce collisions in string hashing
	}
	return hashVal;
}

//Insert
bool hashTableInsert(hashMap *s){
	unsigned int idx = hash(s->name);
	unsigned int original_idx = idx;
	while(hashTable[idx].is_occupied = true){
		idx = (idx+1)%tableSize;
		if(idx==original_idx) return false;
	}
	hashTable[idx] = s;
	hashTable[idx].is_occupied = true;
	return true;
}

//Delete

//Search

//Display

int main(){
	initHashTable();
	hashMap Nathi = {.name="Nathi", .age = 21};

	hashTableInsert
}