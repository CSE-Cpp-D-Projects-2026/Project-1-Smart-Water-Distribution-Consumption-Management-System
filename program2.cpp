#include<iostream>
#include<string>
using namespace std;
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
    Tank t;
    t.menu();
    return 0;
}