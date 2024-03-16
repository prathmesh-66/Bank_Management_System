#include<bits/stdc++.h>
#include<conio.h> //getch
#include<windows.h> //system and sleep
using namespace std;

class banking{
    int completed; // it will keep update the how many coustomer are there
    string id;
    struct customer{
        string id,name,fname,address,phone, idcard;
        int cash; 
    }customer[100];

    public:
        banking(){
            completed=0;
        }
    
    public: 
        void options(); 
        void newaccount();
        void display();
        void update();
        void search();
        void transaction();
        void logout();

};

int main(){
    string name;
    int pin;

    cout<<"\n\n\n\t\t\tBank management system\t\t\t\t\t\n\n"<<endl;

    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter a 4 digit pin: ";
    cin>>pin;
    cout<<"your account is creating... please wait";
    for(int i=0;i<4;i++){
        cout<<".";
        Sleep(1000);
    }
    cout<<"\n\nyour account is created succesfully";
    system("CLS");


    loginpage:

    cout<<"\n\n\n\t\t\tlogin page\t\t\t\t\t\n\n"<<endl;
    string name1;
    int pin1;
    cout<<"Enter your name: ";
    cin>>name1;
    cout<<"Enter a 4 digit pin: ";
    cin>>pin1;

    if(name==name1 && pin==pin1){
        system("CLS");
        banking obj;
        obj.options();
        
    }
    else{
        cout<<"incorrect username or pin"<<endl;
        goto loginpage;
    }
    return 0;

}

void banking::options(){
    char select;
    while(1){
        cout<<"press 1 for Creating New Account: "<<endl;
    cout<<"press 2 for Displaying the Customer Information: "<<endl;
    cout<<"press 3 for Updating Customer Information: "<<endl;   
    cout<<"press 4 for Searching the Specific Customer: "<<endl;   
    cout<<"press 5 for Transaction Operations like Deposite and Withdraw: "<<endl;
    cout<<"press 6 Lougout: "<<endl;    

    select=getch();  
    switch (select){
    case '1':
    system("CLS");
    banking::newaccount();
        break;
    
    case '2':
    system("CLS");
    banking::display();
        break;
    
    case '3':
    system("CLS");
    banking::update();
        break;
    
    case '4':
    system("CLS");
    banking::search();
        break;
    

    case '5':
    system("CLS");
    banking::transaction();
        break;
    
    case '6':
    system("CLS");
    banking::logout();
        break;
    
    default:
    cout<<"Invalid Operation";
        break;
    }
    }
}

void banking::newaccount(){
    cout<<"\n New account Creating..."<<endl;
    cout<<"Enter the Record of "<<completed+1 << " customer"<<endl;
    cout<<"Enter your ID: ";
    cin>>customer[completed].id;
    cout<<"Enter your Name: ";
    cin>>customer[completed].name;
    cout<<"Enter your Father Name: ";
    cin>>customer[completed].fname;
    cout<<"Enter your Phone Number: ";
    cin>>customer[completed].phone;
    cout<<"Enter your ID Card Number: ";
    cin>>customer[completed].idcard;
    cout<<"Enter your Cash: ";
    cin>>customer[completed].cash;

    completed++;
    
}


void banking::display(){
    for(int i=0;i<completed;i++){
        cout<<"Record of customer"<<endl;
        cout<<"Customer unique ID: "<<customer[i].id<<endl;
        cout<<"Customer Name: "<<customer[i].name<<endl;
        cout<<"Customer Father Name: "<<customer[i].fname<<endl;
        cout<<"Customer Phone No: "<<customer[i].phone<<endl;
        cout<<"Customer ID Card Number: "<<customer[i].idcard<<endl;
        cout<<"Customer Amount: "<<customer[i].cash<<endl;

        i++;

    }
    
}

void banking::update(){
    cout<<"Enter the id of customer for updating the information";

    cin>>id;
    for(int i=0;i<completed;i++){
        if(id==customer[i].id){
            cout<<"Existing Record of "<<completed<<" customer"<<endl;
        cout<<"Customer unique ID: "<<customer[i].id<<endl;
        cout<<"Customer Name: "<<customer[i].name<<endl;
        cout<<"Customer Father Name: "<<customer[i].fname<<endl;
        cout<<"Customer Phone No: "<<customer[i].phone<<endl;
        cout<<"Customer ID Card Number: "<<customer[i].idcard<<endl;
        cout<<"Customer Amount: "<<customer[i].cash<<endl;


    cout<<"Udating the customer information..."<<endl;
    cout<<"Enter your ID: ";
    cin>>customer[i].id;
    cout<<"Enter your Name: ";
    cin>>customer[i].name;
    cout<<"Enter your Father Name: ";
    cin>>customer[i].fname;
    cout<<"Enter your Phone Number: ";
    cin>>customer[i].phone;
    cout<<"Enter your ID Card Number: ";
    cin>>customer[i].idcard;
    cout<<"Enter your Cash: ";
    cin>>customer[i].cash;
        }
        else if(i==completed-1){
            cout<<"Customer Record NOT Found !"<<endl;
        }
    }
    
    
}

void banking::search(){
    cout<<"Enter the ID of customer for searching the information: ";
    cin>>id;
    
 for(int i=0;i<completed;i++){
        if(id==customer[i].id){
            cout<<"Customer Record Found"<<endl;
        cout<<"Customer unique ID: "<<customer[i].id<<endl;
        cout<<"Customer Name: "<<customer[i].name<<endl;
        cout<<"Customer Father Name: "<<customer[i].fname<<endl;
        cout<<"Customer Phone No: "<<customer[i].phone<<endl;
        cout<<"Customer ID Card Number: "<<customer[i].idcard<<endl;
        cout<<"Customer Amount: "<<customer[i].cash<<endl;
        }

        else if(i==completed-1){
            cout<<"Customer Record NOT Found !"<<endl;
        }
    }
    
}

void banking::transaction(){
    cout<<"Enter the ID of customer for Transaction the information";
    cin>>id;
    int cash1;

    char select;

    for(int i=0;i<completed;i++){
        if(id==customer[i].id){
            cout<<"Customer Record Found"<<endl;
            cout<<"Customer name: "<<customer[i].name<<endl;
            cout<<"Customer Existing Amount:"<<customer[i].cash<<endl;
            cout<<"press 1 for deposite amount: "<<endl;
            cout<<"press 2 for wihtdraw amount: "<<endl;

            select=getch();
        switch (select)
        {
        case '1':
            cout<<"Enter the Amount for Deposite: ";
            cin>>cash1;
            cout<<"Your Transaction is Processing please wait...! "<<endl;
            Sleep(3000);
            customer[i].cash+=cash1;
            cout<<"Transaction DONE ! "<<endl;
            cout<<"New Amount: "<<customer[i].cash<<endl;
            
            break;

        case '2':
        previouswithdraw:
            cout<<"Enter the Amount for withdraw: ";
            cin>>cash1;
            if(cash1>customer[i].cash){
                cout<<"Your amount is greater than existing amount"<<endl;
                goto previouswithdraw;
            }
            cout<<"Your Transaction is Processing please wait...! "<<endl;
            Sleep(3000);
            customer[i].cash-=cash1;
            cout<<"Transaction DONE ! "<<endl;
            cout<<"New Amount: "<<customer[i].cash<<endl;
            
            break;
        
        default:
            break;
        }

        }
        else if(i==completed-1){
            cout<<"Customer Record NOT Found !"<<endl;
        }
    }

}

void banking::logout(){
    exit(0);
    
}
