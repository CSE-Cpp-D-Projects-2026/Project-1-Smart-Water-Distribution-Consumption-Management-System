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
void menu()
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
            cout<<"\nExit";
            break;
        }
        default: 
        cout<<"\nInvalid choice";
        break;
    }
   }while(choice!=8);

}
 };

class Tank{
    public:
     string id,refilldate;
     int capacity,available,minimum;
     void addtank()
     {
        cout<<"Enter Tank ID : ";
        cin>>id;
        cout<<"Enter Tank Capacity : ";
        cin>>capacity;
        cout<<"Enter Available Water : ";
        cin>>available;
        cout<<"Enter Minimum Level : ";
        cin>>minimum;
        cout<<"Enter last Refill Date : ";
        cin>>refilldate;
         if (capacity<=0||available<0||available>capacity||minimum<0||minimum>capacity)
         {
            cout<<"Invalid Input! Please enter valid values."<<endl;
            return;
         }
         cout<<"Tank added successfully!"<<endl;
     }
     void replenish()
     {
        cout<<"Enter the amount of water to replenish: ";
        int amount;
        cin>>amount;
        if (amount <= 0)
        {
            cout<<"Invalid Input! Please enter a positive value."<<endl;
            return;
        }
        if (available + amount > capacity)
        {
            cout<<"Cannot replenish. Exceeds tank capacity."<<endl;
            return;
        }
        available += amount;
        cout<<"Tank replenished successfully!"<<endl;
     }
     void display()
     {
        cout<<"Tank ID : "<<id<<endl;
        cout<<"Tank Capacity : "<<capacity<<endl;
        cout<<"Available Water : "<<available<<endl;
        cout<<"Minimum Level : "<<minimum<<endl;
        cout<<"Last Refill Date : "<<refilldate<<endl;
     }
     void checklevel()
     {
        if(available<=minimum)
        {
            cout<<"Low storage alert!"<<endl;
        }
        else
        {
            cout<<"Water level is enough."<<endl;
        }
     }
     void menu()
     {
        Tank t[100];
        int count=0,choice,i;
        string searchIO;
        do
        {
            cout<<"\n1.Add Tank";
            cout<<"\n2.Replenish Tank";
            cout<<"\n3.Display Tank ";
            cout<<"\n4.Check low storage";
            cout<<"\n5.Exit";
            cout<<"\nEnter your choice: ";
            cin>>choice;
            switch (choice)
            {
            case 1:
                t[count].addtank();
                count++;
                break;
            case 2:
                cout<<"Enter Tank ID : ";
                cin>>searchIO;
                for(i=0;i<count;i++)
                {
                    if(t[i].id==searchIO)
                    {
                        t[i].replenish();
                        break;
                    }
                }
                if(i==count)
                {
                    cout<<"Tank not found!"<<endl;
                    break;
                }
                case 3:
                cout<<"Enter Tank ID : ";
                cin>>searchIO;
                for(i=0;i<count;i++)
                {
                    if(t[i].id==searchIO)
                    {
                        t[i].display();
                        break;
                    }
                }
                if(i==count)
                {
                    cout<<"Tank not found!"<<endl;
                    break;
                }
                case 4:
                cout<<"Enter Tank ID : ";
                cin>>searchIO;
                for(i=0;i<count;i++)
                {
                    if(t[i].id==searchIO)
                    {
                        t[i].checklevel();
                        break;
                    }
                }
                if(i==count)
                {
                    cout<<"Tank not found!"<<endl;
                    break;
                }
                case 5:
                cout<<"Exiting..."<<endl;
                break;
            
            default:
                cout<<"Invalid choice"<<endl;
                break;
            }
        }while(choice!=5);
     }
};

int main()
{
    household h;
    Tank t;
    int choice;

    do
    {
        cout<<"\n------ SMART WATER MANAGEMENT ------";
        cout<<"\n1.Household Management";
        cout<<"\n2.Tank Management";
        cout<<"\n3.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                h.menu();
                break;

            case 2:
                t.menu();
                break;

            case 3:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice\n";
        }
    }while(choice!=3);

    return 0;
}