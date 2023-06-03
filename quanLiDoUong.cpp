/*
* File: Quan li do uong.cpp
* Author: Nguyen Van Thanh
* Date: 31/05/2023
* Description:manager drink
*/

#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

//this macro use to enter, check the input data and show error information
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

//this macro use to enter th data
#define INPUT_SEARCH_TYPE(text, var)      \
            cout << text;                \
            cin>>var;

#define NO_CHECK 0      // no check the input data
#define NO_SHOW "\0"    // no show information

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
* Description: This function used to set the beverage name
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
* Description: This function used to get the beverage name
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
* Description: This function used to set the price
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
* Description: This function used to get the price
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
    int16_t QUANTITY;
    void showBeverageAt(Beverage beverage);
    void addBeverage();
    void repairBeverage();
    void eraseBeverage();
    void beverageList();
    void setQuantity();
    public:
    Manager();
    vector<Beverage> get_Database_Beverage();
    int16_t getQuantity();
    void manager();
};

Manager::Manager()
{
    this->QUANTITY = 0;
}

void Manager::manager()
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
            cout <<"5. nhap so ban\n";
            cout <<"0. thoat\n";
            cout <<"vui long nhap phim\n";
            cin >> key;
        }
        while( key <0 || key > 5);
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
            case 4:
            {
                this->eraseBeverage();
                break;
            }
            case 5:
            {
                this->setQuantity();
                break;
            }
        }
    }
    while(key != 0);
}

/*
* Class: Manager
* Function: addBeverage()
* Description: This function used to add the beverage informations
* Input:
*   None
* Output:
*   return: None
*/

void Manager::addBeverage()
{
    string beverageName;
    int32_t price;
    cout << "******them thuc uong******* \n";
    INPUT_TYPE("nhap ten thuc uong: ", beverageName, NO_CHECK,NO_SHOW);
    INPUT_TYPE("nhap gia: ", price, price <= 0, "loi gia\n");
    Beverage beverage(beverageName, price);
    DatabaseBeverage.push_back(beverage);
}

/*
* Class: Manager
* Function: showBeverageAt()
* Description: This function used to show the beverage information in the beverage list
* Input:
*   beverage - a beverage value
* Output:
*   return: None
*/

void Manager::showBeverageAt(Beverage beverage)
{
    cout << beverage.getId() << "\t" << beverage.getBeverageName() << "\t" <<beverage.getPrice()<< "\n";
}

/*
* Class: Manager
* Function: repairBeverage()
* Description: This function used to fix the beverage information in the beverage list
* Input:
*    None
* Output:
*   return: None
*/

void Manager::repairBeverage()
{
    int16_t key=0;
    int16_t id;
    uint8_t status = 0;
    string beverageName;
    int32_t price;
    cout << "*********sua thong tin do uong*******\n";
    INPUT_SEARCH_TYPE("nhap id do uong muon thay doi: ",id);
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
        cout << "khong tim thay id \n";
        return;
    }
    do
    {
        cout<< "vui long chon chuc nang\n";
        cout <<"1. thay doi ten do uong\n";
        cout <<"2. thay doi gia \n";
        cout <<"0. thoat\n";
        cin >> key;
        switch(key)
        {
            case 1:
            {
                INPUT_TYPE("nhap ten do uong : ", beverageName, NO_CHECK, "loi ten do uong\n");
                this->DatabaseBeverage[i].setBeverageName(beverageName);
                break;
            }
            case 2:
            {
                INPUT_TYPE("nhap gia :", price, price <=0, "loi gia\n");
                this->DatabaseBeverage[i].setprice(price);
                break;
            }
        }
    }
    while(key != 0);
}

/*
* Class: Manager
* Function: eraseBeverage()
* Description: This function used to erase the beverage information in the beverage list
* Input:
*    None
* Output:
*   return: None
*/

void Manager::eraseBeverage()
{
    int16_t id;
    cout<< "*****xoa thuc uong********\n";
    INPUT_TYPE("nhap id: ", id, NO_CHECK,NO_SHOW);
    for(int i=0 ; i< DatabaseBeverage.size(); i++)
    {
        if(DatabaseBeverage[i].getId() == id)
        {
            this->showBeverageAt(DatabaseBeverage[i]);
            cout<<" da xoa\n";
            DatabaseBeverage.erase(DatabaseBeverage.begin()+1);
            return;
        }
    }
    cout << "khong tim thay id\n";
}

/*
* Class: Manager
* Function: beverageList()
* Description: This function used to show the beverage list
* Input:
*    None
* Output:
*   return: None
*/

void Manager::beverageList()
{
    cout<<"id \t ten \t gia\n";
    for(Beverage beverage : DatabaseBeverage)
    {
        this->showBeverageAt(beverage);
    }
}

