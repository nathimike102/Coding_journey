//Hashtable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_VAL 256
#define TABLE_SIZE 10

typedef struct student{
    int id;
    char name[MAX_VAL];
    struct student *next;
}student;

struct student *hashTable[TABLE_SIZE];
void inti_table(){
    for(int i=0;i<TABLE_SIZE;i++){
        hashTable[i]=NULL;
    }
}
//Hash Function
unsigned int hash(int num){
    unsigned int idx = num % TABLE_SIZE;
    return idx;
}

//Insert
bool insertIntoTable(student *s){
    if(s==NULL) return false;
    unsigned int idx = hash(s->id);
    s->next = hashTable[idx];
    hashTable[idx]=s;
    return true;
}

//Delete
student *hashDelete(student *s){
    unsigned int idx = hash(s->id);
    if(hashTable[idx]==NULL){
        return NULL;
    }
    student *temp = hashTable[idx];
    student *prev = NULL;
    while(temp && temp->id!=s->id){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return NULL;
    }
    else if(prev==NULL){
        hashTable[idx]=temp->next;
    }
    else{
        prev->next = temp->next;
    }
    return temp;
}

//Search
student *hashLookUp(int id){
    unsigned int idx = hash(id);
    if(hashTable[idx]==NULL){
        return NULL;
    }
    student *temp = hashTable[idx];
    while(temp && temp->id!=id){
        temp=temp->next;
    }
    if(temp==NULL){
        return NULL;
    }
    return temp;
}

//Display
void print_table(){
    for(int i=0;i<TABLE_SIZE;i++){
        if(hashTable[i]==NULL){
            printf("\t%i\t-----\n",i);
        }
        else{
            student *temp= hashTable[i];
            printf("\t%i\t",i);
            while(temp){
                printf("-----%d %s \t",temp->id,temp->name);
                temp=temp->next;
            }
            printf("\n");
        }
    }
}

int main()
{
	inti_table();

    student Nathi = {.id=123, .name = "Nathi"};
    student Denis = {.id=133, .name = "Denis"};
    student Danny = {.id=124, .name = "Danny"};
    student Mike = {.id=125, .name="Mike"};

    insertIntoTable(&Nathi);
    insertIntoTable(&Denis);
    insertIntoTable(&Danny);
    insertIntoTable(&Mike);

    print_table();

    student *temp = hashLookUp(123);
    if(temp == NULL){
        printf("\tNot found");
    }
    else{
        printf("\tFound %s",temp->name);
    }
    printf("\n");

    student *temp1 = hashLookUp(134);
    if(temp1 == NULL){
        printf("\tNot found");
    }
    else{
        printf("\tFound");
    }
    printf("\n");

    // student *temp = hashLookUp(125);
    // if(temp == NULL){
    //     printf("NOt found");
    // }
    // else{
    //     printf("Found");
    // }
    // printf("\n");

}