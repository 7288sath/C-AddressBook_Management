#include <stdio.h>
#include <stdlib.h>
#include "contact.h"
#include "file.h"
#include <unistd.h>

int choice = 0;
int i = 0, k = 0, found = 0;
int list_found[MAX_CONTACTS];
int list_index = 0;

Contact newContact;     //one structure to store new contact

void listContacts(AddressBook *addressBook, int sortCriteria)
{
    int i,j;
    Contact temp;

    switch (sortCriteria)
    {
        case 1:

        for(i=0; i<addressBook->contactCount - 1; i++)
        {
            for(j=0; j<addressBook->contactCount-1-i; j++)
            {
                if(my_strcmp(addressBook->contacts[j].name, addressBook->contacts[j+1].name) > 0)
                {
                    temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j+1];
                    addressBook->contacts[j+1] = temp;
                }
            }
        }
        break;

        case 2:

        for(i=0; i<addressBook->contactCount-1; i++)
        {
            for(j=0; j<addressBook->contactCount-1-i; j++)
            {
                if(my_strcmp(addressBook->contacts[j].email, addressBook->contacts[j+1].email) > 0)
                {
                    temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j+1];
                    addressBook->contacts[j+1] = temp;
                }
            }
        }
        break;

        case 3:

        for(i=0; i<addressBook->contactCount-1; i++)
        {
            for(j=0; j<addressBook->contactCount-1-i; j++)
            {
                if(my_strcmp(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone) > 0)
                {
                    temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j+1];
                    addressBook->contacts[j+1] = temp;
                }
            }
        }
        break;

        case 4:
            break;
            
        default:
            break;
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int i = 0;
    do
    {
        i=0;
        printf("Enter the Name : ");
        getchar();
        scanf("%[^\n]",newContact.name);

        while(newContact.name[i] != '\0')
        {
            if( !((newContact.name[i] >= 'A' && newContact.name[i] <= 'Z') || (newContact.name[i] >= 'a' && newContact.name[i] <= 'z') || newContact.name[i] == ' '))
            {
                printf("\033[31mInvalid Name. Enter Valid name.\033[0m\n");
                break;
            }
            i++;
        }
    }while(newContact.name[i] != '\0');


    int valid;
   do
    {
        int j=0;
        int k=0;
        int found = 0;
        valid = 1;

        getchar();
        printf("Enter the Phone Number : ");
        scanf("%49[^\n]",newContact.phone);

        if(my_strlen(newContact.phone) != 10)
        {
            valid = 0;
            printf("\033[31mPhone number should be exactly 10 digits.\033[0m\n");
            continue;
        }

        while(newContact.phone[j] != '\0')
        {
            if(!(newContact.phone[j] >= '0' && newContact.phone[j] <= '9'))
            {
                valid = 0;
                break;
            }
            j++;
        }

        if(valid)
        {
            for(k=0; k<addressBook->contactCount; k++)
            {
                if(my_strcmp(newContact.phone, addressBook->contacts[k].phone) == 0)
                {
                    valid = 0;
                    found = 1;
                    break;
                }    
            }
        }

        if(found)
        {
            printf("\033[31mPhone number exist. Enter New Number.\033[0m\n");
        }
        else if(!valid)
        {
            printf("\033[31mInvalid Phone Number. Enter Valid Number.\033[0m\n");
        }


    }while(!valid);

    int email_valid;
    do
    {
        int i=0;
        int j=0;
        int count = 0;
        email_valid = 1;

        getchar();
        printf("Enter the Email ID : ");
        scanf("%49[^\n]",newContact.email);
        int n = my_strlen(newContact.email);

        while(newContact.email[i] != '\0')
        {
            if((i==0 || i==n-1) && (newContact.email[0] == '@' || newContact.email[n-1] == '@' || newContact.email[0] == '.' || newContact.email[n-1] == '.'))
            {
                email_valid = 0;
                printf("\033[31m'@' or '.' should not be present at first or last.\033[0m\n");
                break;
            }
            else if((newContact.email[i] == '.' && newContact.email[i+1] == '.') || (newContact.email[i] == '@' && newContact.email[i+1] == '.'))
            {
                email_valid=0;
                printf("\033[31mInvalid Email address.\033[0m\n");
                break;
            }
            else if(newContact.email[i] == '@')
            {
                if(count == 0)
                {
                    count++;
                }
                else
                {
                    email_valid = 0;
                    printf("\033[31m'@' should be present only once.\033[0m\n");
                    break;
                }
            }
            else if(!((newContact.email[i] >= 'a' && newContact.email[i] <= 'z') || (newContact.email[i] == '.') || (newContact.email[i] == '-') || (newContact.email[i] == '_') || (newContact.email[i] >= '0' && newContact.email[i] <= '9')))
            {
                email_valid = 0;
                printf("\033[31mInvalid Email Address.\033[0m\n");
                break;
            }
            else if(my_strcmp(&newContact.email[n-4], ".com") != 0)
            {
                email_valid = 0;
                printf("\033[31mEmail address invalid.\033[0m\n");
                break;
            }
            i++;
        }

        if(email_valid)
        {
            for(j=0; j<addressBook->contactCount; j++)
            {
                if(my_strcmp(newContact.email, addressBook->contacts[j].email) == 0)
                {
                    email_valid = 0;
                    printf("\033[31mEmail address exist. Enter New ID.\033[0m\n");
                    break;
                }    
            }
        }

    }while(!email_valid);
    printf("\n\033[35mContact details:\033[0m\nName : %s\nPhone Number : %s\nEmail : %s\n",newContact.name,newContact.phone,newContact.email);
    addressBook->contacts[addressBook->contactCount++] = newContact;
    printf("\033[35m...Select option to Save the changes ...\033[0m\n");
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    choice = 0;
    char searchChoice[50];

    do
    {
        printf("Choose Option to Search by :\033[33m\n 1. Name\t 2. Email\t 3. Number\t 4. Exit\033[0m\nEnter the option : ");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
                printf("Enter Name to search : ");
                scanf("%49[^\n]",searchChoice);
                searchByChoice(addressBook, searchChoice, choice);
                break;

            case 2:
                printf("Enter Email to search : ");
                scanf("%49[^\n]",searchChoice);
                searchByChoice(addressBook, searchChoice, choice);
                break;
            case 3:
                printf("Enter Phone Number to search : ");
                scanf("%49[^\n]",searchChoice);
                searchByChoice(addressBook, searchChoice, choice);
                break;
        
            case 4:
                break;
            default :
                printf("Invalid Option\n");
                break;
        }
    }while(choice > 4);

}

