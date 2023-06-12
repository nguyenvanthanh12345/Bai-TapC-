#include<stdio.h>
#include<string>
#include<stdint.h>
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;




//this macro use to enter, check the input data and show error information
#define INPUT_TYPE(text, var, check, show_Erorr)      \
        do                                                  \
        {                                                    \
            cout << text;\
            cin>>var;            \
            if(check)  \
            {                                             \
                cout << show_Erorr<< endl;                    \
                cout << "please enter again \n";  \
            }                                             \
        }                                                    \
        while(check) 
    
#define NO_CHECK 0
#define NO_SHOW "\0"

typedef enum
{
    CLEANING_STAFF,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    GARDENER,
    LUGGAGE_STAFF,
    _NULL
}Job_Position;

typedef struct
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
}Type_Date;

typedef struct 
{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
}Type_Time;

typedef enum
{
    IN_SHIFT ,
    OUT_SHIFT 
}Type_Status;

typedef struct
{
    Type_Date date;
    Type_Time time;
    Type_Status status;
}Job_Skedule;

class User
{
    private:
    string USER_NAME;
    string PASSWORD;
    public:
    User(string user_Name, string password);
    User();
    string get_User_Name();
    bool authenticate(string password);
};

User::User(string user_Name, string password)
{
    this->PASSWORD = password;
    this->USER_NAME = user_Name;
}

User::User()
{

}

string User::get_User_Name()
{
    return this->USER_NAME;
}

bool User::authenticate(string password)
{
    if((password.compare("admin") == 0) || this->PASSWORD.compare(password) == 0) return true;
    return false;
}

class Employee
{
    private:
    string NAME;
    string PHONE;
    Job_Position POSITION;
    Job_Skedule SKEDULE;
    User USER;
    
    public:
    Employee(string name, string phone, Job_Position position, User user);
    string getName(string password);
    string setName(string name, string password);
    string getPhone(string password);
    string setPhone(string phone, string password);
    Job_Position getPosition(string password);
    Job_Position setPosition(Job_Position position, string password);
};

Employee::Employee(string name, string phone, Job_Position position, User user)
{
    this->NAME = name;
    this->PHONE = phone;
    this->POSITION = position;
    this->USER = user;
    //this->SKEDULE = skedule;
}

string Employee::getName(string password)
{
    if(this->USER.authenticate(password)) return this->NAME;
    return "\0";
}

string Employee::setName(string name, string password)
{
    if(this->USER.authenticate(password)) this->NAME = name;
    else return "\0";
}

string Employee::getPhone(string password)
{
    if(this->USER.authenticate(password)) return this->PHONE;
    else return "\0";
}

string Employee::setPhone(string phone,string password)
{
    if(this->USER.authenticate(password)) this->PHONE = phone;
    else return "\0";
}

Job_Position Employee::getPosition(string password)
{
    if(this->USER.authenticate(password)) return this->POSITION;
    else return _NULL;
}

Job_Position Employee::setPosition(Job_Position position,string password)
{
    if(this->USER.authenticate(password)) this->POSITION = position;
    else return _NULL;
}

class ManageEmployee
{
    private:
    vector<Employee> Employee_List;
    void show_Employee(Employee employee, string password);
    public:
    ManageEmployee();
    void add_Employee();
    void update_Employee();
    void delete_Employee();
    void show_Employee_List();
};

ManageEmployee::ManageEmployee()
{
    int16_t key;
    while(1)
    {
        do
        {
            cout <<"\n**************menu**************" << endl;
            cout <<"1. them nhan vien" << endl;
            cout <<"2. thay doi thong tin nhan vien" << endl;
            cout <<"3. xoa khach hang" << endl;
            cout <<"4. danh sach nhan vien" << endl;
            cout <<"0. thoat" << endl;
            cout <<"vui long nhap chuc nang" << endl;
            cin >> key;
        }
        while(key < 0 || key >4);
        if(key == 0) break;
        switch(key)
        {
            case 1:
            {
               this->add_Employee();
                break;
            }
            case 2:
            {
                this->update_Employee();
                break;
            }
            case 3:
            {
                this->delete_Employee();
                break;
            }
            case 4:
            {
                this->show_Employee_List();
                break;
            }
        }
    }
}

void ManageEmployee::add_Employee()
{
    string name;
    string phone;
    string s_position;
    Job_Position position;
    string user_Name;
    string password;

    cout<<"**********them nhan vien***********"<< endl;
    INPUT_TYPE("nhap ten: ", name, NO_CHECK,NO_SHOW);
    INPUT_TYPE("nhap so dien thoai: ", phone, NO_CHECK, NO_SHOW);
    INPUT_TYPE("nhap chuc vu: ", s_position,(s_position.compare("lao_cong") != 0) && (s_position.compare("lam_vuon")!= 0) && (s_position.compare("giat_la")!= 0) && (s_position.compare("hanh_ly")!= 0), "loi input chuc vu");
    if(s_position.compare("lao cong") == 0) position = CLEANING_STAFF;
    else if(s_position.compare("tiep_tan")== 0) position = RECEPTIONIST;
    else if(s_position.compare("lam_vuon")== 0) position = GARDENER;
    else if(s_position.compare("gia_la")== 0) position =  LAUNDRY_STAFF;
    else if(s_position.compare("hanh_ly")== 0) position =  LUGGAGE_STAFF;
    INPUT_TYPE("nhap password: ", password, NO_CHECK, NO_SHOW);

    User user(user_Name, password);
    Employee employee(name,phone, position,user);
    Employee_List.push_back(employee);
}
    
