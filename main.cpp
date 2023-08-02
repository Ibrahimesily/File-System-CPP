#include <iostream>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int option ;
int modification;
char ch ;

//************************** Customer1 CODE *****************************


class Customer1
{
  public:
    char name[10] , Visa_Number[10] , Bank_Name[10] , gender[10] ;
    long long id , Phone_Number ;
    double age ;
};

void Write_Customer1()
{
    Customer1 s ;
    char ch ;
    ofstream file ;
    file.open("Customer1.txt" , ios::out ) ;
    do
    {

        cout<<"Enter Name : "; cin>>s.name;
        cout<<"Enter The Visa Number : "; cin>>s.Visa_Number;
        cout<<"Enter The Bank Name : "; cin>>s.Bank_Name;
        cout<<"Enter The Gender : "; cin>>s.gender;
        cout<<"Enter The Age : "; cin>>s.age;
        cout<<"Enter The Phone Number : "; cin>>s.Phone_Number;
        cout<<"Enter The ID : "; cin>>s.id;

        cout<<"---------------------------------------------------------------------------------"<<endl;

        file.write( (char*) &s , sizeof(s)) ;

        cout<<"Enter Another Record ? (y/n) : "; cin>>ch;
        cout<<"---------------------------------------------------------------------------------"<<endl;

    }while(ch=='y');

    file.close();

}

void Read_Customer1()
{
    Customer1 s ;
    ifstream infile ;
    infile.open("Customer1.txt",ios::in);

    if(infile.is_open())
    {
        cout<<endl<<endl;
        cout<<"Name"<<"\t  "<<"Age"<<"\t"<<"  ID"<<"\t"<<"  Visa_Number"<<"\t"<<"   Bank_Name"<<"\t"<<" Gender"<<"\t"<<"  Phone_Number"<<endl;
        cout<<"*********************************************************************************"<<endl;


        int id = 0 ;
        while(!infile.eof())
        {
            infile.read((char*)&s,sizeof(s));
            if(s.id != id)
            {
               cout<<s.name<<"\t  "<<s.age<<"\t "<<s.id<<"\t     "<<s.Visa_Number<<"\t   "<<s.Bank_Name<<"\t "<<s.gender<<"\t  "<<s.Phone_Number<<"\t"<<endl;
               id = s.id ;
            }
        }
            cout<<endl<<endl;
            cout<<"---------------------------------------------------------------------------------";
        infile.close();
    }
    else
    {
        cout<<"Cannot Open This Specified File !"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }

}

void Search_Customer1()
{
    Customer1 s ;
    char str[10] ;
    bool found = false ;

    cout<<"Enter The Name You Want To Search For : " ; cin>>str;
    cout<<"---------------------------------------------------------------------------------"<<endl;

    ifstream infile ;
    infile.open("Customer1.txt",ios::in);

    if(infile.is_open())
    {
        infile.read((char*)&s,sizeof(s)); cout<<endl<<endl;
        cout<<"Name"<<"\t  "<<"Age"<<"\t"<<"  ID"<<"\t"<<"  Visa_Number"<<"\t"<<"   Bank_Name"<<"\t"<<" Gender"<<"\t"<<"  Phone_Number"<<endl;
        cout<<"*********************************************************************************"<<endl;

       while(!infile.eof())
           {

              if( strcmp(str,s.name)==0 )
               {
                   found = true ;
                   cout<<s.name<<"\t  "<<s.age<<"\t "<<s.id<<"\t     "<<s.Visa_Number<<"\t   "<<s.Bank_Name<<"\t "<<s.gender<<"\t  "<<s.Phone_Number<<"\t"<<endl;
               }

               infile.read((char*)&s,sizeof(s));
          }

    if(!found) cout<<"No Items Matched Your Search"<<endl;
        infile.close();
        cout<<endl<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;

    }
    else
    {
        cout<<"Cannot Open This Specified File !"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }

}