void editContact(AddressBook *addressBook)
{
    int flag = 0;
	/* Define the logic for Editcontact */
    searchContact(addressBook);
    if(found)
    {
        static int choice;
        char editChoice[50];
        int reg_no;

        do
        {
            printf("Confirm the Registered No. : ");
            scanf("%d",&reg_no);

            for(i = 0; i<list_index; i++)
            {
                if(reg_no - 1 == list_found[i])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag)
            {
                printf("Choose Option to edit :\n\033[33m1. Name\t 2. Email\t 3. Number\t 4. Exit\033[0m\nEnter the option : ");
                scanf("%d",&choice);
                getchar();
                switch(choice)
                {
                    case 1:
                        int i = 0;
                        do
                        {
                            i=0;
                            printf("Enter the Name : ");
                            scanf("%[^\n]",editChoice);
                            getchar();
                            while(editChoice[i] != '\0')
                            {
                                if( !((editChoice[i] >= 'A' && editChoice[i] <= 'Z') || (editChoice[i] >= 'a' && editChoice[i] <= 'z') || editChoice[i] == ' '))
                                {
                                    printf("\033[31mInvalid Name. Enter Valid name.\033[0m\n");
                                    break;
                                }
                                i++;
                            }
                        }while(editChoice[i] != '\0');
                        EditChoice(addressBook, editChoice, choice, reg_no);
                        break;

                    case 2:
                        int email_valid;
                        do
                        {
                            
                            int i=0;
                            int j=0;
                            int count = 0;
                            email_valid = 1;

                            printf("Enter the Email ID : ");
                            scanf("%49[^\n]",editChoice);
                            getchar();
                            int n = my_strlen(editChoice);
                            while(editChoice[i] != '\0')
                            {
                                if(editChoice[0] == '@' || editChoice[n-1] == '@' || editChoice[0] == '.' || editChoice[n-1] == '.')
                                {
                                    email_valid = 0;
                                    printf("\033[31m'@' or '.' should not be present at first or last.\033[0m\n");
                                    break;
                                }
                                else if((editChoice[i] == '.' && editChoice[i+1] == '.') || (editChoice[i] == '@' && editChoice[i+1] == '.'))
                                {
                                    email_valid=0;
                                    printf("\033[31mInvalid Email address.\033[0m\n");
                                    break;
                                }
                                else if(editChoice[i] == '@')
                                {
                                    if(count == 0)
                                    {
                                        count++;
                                    }
                                    else
                                    {
                                        email_valid = 0;
                                        printf("\033[31m'@' should be present only once.\033[0m\n");
                                        break;
                                    }
                                }
                                else if(!((editChoice[i] >= 'a' && editChoice[i] <= 'z') || (editChoice[i] == '.') || (editChoice[i] == '-') || (editChoice[i] == '_') || (editChoice[i] >= '0' && editChoice[i] <= '9')))
                                {
                                    email_valid = 0;
                                    printf("\033[31mInvalid Email Address.\033[0m\n");
                                    break;
                                }
                                else if(my_strcmp(&editChoice[n-4], ".com") != 0)
                                {
                                    email_valid = 0;
                                    printf("\033[31mInvalid Email Address.\033[0m\n");
                                    break;
                                }
                                i++;
                            }

                            if(email_valid)
                            {
                                for(j=0; j<addressBook->contactCount; j++)
                                {
                                    if(my_strcmp(editChoice, addressBook->contacts[j].email) == 0)
                                    {
                                        email_valid = 0;
                                        printf("\033[31mEmail address exist. Enter New ID.\033[0m\n");
                                        break;
                                    }    
                                }
                            }

                        }while(!email_valid);
                        EditChoice(addressBook, editChoice, choice, reg_no);
                        break;

                    case 3:
                        int valid;
                        do
                        {
                            int j=0;
                            int k=0;
                            int found = 0;
                            valid = 1;

                            printf("Enter the Phone Number : ");
                            scanf("%s",editChoice);
                            getchar();

                            if(my_strlen(editChoice) != 10)
                            {
                                valid = 0;
                                printf("\033[31mPhone number should be exactly 10 digits.\033[0m\n");
                                continue;
                            }

                            while(editChoice[j] != '\0')
                            {
                                if(!(editChoice[j] >= '0' && editChoice[j] <= '9'))
                                {
                                    valid = 0;
                                    break;
                                }
                                j++;
                            }

                            if(valid)
                            {
                                for(k=0; k<addressBook->contactCount; k++)
                                {
                                    if(my_strcmp(editChoice, addressBook->contacts[k].phone) == 0)
                                    {
                                        valid = 0;
                                        found = 1;
                                        break;
                                    }    
                                }
                            }

                            if(found)
                            {
                                printf("\033[31mPhone number exist. Enter New Number.\033[0m\n");
                            }
                            else if(!valid)
                            {
                                printf("\033[31mInvalid Phone Number. Enter Valid Number.\033[0m\n");
                            }


                        }while(!valid);
                        EditChoice(addressBook, editChoice, choice, reg_no);
                        break;
        
                    case 4:
                        break;
                    default :
                        printf("Invalid Option\n");
                        break;
                }
            }
            else
            {
                printf("\n----------\033[1;31mRegister Number not matching. Please enter correct register number.\033[0m----------\n");
                break;
            }
        }while(choice > 4);
    }
    
}

