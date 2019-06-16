#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Restaurants
               {
                   protected:
                             string name,address;
                             float rating,rating_counter;
                             long long int contact;
                             vector<string> menu;
                             vector<float> price;
                   public:
                             void read(int &);
                             void add(int &);
                             void del();
                             void detail();
                             void add_dish();
                             void read_dish();
                             bool operator>(const Restaurants& temp)const
                              {
                                return (rating>temp.rating);
                              }
                             friend void rate(vector<Restaurants> &,int &,int &);
                             friend void dish_search(vector<Restaurants> &,int &,string &);
                };

 void Restaurants::read(int &i)
 {
     string dish,temp;
     float amount;
     int cnt=0;
     ifstream fin,finn;
     fin.open("Restaurant_names.txt");
     while(getline(fin,temp))
      {
         finn.open(temp+"_detail.txt");
         while(getline(finn,address)&&finn>>contact>>rating>>rating_counter)
          {
             }
         finn.close();
         if(temp!=" ")
           name=temp;
         if(cnt==i)
           {  fstream fine,finne;
               fine.open(name+"_menu.txt");
               finne.open(name+"_price.txt");
               while(getline(fine,dish)&&finne>>amount)
                {
                 menu.push_back(dish);
                 price.push_back(amount);
                }
               fine.close();
               finne.close();
               break;
            }
         else
            cnt++;
     }
     fin.close();
 }

 void Restaurants::add(int &all)
 {
   ofstream fout,foit;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tEnter name of restaurant:";
   cin>>name;
   fflush(stdin);
   system("CLS");
   fout.open("Restaurant_names.txt",ios::out|ios::app);
   fout<<name<<"\n";
   foit.open(name+"_detail.txt");
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tEnter address of restaurant:";
   cin>>address;
   system("CLS");
   foit<<address<<"\n";
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tEnter contact details:";
   cin>>contact;
   system("CLS");
   foit<<contact<<" "<<0<<" "<<0;
   foit.close();
   fout.close();
   ++all;
   fout.open("Number_of_restaurant.txt");
   fout<<all;;
   fout.close();
 }

 void Restaurants::add_dish()
 {
      int dish_count=1;
      string dish;
      float price;
      ofstream fout,foit;
      fout.open(name+"_menu.txt");
      foit.open(name+"_price.txt");
      while(dish_count)
       {
         cout<<"Enter name of dish\n";
         cin.sync();
         getline(cin,dish);
         fout<<dish<<"\n";
         cout<<"Enter price\n";
         cin>>price;
         foit<<price<<"\n";
         cout<<"To enter another dish press 1\nTo exit press 0\n";
         cin>>dish_count;
         system("CLS");
       }
     fout.close();
     foit.close();
 }

 void Restaurants::detail()
 {
     cout<<"Name: "<<name<<endl;
     cout<<"Address: "<<address<<endl;
     cout<<"Contact: "<<contact<<endl;
     cout<<"Rating: "<<rating<<endl<<endl;
 }

 void rate(vector<Restaurants>&r, int &all, int &t)
 {
     for(int i=0;i<all;i++)
     {
         if(i==t)
         {
             cout<<"MENU\n";
             string temp;
             float tem;
             fstream fin(r[i].name+"_menu.txt");
             fstream finn(r[i].name+"_price.txt");
             while(getline(fin,temp)&&finn>>tem)
             {
                 cout<<temp<<"\t"<<tem<<endl;
             }
             fin.close();
             finn.close();
            float p;
            cout<<"Please rate the restaurant for their service out of 5\n";
            cin>>p;
            if(r[i].rating_counter==0)
             {
               r[i].rating=p;
               r[i].rating_counter++;
             }
            else
             {
               r[i].rating=(r[i].rating+p)/2;
               r[i].rating_counter++;
             }
            fstream fout(r[i].name+"_detail.txt");
            fout<<r[i].address<<"\n";
            fout<<r[i].contact<<" "<<r[i].rating<<" "<<r[i].rating_counter;
            fout.close();
         }
    }
 }

void dish_search(vector<Restaurants>&r, int &all,string &dish)
{
     int check=0;
     for(int i=0;i<all;i++)
        {
            fstream fin(r[i].name+"_menu.txt");
            fstream finn(r[i].name+"_price.txt");
            string temp;
            float tem;
            while(getline(fin,temp)&&finn>>tem)
            {
                if(temp==dish)
                {
                    r[i].detail();
                    check++;
                    cout<<"Price of dish: "<<tem<<"\n\n";
                }
            }
            fin.close();
            finn.close();
        }
     if(check==0)
        cout<<"Dish not found in any restaurants\n";
}

