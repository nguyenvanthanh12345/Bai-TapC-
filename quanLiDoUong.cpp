/*
* File: quan li sinh vien.cpp
* Author: Nguyen Van Thanh
* Date: 31/05/2023
* Description:manager drink
*/

#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

//this macro use to enter, check the input data and show erroe information
#define INPUT_TYPE(text, var, check, show_Erorr)      \
        do                                                  \
        {                                                    \
            cout << text;\
            cin>>var;            \
            if(check)  \
            {                                             \
                cout << show_Erorr;                    \
                cout << "please enter again \n";  \
            }                                             \
        }                                                    \
        while(check) 

#define INPUT_SEARCH_TYPE(text, var)      \
            cout << text;                \
            cin>>var;
// no check the input data
#define NO_CHECK 0
#define NO_SHOW "\0"

// class Beverage
class Beverage
{
    private:
    int16_t ID;
    string BEVERAGE_NAME;
    int32_t PRICE;

    public:
    Beverage(string bverage, int16_t price);
    Beverage();
    int16_t getId();
    void setBeverageName(const string beverageName);
    string getBeverageName ();
    void setprice(const int32_t price);
    int32_t getPrice();
};

Beverage::Beverage(string beverage, int16_t price)
{
    static int16_t id=1;
    this->ID = id;
    this->BEVERAGE_NAME = beverage;
    this->PRICE = price;
    id++;
}

Beverage::Beverage ()
{
}

int16_t Beverage::getId()
{
    return this->ID;
}

/*
* Class: beverage
* Function: setBeverageName
* Description: This function use to set the beverage name
* Input:
*   beverage - an string value
* Output:
*   return: None
*/

void Beverage::setBeverageName(const string beverage)
{
    this->BEVERAGE_NAME = beverage;
}

/*
* Class: beverage
* Function: getBeverageName
* Description: This function use to get the beverage name
* Input:
*   None
* Output:
*   return: the beverage name
*/

string Beverage::getBeverageName()
{
    return this->BEVERAGE_NAME;
}

/*
* Class: beverage
* Function: setprice
* Description: This function use to set the price
* Input:
*   price - an integer-32 bit value
* Output:
*   return: None
*/

void Beverage::setprice(const int32_t price)
{
    this->PRICE = price;
}

/*
* Class: beverage
* Function: setprice
* Description: This function use to get the price
* Input:
*   None
* Output:
*   return: the beverage price
*/

int32_t Beverage::getPrice()
{
    return this->PRICE;
}

class Manager
{
    private:
    vector <Beverage> DatabaseBeverage;
    void showBeverageAt(Beverage beverage);
    void addBeverage();
    void repairBeverage();
    void eraseBeverage();
    void beverageList();
    public:
    Manager();
    vector<Beverage> get_Database_Beverage();
};

Manager::Manager()
{
    int16_t key;
    cout << "**********manager*********\n";
    do
    {
        do
        {
            cout <<"1. them do uong\n";
            cout <<"2. danh sach do uong\n";
            cout <<"3. sua do uong\n";
            cout <<"4. xoa do uong\n";
            cout <<"0. thoat\n";
            cout <<"vui long nhap phim\n";
            cin >> key;
        }
        while( key <0 || key > 4);
        switch(key)
        {
            case 1:
            {
                this->addBeverage();
                break;
            }
            case 2:
            {
                this->beverageList();
                break;
            }
            case 3:
            {
                this->repairBeverage();
                break;
            }
            case4:
            {
                this->eraseBeverage();
                break;
            }
        }
    }
    while(key != 0);
}

void Manager::addBeverage()
{
    string beverageName;
    int32_t price;
    cout << "******add beverage information******* \n";
    INPUT_TYPE("entering beverage: ", beverageName, NO_CHECK,NO_SHOW);
    INPUT_TYPE("entering price: ", price, price <= 0, "error price\n");
    Beverage beverage(beverageName, price);
    DatabaseBeverage.push_back(beverage);
}

void Manager::showBeverageAt(Beverage beverage)
{
    cout << beverage.getId() << "\t" << beverage.getBeverageName() << "\t" <<beverage.getPrice()<< "\n";
}

void Manager::repairBeverage()
{
    int16_t key=0;
    int16_t id;
    uint8_t status = 0;
    string beverageName;
    int32_t price;
    cout << "*********fix beverage information*******\n";
    INPUT_SEARCH_TYPE("entering id to change beverage information: ",id);
    int i=0;
    for(i=0; i< DatabaseBeverage.size(); i++)
    {
        if(id == this->DatabaseBeverage[i].getId())
        {
            status = 1;
            this->showBeverageAt(DatabaseBeverage[i]);
            break;
        }
    }
    if(status == 0) 
    {
        cout << "the id didn't found \n";
        return;
    }
    do
    {
        cout<< "please chose function\n";
        cout <<"1. exchanging beverage name\n";
        cout <<"2. exchanging price \n";
        cout <<"0. exit\n";
        cin >> key;
        switch(key)
        {
            case 1:
            {
                INPUT_TYPE("entering beverage name: ", beverageName, NO_CHECK, "erorr beverage\n");
                this->DatabaseBeverage[i].setBeverageName(beverageName);
                break;
            }
            case 2:
            {
                INPUT_TYPE("entering price :", price, price <=0, "erorr beverage\n");
                this->DatabaseBeverage[i].setprice(price);
                break;
            }
        }
    }
    while(key != 0);
}

