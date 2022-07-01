#include <iostream>
#include <fstream>

#include <string>
using namespace std;

void main_menu();
string validation_contact(string x);
string validation_age(string y);

class info
{
protected:
    string f_name, l_name, age, gender, email, contact;

public:
    info()
    {
        f_name = " ";
        l_name = " ";
        age = " ";
        gender = " ";
        email = " ";
        contact = " ";
    }

    friend string validation_contact(string x);
    friend string validation_age(string y);
};

class user : protected info
{
private:
    string user_num, height, weight, BMI, activity_stat, diet, exercise;
    float b, h, w;

public:
    friend class admin;

    void calc_bmi()
    {

        b = w / (h * h);
        BMI = to_string(b);
        height = to_string(h);
        weight = to_string(w);

        if (b >= 18.5 && b <= 24.9)
        {
            cout << "\t\t\tYour BMI : " << b << " is perfectly fine!" << endl;
        }

        else if (b < 18.5)
        {
            cout << "\t\t\tYour BMI : " << b << endl;
            cout << "\t\t\tYou are under-weight!" << endl;
        }

        else if (b >= 24.9 && b <= 29.9)
        {
            cout << "\t\t\tYour BMI : " << b << endl;
            cout << "\t\t\tYou are over-weight!" << endl;
        }

        else if (b > 29.9)
        {
            cout << "\t\t\tYour BMI : " << b << endl;
            cout << "\t\t\tObese!!!!" << endl;
        }
    }

    void diet_plan(int bmi)
    {
        // cout<<"Your BMI is: "<BMI;
        if (bmi >= 25.9)
        {
            exercise = "WEIGHT-LOSS";

            diet = "PLAN-1(RIGID)";
        }

        else if (bmi < 25.9 && bmi >= 24.9)
        {
            exercise = "MIX-EXERCISE-PLAN";

            diet = "PLAN-2(MODERATE)";
        }

        else if (bmi < 24.9)
        {
            exercise = "BODY-BUILDING";

            diet = "PLAN-3(EASY)";
        }

        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\tYour recommended Diet plan is: " << diet << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\tYour recommended Exercise plan is: " << exercise << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
    }

    void diet_plan(int bmi, string activity_stat)
    {
        if ((bmi >= 25.9 && activity_stat == "high") || (bmi < 24.9 && activity_stat == "low") || ((bmi < 25.9 && bmi >= 24.9) && activity_stat == "medium"))
        {
            exercise = "MIX-EXERCISE-PLAN";

            diet = "PLAN-2(MODERATE)";
        }

        else if ((bmi >= 25.9 && (activity_stat == "medium" || activity_stat == "low")) || ((bmi < 25.9 && bmi >= 24.9) && activity_stat == "low"))
        {
            exercise = "WEIGHT-LOSS";

            diet = "PLAN-1(RIGID)";
        }

        else if (((bmi < 25.9 && bmi >= 24.9) && activity_stat == "high") || (bmi < 24.9 && (activity_stat == "high" || activity_stat == "medium")))
        {
            exercise = "BODY-BUILDING";

            diet = "PLAN-3(EASY)";
        }

        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\tYour recommended Diet plan is: " << diet << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
        cout << "\t\t\tYour recommended Exercise plan is: " << exercise << endl;
        cout << "\t\t\t-----------------------------------------------------------" << endl;
    }

    void umenu();
    void uinsert();
    void udisplay();
    void umodify();
    void usearch();
    void udeleted();
};

