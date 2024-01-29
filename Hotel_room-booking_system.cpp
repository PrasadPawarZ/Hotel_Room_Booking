#include <iostream>
#include <windows.h>
#include <fstream>
#include <string.h>
using namespace std;

//Gobal variables
int romo[30] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int len, check;

class room_book
{
private:
    char name[20] ;
    int age;
    long  mob_no;
    int verfi_doc_name;
    long  verfi_no;
    char address[50];

protected:
    int no, no1;
    int bed, mem;
    int luxy;
    char getwifi;
    int no_of_days;
    int family = 2;

public:
    int room_no_ = 0;
    int floor = 0;
    int get_person(void)
    {
        cout << "Enter Name : ";
        fflush(stdin);
        gets(name);

        cout << "Enter Age : ";
        cin >> age;

        if (age < 18)
        {
            cout << "\n\n\nYou are under age\n\n";
            return 2;
        }

        cout << "Enter Mobile No : +91 ";
        cin >> mob_no;
        fflush(stdin);
        cout << "Select Document for verification : " << endl;
        cout << "  1.Adharcard : " << endl;
        cout << "  2.Voter Id : " << endl;
        cout << "  3.Passport : " << endl;
        cin >> verfi_doc_name;//choise
        //switch(ch)
        //{}
        if (verfi_doc_name == 1)
        {
            cout << "Enter your adhaarcard no : ";
            cin >> verfi_no;
        }
        else if (verfi_doc_name == 2)
        {
            cout << "Enter your Voter Id no : ";
            cin >> verfi_no;
        }

        else
        {
            cout << "Enter your Passport no :";
            cin >> verfi_no;
        }
        fflush(stdin);

        cout << "Enter your Address : ";
        fflush(stdin);  
        gets(address);
        fflush(stdin);  
        return 100;
    }

    void get_room()
    {

        cout << "Type of room you want : " << endl;
        cout << "Enter 1.Single : " << endl;
        cout << "Enter 2.Family(Upto 4 - 6 members can stay) : " << endl;
        cout << "Enter 3.Couples/Pair : " << endl;
        cin >> no1;
        switch (no1)
        {
        case 1:
            mem = 1;
            break;
        case 2:
            mem = 2;
            cout << "How many family members are there : ";
            cin >> family;
            break;
        case 3:
            mem = 3;
            break;

        default:
            mem = 2;
            break;
        }
        if (mem == 1)
        {
            no = 1;
        }
        else
        {

            cout << "Enter 1. For Single bed : " << endl;
            cout << "Enter 2. For Double bed : " << endl;
            cin >> no;
        }
        switch (no)
        {
        case 1:
            bed = 1;
            break;
        case 2:
            bed = 2;
        default:
            bed = 1;
            break;
        }

        cout << "Do you want wifi : y/n : " << endl;
        cin >> getwifi;

        cout << "Do you want 1.Luxary room or 2.Normal room : " << endl;
        cin >> luxy;

        cout << "How many days you want stay : ";
        cin >> no_of_days;
    }

    void display()
    {
        //person
        cout << "   Name      : "<< name <<endl;
        cout << "   Age       :  " << age  << endl;
        cout << "   Mobile No :  " << mob_no  << endl;
        cout << "   Room No   : " << room_no_ << " on " << floor << " floor " << endl;
    }

    void adv_display()
    {
        //person detail
        cout << " Name      : "<<name<<endl;
        cout << ""<< endl;
        cout << " Age       :  " << age <<  endl;
        cout << " Mobile No :  " << mob_no  << endl;
        cout << " Room No   : " << room_no_ << " on " << floor << " floor" << endl;

        if (verfi_doc_name == 1)
        {
            cout << "Adharcard No : " << verfi_no << endl;
        }
        else if (verfi_doc_name == 2)
        {
            cout << "Voter Id No : " << verfi_no << endl;
        }
        else
        {
            cout << "Passport No : " << verfi_no << endl;
        }

        cout << "Address : " << address << endl;

        //room
        if (mem == 1)
        {
            cout << "Single person in room" << endl;
        }
        else if (mem == 2)
        {
            cout << "Family staying in room" << endl;
        }
        else
        {
            cout << "Couples staying in room" << endl;
        }

        if (getwifi == 'y')
        {
            cout << "Wifi is availbe in room" << endl;
        }
        else
        {
            cout << "No wifi availbe in room" << endl;
        }

        if (luxy == 1)
        {
            cout << "Luxary room" << endl;
        }
        else
        {
            cout << "Compatible room" << endl;
        }
    }

