#include<bits/stdc++.h>
using namespace std;
vector<pair<string, int>> info;
void payslip();
void DisplayPayslip();
void Totalsell();
void Exit();

double NetSell=0;
void payslip()
{

    time_t now = time(0);
    char * dt = ctime(&now);
    ofstream file;
    file.open("input.txt");
    file<<"\tPayslip of IST\n\n";
    cout<<"Enter Customer Name: ";
    string name;
    cin.ignore();
    getline(cin,name);


    file<<"To: "<<name<<"\n"<<"Date and Time:"<<dt<<"\n\n";
    file<<"Product\t\t  quantity\tcost\n";
    cout<<"Types of Punjabi\n\n";
    double total = 0;


    cout<<"1. Shahara Punjabi\n2. platinum Punjabi\n3. premium Punjabi\n4. Laxury Punjabi\n5.Exit\n";
    while(1)
    {
         cout<<"Select the Punjabi: ";
        int p, n, t;
        string punjabi;
        cin>>p;
        if(p==1)
        {
            punjabi = "Shahara Punjabi ";
            file<<punjabi<<"\t";
            cout<<"Enter the quanitiy: ";
            cin>>n;
            file<<n<<"\t";
            t = (n*7950);
            file<<t<<"BDT\n";
            total += t;
        }
        else if(p==2)
        {
            punjabi = "Platinum Punjabi";
            file<<punjabi<<"\t";
            cout<<"Enter the quanitiy: ";
            cin>>n;
            file<<n<<"\t";
            t = (n*6950);
            file<<t<<"BDT\n";
            total += t;
        }
        else if(p==3)
        {
            punjabi = "Premium Punjabi ";
            file<<punjabi<<"\t";
            cout<<"Enter the quanitiy: ";

            cin>>n;
            file<<n<<"\t";
            t = (n*3950);
            file<<t<<"BDT\n";
            total += t;
        }
        else if(p==4)
        {
            punjabi = "Laxury Punjabi  ";
            file<<punjabi<<"\t";
            cout<<"Enter the quanitiy: ";
            cin>>n;
            file<<n<<"\t";
            t = (n*5950);
            file<<t<<"BDT\n";
            total += t;
        }
        else if(p>=5)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice\n";
            return ;
        }
    }
    file<<"----------------------------------------\n";
    file<<"Total\t\t\t\t"<<total<<"BDT\n";
    file<<"discount(0%)\t\t\t00000BDT\n";
    file<<"----------------------------------------\n";
    file<<"Net Total\t\t\t"<<total<<"BDT\n";
    file<<"\t\tGood Bye\n\n";
    file.close();
    NetSell +=total;
    cout<<"\n\npayslip Procedure successfully done\n";
    info.push_back({name, total});
}
void DisplayPayslip()
{
    ifstream file;
    file.open("input.txt", ios::out|ios::in);
    string s;
    while(getline(file, s))
    {
        cout<<s<<"\n";
    }
    file.close();
}

void Totalsell()
{
    time_t now = time(0);
    char * dt = ctime(&now);
    long long T = 0;
    cout<<"\t---Todays sell---\n";
    cout<<dt<<endl;
    cout<<"SL No.\tCustomer Name\t\tAmount(BDT)\n";
    cout<<"-----------------------------------\n";

    for(int i=0; i<info.size(); i++){
        cout<<i+1<<"\t"<<info[i].first<<"\t\t"<<info[i].second<<"BDT"<<endl;
        T += info[i].second;
    }
    cout<<"-----------------------------------\n";
    cout<<"\n"<<"IN Total sell = "<<T<<"BDT\n";
}

void Exit()
{
    ofstream file;
    file.open("sell.txt", ios::app);

    time_t now = time(0);
    char * dt = ctime(&now);

    file<<dt<<"-->"<<endl;
    for(int i=0; i<info.size(); i++){
        file<<info[i].first<<"\t"<<info[i].second<<"BDT"<<endl;
    }
    file.close();
}


int main()
{

    cout<<"\t\tWELCOME TO ISTShop\n\n";
    bool loop = true;
    while(loop)
    {
        cout<<"The operation what you can make\n";
        cout<<"1. Create payslip\n";
        cout<<"2.Display payslip\n";
        cout<<"3. Total sell\n";
        cout<<"4. Exit\n\n";
        cout<<"Enter your operation: \n";
        int op;
        cin>>op;
        switch (op)
        {
        case 1:
            payslip();
            break;
        case 2:
            DisplayPayslip();
            break;
        case 3:
            Totalsell();
            break;
        case 4:
            Exit();
            loop = false;
            break;
        }
        cout<<"---------------------------------------\n";
    }
    cout<<"\t----GOODBYE----\n";

    return 0;
}
