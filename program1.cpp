#include<iostream>
#include<vector>
#include<string>
using namespace std;
 class household
 {
    private:
    string id;
    string head;
    string address;
    int members;
    string contact;
    string status;
    public:
    household()
    {
    id=" ";
    head=" ";
    address=" ";
    members=0;
    contact=" ";
    status="active";
    }
    void registerhousehold(string houseid)
    {
      id=houseid;
      cout<<"Enter the headname: ";
      getline(cin,head);
      cout<<"Enter the address/Block Number: ";
      getline(cin,address);
      cout<<"Enter the number of members: ";
      cin>>members;
      cin.ignore();
      cout<<"Enter contact Number: ";
      getline(cin,contact);
      status="active";
      cout<<"\nHousehold register successfully ";
    }
    void display()
    {
    cout<<"HouseHold ID                 : "<<id;
    cout<<"\nHeadname                   :"<<head;
    cout<<"\nThe address/Block number is: "<<address;
    cout<<"\nThe Number of members      : "<<members;
    cout<<"\nThe contact number is      : "<<contact;
    cout<<"\nStatus                     : "<<status;   
 }
 bool search(string key)
 {
    return(id==key||head==key);
 }
 void modify()
 {
    cout<<"\nEnter the New Head Name      : ";
    getline(cin,head);
    cout<<"\nEnter the New address        : ";
    getline(cin,address);
    cout<<"\nEnter the New Number  of members: ";
    cin>>members;
    cout<<"\nEnter the New Contact number  : ";
    getline(cin,contact);
    cout<<"\nHouseHold details updated";
}
string getid()
{
    return id;
}
void changestatus(string s)
{
    status=s;
    cout<<"\nConnection status updated successfully";
}
 };
int main()
{
  household h[50];
  int count=0;
  int choice;
   string key;
   do 
   {
    cout<<"\n-----------SMART WATER MANAGEMENT--------------";
    cout<<"\n1.register";
    cout<<"\n2.Display all households";
    cout<<"\n3.search Households";
    cout<<"\n4.Modify Households";
    cout<<"\n5.Delete households";
    cout<<"\n6.Activate connection";
    cout<<"\n7.Deactivate connection";
    cout<<"\n8.Exit";
    cout<<"\n\nEnter your choice: ";
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1: 
        {
            if(count>=50)
            {
                cout<<"\nHousehold limit reached";
                break;
            }
           
            cout<<"\nEnter the Household ID: ";
            getline(cin,key);
            bool duplicate=false;
            for(int i=0;i<count;i++)
            {
                if(h[i].getid()==key)
                {
                    duplicate=true;
                    break;
                }
            }
                if(duplicate)
                {
                    cout<<"\nThe Household is already resistered";
                }
                else{
                    h[count].registerhousehold(key);
                    count++;
                }
                break;
            
                
            
        }
        case 2: 
        {
            if(count==0)
            {
                cout<<"\nNo Household is  found ";
            }
            else{
                for(int i=0;i,count;i++)
                {
                    h[i].display();
                    break;
                }
            }
            break;
        }
        case 3:
        {
            cout<<"Enter the Household id to search: ";
            getline(cin,key);
            bool found=false;
            for(int i=0;i<count;i++)
            {
                if(h[i].getid()==key)
                {
                    h[i].display();
                    bool found=true;
                    break;
                }
                if(!found)
                {
                    cout<<"\nThe household id is not found";
                }
            }
            break;
        }
        case 4:
        {
            cout<<"\nEnter the Household id to  modify: ";
            getline(cin,key);
            bool found=false;
            for(int i=0;i<count;i++)
            {
                if(h[i].getid()==key)
                {
                    h[i].modify();
                    found=true;
                    break;
                }
                if(!found)
                cout<<"\nThe Household id is not found";
            }
            break;
        }
        case 5:
        {
            cout<<"\nEnter the household id to delete: ";
            getline(cin,key);
            bool found=false;
            for(int i=0;i<count;i++)
            {
                if(h[i].getid()==key)
                {
                    for(int j=i;j<count-1;i++)
                    {
                        h[j]=h[j+1];
                        found=true;
                        break;
                    }

                }
                if(!found)
                {
                    cout<<"\nhousehold is not found";
                }
            }
            break;
            
        }
        case 6:
        case 7:
        {
            cout<<"\nEnter the Household id to change the status: ";
            getline(cin,key);
            bool found=false;
            for(int i=0;i<count;i++)
            {
                if(choice==6)
                {
                    h[i].changestatus("active");
                   
                }
                else
                {
                    h[i].changestatus("inactive");
                     found=true;
                    break;
                }
            }
            if(!found)
            {
                cout<<"\nHousehold not found";
            }
            break;
        }
        case 8:
        {
            cout<<"\nExitting";
            break;
        }
        default: 
        cout<<"\nInvalid choice";
        break;
    }
   }while(choice!=8);
   return 0;
}