void user::umenu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| GYM MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. REGISTER A NEW USER" << endl;
    cout << "\t\t\t 2. DISPLAY RECORDS OF ALL USERS" << endl;
    cout << "\t\t\t 3. SEARCH USER" << endl;
    cout << "\t\t\t 4. MAIN MENU" << endl;
    cout << "\t\t\t 5. EXIT" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tEnter your Option: ";
    cin >> choice;
    cout << "\t\t\t---------------------------" << endl;

    switch (choice)
    {
    case 1:
        do
        {
            uinsert();
            cout << "\n\t\t\t Add Another Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;

    case 2:
        udisplay();
        break;

    case 3:
        usearch();
        break;

    case 4:
        main_menu();
        break;

    case 5:
        exit(0);

    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getchar();
    goto menustart;
}

void user ::uinsert() // add user details
{
    string n, a;
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add USER Details ---------------------------------------------" << endl;

    cout << "\t\t\tEnter First Name: ";
    cin >> f_name;
    cout << "\t\t\tEnter Last Name: ";
    cin >> l_name;
    cout << "\t\t\tEnter User No.: ";
    cin >> user_num;
    age = validation_age(a);
    cout << "\t\t\tEnter your Gender(Male/Female/Other): ";
    cin >> gender;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email;
    contact = validation_contact(n);
    cout << "\t\t\tEnter height: ";
    cin >> h;
    cout << "\t\t\tEnter weight: ";
    cin >> w;
    calc_bmi();
    cout << "\t\t\tEnter your Activity Status: ";
    cin >> activity_stat;
    cout << endl
         << "\t\t\tRecommend DIET and EXERCISE Plan on the basis of: " << endl;
    cout << "\t\t\t-----------------------------------------------------------" << endl;
    cout << "\t\t\t1. BMI and Activity Status." << endl;
    cout << "\t\t\t2. Only BMI." << endl;
    cout << endl
         << "\t\t\tEnter your option: ";
    int i;
    cin >> i;
    cout << endl;

    if (i == 1)
    {
        diet_plan(b, activity_stat);
    }

    else if (i == 2)
    {
        diet_plan(b);
    }

    file.open("USERRECORD.txt", ios::app | ios::out);

    file << " " << f_name << " " << l_name << " " << user_num << " " << age << " " << gender << " " << email << " " << contact << " "
         << height << " " << weight << " " << BMI << " " << activity_stat << " " << diet << " " << exercise << "\n";

    file.close();
}

void user::udisplay() // display user details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- User Records Table --------------------------------------------" << endl;
    file.open("USERRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }

    else
    {
        file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;

        while (!file.eof())
        {
            cout << "\n\n\t\t\t User count: " << total++ << endl;
            cout << "\t\t\t User Name: " << f_name << " " << l_name << endl;
            cout << "\t\t\t User Number: " << user_num << endl;
            cout << "\t\t\t User Age: " << age << endl;
            cout << "\t\t\t User Gender: " << gender << endl;
            cout << "\t\t\t User Email ID: " << email << endl;
            cout << "\t\t\t User Contact Number: " << contact << endl;
            cout << "\t\t\t User Height: " << height << endl;
            cout << "\t\t\t User Weight: " << weight << endl;
            cout << "\t\t\t User BMI: " << BMI << endl;
            cout << "\t\t\t User Activity Status: " << activity_stat << endl;
            cout << "\t\t\t User Diet: " << diet << endl;
            cout << "\t\t\t User Exercise Plan: " << exercise << endl
                 << endl;

            file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;
        }

        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}

void user::umodify() // Modify User Details
{
    system("cls");
    fstream file, file1;
    string num;
    static int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- User Modify Details ------------------------------------------\n"
         << endl;
    file.open("USERRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }

    else
    {
        cout << "\nEnter user number you want to Modify: ";
        cin >> num;

        file1.open("RECORD.txt", ios::app | ios::out);

        file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;
        while (!file.eof())
        {
            if (num != user_num)

                file1 << " " << f_name << " " << l_name << " " << user_num << " " << age << " " << gender << " " << email << " " << contact << " " << height
                      << " " << weight << " " << BMI << " " << activity_stat << " " << diet << " " << exercise << "\n";
            else if (num == user_num)
            {
                string n, a;
                found++;
                cout << "\t\t\tEnter First Name: ";
                cin >> f_name;
                cout << "\t\t\tEnter Last Name: ";
                cin >> l_name;
                cout << "\t\t\tEnter User No.: ";
                cin >> user_num;
                age = validation_age(a);
                cout << "\t\t\tEnter your Gender(Male/Female/Other): ";
                cin >> gender;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email;
                contact = validation_contact(n);
                cout << "\t\t\tEnter height: ";
                cin >> h;
                cout << "\t\t\tEnter weight: ";
                cin >> w;
                calc_bmi();
                cout << "\t\t\tEnter your Activity Status: ";
                cin >> activity_stat;
                cout << endl
                     << "Recommend DIET and EXERCISE Plan on the basis of: " << endl;
                cout << "-----------------------------------------------------------" << endl;
                cout << "1. BMI and Activity Status." << endl;
                cout << "2. Only BMI." << endl;
                cout << endl
                     << "Enter your option: ";
                int i;
                cin >> i;
                cout << endl;

                if (i == 1)
                {
                    diet_plan(b, activity_stat);
                }

                else if (i == 2)
                {
                    diet_plan(b);
                }
                file1 << " " << f_name << " " << l_name << " " << user_num << " " << age << " " << gender << " " << email << " " << contact
                      << " " << height << " " << weight << " " << BMI << " " << activity_stat << " " << diet << " " << exercise << "\n";
            }
            file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;
            if (found == 0)
            {
                cout << "\n\n\t\t\t User No. Not Found....\n";
            }
        }
        file1.close();
        file.close();
        remove("USERRECORD.txt");
        rename("RECORD.txt", "USERRECORD.txt");
    }
}

void user::usearch() // search data of a user member
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("USERRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- User Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string n;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- User Search Data ------------------------------------------" << endl;
        cout << "\n Enter User number You Want to Search: ";
        cin >> n;
        file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;
        while (!file.eof())
        {
            if (n == user_num)
            {
                cout << "\t\t\t User Name: " << f_name << " " << l_name << endl;
                cout << "\t\t\t User Number: " << user_num << endl;
                cout << "\t\t\t User Age: " << age << endl;
                cout << "\t\t\t User Gender: " << gender << endl;
                cout << "\t\t\t User Email ID: " << email << endl;
                cout << "\t\t\t User Contact Number: " << contact << endl;
                cout << "\t\t\t User Height: " << height << endl;
                cout << "\t\t\t User Weight: " << weight << endl;
                cout << "\t\t\t User BMI: " << BMI << endl;
                cout << "\t\t\t User Activity Status: " << activity_stat << endl;
                cout << "\t\t\t User Diet: " << diet << endl;
                cout << "\t\t\t User Exercise Plan: " << exercise << endl
                     << endl;
                found++;
            }
            file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tUser No. Not Found...";
        }

        file.close();
    }
}

void user ::udeleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string n;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete User Details ------------------------------------------" << endl;
    file.open("USERRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter User number you want Delete Data: ";
        cin >> n;
        file1.open("RECORD.txt", ios::app | ios::out);
        file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;
        while (!file.eof())
        {
            if (n != user_num)
            {
                file1 << " " << f_name << " " << l_name << " " << user_num << " " << age << " " << gender << " " << email << " " << contact << " "
                      << height << " " << weight << " " << BMI << " " << activity_stat << " " << diet << " " << exercise << "\n";
                found++;
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data\n";
            }
            file >> f_name >> l_name >> user_num >> age >> gender >> email >> contact >> height >> weight >> BMI >> activity_stat >> diet >> exercise;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t User No. Not Found....";
        }
        file1.close();
        file.close();
        remove("USERRECORD.txt");
        rename("RECORD.txt", "USERRECORD.txt");
    }
}

class admin : protected info
{
private:
    string admin_num, employement_stat, password;

public:
    admin()
    {
        password = "admin123";
    }

    void amenu(user);
    void ainsert();
    void adisplay();
    void amodify();
    void asearch();
    void adeleted();
};

void main_menu();

void admin::amenu(user u1)
{
_password:
    string pass;
    cout << "\t\t\tWelcome to the Admin login" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\tEnter the Admin Password: ";
    cin >> pass;

    if (pass == password)
    {
    menustart:
        int choice;
        char x;
        system("cls");

        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t| GYM MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. ENTER NEW ADMIN RECORD" << endl;
        cout << "\t\t\t 2. DISPLAY ALL ADMIN RECORDS" << endl;
        cout << "\t\t\t 3. MODIFY ADMIN RECORD" << endl;
        cout << "\t\t\t 4. SEARCH ADMIN RECORD" << endl;
        cout << "\t\t\t 5. DELETE ADMIN RECORD" << endl;
        cout << "\t\t\t 6. DISPLAY ALL USER RECORDS" << endl;
        cout << "\t\t\t 7. MODIFY USER RECORD" << endl;
        cout << "\t\t\t 8. SEARCH USER RECORD" << endl;
        cout << "\t\t\t 9. DELETE USER RECORD" << endl;
        cout << "\t\t\t 10. MAIN MENU" << endl;
        cout << "\t\t\t 11. EXIT" << endl;

        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\tEnter your Option: ";
        cin >> choice;
        cout << "\t\t\t---------------------------" << endl;

        switch (choice)
        {
        case 1:
            do
            {
                ainsert();
                cout << "\n\t\t\t Add Another Record (Y,N): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;

        case 2:
            adisplay();
            break;

        case 3:
            amodify();
            break;

        case 4:
            asearch();
            break;

        case 5:
            adeleted();
            break;

        case 6:
            u1.udisplay();
            break;

        case 7:
            u1.umodify();
            break;

        case 8:
            u1.usearch();
            break;

        case 9:
            u1.udeleted();
            break;

        case 10:
            main_menu();
            break;

        case 11:
            exit(0);

        default:
            cout << "\n\t\t\t Invalid choice... Please Try Again..";
        }
        getchar();
        goto menustart;
    }

    else
    {
        cout << "\n\t\t\t----WRONG PASSWORD----\n"
             << endl;
        goto _password;
    }
}
void admin::ainsert() // add admin details
{
    string n, a;
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Admin Details ---------------------------------------------" << endl;

    cout << "\t\t\tEnter First Name: ";
    cin >> f_name;
    cout << "\t\t\tEnter Last Name: ";
    cin >> l_name;
    cout << "\t\t\tEnter Admin No.: ";
    cin >> admin_num;
    age = validation_age(a);
    cout << "\t\t\tEnter your Gender(Male/Female/Other): ";
    cin >> gender;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email;
    contact = validation_contact(n);
    cout << "\t\t\tEnter Employement Status: ";
    cin >> employement_stat;
    file.open("ADMINRECORD.txt", ios::app | ios::out);
    file << " " << f_name << " " << l_name << " " << admin_num << " " << age << " " << gender << " " << email << " " << contact << " " << employement_stat << "\n";
    file.close();
}

void admin::adisplay() // display admin details
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Admin Records Table --------------------------------------------" << endl;
    file.open("ADMINRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }

    else
    {
        file >> admin_num >> f_name >> l_name >> age >> gender >> email >> contact >> employement_stat;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Admin count: " << total++ << endl;
            cout << "\t\t\t Admin Name: " << f_name << " " << l_name << endl;
            cout << "\t\t\t Admin Number: " << admin_num << endl;
            cout << "\t\t\t Admin Age: " << age << endl;
            cout << "\t\t\t Admin Gender: " << gender << endl;
            cout << "\t\t\t Admin Email ID: " << email << endl;
            cout << "\t\t\t Admin Contact Number: " << contact << endl;
            cout << "\t\t\t Admin Employement Status: " << employement_stat << endl
                 << endl;
            file >> f_name >> l_name >> admin_num >> age >> gender >> email >> contact >> employement_stat;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}
void admin::amodify() // Modify Admin Details
{
    system("cls");
    fstream file, file1;
    string num;
    static int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Admin Modify Details ------------------------------------------\n"
         << endl;
    file.open("ADMINRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Admin number you want to Modify: ";
        cin >> num;
        file1.open("RECORD.txt", ios::app | ios::out);
        file >> f_name >> l_name >> admin_num >> age >> gender >> email >> contact >> employement_stat;
        while (!file.eof())
        {
            if (num != admin_num)

                file1 << " " << f_name << " " << l_name << " " << admin_num << " " << age << " " << gender << " " << email << " " << contact << " " << employement_stat << "\n";
            else if (num == admin_num)
            {
                string n, a;
                found++;
                cout << "\t\t\tEnter First Name: ";
                cin >> f_name;
                cout << "\t\t\tEnter Last Name: ";
                cin >> l_name;
                cout << "\t\t\tEnter Admin No.: ";
                cin >> admin_num;
                age = validation_age(a);
                cout << "\t\t\tEnter your Gender(Male/Female/Other): ";
                cin >> gender;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email;
                contact = validation_contact(n);
                cout << "\t\t\tEnter Employement Status: ";
                cin >> employement_stat;
                file1 << " " << f_name << " " << l_name << " " << admin_num << " " << age << " " << gender << " " << email << " " << contact << " " << employement_stat << "\n";
            }
            file >> f_name >> l_name >> admin_num >> age >> gender >> email >> contact >> employement_stat;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Admin No. Not Found....\n";
            }
        }
        file1.close();
        file.close();
        remove("ADMINRECORD.txt");
        rename("RECORD.txt", "ADMINRECORD.txt");
    }
}
void admin::asearch() // search data of a admin member
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("ADMINRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Admin Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string n;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Admin Search Data ------------------------------------------" << endl;
        cout << "\n Enter Admin number You Want to Search: ";
        cin >> n;
        file >> f_name >> l_name >> admin_num >> age >> gender >> email >> contact >> employement_stat;
        while (!file.eof())
        {
            if (n == admin_num)
            {
                cout << "\t\t\t Admin Name: " << f_name << " " << l_name << endl;
                cout << "\t\t\t Admin Number: " << admin_num << endl;
                cout << "\t\t\t Admin Age: " << age << endl;
                cout << "\t\t\t Admin Gender: " << gender << endl;
                cout << "\t\t\t Admin Email ID: " << email << endl;
                cout << "\t\t\t Admin Contact Number: " << contact << endl;
                cout << "\t\t\t Admin Employement Status: " << employement_stat << endl;
                found++;
            }
            file >> f_name >> l_name >> admin_num >> age >> gender >> email >> contact >> employement_stat;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tAdmin No. Not Found...";
        }
        file.close();
    }
}
void admin ::adeleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string n;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Admin Details ------------------------------------------" << endl;
    file.open("ADMINRECORD.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Admin number you want Delete Data: ";
        cin >> n;
        file1.open("RECORD.txt", ios::app | ios::out);
        file >> f_name >> l_name >> admin_num >> age >> gender >> email >> contact >> employement_stat;
        while (!file.eof())
        {
            if (n != admin_num)
            {
                file1 << " " << f_name << " " << l_name << " " << admin_num << " " << age << " " << gender << " " << email << " " << contact << " " << employement_stat << "\n";
                found++;
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> f_name >> l_name >> admin_num >> age >> gender >> email >> contact >> employement_stat;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Admin No. Not Found....";
        }
        file1.close();
        file.close();
        remove("ADMINRECORD.txt");
        rename("RECORD.txt", "ADMINRECORD.txt");
    }
}

void main_menu()
{
menustart:
    int option;
    user u;
    admin a;
    cout << "\t\t\t---------------------------------" << endl;
    cout << "\t\t\tWELCOME TO FITNESS BOX GYM" << endl;
    cout << "\t\t\t---------------------------------" << endl;
    cout << "\t\t\t1. USER LOGIN" << endl;
    cout << "\t\t\t2. ADMIN LOGIN" << endl;
    cout << "\t\t\t---------------------------------" << endl;
    cout << "\t\t\tEnter your Option: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        u.umenu();
    }
    break;

    case 2:
    {
        a.amenu(u);
    }
    break;

    case 3:
        exit(0);

    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getchar();
    goto menustart;
}

string validation_contact(string n)
{
    cout << "\t\t\tEnter your Contact Number: ";
    cin >> n;
    int len = n.length();

    if (len > 10 || len < 10)
    {
        cout << "\n\t\t\t------!!ERROR: Enter a Valid Contact Number!!------" << endl;
        cout << "\t\t\tEnter your Contact Number: ";
        cin >> n;
    }
    return n;
}

string validation_age(string a)
{
    cout << "\t\t\tEnter your Age: ";
    cin >> a;
    int len = a.length();

    if (len > 2)
    {
        cout << "\n\t\t\t------!!ERROR: Enter a Valid Age!!------" << endl;
        cout << "\t\t\tEnter your Age: ";
        cin >> a;
    }

    return a;
}

int main()
{
    main_menu();

    return 0;
}