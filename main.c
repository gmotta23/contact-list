#include "contacts/contacts.h"

int main() {
  contact_list* pContactList = create_contact_list(2);

  for (int iter = 0; iter <= 4; iter++) {
    char name[100], number[100];
    sprintf(name, "name %d", iter);
    sprintf(number, "number %d", iter);
    contact newContact = {.name = name, .number = number};
    add_contact_to_contact_list(pContactList, &newContact);
  }

  contact updatedContact = {.name = "updated name 3", .number = "updated number 3"};
  update_contact_from_contact_list(pContactList, &updatedContact, 3);

  remove_contact_from_contact_list(pContactList, 2);

  print_contacts(pContactList);

  contact* contact = find_contact(pContactList, 5);
  print_contact(contact);

  return 0;
}