void Manager::eraseBeverage()
{
    int16_t id;
    cout<< "*****erase beverage********\n";
    INPUT_TYPE("entering id: ", id, NO_CHECK,NO_SHOW);
    for(int i=0 ; i< DatabaseBeverage.size(); i++)
    {
        if(DatabaseBeverage[i].getId() == id)
        {
            this->showBeverageAt(DatabaseBeverage[i]);
            cout<<" already erase\n";
            DatabaseBeverage.erase(DatabaseBeverage.begin()+1);
            return;
        }
    }
    cout << "the id didn't found\n";
}

void Manager::beverageList()
{
    cout<<"id \t beverage name \t price\n";
    for(Beverage beverage : DatabaseBeverage)
    {
        this->showBeverageAt(beverage);
    }
}

vector<Beverage> Manager::get_Database_Beverage()
{
    return DatabaseBeverage;
}

typedef enum
{
    EMPTY,
    FULL
}TableStatus;

typedef struct
{
    Beverage beverage;
    int16_t quantity;
}Order_Beverage;

typedef struct
{
    int16_t number_Table;
    TableStatus table_Status;
    vector <Order_Beverage> DataBase_Order_Beverage;
}Table;

class Staff
{
    private:
    vector <Table> Database_Table;
    vector <Beverage> Database_Beverage;
    void order_Beverage ();
    void fix_Order_beverage();
    void erase_Beverage();
    void Pay_Beverage();
    void list_order();
    void list_Beverage();
    public:
    Staff( vector <Beverage> database_beverage, int16_t table_Quantity);
    
};

Staff::Staff( vector <Beverage> database_beverage, int16_t table_Quantity)
{
    this->Database_Beverage = database_beverage;
    for(uint8_t i=1 ; i <= table_Quantity; i++)
    {
        Table table;
        table.number_Table = i;
        table.table_Status = EMPTY;
        Database_Table.push_back(table);
    }
}

void Staff::order_Beverage ()
{
    uint8_t status_Table =0;
    int16_t number_Table;
    int16_t id;
    Table table;
    int i=0;
    cout<<" ********order beverage**************\n";
    INPUT_SEARCH_TYPE("entering number table:", number_Table);
    for(Table table : Database_Table)
    {
        if(table.number_Table == number_Table)
        {
            if(table.table_Status == EMPTY)
            {
                status_Table = 1;
                table.table_Status = FULL;
                break;
            }
            else 
            {
                cout << "ban da co nguoi ngoi";
                return;
            }
        }
        i++;
    }
    
    if(status_Table ==1 )
    {
        uint8_t key;
        do
        {
            uint8_t key;
            uint8_t status_Id = 0;
            int16_t quantity;
            Order_Beverage order_Beverage;
            INPUT_SEARCH_TYPE("entering beverage id: ", id);
            for(Beverage drink : Database_Beverage)
            {
                if(drink.getId() == id)
                {
                    status_Id == 1;
                    INPUT_TYPE("entering quantity: ",quantity, quantity < 1, "erorr quantity\n");
                    order_Beverage.quantity = quantity;
                    order_Beverage.beverage = drink;
                    Database_Table[i].DataBase_Order_Beverage.push_back(order_Beverage);
                    break;
                }
            }
            if(status_Id == 0) cout << " khong tim thay id do uong \n";

            cout << "1. tiep tuc order do uong\n";
            cout << "0. thoat\n";
            cout << "vui long nhap phim :";
            cin >> key;
        }
        while(key == 1);
    }
    else cout <<"khong tim thay so ban\n";
}

void Staff::fix_Order_beverage()
{
}

void Staff::list_order()
{
    int16_t number_table;
    uint8_t status = 0;
    INPUT_SEARCH_TYPE("nhap so ban: ",number_table);
    for(Table table : Database_Table)
    {
        if(table.number_Table == number_table)
        {
            status = 1;
            if(table.table_Status == EMPTY)
            {
                cout << "ban trong";
            }
            else
            {
                cout <<"id \t ten \t gia \t so luong\n";
                for(Order_Beverage order : table.DataBase_Order_Beverage)
                {
                    cout << order.beverage.getId()<< "\t" <<order.beverage.getBeverageName()<< "\t" << order.beverage.getPrice()<<"\t" << order.quantity ;
                }
            }
            break;
            
        }
    }
    if(status == 0) cout << "khong tim thay ban";
}
int main()
{
//    Beverage douong1("c2",1000), douong2("c3",574);
//    vector <Beverage> douong;
//    douong.push_back(douong1);
//    douong.push_back(douong2);
//    Staff staff(douong,10);
//    staff.order_Beverage();
//    staff.list_order();

}