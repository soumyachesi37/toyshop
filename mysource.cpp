#include "myheader.h"

void Admin ::create_admin(string id_p, string password_p)
{
    id=id_p;
    password=password_p;
    login_status=false;
    fstream file;
    file.open("admin_details.txt", ios::app);
    file << id << " " << password << endl;
    file.close();
}

bool Admin ::login(string id_p, string password_p)
{
    int tries = 0;
    while (id_p != id and tries != 3)
    {
        // if()
        // {
        cout << "XXXXXXXX  INVALID ADMIN ID. TRY AGAIN!! XXXXXXXXX" << endl;
        tries += 1;
        if (tries == 3)
        {
            cout << "You have entered the incorrect id 3 times in a row. Exiting admin interface" << endl;
            return false;
        }

        // }
    }
    tries = 0;
    while (tries != 3 and password_p != password)
    {
        // if()
        // {
        cout << "XXXXXXXX  INVALID ADMIN PASSWORD. TRY AGAIN!! XXXXXXXXX" << endl;
        tries += 1;
        if (tries == 3)
        {
            cout << "You have entered the incorrect password 3 times in a row. Exiting admin interface" << endl;
            return false;
        }
        // }
    }
    cout<<"Welcome Admin : "<<id<<endl;
    login_status=true;
    return true;
}

void Customer ::create_user(string user, string pass)
{
    username=user;
    password=pass;
    login_status=false;
    fstream file;
    file.open("customer_details.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
}

bool Customer ::login(string id_p, string password_p)
{
    int tries = 0;
    while (id_p != username and tries != 3)
    {
        // if()
        // {
        cout << "XXXXXXXX  INVALID USER ID. TRY AGAIN!! XXXXXXXXX" << endl;
        tries += 1;
        if (tries == 3)
        {
            cout << "You have entered the incorrect id 3 times in a row. Exiting user interface" << endl;
            return false;
        }

        // }
    }
    tries = 0;
    while (tries != 3 and password_p != password)
    {
        // if()
        // {
        cout << "XXXXXXXX  INVALID USER PASSWORD. TRY AGAIN!! XXXXXXXXX" << endl;
        tries += 1;
        if (tries == 3)
        {
            cout << "You have entered the incorrect password 3 times in a row. Exiting user interface" << endl;
            return false;
        }
        // }
    }
    cout<<"Welcome Customer : "<<username<<endl;
    login_status=true;
    return true;
}

void Customer ::display_balance(int cash, string toy_name)
{
}

void Admin :: delete_toy(string toy_name)
{
    // * delete the info of this toy from the toy_information file
    // delete(&T);
}

void Customer :: view_toys_list()
{
    ifstream file;string s; int c=0;
    file.open("toy_list.txt");
    while(1)
    {
        getline(file,s);
        if(!file) break;
        cout<<s<<endl;
    }
    file.close();
}

void Admin :: create_toy()
{
    cout<<"Enter the name of the new toy : ";string toy_name;cin>>toy_name;
    fstream file;
    file.open("toy_list.txt",ios:: app);
    file<<toy_name<<endl;
    file.close();
}

void Customer :: search_toy()
{
    string toy_name,toy_name_from_list,prompt_response;
    cout<<"Enter the name of the toy that you want to search : ";cin>>toy_name;
    ifstream file;
    file.open("toy_list.txt");
    while(1)
    {
        getline(file,toy_name_from_list);
        if(toy_name==toy_name_from_list)
        {
            cout<<toy_name<<" is available in the store. Type yes to purchase when prompted or type no to exit Search Module!!"<<endl;
            cout<<"Do you want to purchase "<<toy_name<<" ?"<<endl;cin>>prompt_response;
            if(prompt_response=="yes")
            {
                Customer :: purchase();
                break ;
            }
            else
            {
                //menu
                break;
            } 
        }
        else if(!file)
        {
            cout<<toy_name<<" is not available in the store at the moment. Contact the admin to add this toy to the list. Thanks!!!"<<endl;
            break;
        }
    }
    file.close();
}

void Customer :: purchase()
{
    fstream buy_ptr;
    buy_ptr.open("toy_information.csv",ios::in);
    vector<string> row;
    
    while(buy_ptr >> temp)
    {
        row.clear();
    }

    cout<<"purchase called successfully"<<endl;
}