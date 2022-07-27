#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacts.h"

contact_list* create_contact_list(size_t contact_size) {
  contact_list* pContactList = malloc(sizeof(contact_list));
  if (NULL != pContactList) {
    pContactList->nContacts = 0;
    pContactList->size = contact_size;
    pContactList->contact_size = contact_size;
    pContactList->contacts = malloc(sizeof(contact*) * contact_size);

    if (NULL == pContactList->contacts) {
      free(pContactList);
      return NULL;
    }
  }
  return pContactList;
}

char* copy_string(char* string) {
  int len = strlen(string);
  char* pNewString = malloc(len);
  memcpy(pNewString, string, len);
  return pNewString;
}

contact* create_contact(int id, char* name, char* number) {
  contact* pContact = malloc(sizeof(contact));

  char* pNewName = copy_string(name);
  char *pNewNumber = copy_string(number);

  if (NULL != pContact) {
    pContact->id = id;
    pContact->name = pNewName;
    pContact->number = pNewNumber;
  }

  return pContact;
}

void delete_contact_list(contact_list* contactList) {
  free(contactList->contacts);
  free(contactList);
}

int add_contact_to_contact_list(contact_list* contactList, contact* newContact) {
  size_t nContacts = contactList->nContacts;

  if (nContacts >= contactList->size) {
    size_t newSize = contactList->size + contactList->contact_size;
    void* newContacts = realloc(contactList->contacts, sizeof(contact*) * newSize);
    if (NULL == newContacts) {
      return 0;
    } else {
      contactList->size = newSize;
      contactList->contacts = (contact**)newContacts;
    }
  }

  newContact->id = nContacts;

  contact* pCreatedContact = create_contact(newContact->id, newContact->name, newContact->number);

  contactList->contacts[nContacts] = pCreatedContact;
  ++contactList->nContacts;

  return 1;
}

contact* find_contact(contact_list* contactList, int contact_id) {
  contact* contact = contactList->contacts[contact_id];
  if (contact && contact->id < 0) {
    return NULL;
  }
  return contact;
}

void remove_contact_from_contact_list(contact_list* contactList, int contact_id) {
  contact* contact = find_contact(contactList, contact_id);
  if (contact != NULL) {
    contact->id = -1;
    contact->name = "";
    contact->number = "";
  }
}

void update_contact_from_contact_list(contact_list* contactList, contact* newContact, int contact_id) {
  contact* contact = find_contact(contactList, contact_id);
  if (contact != NULL) {
    contact->name = newContact->name;
    contact->number = newContact->number;
  }
}

void print_contacts(contact_list* contactList) {
  for (int id = 0; id <= contactList->nContacts; id++) {
    contact* contact = find_contact(contactList, id);
    print_contact(contact);
  }
}

void print_contact(contact* contact) {
  if (contact) {
    printf("%d\n", contact->id);
    printf("%s\n", contact->name);
    printf("%s\n", contact->number);
  }
}