void deleteContact(AddressBook *addressBook)
{
    int reg_no, k=0, flag=0;
	/* Define the logic for deletecontact */
    searchContact(addressBook);

    if(found)
    {
        printf("Confirm the Register Number to Delete (0 - for exit) : ");
        scanf("%d",&reg_no);

        if(reg_no == 0)
        {
            return;
        }
        for(i = 0; i<list_index; i++)
        {
            if(reg_no - 1 == list_found[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            char ch;
            getchar();
            printf("Are you sure ? You want to delete ? (Y/N) : Enter Y-yes or N-no :\n");
            scanf("%c",&ch);

            switch(ch)
            {
                case 'Y':
                case 'y':
                    for(k = reg_no - 1; k < addressBook->contactCount - 1; k++)
                    {
                        addressBook->contacts[k] = addressBook->contacts[k+1];
                    }
                    addressBook->contactCount--;
                    printf("\n");
                    Loading();
                    printf("\033[32m......Delete Contact Completed Successfully ......\033[0m\n");
                    break;
                case 'N':
                case 'n':
                    return;
                
                default :
                    return;
            }
        }
        else
        {
            printf("\n----------\033[1;31mRegister Number not matching. Please enter correct register number.\033[0m----------\n");
        }
    }
    else
    {
        return;
    }
    printf("\033[35m...Select option to Save the changes ...\033[0m\n");
}

void searchByChoice(AddressBook *addressBook, char *searchChoice, int choice)
{
    /* Define the logic for search by user choice*/
    i = 0;
    found = 0;
    list_index = 0;
    printf("\n<=><=>=<=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><\n\n");
    printf("===============================================================================================\n");
    printf("|                                       LIST OF CONTACTS Found                                |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("| Reg.No  |              NAME              |               EMAIL            | CONTACT NUMBER  |\n ");
    printf("-----------------------------------------------------------------------------------------------\n");
    for(i=0; i<addressBook->contactCount; i++)
    {
        switch(choice)
        {
            case 1:
                if((my_strstr(addressBook->contacts[i].name, searchChoice)) != NULL)
                {
                    found++;
                    list_found[list_index++] = i;
                    printf("| \033[30;47m%-5d\033[0m   | \033[30;47m%-30s\033[0m | %-30s | %-15s |\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].email,addressBook->contacts[i].phone);
                }
                break;

            case 2:
                if((my_strstr(addressBook->contacts[i].email, searchChoice)) != NULL)
                {
                    found++;
                    list_found[list_index++] = i;
                    printf("|\033[30;47m %-5d\033[0m   | %-30s | \033[30;47m%-30s\033[0m | %-15s |\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].email,addressBook->contacts[i].phone);
                }
                break;

            case 3:
                if((my_strstr(addressBook->contacts[i].phone, searchChoice)) != NULL)
                {
                    found++;
                    list_found[list_index++] = i;
                    printf("| \033[30;47m%-5d\033[0m   | %-30s | %-30s | \033[30;47m%-15s\033[0m |\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].email,addressBook->contacts[i].phone);
                }
                break;
        }
        
    }
    if(found)
    {
        printf("===============================================================================================\n");
        printf("\n<=><=>=<=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><\n\n");
    }
    else
    {
        printf("|                                       \033[31mCONTACTS Not found\033[0m                                    |\n");
        printf("===============================================================================================\n");
        printf("\n<=><=>=<=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><\n\n");
    }
}

void EditChoice(AddressBook *addressBook, char *editChoice, int choice, int num)
{
    if(choice == 1)
    {
        my_strcpy(addressBook->contacts[num - 1].name, editChoice);
        printf("\n");
        Loading();
        printf("\033[32m......Edit Completed Successfully ......\033[0m\n");
    }
    else if(choice == 2)
    {
        my_strcpy(addressBook->contacts[num - 1].email, editChoice);
        printf("\n");
        Loading();
        printf("\033[32m......Edit Completed Successfully ......\033[0m\n");
    }
    else if(choice == 3)
    {
        my_strcpy(addressBook->contacts[num - 1].phone, editChoice);
        printf("\n");
        Loading();
        printf("\033[32m......Edit Completed Successfully ......\033[0m\n");
    }
    printf("\033[35m...Select option to Save the changes ...\033[0m\n");
}

void Loading(void)
{
    int i,j;

    for(i=0; i<=25; i++)
    {
        printf("\rloading [ ");
        for(j=0; j<i; j++)
        {
            printf("-");
        }
        printf("] %d%%",j*4);
        fflush(stdout);
        usleep(100000);
    }
    printf("\r\033[K");
}

void print(AddressBook *addressBook)
{
    int i;
    printf("\n<=><=>=<=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><\n\n");
    printf("===============================================================================================\n");
    printf("|                                       LIST OF CONTACTS                                      |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("| Reg.No  |              NAME              |               EMAIL            | CONTACT NUMBER  |\n ");
    printf("-----------------------------------------------------------------------------------------------\n");
    for(i=0; i<addressBook->contactCount; i++)
    {
        printf("| %-5d   | %-30s | %-30s | %-15s |\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].email,addressBook->contacts[i].phone);
    }
    printf("===============================================================================================\n");
    printf("\n<=><=>=<=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><\n\n");
}