void Update_Customer1()
{
    char str[10] ;
   cout<<"Enter The name you Want To Update : " ; cin>>str;
   cout<<"---------------------------------------------------------------------------------"<<endl;

    Customer1 s;
    bool found = false ;

    fstream file ;
    file.open("Customer1.txt" , ios::in|ios::out );

     if(file.is_open())
      {
        file.read((char*) &s , sizeof(s));

        while(!file.eof())
        {
            if( strcmp(str,s.name)==0 )
            {
                cout<<"1 - Update The Name "<<endl;
                cout<<"2 - Update The Visa Number "<<endl;
                cout<<"3 - Update The Bank Name "<<endl;
                cout<<"4 - Update The Gender "<<endl;
                cout<<"5 - Update The Age "<<endl;
                cout<<"6 - Update The Phone Number "<<endl;
                cout<<"7 - Update The ID "<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                int ch ;
                cout<<"Choose The Update Type Number : "; cin>>ch;
                cout<<"---------------------------------------------------------------------------------"<<endl;

                if(ch==1)
                {
                    cout<<"Enter The New Name : "; cin>>s.name;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==2)
                {
                    cout<<"Enter The New Visa Number : "; cin>>s.Visa_Number;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==3)
                {
                    cout<<"Enter The New Bank Name : "; cin>>s.Bank_Name;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==4)
                {
                    cout<<"Enter The New Gender : "; cin>>s.gender;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==5)
                {
                    cout<<"Enter The New Age : "; cin>>s.age;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==6)
                {
                    cout<<"Enter The New Phone Number : "; cin>>s.Phone_Number;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==7)
                {
                    cout<<"Enter The New ID : "; cin>>s.id;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }



                int curpos = file.tellg() ;
                int stusize = sizeof(s) ;

                file.seekp(curpos-stusize , ios::beg);

                file.write((char*) &s , sizeof(s));

                file.seekg(curpos-stusize , ios::beg);

                file.read((char*) &s , sizeof(s));

                cout<<endl<<endl;
                cout<<"Name"<<"\t  "<<"Age"<<"\t"<<"  ID"<<"\t"<<"  Visa_Number"<<"\t"<<"   Bank Name"<<"\t"<<" Gender"<<"\t"<<"  Phone_Number"<<endl;
                cout<<"*********************************************************************************"<<endl;
                cout<<s.name<<"\t  "<<s.age<<"\t "<<s.id<<"\t     "<<s.Visa_Number<<"\t   "<<s.Bank_Name<<"\t "<<s.gender<<"\t  "<<s.Phone_Number<<"\t"<<endl<<endl<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;

                found = true ;
                break ;
            }

            file.read((char*)&s , sizeof(s));
        }

        if(!found)
        {
            cout<<"The File Does Not Contain This Name !"<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
        }

        file.close();
    }
    else
    {
        cout<<"Cannot Open This Specified File !"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }
}

void Delete_Customer1()
{
    Customer1 s ;
    bool found = false ;

    char str[10] ;
    cout<<"Enter The Name You Want To Delete : "; cin>>str;
    cout<<"---------------------------------------------------------------------------------"<<endl;

    ifstream infile ;
    infile.open("Customer1.txt" , ios::in) ;

    ofstream outfile ;
    outfile.open("Customer1_Fake.txt" , ios::out);

    if(infile.is_open())
    {
        infile.read((char*)&s , sizeof(s)) ;

        while(!infile.eof())
        {
            if( strcmp(str,s.name) != 0 )
            {
                outfile.write((char*)&s , sizeof(s));
                found = true ;

            }

            infile.read((char*)&s , sizeof(s)) ;
        }

        if(!found)
        {
            cout<<"The File Does Not Contain This Name !"<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
        }

        infile.close();
        outfile.close();

        remove("Customer1.txt");
        rename("Customer1_Fake.txt" , "Customer1.txt");
    }
    else
    {
      cout<<"Cannot Open This Specified File !"<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
    }

}

void Modify_Customer1()
{
    cout<<"1 - Read A Customer "<<endl;
    cout<<"2 - Search For A Customer "<<endl;
    cout<<"3 - Update A Customer "<<endl;
    cout<<"4 - Delete A Customer "<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"Choose The Modification Type Number : "; cin>>modification;
    cout<<"---------------------------------------------------------------------------------"<<endl;

    switch (modification)
    {
    case 1 :
        Read_Customer1(); cout<<endl;
        break;
    case 2 :
        Search_Customer1(); cout<<endl;
        break;
    case 3 :
        Update_Customer1(); cout<<endl;
        break;
    case 4 :
        Delete_Customer1(); cout<<endl;
        break;
    }

}

//*************** Products *********************

class Products
{
  public :
    char name[20] ;
    long long id  ;
    double Price ;
};

void Write_Products()
{
    Products s ;
    char ch ;
    ofstream file ;
    file.open("Products.txt" , ios::out ) ;
    do
    {
        cout<<"Enter Name : "; cin>>s.name;
        cout<<"Enter The Price : "; cin>>s.Price;
        cout<<"Enter The ID : "; cin>>s.id;

        cout<<"---------------------------------------------------------------------------------"<<endl;

        file.write( (char*) &s , sizeof(s)) ;

        cout<<"Enter Another Record ? (y/n) : "; cin>>ch;
        cout<<"---------------------------------------------------------------------------------"<<endl;

    }while(ch=='y');

    file.close();

}

