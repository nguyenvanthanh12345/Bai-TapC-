#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;



#define INPUT_TYPE(text, var, check)      \
        do                                                  \
        {                                                    \
            cout << text;\
            cin>>var;            \
            if(check) cout << "please enter again \n"; \
        }                                                    \
        while(check) 

#define NO_CHECK 0

#define INPUT(text, var, check, showError)      \
        do                                                  \
        {                                                    \
            cout << text;\
            cin>>var;            \
            if(check) cout<< showError; \
        }                                                    \
        while(check) 

class Beverage
{
    private:
    uint16_t ID;
    string BEVERAGE_NAME;
    int32_t PRICE;

    public:
    Beverage(string bverage, uint16_t price);
    Beverage();
    uint16_t getId();
    void setBeverageName(string beverageName);
    string getBeverageName ();
    void setprice(int32_t price);
    int32_t getPrice();
};

Beverage::Beverage(string beverage, uint16_t price)
{
    static uint16_t id=0;
    this->ID = id;
    this->BEVERAGE_NAME = beverage;
    this->PRICE = price;
    id++;
}

Beverage::Beverage ()
{

}

uint16_t Beverage::getId()
{
    return this->ID;
}

void Beverage::setBeverageName(string beverage)
{
    this->BEVERAGE_NAME = beverage;
}

string Beverage::getBeverageName()
{
    return this->BEVERAGE_NAME;
}

void Beverage::setprice(int32_t price)
{
    this->PRICE = price;
}

int32_t Beverage::getPrice()
{
    return this->PRICE;
}

class manager
{
    private:
    vector <Beverage> DatabaseBeverage;
    void showBeverageAt(Beverage beverage);
    public:
    void addBeverage();
    void repairBeverage();
    void eraseBeverage();
    void beverageList();
};

void manager::addBeverage()
{
    string beverageName;
    int32_t price;
    cout << "please enter beverage information \n";
    INPUT_TYPE("entering beverage: ", beverageName, NO_CHECK);
    INPUT_TYPE("entering price: ", price, price <= 0);
    Beverage beverage(beverageName, price);
    DatabaseBeverage.push_back(beverage);
}

void manager::showBeverageAt(Beverage beverage)
{
    cout << beverage.getId() << "\t" << beverage.getBeverageName() << "\t" <<beverage.getPrice()<< "\n";
}

void manager::repairBeverage()
{
    uint8_t phim=0;
    uint16_t id;
    uint8_t status = 0;
    string beverageName;
    int32_t price;
    cout << "repairing beverage information\n";
    cout <<"please enter id\n";
    cin >> id;
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
        cout <<"3. exit\n";
        switch(phim)
        {
            case 1:
            {
                INPUT_TYPE("entering beverage name: ", beverageName, NO_CHECK);
                this->DatabaseBeverage[i].setBeverageName(beverageName);
                break;
            }
            case 2:
            {
                INPUT_TYPE("entering price :", price, price <=0);
                this->DatabaseBeverage[i].setprice(price);
                break;
            }
        }
    }
    while(phim != 0);
}

void manager::eraseBeverage()
{
    uint16_t id;
    cout<< "*****erase beverage********\n";
    INPUT_TYPE("entering id: ", id, NO_CHECK);
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

void manager::beverageList()
{
    cout<<"id \t beverage name \t price\n";
    for(Beverage beverage : DatabaseBeverage)
    {
        this->showBeverageAt(beverage);
    }
}

typedef enum
{
    EMPTY,
    FULL
}TableStatus;
class Table
{
    private:
    uint16_t NUMBER_TABLE;
    TableStatus TABLE_STATUS;
    int16_t QUANTITY;
    int32_t PAY;
    public:
    Table();
    vector <Beverage> DatabaseBeverage;
    uint16_t getNumberTable();
    void setTableStatus(TableStatus status);
    TableStatus getTableStatus();
    void setBeverage(Beverage beverage);
    Beverage getBeverage();
    void setQuantity(int16_t quantity);
    int16_t getQuantity();
    void setPay(int32_t pay);
    int32_t getPay();
};

Table::Table()
{
    this->NUMBER_TABLE = EMPTY;
}

uint16_t Table::getNumberTable()
{
    return this->NUMBER_TABLE;
}

void Table::setTableStatus(TableStatus status)
{
    this->TABLE_STATUS = status;
}

TableStatus Table::getTableStatus()
{
    return this->TABLE_STATUS;
}

void Table::setQuantity(int16_t quantity)
{
    this->QUANTITY= quantity;
}

int16_t Table::getQuantity()
{
    return this->QUANTITY;
}

void Table::setPay(int32_t pay)
{
    this->PAY = pay;
}

int32_t Table::getPay()
{
    return this->PAY;
}

class Staff
{
    private:
    vector < Table> DatabaseTable;
    public:
    Staff();
    void orderTable();
    void Payment();
};

Staff::Staff()
{
    Table table;
    this->DatabaseTable.assign(10,table);
}

void Staff::orderTable()
{
    manager mn;
    int16_t id;
    int16_t numberTable;
    cout << "*******order table***********\n";
    cout<< "plese enter number table: \n";
    cin >> numberTable;
    for(int i=0 ; i<DatabaseTable.size(); i++)
    {
        if(DatabaseTable[i].getTableStatus() == EMPTY)
        {
            INPUT("entering id:\n",id, id < 0, "error id drink\n");
        }
    }
    
}
//void Staff::Payment()

int main()
{
    vector<int> a;
    a.assign(20,5);
    vector<int> m;
    m=a;
    m[3]=6;
    printf("%d",a[3]);

}