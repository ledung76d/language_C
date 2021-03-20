#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    char name[80];
    char number[20];
} PhoneEntry;
 
#define MAX_PHONE_ENTRIES 1000
typedef struct {
    //PhoneEntry entries[MAX_PHONE_ENTRIES];
    PhoneEntry *entries;
    int total;
} PhoneBook;
 
PhoneBook* createPhonebook(int size) {
    PhoneBook* nbook = malloc(sizeof(PhoneBook));
    nbook->entries=(PhoneEntry*)malloc(size *sizeof(PhoneEntry));
    nbook->total = 0;
    return nbook;
}

void dropPhoneBook(PhoneBook* book){
    free(book->entries);
    free(book);
}
void addPhoneNumber(char* number, char* name, PhoneBook* book);
char* getPhoneNumber(char* name, const PhoneBook* book);
int main() {
    printf("Size entries: ");
    int size;
    scanf("%d",&size);
    PhoneBook* nbook = createPhonebook(size);
    char number[10],name[10];
    //printf("Number: ");
    //scanf("%s",number);
    //printf("Name: ");
    //scanf("%s",name);
    //addPhoneNumber(number, name, nbook); 
    //printf("%s number: %s \n",name ,getPhoneNumber(name, nbook)); 
    addPhoneNumber("09", "name", nbook); 
    addPhoneNumber("08", "name1", nbook); 
    addPhoneNumber("07", "name2", nbook); 
    printf("%s number: %s \n","name" ,getPhoneNumber("name", nbook)); 
    printf("%s number: %s \n","name1" ,getPhoneNumber("name1", nbook));    
    printf("%s number: %s \n","name2" ,getPhoneNumber("name2", nbook));  
}

void addPhoneNumber(char* number, char* name, PhoneBook* book) {
    for(int i = 0; i < book->total; ++i) {
        if(strcmp(name, book->entries[i].name) == 0) {
            strcpy(book->entries[i].number, number);
            return;
        }
    }
    strcpy(book->entries[book->total].name, name);
    strcpy(book->entries[book->total].number, number);
    book->total++;
}
char* getPhoneNumber(char* name, const PhoneBook* book) {
    for(int i = 0; i < book->total; ++i) {
        if(strcmp(name, book->entries[i].name) == 0) {
            char* number = malloc(sizeof(char) * 20);
            strcpy(number, book->entries[i].number);
            return number;
        }
    }
    return NULL;
}