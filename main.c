#include <stdio.h>
#include "contact.h"

int main() 
{

    int choice;
    int sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\n----------------------------\n");
        printf("|    \033[1;30mAddress Book Menu\033[0m     |\n");
        printf("----------------------------\n");
        printf("| 👤 1. \033[1;32mCreate contact\033[0m     |\n");
        printf("| 🔎 2. \033[1;36mSearch contact\033[0m     |\n");
        printf("| 📝 3. \033[1;33mEdit contact\033[0m       |\n");
        printf("| ❌ 4. \033[1;31mDelete contact\033[0m     |\n");
        printf("| 📝 5. \033[1;34mList all contacts\033[0m  |\n");
    	printf("| 📁 6. \033[1;35mSave contacts\033[0m      |\n");		
        printf("| 🔚 7. \033[1;31mExit\033[0m               |\n");
        printf("----------------------------\n");
        printf("\n<=><=>=<=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><\n\n");
        printf("\033[32mEnter your choice:\033[0m ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5: 
                int sortChoice; 
                printf("Enter the Choice to sort by : \n \033[33m1. Name\t 2.Email\t 3.Phone\t 4.No need of sorting\033[0m\nEnter the Choice : ");
                scanf("%d",&sortChoice);        
                listContacts(&addressBook, sortChoice);
                print(&addressBook);
                break;
            case 6:
                printf("\033[32mSaving and Exiting...\033[0m\n");
                Loading();
                printf("\033[32m...Completed !!!...\033[0m\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("\n\033[1;32m........THANK YOU ..........\033[0m\n\n");
                break;
            default:
                printf("\n\033[1;31mInvalid choice. Please try again.\033[0m\n\n");
        }
    } while (choice != 7);
    
       return 0;
}
