// #include <stdio.h>
// #include<string.h>

// #define MAX_CONTACTS 1

// struct contacts {
//     char name[50];
//     int phoneNo;
//     char emailid[50];
// };

// struct contacts contactList[MAX_CONTACTS];
// int contactCount = 0;

// void addContact(char name[], int phoneNo, char emailid[]) {
//     if (contactCount < MAX_CONTACTS) {
//         strncpy((char *)&contactList[contactCount].name, name, sizeof(contactList[contactCount].name));
//         contactList[contactCount].phoneNo = phoneNo;
//         strncpy((char *)&contactList[contactCount].emailid, emailid, sizeof(contactList[contactCount].emailid));
//         contactCount++;
//         printf("Contact added successfully.\n");
//     } else {
//         printf("Contact list is full.\n");
//     }
// }

// void searchContact(char name[]) {
//     int found = 0;
//     for (int i = 0; i < contactCount; i++) {
//         if (strcmp((char *)&contactList[i].name, name) == 0) {
//             printf("Contact found:\nName: %s\nPhone No: %d\nEmail: %s\n",
//                    (char *)&contactList[i].name,
//                    contactList[i].phoneNo,
//                    (char *)&contactList[i].emailid);
//             found = 1;
//             break;
//         }
//     }
//     if (!found) {
//         printf("Contact not found.\n");
//     }
// }

// void displayContacts() {
//     printf("Contact List:\n");
//     for (int i = 0; i < contactCount; i++) {
//         printf("Name: %s, Phone No: %d, Email: %s\n",
//                (char *)&contactList[i].name,
//                contactList[i].phoneNo,
//                (char *)&contactList[i].emailid);
//     }
// }

// int main() {
//     int choice;
//     char name[50], emailid[50];
//     int phoneNo;

//     while (1) {
//         printf("\n1. Add Contact\n2. Search Contact\n3. Display Contacts\n4. Exit\nEnter choice: ");
//         scanf("%d", &choice);
//         getchar();

//         switch (choice) {
//             case 1:
//                 printf("Enter name: ");
//                 fgets(name, sizeof(name), stdin);
//                 name[strcspn(name, "\n")] = 0;
//                 printf("Enter phone number: ");
//                 scanf("%d", &phoneNo);
//                 getchar();
//                 printf("Enter email: ");
//                 fgets(emailid, sizeof(emailid), stdin);
//                 emailid[strcspn(emailid, "\n")] = 0;
//                 addContact(name, phoneNo, emailid);
//                 break;
//             case 2:
//                 printf("Enter name to search: ");
//                 fgets(name, sizeof(name), stdin);
//                 name[strcspn(name, "\n")] = 0;
//                 searchContact(name);
//                 break;
//             case 3:
//                 displayContacts();
//                 break;
//             case 4:
//                 return 0;
//             default:
//                 printf("Invalid choice.\n");
//         }
//     }
//     return 0;
// }


