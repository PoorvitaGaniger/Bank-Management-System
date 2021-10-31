#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
class account
{
	int acno;
	char name[50];
  char address[60];
	int deposit;
	char type;
public:
  
	void create_account();	
  //function to get data from user
	void show_account() const;	
  //function to show data on screen
	void modify();	
  //function to add new data
	void dep(int);	
  //function to accept amount and add to balance amount
	void draw(int);	
  //function to accept amount and subtract from balance amount
	void report() const;	
  //function to show data in tabular format
  void info1() const;	
  //function to show name of required user
  void info2() const;
  //function to show address of required user
  void info3() const;
  //function to show balance of required user
	int return_accountNo() const;	
  //function to return account number
	int return_deposit() const;	
  //function to return balance amount
	char return_accType() const;	
  //function to return type of account
};    
void account::create_account()
{
	cout<<"\nEnter The account Number :";
	cin>>acno;
	cout<<"\nEnter The Name of The account Holder :";
	cin.ignore();
	cin.getline(name,50);
  cout<<"\nEnter The address of The account Holder :";
	//cin.ignore();
	cin.getline(address,60);
	cout<<"\nEnter Type of The account (Current[C]/Savings[S]) : ";
	cin>>type;
	type=toupper(type);
  if (type=='C')
  {
    cout<<"\nEnter The Initial amount(>=1000 for current account) : ";
  }
	else if(type=='S')
  {
    cout<<"\nEnter The Initial amount(>=500 for savings account) : ";
  }
	cin>>deposit;
	cout<<"\nAccount Created..";
}

void account::show_account() const
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name :";
	cout<<name;
  cout<<"\nAccount Holder Address :";
	cout<<address;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}
void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
  cout<<"\nModify Account Holder Address : ";
	cin.ignore();
	cin.getline(address,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}
void account::dep(int x)
{
	deposit+=x;
}	
void account::draw(int x)
{
	deposit-=x;
}	
void account::report() const
{
	cout<<acno<<"\t\t"<<name<<"\t\t\t"<<address<<"\t\t"<<type<<"\t\t"<<deposit<<endl;
}
void account::info1() const
{
	cout<<acno<<"\t\t"<<name<<endl;
}
void account::info2() const
{
	cout<<acno<<"\t\t"<<address<<endl;
}
void account::info3() const
{
	cout<<acno<<"\t\t"<<deposit<<endl;
}
int account::return_accountNo() const
{
	return acno;
}
int account::return_deposit() const
{
	return deposit;
}
char account::return_accType() const
{
	return type;
}
//function declaration
void write_account();	
//function to write record in binary file
void display_sp(int);	
//function to display account details given by user
void modify_account(int);	
//function to modify record of file
void total_interest(int);	
//function to find the find the interest
void delete_account(int);	
//function to delete record of file
void display_all();		
//function to display all account details
void display_per(int);
//function to display information of a perticular customer
void deposit_withdraw(int, int); 
// function to desposit/withdraw amount for given account
void intro();	
//introductory screen function
int main()
{
	int ch;
	int num;
	intro();
	do
	{
		//system("cls");
		cout<<"\n\nMAIN MENU";
		cout<<"\n\t1. NEW ACCOUNT";
		cout<<"\n\t2. DEPOSIT AMOUNT";
		cout<<"\n\t3. WITHDRAW AMOUNT";
		cout<<"\n\t4. BALANCE ENQUIRY";
		cout<<"\n\t5. ALL ACCOUNT HOLDER LIST";
    cout<<"\n\t6. SPECIFIC INFORMATION";
    cout<<"\n\t7. TOTAL INTEREST";
		cout<<"\n\t8. CLOSE AN ACCOUNT";
		cout<<"\n\t9. MODIFY AN ACCOUNT";
		cout<<"\n\t10. EXIT";
		cout<<"\nSelect Your Option :";
		cin>>ch;
		/*if(islower(ch))
    {
      ch=toupper(ch);
    }*/
		switch(ch)
		{
		case 1:
			write_account();
			break;
		case 2:
			cout<<"\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case 3:
			cout<<"\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case 4: 
			cout<<"\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case 5:
			display_all();
			break;
    case 6:
      cout<<"\n\tEnter The account No. : "; cin>>num;
			display_per(num);
			break;
		case 7:
			cout<<"\n\tEnter The account No. : "; cin>>num;
			total_interest(num);
			break;
    case 8:
			cout<<"\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case 9:
			cout<<"\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case 10:
			cout<<"\n\tThank You for using BANK MANAGEMENT SYSTEM!!";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.txt",ios::app|ios::out);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}
void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.txt",ios::app|ios::in);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.return_accountNo()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\nAccount number does not exist";
}
void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.txt",ios::in|ios::out);//**ios::binary
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.return_accountNo()==n)
		{
			ac.show_account();
			cout<<"\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n Record Not Found! ";
}

void total_interest(int n)
{
  int p,r,t;
  float interest;
  cout<<"\nEnter the principle amount,rate of interest and time(in days) :";
  cin>>p>>r>>t;
  if(t>30)
  {
    interest=(p*t*r)/100;
    cout<<"\nTotal Interest is :"<<interest;
  }
  else
  {
    cout<<"\nTransactions found within 30 days!";
  }
  
}

void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt");//**ios::binary
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.txt",ios::app);//**ios::binary
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.return_accountNo()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt","account.txt");
	cout<<"\n\n\tRecord Deleted ..";
}
//function to display all accounts deposit list
void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.txt");//**ios::binary
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"A/c no.\t\tNAME\t\t\tAddress\t\tType\t\tBalance\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

void display_per(int n)
{
  int c;
  bool found=false;
	account ac;
	fstream File;
	File.open("account.txt", ios::in|ios::out);//**ios::binary
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
  
	cout<<"\n1. RETRIEVE NAME";
  cout<<"\n2. RETRIEVE ADDRESS";
  cout<<"\n3. RETRIEVE BALANCE";
	cout<<"\nEnter the choice :";
  cin>>c;
  switch(c)
  {
    case 1 :         
            while(!File.eof() && found==false)
	          {
		          File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		          if(ac.return_accountNo()==n)
		          {
			          //ac.show_account();
                ac.info1();
              }
            }
            break;
    case 2 :
            while(!File.eof() && found==false)
	          {
		          File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		          if(ac.return_accountNo()==n)
		          {
			          //ac.show_account();
                ac.info2();
              }
            }
            break;
    case 3 :
            while(!File.eof() && found==false)
	          {
		          File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		          if(ac.return_accountNo()==n)
		          {
			          //ac.show_account();
                ac.info3();
              }
            }
            break;
    default :cout<<"Not a valid input!";
  }
	
}
//function to deposit and withdraw amounts
void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.txt", ios::in|ios::out);//**ios::binary
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.return_accountNo()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\tTO DEPOSITE AMOUNT ";
				cout<<"\nEnter The amount to be deposited :";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\tTO WITHDRAW AMOUNT ";
				cout<<"\nEnter The amount to be withdraw :";
				cin>>amt;
				int bal=ac.return_deposit()-amt;
				if((bal<500 && ac.return_accType()=='S') || (bal<1000 && ac.return_accType()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n Record Not Found ";
}
void intro()
{
	cout<<"\n\t  BANK MANAGEMENT SYSTEM";
	cin.get();
}