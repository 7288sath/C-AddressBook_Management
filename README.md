# Address Book Management System (C)

A modular address book application written in C.
The project supports storing, managing, sorting and validating contact details using CSV-based file handling.

## Features
- Add contact
- Delete contact
- Update contact
- Search contact (by name, email, phone)
- Sort contacts (by name, email, phone)
- Input validation (email, phone number, empty fields)
- Persistent storage using CSV file
- Modular design using multiple .c and .h files

## Project Structure
- main.c
- contact.c/ contact.h
- file.c/ file.h
- strings.c
- populate.c/ populate.h
- contacts.csv (storing contacts)

## How to compile
1. gcc main.c contact.c file.c strings.c populate.c
2. gcc *.c

## How to Run
- ./a.out

## Concepts Used
- File handling (read/write CSV)
- Structures and pointers
- Modular programming
- String manipulation and validation
  
  
