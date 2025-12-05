#include <stdio.h>
#include "file.h"
#include "contact.h"

//This function collects the data and write those in contact text file in csv formate.
void saveContactsToFile(AddressBook *addressBook) 
{
    int i = 0;
    FILE *data = fopen("contacts.csv","w");         //opens file and stores address in FILE pointer data

    fprintf(data, "%d\n", addressBook->contactCount);       //to print total number of contacts present 

    for(i=0; i<addressBook->contactCount; i++)
    {
        fprintf(data, "%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);  //Adds all contacts line by line
    }

    fclose(data);       //need to close the file once done
}


//Same as save contacts, but here we load contacts from text file one by one using read mode and fscanf function
void loadContactsFromFile(AddressBook *addressBook) 
{
    int i = 0;
    FILE *data = fopen("contacts.csv", "r");

    fscanf(data, "%d\n", &addressBook->contactCount);

    for(i=0; i<addressBook->contactCount; i++)
    {
        fscanf(data, "%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    fclose(data);
}
