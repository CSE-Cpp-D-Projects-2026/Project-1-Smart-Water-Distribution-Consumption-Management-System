
#include <iostream>
using namespace std;
struct Household
{
    string id, name, address, contact, status;
    int members;
};
Household h[100];
int count = 0;
void addHousehold()
{
    cout << "\nEnter ID: ";
    cin >> h[count].id;
    for (int i = 0; i < count; i++)
    {
        if (h[i].id == h[count].id)
        {
            cout << "ID already exists!\n";
            return;
        }
    }
    cout << "Enter Name: ";
    cin >> h[count].name;
    cout << "Enter Address: ";
    cin >> h[count].address;
    cout << "Enter Number of Members: ";
    cin >> h[count].members;
    cout << "Enter Contact Number: ";
    cin >> h[count].contact;
    cout << "Enter Status: ";
    cin >> h[count].status;
    count++;
    cout << "Household Added Successfully!\n";
}
void display()
{
    if (count == 0)
    {
        cout << "\nNo Records Found!\n";
        return;
    }
    for (int i = 0; i < count; i++)
    {
        cout << "\nID: " << h[i].id;
        cout << "\nName: " << h[i].name;
        cout << "\nAddress: " << h[i].address;
        cout << "\nMembers: " << h[i].members;
        cout << "\nContact: " << h[i].contact;
        cout << "\nStatus: " << h[i].status << "\n";
    }
}
void search()
{
    string id;
    cout << "\nEnter ID to Search: ";
    cin >> id;
    for (int i = 0; i < count; i++)
    {
        if (h[i].id == id || h[i].name == id)
        {
            cout << "\nRecord Found!";
            cout << "\nID: " << h[i].id;
            cout << "\nName: " << h[i].name;
            cout << "\nAddress: " << h[i].address;
            cout << "\nMembers: " << h[i].members;
            cout << "\nContact: " << h[i].contact;
            cout << "\nStatus: " << h[i].status << "\n";
            return;
        }
    }
    cout << "Record Not Found!\n";
}
void modify()
{
    string id;
    cout << "\nEnter ID to Modify: ";
    cin >> id;
    for (int i = 0; i < count; i++)
    {
        if (h[i].id == id)
        {
            cout << "Enter New Name: ";
            cin >> h[i].name;
            cout << "Enter New Address: ";
            cin >> h[i].address;
            cout << "Enter New Members: ";
            cin >> h[i].members;
            cout << "Enter New Contact: ";
            cin >> h[i].contact;
            cout << "Record Updated!\n";
            return;
        }
    }
    cout << "Record Not Found!\n";
}
void deleteHousehold()
{
    string id;
    cout << "\nEnter ID to Delete: ";
    cin >> id;
    for (int i = 0; i < count; i++)
    {
        if (h[i].id == id)
        {
            for (int j = i; j < count - 1; j++)
                h[j] = h[j + 1];
            count--;
            cout << "Record Deleted!\n";
            return;
        }
    }
    cout << "Record Not Found!\n";
}
void changeStatus()
{
    string id;
    cout << "\nEnter ID: ";
    cin >> id;
    for (int i = 0; i < count; i++)
    {
        if (h[i].id == id)
        {
            cout << "Enter New Status (Active/Inactive): ";
            cin >> h[i].status;
            cout << "Status Changed!\n";
            return;
        }
    }
    cout << "Record Not Found!\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n===== HOUSEHOLD MANAGEMENT =====";
        cout << "\n1. Add Household";
        cout << "\n2. Modify Household";
        cout << "\n3. Delete Household";
        cout << "\n4. Search Household";
        cout << "\n5. Display Households";
        cout << "\n6. Change Status";
        cout << "\n7. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: addHousehold(); break;
            case 2: modify(); break;
            case 3: deleteHousehold(); break;
            case 4: search(); break;
            case 5: display(); break;
            case 6: changeStatus(); break;
            case 7: cout << "Thank You!"; break;
            default: cout << "Invalid Choice!";
        }
    } while (choice != 7);
    return 0;
}
