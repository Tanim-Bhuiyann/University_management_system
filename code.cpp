#include <bits/stdc++.h>
using namespace std;

int Total_Admin = 0;
int student = 0;

class Admin
{
protected:
    string Name;
    string Mobile_num;
    string Password;

public:
    void read1(string Name, string Mobile_num, string Password)
    {
        this->Name = Name;
        this->Mobile_num = Mobile_num;
        this->Password = Password;
    }

    string getName()
    {
        return Name;
    }
    string getMobile_num()
    {
        return Mobile_num;
    }
    string getPassword()
    {
        return Password;
    }
    void set_password(string Password)
    {
        this->Password = Password;
    }

    void ADD(string name, string mobile_num, string password)
    {
        Name = name;
        Mobile_num = mobile_num;
        Password = password;
    }
};

class Admin admin[10];

// Reading Data from Owner File.
void Read_Admin_file()
{
    string Name;
    string Mobile_num;
    string Password;
    ifstream file("Admin_info.txt");
    while (file >> Name)
    {
        file >> Mobile_num;
        file >> Password;
        admin[Total_Admin].read1(Name, Mobile_num, Password);
        Total_Admin++;
    }
    file.close();
}

// Saving Data in Owner File.
void Save_Admin_file()
{
    ofstream file("Admin_info.txt");
    for (int i = 0; i < Total_Admin; i++)
    {
        file << admin[i].getName() << endl;
        file << admin[i].getMobile_num() << endl;
        file << admin[i].getPassword() << endl;
    }
    file.close();
}

// New Admin Registration.
void New_Registration()
{
    system("cls");

    int id;
    string name;
    string mobile_num;
    string password;
    Total_Admin++;

    cout << endl
         << "\tEnter your Username(You can't use any SPACE in Username) : ";
    cin.ignore();
    getline(cin, name);
    cout << endl
         << "\tEnter your mobile number : ";
    cin >> mobile_num;
    cout << endl
         << "\tEnter your password(You can't use any SPACE in Password) : ";
    cin.ignore();
    getline(cin, password);
    admin[Total_Admin - 1].ADD(name, mobile_num, password);
    Save_Admin_file();
    system("cls");
}