    int display_room_no(void)
    {
        return room_no_;
    }
};

class billroom : virtual public room_book
{
private:
    int bill = 0;

public:
    void get_bill_room()
    {
        if (bed == 1) //bed
        {
            bill = bill + 150;
        }
        else if (bed == 2)
        {
            bill = bill + 250;
        }
        if (mem == 1) //members in room
        {
            bill = bill + 50;
        }
        else if (mem == 2)
        {
            if (family != 2)
            {
                bill = bill + (family * 100);
            }
            else
            {
                bill = bill + 200;
            }
        }
        else if (mem == 3)
        {
            bill = bill + 150;
        }
        if (getwifi == 'y')
        {
            bill = bill + 70;
        }
        else
        {
            bill = bill + 0;
        }
        if (luxy == 1)
        {
            bill = bill + 1000;
        }
        else
        {
            bill = bill + 400;
        }
        bill = bill * no_of_days;
        cout << "Your bill : " << bill << endl;
    }
};

class search : virtual public room_book
{
    int a;

public:
    int search_room(int a, int no)
    {
        if (a == 2)
        {
            if (no == room_no_)
            {
                return 10;
            }
        }
        else if (a == 5)
        {
            if (no == room_no_)
            {
                return 20;
            }
        }

        else
        {

            if (no == room_no_)
            {
                cout << "room founded sucessfully!" << endl;
                display();
                return 2;
            }
        }
        return 1;
    }
};

class leaveroom : public search, public billroom
{
    int b;

public:
    int leave_room(int a)
    {

        b = search_room(2, a);
        if (b == 10)
        {
            cout << "Room leave sucessful" << endl;
            return 10;
        }
        return 1;
    }
};

class room_no : public leaveroom
{
public:
    int get_room_no(void)
    {
         
        if (mem == 1)
        {
            floor++;
        }
        else if (mem == 2)
        {
            floor = floor + 2;
        }
        else
        {
            floor = floor + 3;
        }
        if (luxy == 1)
        {
            floor = floor + 3;
        }

        switch (floor)
        {
        case 1:
            room_no_ = 100;
            break;
        case 2:
            room_no_ = 200;
            break;
        case 3:

            room_no_ = 300;
            break;
        case 4:

            room_no_ = 400;
            break;
        case 5:
            room_no_ = 500;
            break;
        case 6:
            room_no_ = 600;
            break;
        
        }

        return room_no_;
    }
};

class pass
{
    int p = 0, i = 0;
    int change;
    int n;

public:
    void get_pass(void)
    {
        
        ifstream inpassword("pass1.txt");
        if (!inpassword)
        {
            int p = 1234;
            ofstream inpass("pass1.txt");
            inpass << p;
            
        }
        
        inpassword >> n;
        do
        {
            p = 0;
            cout << "    (IF FIRST TIME PASSWORD IS - 1234)   " << endl;
            cout << "    Username   :   Adminastor   " << endl;
            cout << "Enter Password :    " ;
            cin >> p;
        } while (p != n);
        inpassword.close();
    }

    void change_pass(void)
    {
        i = 0;
        while (i != 1)
        {
            ifstream inpassword("pass1.txt");
            inpassword >> n;
            p = 0;
            cout << "\nEnter Old Password : ";
            cin >> p;
            if (p == n)
            {
                inpassword.close();
                ofstream outpass("pass1.txt");
                cout << "Enter New Password : ";
                cin >> change;
                // change = n;
                outpass << change << "\n";
                outpass.close();
                cout << "Password changed successfully!" << endl;
                i++;
            }
            else
            {
                cout << "\nEntered Password is Invalid\n";
            }
        }
    }
};

