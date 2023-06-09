#include<stdio.h>
#include<string>
#include<stdint.h>
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

#define INPUT_TYPE(text, var, check, show_Erorr)      \
        do                         \
        {                        \
            cout << text;          \
            cin >> var;                \
        }                       \
        while(check) 

#define NO_CHECK 0
#define NO_SHOW "\0"

typedef struct
{
    uint8_t day;
    uint8_t month;
    uint8_t year;
}Type_Date;

typedef struct 
{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
}Type_Time;

typedef enum
{
    IN ,
    ON 
}Type_Status;

typedef struct
{
    Type_Date date;
    Type_Time time;
    Type_Status status;
}booking_History;

class Customer
{
    private:
    vector <booking_History> History_Detail;
    int16_t ID_ROOM;
    string NAME;
    int16_t AGE;
    string ADDRESS;
    public:
    Customer(string name, int16_t age, string address);
    void setName(string name);
    string getName();
    void setAge(uint8_t age);
    int16_t getAge();
    void setAddress(string address);
    string getAddress();
    int16_t get_Id_Room();
    void add_Hitory_Detail(booking_History history_Detail);
    vector<booking_History> get_Hitory_Detail();
};

Customer::Customer(string name, int16_t age, string address)
{
    static int16_t id_Room = 1;
    this->NAME = name;
    this->AGE = age;
    this->ADDRESS = address;
    this->ID_ROOM = id_Room;
    id_Room++;
}

void Customer::setName(string name)
{
    this->NAME = name;
}

string Customer::getName()
{
    return this->NAME;
}
void Customer::setAge(uint8_t age)
{
    this->AGE = age;
}
    
int16_t Customer::getAge()
{
    return this->AGE;
}

void Customer::setAddress(string address)
{
    this->ADDRESS = address;
}

string Customer::getAddress()
{
    return this->ADDRESS;
}

int16_t Customer::get_Id_Room()
{
    return this->ID_ROOM;
}


void Customer::add_Hitory_Detail(booking_History history_Detail)
{
    this->History_Detail.push_back(history_Detail);
}

vector<booking_History> Customer::get_Hitory_Detail()
{
    return this->History_Detail;
}

class CustomManger
{
    private:
    vector<Customer> Customer_List;
    void show_Custom_Info(Customer customer);
    void show_booking_history(vector <booking_History> detai_History);
    public:
    CustomManger();
    void addCutomer();
    void editCustomer();
    void deleteCustomer();
    void displayCustomerInfo();
    void checkEntry();
};

CustomManger::CustomManger()
{
    int16_t key;
    int16_t number_Room;
    while(1)
    {
        do
        {
            cout <<"\n**************menu**************" << endl;
            cout <<"1. them khach hang" << endl;
            cout <<"2. hien thi danh sach" << endl;
            cout <<"3. xoa khach hang" << endl;
            cout <<"4. check loi vao" << endl;
            cout <<"0. thoat" << endl;
            cout <<"vui long nhap chuc nang" << endl;
            cin >> key;
        }
        while(key < 0 && key >4);
        if(key == 0) break;
        switch(key)
        {
            case 1:
            {
               this->addCutomer();
                break;
            }
            case 2:
            {
                this->displayCustomerInfo();
                break;
            }
            case 3:
            {
                this->deleteCustomer();
                break;
            }
            case 4:
            {
                this->checkEntry();
                break;
            }
            
        }
    }
}

void CustomManger::addCutomer()
{
    string name;
    int16_t age; 
    string address;
    cout <<"them thong tin khach hang" << endl;
    INPUT_TYPE("nhap ten: ",name,NO_CHECK, NO_SHOW);
    INPUT_TYPE("nhap tuoi: ",age, age < 0, "loi tuoi");
    INPUT_TYPE("nhap dia chi: ", address, NO_CHECK, NO_SHOW);
    Customer customer(name, age, address);
    Customer_List.push_back(customer);
}

void CustomManger::show_Custom_Info(Customer customer)
{
    cout<<customer.get_Id_Room()<< "\t" << customer.getName()<<"\t"<< customer .getAge()<<"\t" << customer.getAddress()<< endl;
}

void CustomManger::displayCustomerInfo()
{
    cout<<"ID \t NAME \t AGE \t ADDRESS" << endl;
    for(Customer customer: Customer_List)
    {
        show_Custom_Info(customer);
    }
}

void CustomManger::checkEntry()
{
    uint8_t status = 0;
    booking_History history;
    int16_t id_Room;
    time_t current;
    time(&current);
    tm *timeCurrent = localtime(&current);
    history.time.second = timeCurrent->tm_sec;
    history.time.minute = timeCurrent->tm_min;
    history.time.hour = timeCurrent->tm_hour;
    history.date.day = timeCurrent->tm_mday;
    history.date.month = timeCurrent->tm_mon;
    history.date.year = timeCurrent->tm_year +1900;
    INPUT_TYPE("nhap so phong: ",id_Room, NO_CHECK, NO_SHOW);
    for(int i=0; i < Customer_List.size(); i++ )
    {
        if(Customer_List[i].get_Id_Room() == id_Room )
        {
            if(Customer_List[i].get_Hitory_Detail().empty()) history.status = IN;
            else
            {
                if(Customer_List[i].get_Hitory_Detail().back().status == IN) history.status = IN;
                else history.status = ON;
            }

            Customer_List[i].add_Hitory_Detail(history);
            status =1;
            break;
        }
    }
    if (status == 0) cout << "khong tim so phong" << endl;
}

void CustomManger::deleteCustomer()
{
    uint8_t status = 0;
    int16_t key;
    int16_t id_Room;
    INPUT_TYPE("nhap so phong: ",id_Room, NO_CHECK, NO_SHOW);
    for(int i =0 ; i < Customer_List.size(); i++)
    {
        if(Customer_List[i].get_Id_Room() == id_Room)
        {
            this->show_Custom_Info(Customer_List[i]);
            this->show_booking_history(Customer_List[i].get_Hitory_Detail());    
            cout << "1. xoa" << endl;
            cout << "0. thoat" << endl;
            cout << "vui long nhan phim: ";
            cin >> key;
            if(key == 1) this->Customer_List.erase(Customer_List.begin()+ i); 
            status =1;
            break;   
        }
    }
    if(status == 0) cout<< "khong tim thay id phong" << endl;
}

void CustomManger::show_booking_history(vector <booking_History> detai_History)
{
    string s_Status;
    cout << "lich su ra vao"<< endl;
    for(booking_History history: detai_History)
    {
        if(history.status == IN) s_Status = "IN";
        else s_Status = "ON";
        //cout << s_Status << history.time.hour<<":"<<history.time.minute<<":"<<history.time.second<<"\t "<<history.date.day<<"/" <<history.date.month <<"/" <<history.date.year<< endl;
        printf("%s\t %d :%d: %d \t %d/%d/%d\n",s_Status.c_str(), history.time.hour, history.time.minute, history.time.second, history.date.day, history.date.month, history.date.year);
    }
}
int main()
{
    CustomManger cs;
   
}