class University
{
    int id;
    string name;
    string department;
    string section;

public:
    void read(int id, string name, string department, string section)
    {
        this->id = id;
        this->name = name;
        this->department = department;
        this->section = section;
    }

    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getDepartment()
    {
        return department;
    }
    string getSection()
    {
        return section;
    }
    void setId(int id)
    {
        this->id = id;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setDepartment(string department)
    {
        this->department = department;
    }
    void setSection(string section)
    {
        this->section = section;
    }
    void show()
    {
        cout << endl;
        cout << "\t#ID         :" << getId() << endl;
        cout << "\t#NAME       :" << getName() << endl;
        cout << "\t#DEPARTMENT :" << getDepartment() << endl;
        cout << "\t#SECTION    :" << getSection() << endl
             << endl;
    }
};

class University university[100];

void save_txt_file() // Save Data in Text file.
{
    ofstream file("Student_info.txt");
    for (int i = 0; i < student; i++)
    {
        file << university[i].getId() << endl;
        file << university[i].getName() << endl;
        file << university[i].getDepartment() << endl;
        file << university[i].getSection() << endl;
    }
    file.close();
}

void read_txt_file() // read data from text file.
{
    ifstream file("version3.txt");
    int id;
    string name;
    string department;
    string section;

    while (file >> id)
    {
        file.ignore();
        getline(file, name);
        file >> department;
        file >> section;
        university[student].read(id, name, department, section);
        student++;
    }
    file.close();
}

void msg()
{
    cout << "\t_____________________________" << endl;
    cout << "\t|                           |" << endl;
    cout << "\t| PRESS 7 TO VIEW HOME PAGE |" << endl;
    cout << "\t|___________________________|" << endl;
}
void add()
{
    system("cls");
    system("color B");
    cout << "\tHOW MANY STUDENTS YOU WANT TO ADD : ";
    cin >> student;
    cout << endl;
    int id;
    string name;
    string department;
    string section;

    for (int i = 0; i < student; i++)
    {
        cout << "\t->ID          :";
        cin >> id;
        cin.ignore();
        cout << "\t->NAME        :";
        getline(cin, name);
        cout << "\t->DEPARTMENT  :";
        cin >> department;
        cout << "\t->SECTION     :";
        cin >> section;
        cout << endl;
        university[i].read(id, name, department, section);
    }
    save_txt_file();
    msg();
}

void see_all_student()
{
    system("cls");
    system("color 9");
    cout << "\tALL STUDENTS INFORMATION" << endl
         << endl;
    for (int i = 0; i < student; i++)
    {
        university[i].show();
    }
    if (student == 0)
        cout << "\tNO STUDENTS FOUND...!!!" << endl;
    msg();
}

void see_a_student()
{
    system("cls");
    system("color 5");
    cout << "\tENTER STUDENT ID : ";
    int x, count = 0;
    cin >> x;
    cout << endl;
    for (int i = 0; i < student; i++)
    {
        if (university[i].getId() == x)
        {
            university[i].show();
            count++;
        }
    }
    if (student == 0 || count == 0)
        cout << "\tID NOT FOUND...!!!" << endl;
    msg();
}

void see_department()
{
    system("cls");
    system("color 3");
    cout << "\t->ENTER A DEPARTMENT : ";
    int count = 0;
    string x;
    cin >> x;
    cout << endl;
    for (int i = 0; i < student; i++)
    {
        if (university[i].getDepartment() == x)
        {
            university[i].show();
            count++;
        }
    }
    if (student == 0 || count == 0)
        cout << "\tNO STUDENTS FOUND...!!!" << endl;
    msg();
}

void see_section()
{
    system("cls");
    system("color 3");
    cout << "\tENTER A SECTION :";
    int count = 0;
    string x;
    cin >> x;
    cout << endl;
    for (int i = 0; i < student; i++)
    {
        if (university[i].getSection() == x)
        {
            university[i].show();
            count++;
        }
    }
    if (student == 0 || count == 0)
        cout << "\tNO STUDENTS FOUND...!!!" << endl;
    msg();
}

void delete_student()
{
    system("cls");
    system("color C");
    int x, count = 0;
    cout << "\tENTER STUDENT ID : ";
    cin >> x;
    cout << endl;
    for (int i = 0; i < student; i++)
    {
        if (university[i].getId() == x)
        {
            for (int j = i; j < student - 1; j++)
            {
                university[j] = university[j + 1];
            }
            count++;
            student--;
        }
    }
    cout << endl;
    save_txt_file();
    if (count == 0)
        cout << "\tId Not Found...!!!" << endl;
    else
        cout << "\tId Deleted successfully..!!" << endl;
    msg();
}

void edit_student()
{
    system("cls");
    system("color E");
    int x, count = 0;
    cout << "\tENTER STUDENT ID : ";
    cin >> x;
    cout << endl;
    string name;
    string department, section;
    for (int i = 0; i < student; i++)
    {
        if (university[i].getId() == x)
        {
            cin.ignore();
            cout << "\tNAME       :";
            getline(cin, name);
            university[i].setName(name);
            cout << "\tDEPARTMENT :";
            cin >> department;
            university[i].setDepartment(department);
            cout << "\tSECTION    :";
            cin >> section;
            university[i].setSection(section);
            count++;
        }
    }
    save_txt_file();
    cout << endl;
    if (count == 0)
        cout << "\tId Not Found...!!!" << endl;
    else
        cout << "\tId Edited successfully..!!" << endl;
    msg();
}

void home_page()
{
    system("cls");
    system("color 2");
    cout << "\t____________________________________________________" << endl;
    cout << "\t|                                                  |" << endl;
    cout << "\t|  -> PRESS 0 TO ADD STUDENTS.                     |" << endl;
    cout << "\t|  -> PRESS 1 TO SEE ALL STUDENTS.                 |" << endl;
    cout << "\t|  -> PRESS 2 TO SEE A SPECIFIC STUDENT.           |" << endl;
    cout << "\t|  -> PRESS 3 TO SEE A DEPARTMENT.                 |" << endl;
    cout << "\t|  -> PRESS 4 TO SEE A SECTION.                    |" << endl;
    cout << "\t|  -> PRESS 5 TO DELETE A STUDENT.                 |" << endl;
    cout << "\t|  -> PRESS 6 TO EDIT A STUDENT.                   |" << endl;
    cout << "\t|  -> PRESS 8 TO SEE STUDENTS IN ASCENDING ORDER.  |" << endl;
    cout << "\t|  -> PRESS 9 TO Log Out.                          |" << endl;
    cout << "\t|__________________________________________________|" << endl
         << endl;
}

void sort_student()
{
    system("cls");
    system("color B");
    int i, j, temp;
    for (i = 0; i < student; i++)
    {
        for (j = i + 1; j < student; j++)
        {
            if (university[i].getId() > university[j].getId())
            {
                swap(university[i], university[j]);
            }
        }
    }
    for (i = 0; i < student; i++)
    {
        university[i].show();
    }
    if (student == 0)
        cout << "\tNO STUDENTS FOUND...!!!" << endl;
    save_txt_file();
    msg();
}
void Welcome()
{
    system("color A");
    cout << "\t_________________________________" << endl;
    cout << "\t|                               |" << endl;
    cout << "\t| University Student Management |" << endl;
    cout << "\t|_______________________________|" << endl;
}
void Quick_msg()
{
     system("color 3");
    cout << endl
         << "\t->Sign in          (1) " << endl
         << "\t->Sign up          (2) " << endl
         << "\t->Forgot Password  (3) " << endl
         << "\t->Exit             (0) " << endl
         << "\t->Enter Here : ";
}

void Reset_pass()
{
    system("cls");
    system("color C");
    cout << "\tEnter Mobile Number : ";
    string M_num;
    string Password;
    cin >> M_num;
    int found = 0;

    for (int i = 0; i < Total_Admin; i++)
    {
        if (admin[i].getMobile_num() == M_num)
        {
            cout << "\tUser Name : " << admin[i].getName() << endl;
            cin.ignore();
            cout << "\tEnter New Password :";
            getline(cin, Password);
            admin[i].set_password(Password);
            found = 1;
        }
    }
    Save_Admin_file();
    if (found == 0)
    {
        system("cls");
        cout << endl<<
        "\tMobile Number Does Not Match !!" << endl;
        cout<<"\tTry Again."<<endl<<endl;
    }
   // system("cls");

}

void login()
{

    system("color A");
    Read_Admin_file();
    while (1)
    {
        Quick_msg();
        int num;
        cin >> num;
        if (num == 1)
        {
            string username;
            string password;
            cout << endl
                 << "\tEnter your Username   : ";
            cin >> username;
            cout << "\tEnter your Password   : ";
            cin >> password;
            int i = 0;
            int found = 0;
            for(i=0; i<Total_Admin; i++)
            {
                if (admin[i].getName() == username && admin[i].getPassword() == password)
                {
                    home_page();
                    while (1)
                    {
                        int x;
                        cout << endl;
                        cout << "\t[ENTER] :";
                        cin >> x;
                        cout << endl;
                        if (x == 0)
                            add();
                        if (x == 1)
                            see_all_student();
                        if (x == 2)
                            see_a_student();
                        if (x == 3)
                            see_department();
                        if (x == 4)
                            see_section();
                        if (x == 5)
                            delete_student();
                        if (x == 6)
                            edit_student();
                        if (x == 7)
                            home_page();
                        if (x == 8)
                            sort_student();
                        if (x == 9)
                        {
                            system("cls");
                            break;
                        }
                    }

                    found = 1;
                }
                i++;
            }

            if (found == 0)
            {
                system("cls");
                cout << endl
                     << "\tUser Name or Password Not Found pls try again !!" << endl;
            }
        }
        else if (num == 2)
        {
            New_Registration();
        }
        else if (num == 3)
        {
            Reset_pass();
        }
        else if (num == 0)
        {
            break;
        }
    }
}

int main()
{
    system("cls");
    read_txt_file();
    Welcome();
    login();
    return 0;
}

//complete