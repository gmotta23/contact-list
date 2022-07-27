#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char* name;
  char* number;
} contact;

typedef struct {
  contact **contacts;
  size_t nContacts;
  size_t size;
  size_t contact_size;
} contact_list;

contact_list* create_contact_list(size_t contact_size);

char* copy_string(char* string);

contact* create_contact(int id, char* name, char* number);

void delete_contact_list(contact_list* contactList);

int add_contact_to_contact_list(contact_list* contactList, contact* newContact);

contact* find_contact(contact_list* contactList, int contact_id);

void remove_contact_from_contact_list(contact_list* contactList, int contact_id);

void update_contact_from_contact_list(contact_list* contactList, contact* newContact, int contact_id);

void print_contacts(contact_list* contactList);

void print_contact(contact* contact);