class Manager
            {
                string name,password;
             public:
                    void input();
                    void read();
                    int operator =(Manager &);
            };
 void Manager::input()
 {
     cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tLogin\n";
     cout<<"\t\t\t\t\tUsername:";
     cin>>name;
     cout<<"\n\t\t\t\t\tPassword:";
     cin>>password;
     system("CLS");
 }
 void Manager::read()
 {
     ifstream fin;
     fin.open("username.txt");
     while(fin)
     {
         getline(fin,name);
     }
     fin.close();
     fin.open("password.txt");
     while(fin)
     {
         getline(fin,password);
     }
     fin.close();
 }
 int Manager::operator=(Manager &n)
 {
     if((name==n.name)&&(password==n.password))
        return 1;
     else
        return 0;
 }

int main()
{  int all=0,app=1;
Restaurants res_call;
vector<Restaurants> r;
    ifstream fin;
    fin.open("Number_of_restaurant.txt");
    while(fin)
    {
        fin>>all;
    }
    fin.close();
    for(int i=0;i<all;i++)
    {
        res_call.read(i);
        r.push_back(res_call);
    }

    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t-----------Welcome to ZIGGY------------\n";
    cout<<"\t\t\t\t\tSelect a login option\n";
    cout<<"\t\t\t\t\t1:Manager\n";
    cout<<"\t\t\t\t\t2:Customer\n";
    int main_menu_choice;
    cin>>main_menu_choice;
    system("CLS");
    int main_menu_counter=1;
    while(main_menu_counter)
    {
        if(main_menu_choice==1)
         {
           Manager m,n;
           m.input();
           n.read();
           if(m=n)
            {
                main_menu_counter=0;
             }//Check,program works correctly till this point.
        else
          cout<<"Invalid name or password\nEnter again\n";
          }
        else if(main_menu_choice!=2)
         {
           cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid entry\nEnter choice again\n";
           cout<<"\t\t\t\t\t1:Manager\n";
           cout<<"\t\t\t\t\t2:Customer\n";
           cin>>main_menu_choice;
           system("CLS");
          }
        else
           main_menu_counter=0;
      }
while(app)
   {
       switch(main_menu_choice)
        {
          case 1:
                 {int manager_menu_counter=1,manager_menu_choice;
                 cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tManager menu\n";
                 cout<<"\t\t\t\t\tSelect an option\n";
                 cout<<"\t\t\t\t\t1:Restaurant details\n";
                 cout<<"\t\t\t\t\t2:Add restaurant\n";
                 cout<<"\t\t\t\t\t3:Delete restaurant according to rating\n";
                 cout<<"\t\t\t\t\t4:Go to main menu\n";
                 cin>>manager_menu_choice;
                 system("CLS");
                 while(manager_menu_counter)
                  {
                    if(manager_menu_choice==1)
                     {
                      if(all==0)
                       cout<<"No restaurants to display\n";
                      else
                       {for(int i=0;i<all;i++)
                         r[i].detail();
                       }
                      cout<<"To go back to manager menu press 0\n";
                      cin>>manager_menu_choice;
                      system("CLS");
                     }
                    else if(manager_menu_choice==2)
                     {
                      res_call.add(all);
                      res_call.add_dish();
                      r.push_back(res_call);
                      cout<<"To go back to manager menu press 0\nTo add another restaurant press 2\n";
                      cin>>manager_menu_choice;
                      system("CLS");
                     }
                    else if(manager_menu_choice==3)
                     {
                      char deletion_choice;
                      cout<<"Are you sure you want to delete the last restaurant due to its rating? [Y/N]\n";
                      cin>>deletion_choice;
                      while(deletion_choice=='Y'||deletion_choice=='y')
                       {
                           if(all==0)
                            {
                             cout<<"No restaurants to delete\n";
                             break;
                            }
                           r.pop_back();
                           all--;
                           cout<<"Delete another restaurant due to its rating? [Y/N]\n";
                           cin>>deletion_choice;
                        }
                       ofstream fout("Number_of_restaurant.txt");
                       fout<<all;
                       fout.close();
                       cout<<"To go back to manager menu press 0\nTo add restaurant press 2\n";
                       cin>>manager_menu_choice;
                       system("CLS");
                     }
                    else if(manager_menu_choice==4)
                     {
                      cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t--------Welcome to ZIGGY----------\n";
                      cout<<"\t\t\t\t\tSelect a login option\n";
                      cout<<"\t\t\t\t\t1:Manager\n";
                      cout<<"\t\t\t\t\t2:Customer\n";
                      cout<<"\t\t\t\t\t0:Exit\n";
                      cin>>main_menu_choice;
                      system("CLS");
                      int main_menu_counter=1;
                      while(main_menu_counter)
                        {
                             if(main_menu_choice==1)
                              {
                                Manager m,n;
                                m.input();
                                n.read();
                                if(m=n)
                                 main_menu_counter=0;//Check,program works correctly till this point.
                                else
                                 cout<<"Invalid name or password\nEnter again\n";
                               }
                             else if(main_menu_choice==0)
                                {
                                    app=0;
                                    main_menu_counter=0;
                                }
                             else if(main_menu_choice!=2)
                              {
                               cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid entry\nEnter choice again\n";
                               cout<<"\t\t\t\t\t1:Manager\n";
                               cout<<"\t\t\t\t\t2:Customer\n";
                               cin>>main_menu_choice;
                               system("CLS");
                               main_menu_counter=0;
                               }
                             else
                               main_menu_counter=0;
                        manager_menu_counter=0;
                        }
                    }
                  else
                  {
                      cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter choice again\n";
                      cout<<"\t\t\t\t\t1:Restaurant details\n";
                      cout<<"\t\t\t\t\t2:Add restaurant\n";
                      cout<<"\t\t\t\t\t3:Delete restaurant\n";
                      cout<<"\t\t\t\t\t4:Go to main menu\n";
                      cin>>manager_menu_choice;
                      system("CLS");
                  }
              }
            }
            break;
        case 2:
               {int customer_menu_counter=1,customer_menu_choice;
               cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tCustomer menu\n";
               cout<<"\t\t\t\t\tSelect an option\n";
               cout<<"\t\t\t\t\t1:View restaurants by rating\n";
               cout<<"\t\t\t\t\t2:Search by dish\n";
               cout<<"\t\t\t\t\t3:Go to main menu\n";
               cin>>customer_menu_choice;
               system("CLS");
               while(customer_menu_counter)
               {
                 if(customer_menu_choice==1)
                  {
                       sort(r.begin(),r.end(),greater<Restaurants>());
                       for(int i=0;i<all;i++)
                         r[i].detail();
                    char res;
                    cout<<"Would you like to order from a restaurant.[Y/N]\n";
                    cin>>res;
                    if(res=='Y'||res=='y')
                    {
                        int t;
                        cout<<"Press the number of the restaurant you want to order from\n";
                        cin>>t;
                        system("CLS");
                        t--;
                        rate(r,all,t);
                    }
                    cout<<"Press 0 to go back\n";
                    cin>>customer_menu_choice;
                    system("CLS");
                   }
                 else if(customer_menu_choice==2)
                   {
                    string dish;
                    int check=0;
                    cout<<"Enter the dish to search\n";
                    cin>>dish;
                    dish_search(r,all,dish);
                    cout<<"Press 0 to go back\n";
                    cin>>customer_menu_choice;
                    system("CLS");

                }
                else if(customer_menu_choice==3)
                {
                      cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t-------Welcome to ZIGGY-------\n";
                      cout<<"\t\t\t\t\tSelect a login option\n";
                      cout<<"\t\t\t\t\t1:Manager\n";
                      cout<<"\t\t\t\t\t2:Customer\n";
                      cout<<"\t\t\t\t\t0:Exit\n";
                      cin>>main_menu_choice;
                      system("CLS");
                      int main_menu_counter=1;
                      while(main_menu_counter)
                        {
                             if(main_menu_choice==1)
                              {
                                Manager m,n;
                                m.input();
                                n.read();
                                if(m=n)
                                 main_menu_counter=0;//Check,program works correctly till this point.
                                else
                                 cout<<"Invalid name or password\nEnter again\n";
                               }
                             else if(main_menu_choice==0)
                                {
                                    app=0;
                                    main_menu_counter=0;
                                }
                             else if(main_menu_choice!=2)
                              {
                               cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid entry\nEnter choice again\n";
                               cout<<"\t\t\t\t\t1:Manager\n";
                               cout<<"\t\t\t\t\t2:Customer\n";
                               cin>>main_menu_choice;
                               system("CLS");
                               main_menu_counter=0;
                               }
                             else
                               main_menu_counter=0;
                            customer_menu_counter=0;
                        }
                }
                else
                {
                  cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter choice again\n";
                  cout<<"\t\t\t\t\t1:View restaurants by rating\n";
                  cout<<"\t\t\t\t\t2:Search by dish\n";
                  cout<<"\t\t\t\t\t3:Go to main menu\n";
                  cin>>customer_menu_choice;
                  system("CLS");
                }
               }
               break;
             }
         }
     }
     cout<<"Thank you for using ZIGGY";
     return 0;
}
