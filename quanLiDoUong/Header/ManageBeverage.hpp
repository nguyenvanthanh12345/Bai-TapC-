/*
* File: Manage beverage.hpp
* Author: Nguyen Van Thanh
* Date: 31/05/2023
* Description:This file is a header file that contains all the prototypes to manage the beverage
*/

#ifndef __MANAGE_BEVERAGE_HPP
#define __MANAGE_BEVERAGE_HPP

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

// class manager
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

// the table status is empty or full
typedef enum
{
    EMPTY,
    FULL
}TableStatus;

// the order beverage structure definition
typedef struct
{
    Beverage beverage;
    int16_t quantity;
}Order_Beverage;

// the table structure definition
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

// class menu
class Menu
{
    private:
    Manager mn;
    Staff st;
    public:
    Menu();
};

#endif