void Read_Products()
{
    Products s ;
    ifstream infile ;
    infile.open("Products.txt",ios::in);

    if(infile.is_open())
    {
        cout<<endl<<endl;
        cout<<"Name"<<"\t    "<<" Price"<<endl;
        cout<<"************************"<<endl;


        int id = 0 ;
        while(!infile.eof())
        {
            infile.read((char*)&s,sizeof(s));
            if(s.id != id)
            {
               cout<<s.name<<"\t     "<<s.Price<<endl;
               id = s.id ;
            }
        }
            cout<<endl<<endl;
            cout<<"---------------------------------------------------------------------------------";
        infile.close();
    }
    else
    {
        cout<<"Cannot Open This Specified File !"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }

}

void Search_Products()
{
    Products s ;
    char str[20] ;
    bool found = false ;

    cout<<"Enter The Name You Want To Search For : " ; cin>>str;
    cout<<"---------------------------------------------------------------------------------"<<endl;

    ifstream infile ;
    infile.open("Products.txt",ios::in);

    if(infile.is_open())
    {
        infile.read((char*)&s,sizeof(s)); cout<<endl<<endl;
        cout<<"Name"<<"\t    "<<" Price"<<"\t"<<"ID"<<endl;
        cout<<"*************************************************************************************"<<endl;

       while(!infile.eof())
           {

              if( strcmp(str,s.name)==0 )
               {
                   found = true ;
                   cout<<s.name<<"\t     "<<s.Price<<"\t      "<<s.id<<endl;
               }

               infile.read((char*)&s,sizeof(s));
          }

    if(!found) cout<<"No Items Matched Your Search"<<endl;
        infile.close();
        cout<<endl<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;

    }
    else
    {
        cout<<"Cannot Open This Specified File !"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }

}

void Update_Products()
{
    char str[10] ;
   cout<<"Enter The name you Want To Update : " ; cin>>str;
   cout<<"---------------------------------------------------------------------------------"<<endl;

    Products s;
    bool found = false ;

    fstream file ;
    file.open("Products.txt" , ios::in|ios::out );

     if(file.is_open())
      {
        file.read((char*) &s , sizeof(s));

        while(!file.eof())
        {
            if( strcmp(str,s.name)==0 )
            {
                cout<<"1 - Update The Name "<<endl;
                cout<<"2 - Update The Price "<<endl;
                cout<<"3 - Update The ID "<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                int ch ;
                cout<<"Choose The Update Type Number : "; cin>>ch;
                cout<<"---------------------------------------------------------------------------------"<<endl;

                if(ch==1)
                {
                    cout<<"Enter The New Name : "; cin>>s.name;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==2)
                {
                    cout<<"Enter The New Price : "; cin>>s.Price;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }
                else if(ch==3)
                {
                    cout<<"Enter The New ID : "; cin>>s.id;
                    cout<<"---------------------------------------------------------------------------------"<<endl;
                }



                int curpos = file.tellg() ;
                int stusize = sizeof(s) ;

                file.seekp(curpos-stusize , ios::beg);

                file.write((char*) &s , sizeof(s));

                file.seekg(curpos-stusize , ios::beg);

                file.read((char*) &s , sizeof(s));

                cout<<endl<<endl;
                cout<<"Name"<<"\t    "<<" Price"<<endl;
                cout<<"************************"<<endl;
               cout<<s.name<<"\t     "<<s.Price<<endl<<endl<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;

                found = true ;
                break ;
            }

            file.read((char*)&s , sizeof(s));
        }

        if(!found)
        {
            cout<<"The File Does Not Contain This Name !"<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
        }

        file.close();
    }
    else
    {
        cout<<"Cannot Open This Specified File !"<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }

}