int main()
{
    room_no a[30];
    pass p;
    int full = 0, check, roomno = 0, dv;
    int swich = 0, e, d = 2, romno,laks;

    system("cls");
    while (swich != 8)
    {
    menu:
        full=0;
        e = 0;
        system("cls");
        swich = 0;
        cout << endl;
        cout << "**************************************************************" << endl;
        cout << "* Sr.No * * * * * * * * * Menu * * * * * * * * * * * * * * * *" << endl;
        cout << "**************************************************************" << endl;
        cout << "*   1   *        Book room                                   *" << endl;
        cout << "*   2   *        See details                                 *" << endl;
        cout << "*   3   *        See Advance details                         *" << endl;
        cout << "*   4   *        Search a room                               *" << endl;
        cout << "*   5   *        See Vacant rooms                            *" << endl;
        cout << "*   6   *        Leave a room                                *" << endl;
        cout << "*   7   *        Change password                             *" << endl;
        cout << "*   8   *        Exit                                        *" << endl;
        cout << "**************************************************************" << endl;
        cout << "\nEnter your choice : ";
        cin >> swich;
        switch (swich)
        {
        case 1:
            system("cls");

            for (int i = 0; i < 30; i++)
            {
                full = full + romo[i];
            }
            if (full == 30)
            {
                system("cls");
                cout << "***************************************************************" << endl;
                cout << "*                       No rooms available                    *" << endl;
                cout << "***************************************************************" << endl;
            }

            for (int i = 0; i < 30; i++)
            {
                if (romo[i] == 0)
                {
                    cout << "***************************************************************" << endl;
                    cout << "*                 Enter personal details                      * " << endl;
                    cout << "***************************************************************" << endl;
                    check = a[i].get_person();
                    cout << endl;
                    system("cls");
                    if (check == 2)
                    {
                        goto menu;
                    }

                    cout << "***************************************************************" << endl;
                    cout << "*                  Enter Room details                         *" << endl;
                    cout << "***************************************************************" << endl;
                    a[i].get_room();
                    system("cls");
                    cout << "***************************************************************" << endl;
                    cout << "*                Sucessfully booked a room !                  *" << endl;
                    cout << "***************************************************************" << endl;

                    a[i].get_room_no();
                    romno = a[i].room_no_;
                    laks=0;
                    e=0;
                    roomchecking:
                    for (int g = 0; g < 30; g++)
                    {
                        laks=a[g].search_room(2,romno);
                        if (e == 5)
                        {
                            cout<<"The room you want is unavailable for the moment "<<endl;
                            system("pause");
                            goto menu;
                        }
                        
                        if (laks==10)
                        {
                            romno=romno+1;
                            e=e+1;
                            goto roomchecking;
                        } 
                    }
            
                    
                    a[i].room_no_ = romno;
                    system("pause");
                bill:
                    cout << "Your room no " << a[i].room_no_ << " on floor  " << a[i].floor<<endl;
                    a[i].get_bill_room();
                    cout << endl;
                    system("pause");
                    system("cls");
                    romo[i] = 1;
                    goto menu;
                }
            }

            
            system("cls");

            goto menu;
            break;

        case 2:
            system("cls");
            for (int z = 0; z < 30; z++)
            {
                if (romo[z] == 1)
                {
                    a[z].display();
                }
            }
            system("pause");
            for (int y = 0; y < 30; y++)
            {
                full = full + romo[y];
            }
            if (full == 30)
            {
                cout << "***************************************************************" << endl;
                cout << "*                   No rooms available                        *" << endl;
                cout << "***************************************************************" << endl;
            }
            else if (full == 0)
            {
                cout << "***************************************************************" << endl;
                cout << "*                   No rooms booked yet                       *" << endl;
                cout << "***************************************************************" << endl;
            }

            system("pause");

            goto menu;
            break;
        case 3:
        for (int y = 0; y < 30; y++)
            {
                full = full + romo[y];
            }
            if (full == 30)
            {
                system("cls");
                cout << "***************************************************************" << endl;
                cout << "*                    No rooms available                       *" << endl;
                cout << "***************************************************************" << endl;
                goto menu;
            }
            else if (full == 0)
            {
                cout << "***************************************************************" << endl;
                cout << "*                   No rooms booked yet                       *" << endl;
                cout << "***************************************************************" << endl;
                goto menu;
            }
            system("pause");
            system("cls");
            p.get_pass();
            system("cls");
            for (int u = 0; u < 30; u++)
            {

                if (romo[u] == 1)
                {
                    cout << "***************************************************************" << endl;
                    a[u].adv_display();
                    cout << "***************************************************************" << endl;
                }
            }
            system("pause");
            break;

        case 4:
            e = 0;
            system("cls");
            cout << "***************************************************************" << endl;
            cout << "*                 Enter room no for search                    *" << endl;
            cout << "***************************************************************" << endl;
            cin >> e;

            for (int i = 0; i < 30; i++)
            {
                full = full + romo[i];
            }
            if (full == 0)
            {
                cout << "***************************************************************" << endl;
                cout << "*                   No rooms booked yet                       *" << endl;
                cout << "***************************************************************" << endl;
                system("pause");
                goto menu;
            }
            system("cls");
            for (int i = 0; i < 30; i++)
            {
                a[i].search_room(1, e);
            }
            system("pause");
            break;

        case 5:
            system("cls");
            roomno = 0;
            for (int i = 0; i < 6; i++)
            {
                roomno = roomno + 100;
                if (roomno < 200)
                {
                    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*" << endl;
                    cout << "*                              first floor                                     *" << endl;
                    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*\n\n" << endl;
                }
                else if (roomno < 300)
                {
                    cout << "\n\n* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*" << endl;
                    cout << "*                              Second floor                                    *" << endl;
                    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*\n\n" << endl;
                }
                else if (roomno < 400)
                {
                    cout << "\n\n* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*" << endl;
                    cout << "*                              Third floor                                     *" << endl;
                    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*\n\n" << endl;
                }
                else if (roomno < 500)
                {
                    cout << "\n\n* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*" << endl;
                    cout << "*                              Fourth floor                                    *" << endl;
                    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*\n\n" << endl;
                }
                else if (roomno < 600)
                {
                    cout << "\n\n* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*" << endl;
                    cout << "*                              Fifth floor                                     *" << endl;
                    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*\n\n" << endl;
                }
                else
                {
                    cout << "\n\n* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*" << endl;
                    cout << "*                              Sixth floor                                     *" << endl;
                    cout << "* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*\n\n" << endl;
                }

                for (int j = 0; j < 5; j++)
                {
                    roomno = roomno + 1;
                    for (int k = 0; k < 30; k++)
                    {
                        dv = a[k].search_room(5, roomno);
                        if (dv == 20)
                        {
                            if (romo[k] == 0)
                            {
                                // cout << roomno << " : " << "vacant ";
                                continue;
                            }
                            else
                            {
                                cout << roomno << " : " << "occupied ";
                                break;
                            }
                        }
                        else if (k == 29)
                        {
                            cout << roomno << " : " << "vacant ";
                        }
                    }
                    if (j == 4)
                    {
                        roomno = roomno - 5;
                    }
                }
                cout << endl;
            }
            system("pause");
            break;
        case 6:
            system("cls");
            d = 0;
            full = 0;
            for (int i = 0; i < 30; i++)
            {
                full = full + romo[i];
            }
            if (full == 0)
            {
                cout << "***************************************************************" << endl;
                cout << "*                   No rooms booked yet                       *" << endl;
                cout << "***************************************************************" << endl;
                system("pause");
                goto menu;
            }
            // system("cls");
            cout << "***************************************************************" << endl;
            cout << "*        Enter room no for leave :                            *" << endl;
            cout << "***************************************************************" << endl;
            cin >> d;
            for (int i = 0; i < 30; i++)
            {
                e = a[i].leave_room(d);
                if (e == 10)
                {
                    romo[i] = 0;
                }
            }
            system("pause");
            break;

        case 7:
            system("cls");
            p.change_pass();
            system("pause");
            break;       
        
        case 8:
            break;
        default:
            cout << "Invalid choice :";
            break;
        }
    }
    cout<<"Thank you for using our service!"<<endl;
    return 0;
}