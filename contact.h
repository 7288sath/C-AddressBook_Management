#ifndef CONTACT_H
#define CONTACT_H

//Some macros to store digits

#define MAX_CONTACTS 100        //For maximum contacts 
#define MAX_CHAR 50             //For maximum character length

//Defined a structure to store name, number and email
typedef struct {
    char name[MAX_CHAR];
    char phone[MAX_CHAR];
    char email[MAX_CHAR];
} Contact;                  //typedefed the struture as Contact


//Defined a struture to store Contacts and contact count 
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;                      //typedefed as AddressBook


//All the functions prototype
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);


void searchByChoice(AddressBook *addressBook, char *searcChoice, int choice);
void EditChoice(AddressBook *addressBook, char *editCoice, int choice, int num);
void print(AddressBook *addressBook);
void Loading(void);


//My own string functions prototype
int my_strlen(const char *string);
int my_strcmp(const char *str1, const char *str2);
char *my_strstr(const char *str1, const char *str2);
void my_strcpy(char *dest, const char *src);
#endif