void Delete_Products()
{
    Products s ;
    bool found = false ;

    char str[10] ;
    cout<<"Enter The Name You Want To Delete : "; cin>>str;
    cout<<"---------------------------------------------------------------------------------"<<endl;

    ifstream infile ;
    infile.open("Products.txt" , ios::in) ;

    ofstream outfile ;
    outfile.open("Products_Fake.txt" , ios::out);

    if(infile.is_open())
    {
        infile.read((char*)&s , sizeof(s)) ;

        while(!infile.eof())
        {
            if( strcmp(str,s.name) != 0 )
            {
                outfile.write((char*)&s , sizeof(s));
                found = true ;

            }

            infile.read((char*)&s , sizeof(s)) ;
        }

        if(!found)
        {
            cout<<"The File Does Not Contain This Name !"<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
        }

        infile.close();
        outfile.close();

        remove("Products.txt");
        rename("Products_Fake.txt" , "Products.txt");
    }
    else
    {
      cout<<"Cannot Open This Specified File !"<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
    }




}

void Modify_Products()
{
    cout<<"1 - Write A Product "<<endl;
    cout<<"2 - Read A Product "<<endl;
    cout<<"3 - Search For A Product "<<endl;
    cout<<"4 - Update A Product "<<endl;
    cout<<"5 - Delete A Product "<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<<"Choose The Modification Type Number : "; cin>>modification;
    cout<<"---------------------------------------------------------------------------------"<<endl;

    switch (modification)
    {
    case 1 :
        Write_Products(); cout<<endl;
         break;
    case 2 :
        Read_Products(); cout<<endl;
         break;
    case 3 :
        Search_Products(); cout<<endl;
         break;
    case 4 :
        Update_Products(); cout<<endl;
         break;
    case 5 :
        Delete_Products(); cout<<endl;
         break;
    }

}


///////////////////////////////////////////////////////////////////////////////////////////////////////

int n ;
void price(char str[10])
    {
       fstream file ;
        file.open("Products.txt" , ios::in|ios::out );
        Products s;

     if(file.is_open())
      {
        file.read((char*) &s , sizeof(s));

        for(int i=0 ; i<19 ; i++)
        {
            if( strcmp(str,s.name)==0 )
            {
                n = s.Price;
                break ;
            }
        }
      }
    }


void order()
{

    char o[10] ;
    int p,m=0,x=1,opt;

    char chh ;
    do{
    cout<<"Choose your order : "; cin>>o;
    cout<<"Choose the amount : "; cin>>x;
    price(o);
    p=n*x;
    m += p;
    cout<<"Choose another order ? (y/n) : ";
    cin>>chh;
    }while(chh=='y');

    cout<<"**************  Total Price : "<<m<<" *************"<<endl;
    cout<<"chose the payment method ."<<endl;
    cout<<"1- Cash ."<<endl;
    cout<<"2- Visa ."<<endl;
    cout<<"Please Enter The Number Of The Type  Want : "; cin>>opt;
    cout<<"**************  all done, Thank you for visiting us  *******************"<<endl;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////

void Modify_Customer2()
{
        cout<<"1 - Login ."<<endl;
        cout<<"2 - Register ."<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
        cout<<"Please Enter The Number Of The Type  Want To Modify : "; cin>>option;
        cout<<"---------------------------------------------------------------------------------"<<endl;

        switch(option)
        {
        case 1 :
            {
                long long id , pass;
                cout<<"Enter Your ID : " ; cin>>id;
                cout<<"Enter Your Password : " ; cin>>pass;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                Read_Products(); cout<<endl;
                order(); cout<<endl;
                break;
            }
        case 2 :
            Write_Customer1(); cout<<endl;
            Read_Products(); cout<<endl;
            order(); cout<<endl;
            break;

        }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
        cout<<"**************************** OUR ONLINE SHOP ********************************"<<endl;
    do
    {
        cout<<"1 - Manager ."<<endl;
        cout<<"2 - Customer ."<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
        cout<<"Please Enter The Number Of The Type  Want To Modify : "; cin>>option;
        cout<<"---------------------------------------------------------------------------------"<<endl;
        switch(option)
        {
        case 1 :
            {
                cout<<"4 - Customer ."<<endl;
                cout<<"5 - Products ."<<endl;
                cout<<"6 - Exit"<<endl;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                cout<<"Please Enter The Number Of The Type  Want To Modify : "; cin>>option;
                cout<<"---------------------------------------------------------------------------------"<<endl;
                        switch(option)
                        {
                        case 4 :
                            Modify_Customer1();
                            break;
                        case 5 :
                            Modify_Products();
                            break;
                        case 6 :
                            return 0 ;
                            break;
                        }
            }
            break;
        case 2 :
            {

                Modify_Customer2();
                break;
            }
        }
        cout<<"Do you want to continue using the application? (y/n) : "; cin>>ch; cout<<endl;
        cout<<"---------------------------------------------------------------------------------"<<endl;
    }while (ch=='y');

    return 0;
}