/*
* Class: Manager
* Function: get_Database_Beverage()
* Description: This function used to get the beverage list
* Input:
*    None
* Output:
*   return: the beverage list
*/

vector<Beverage> Manager::get_Database_Beverage()
{
    return this->DatabaseBeverage;
}

/*
* Class: Manager
* Function: getQuantity()
* Description: This function used to get the table quantity
* Input:
*    None
* Output:
*   return: the table quantity
*/

int16_t Manager::getQuantity()
{
    return this->QUANTITY;
}

/*
* Class: Manager
* Function: setQuantity()
* Description: This function used to set the table quantity
* Input:
*    None
* Output:
*   return: None
*/

void Manager::setQuantity()
{
    int16_t quantity;
    cout<<"nhap so luong ban: ";
    cin >> quantity;
    this->QUANTITY = quantity;
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

// class staff
class Staff
{
    private:
    vector <Table> Database_Table;
    vector <Beverage> Database_Beverage;
    void order_Beverage (int16_t number_Table);
    void erase_Beverage(int16_t nuber_Table);
    void list_Beverage();
    void show_Status_Table();

    void order_New_table(int16_t number_Table);
    void fix_Order_Beverage(int16_t number_Table);
    void Pay_Beverage(int16_t number_Table);
    void list_order(int16_t number_Table);

    public:
    Staff();
    
    void staff(vector <Beverage> database_beverage, int16_t table_Quantity);
    
};

Staff::Staff()
{
    
}

void Staff::staff(vector <Beverage> database_beverage, int16_t table_Quantity)
{
    Database_Beverage.clear();
    for(Beverage drink : database_beverage)
    {
        this->Database_Beverage.push_back(drink);
    }

    for(uint8_t i=1 ; i <= table_Quantity; i++)
    {
        Table table;
        table.number_Table = i;
        table.table_Status = EMPTY;
        Database_Table.push_back(table);
    }
    int16_t key;
    while(1)
    {
        int16_t number_Table;
        show_Status_Table();
        cout << "\n0. Thoat" << endl;
        INPUT_SEARCH_TYPE("Vui long chon ban: ", number_Table);
        if(number_Table == 0)break;
        do
        {
            do
            {
                cout<<"\n";
                cout <<"1. Dat ban"<< endl;
                cout <<"2. danh sach goi mon"<<endl;
                cout <<"3. sua mon" << endl;
                cout <<"4. thanh toan" << endl;
                cout <<"0. thoat"<< endl;
                cout <<"vui long chon chuc nang: " <<endl;
                cin >> key;
            }
            while(key <0 || key >4 );
            switch (key)
            {
                case 1:
                {
                    this->order_New_table(number_Table);
                    break;
                }
                case 2:
                {
                    this->list_order(number_Table);
                    break;
                }
                case 3:
                {
                    this->fix_Order_Beverage(number_Table);
                    break;
                }
                case 4:
                {
                    this->Pay_Beverage(number_Table);
                    break;
                }
            }
        }
        while(key != 0);
    }
}

void Staff::order_New_table(int16_t number_Table)
{
    int16_t key;
    cout<<"\n ********order beverage**************\n";
    
    if(number_Table > 0 && number_Table <= Database_Table.size())
    {
        if(Database_Table[number_Table-1].table_Status == EMPTY)
        {
            Database_Table[number_Table-1].table_Status = FULL;
            while(1)
            {
                this->order_Beverage(number_Table);
                INPUT_SEARCH_TYPE("1. Tiep tuc\n0. Thoat\n",key);
                if(key == 0) break;
            }
        }
        else 
        {
            cout << "ban da co nguoi ngoi" <<endl;
            return;
        }
    }
    else cout <<"khong tim thay so ban\n";
}

void Staff::order_Beverage (int16_t number_Table)
{
    int16_t quantity;
    Order_Beverage order_Beverage;
    uint8_t status_Id = 0;
    int16_t id_Beverage;
    this->list_Beverage();
    INPUT_SEARCH_TYPE("nhap id do uong: ",id_Beverage);
    for(Beverage drink : Database_Beverage)
        {
            if(drink.getId() == id_Beverage)
            {
                status_Id = 1;
                INPUT_TYPE("nhap so luong: ",quantity, quantity < 1, "loi so luong\n");
                order_Beverage.quantity = quantity;
                order_Beverage.beverage = drink;
                Database_Table[number_Table-1].DataBase_Order_Beverage.push_back(order_Beverage);
                break;
            }
        }
        if(status_Id == 0) cout << " khong tim thay id do uong \n";
}

void Staff::erase_Beverage(int16_t number_Table)
{
    int16_t id;
    uint8_t status = 0;
    cout << "\n******xoa nuoc ngot trong danh sach nuoc ngot da order*******" << endl;
    this->list_order(number_Table);
    INPUT_SEARCH_TYPE("nhap id mon can xoa: ",id);
    for(int i = 0; i<Database_Table[number_Table-1].DataBase_Order_Beverage.size(); i++)
    {
        if(Database_Table[number_Table-1].DataBase_Order_Beverage[i].beverage.getId() == id)
        {
            status = 1;
            Database_Table[number_Table-1].DataBase_Order_Beverage.erase(Database_Table[number_Table-1].DataBase_Order_Beverage.begin()+i);
            break;
        }

    }
    if(status == 0)
    {
        cout << "khong tim thay id trong danh sach order" << endl;
        return;
    }

}

void Staff::list_Beverage()
{
    cout << "ID\tTEN\tgia"<<endl;
    for(Beverage beverage:Database_Beverage)
    {
        cout << beverage.getId()<<"\t" <<beverage.getBeverageName() <<"\t"<<"\t"<< beverage.getPrice()<< endl;
    }
}

void Staff::list_order(int16_t number_Table)
{
    uint8_t status = 0;
    cout<<"\n*********danh sach order nuoc ngot***********" << endl;
    if(number_Table > 0 && number_Table <= Database_Table.size())
    {
        if(Database_Table[number_Table -1].table_Status == EMPTY)
        {
            cout << "ban trong\n";
        }
        else
        {
            cout <<"id \t ten \t\t gia \t so luong\n";
            for(Order_Beverage order : Database_Table[number_Table -1].DataBase_Order_Beverage)
            {
                cout << order.beverage.getId()<< "\t" <<order.beverage.getBeverageName()<< "\t" << order.beverage.getPrice()<<"\t" << order.quantity << endl;
            }
        }
    }
    else cout << "khong tim thay ban" << endl;
}

void Staff::Pay_Beverage(int16_t number_Table)
{
    int total;
    
    if(number_Table > 0 && number_Table <= Database_Table.size())
    {
        if(Database_Table[number_Table -1].table_Status == FULL)
        {
            for(Order_Beverage order : Database_Table[number_Table -1].DataBase_Order_Beverage)
            {
                total += order.beverage.getPrice()*order.quantity; 
            }
            cout << "ban "<< number_Table <<" :" <<total <<endl;
            Database_Table[number_Table -1].DataBase_Order_Beverage.clear();
            Database_Table[number_Table -1].table_Status = EMPTY;
        }
        else cout << "ban trong" <<endl;
    }
    else cout<<"khong tim thay ban" <<endl;
    
}


void Staff::fix_Order_Beverage(int16_t number_Table)
{
    int16_t key;
    cout<<"\n*********sua order nuoc ngot***********" << endl;
    if(number_Table > 0 && number_Table <= Database_Table.size())
    {
        if(Database_Table[number_Table-1].table_Status == FULL)
        {
            do
            {
                do
                {
                    INPUT_SEARCH_TYPE("1. Xoa do uong\n2. Them do uong\n0. Thoat\n Vui long chon chuc nang: ",key);
                }
                while(key<0 || key > 2 );

                switch (key)
                {
                    case 1:
                    {
                        this->erase_Beverage(number_Table);
                        break;
                    }
                    case 2:
                    {
                        this->order_Beverage(number_Table);
                        break;
                    }
                }
            }
            while(key !=0 );
        }
        else cout <<"ban trong"<<endl;
    }
    cout << "khong tim thay ban"<<endl;
}

void Staff::show_Status_Table()
{
    for(Table table : Database_Table)
        {
            cout <<"|Ban " <<table.number_Table <<":";
            if(table.table_Status == FULL) cout<<" o ";
            else cout << " x ";
        }
        cout <<"|" << endl;
}

class Menu
{
    private:
    Manager mn;
    Staff st;
    public:
    Menu();
};

Menu::Menu()
{
    int16_t key;
    while(1) 
    {
        cout << "\n**********menu**************" << endl;
        INPUT_SEARCH_TYPE("1. quan li\n2. nhan vien\n0. thoat\nvui long chon phim\n",key);
        if (key == 0) break;
        switch (key)
        {
            case 1:
            {
                mn.manager();
                break;
            }
            case 2:
            {
                st.staff(mn.get_Database_Beverage(),mn.getQuantity());
                break;
            }
        }
    }
}

int main()
{
//    Beverage douong1("c2",1000), douong2("c3",574);
//    vector <Beverage> douong;
//    douong.push_back(douong1);
//    douong.push_back(douong2);
//    Staff staff;
//    staff.staff(douong,10);
    Menu menu;
}