void ManageEmployee::update_Employee()
{
    int16_t key;
    string password;
    string phone;
    string name;
    Job_Position position;
    string s_position;
    string input_Name;
    int i;
    uint8_t status = 0;
    INPUT_TYPE("nhap password: ", password,NO_CHECK, NO_SHOW);
    if(password.compare("admin") == 0)
    {
        INPUT_TYPE("nhap ten: ", name,NO_CHECK, NO_SHOW);
        for( i= 0; i < Employee_List.size() ; i++)
        {
            if(Employee_List[i].getName(password) == name)
            {
                status = 1;
                break;
            }
        }
        if(status == 0)
        {
            cout << "khong tim thay ten"<< endl;
            return;
        }
    }
    else
    {
        for( i= 0; i<Employee_List.size(); i++)
        {
            if(Employee_List[i].getName(password) != "\0")
            {
                status = 1;
                break;;
            }
        }
        if(status == 0)
        {
            cout << "password bi sai"<< endl;
            return;
        }
    }

    this->show_Employee(Employee_List[i],password);
    do
    {
        cout<< "vui long chon chuc nang\n";
        cout <<"1. thay doi ten \n";
        cout <<"2. thay doi so dien thoai\n";
        cout<<"3. thay doi vi tri" << endl;
        cout <<"0. thoat\n";
        cout<< "vui long nhap chuc nang"<<endl;
        cin >> key;
        switch(key)
        {
            case 1:
            {
                INPUT_TYPE("nhap ten: ", name, NO_CHECK,NO_SHOW);
                Employee_List[i].setName(name,password);
                break;
            }
            case 2:
            {
                INPUT_TYPE("nhap so dien thoai: ", phone, NO_CHECK, NO_SHOW);
                Employee_List[i].setPhone(phone,password);
                break;
            }
            case 3: 
            {
                INPUT_TYPE("nhap chuc vu: ", s_position,(s_position.compare("lao_cong") != 0) && (s_position.compare("lam_vuon")!= 0) && (s_position.compare("giat_la")!= 0) && (s_position.compare("hanh_ly")!= 0), "loi input chuc vu");
                if(s_position.compare("lao cong") == 0) position = CLEANING_STAFF;
                else if(s_position.compare("tiep_tan")== 0) position = RECEPTIONIST;
                else if(s_position.compare("lam_vuon")== 0) position = GARDENER;
                else if(s_position.compare("gia_la")== 0) position =  LAUNDRY_STAFF;
                else if(s_position.compare("hanh_ly")== 0) position =  LUGGAGE_STAFF;
                Employee_List[i].setPosition(position,password);
                break;
            }
        }
    }
    while(key != 0);
        
}

void ManageEmployee::delete_Employee()
{
    string password;
    uint8_t status = 0;
    int16_t key;
    int i ;
    cout<< "******xoa nhan vien***********" << endl;
    INPUT_TYPE("nhap password nhan vien can xoa: ", password, NO_CHECK, NO_SHOW);
    if(password.compare("admin") == 0)
    {
        string name;
        INPUT_TYPE("nhap ten: ", name, NO_CHECK, NO_SHOW);
        for(i= 0; i < Employee_List.size(); i++)
        {
            if(Employee_List[i].getName(password) == name)
            {
                status = 1;
                break;
            }
        }
        if( status == 0)
        {
            cout<< "khong tim thay ten" << endl;
            return;
        }
    }
    else
    {
        for(i=0 ; i< Employee_List.size(); i++)
        {
            if(Employee_List[i].getName(password) != "\0")
            {
                status = 1;
                break;
            }
        }
        if( status == 0)
        {
            cout <<"password bi sai"<<endl;
            return;
        }
    }
    this->show_Employee(Employee_List[i],password);
    cout <<"1. xoa" << endl;
    cout <<"0. thoat" << endl;
    cout << "vui long nhap phim: ";
    cin >> key;
    if(key == 1) Employee_List.erase(Employee_List.begin() + i);

}

void ManageEmployee::show_Employee_List()
{
    string password;
    INPUT_TYPE("vui long nhap mat khau admin : ",password, NO_CHECK, NO_SHOW);
    if(password.compare("admin") == 0)
    {
        cout<< "***********danh sach nhan vien********"<< endl;
        cout<<"ten" << "\t"<<"dien thoai" <<"\t" <<"chuc vu"<< endl;
        for( Employee employee: Employee_List)
        {
            this->show_Employee(employee,password);
        }
    }
    else cout << "sai mat khau hoac ban khong phai la admin"<<endl;
}

void ManageEmployee::show_Employee(Employee employee, string password)
{
    string s_position;
    if(employee.getPosition(password) == CLEANING_STAFF) s_position = "lam_vuon";
    else if(employee.getPosition(password) == RECEPTIONIST) s_position = "tiep tan";
    else if(employee.getPosition(password) == LAUNDRY_STAFF) s_position = "lao cong";
    else if(employee.getPosition(password) == LUGGAGE_STAFF) s_position = "hanh ly";
    else s_position  = "lam vuon";
    cout << employee.getName(password) << "\t" << employee.getPhone(password)<< "\t" << s_position << endl;
}

int main()
{
    ManageEmployee mn;
    
}
