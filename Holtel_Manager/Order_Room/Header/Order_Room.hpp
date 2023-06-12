#ifndef __ORDER_ROOM_HPP
#define __ORDER_ROOM_HPP

#include<stdio.h>
#include<string>
#include<stdint.h>
#include<iostream>
#include<vector>
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

class Room
{
    private:
    int16_t NUMBER_ROOM;
    bool IS_BOOKED;
    bool IS_CLEAN;
    public:
    Room(int16_t number_Room);
    bool get_Is_booked();
    bool get_Is_clean();
    bool isAvailable();
    void book_Room();
    void check_In();
    void check_Out();
    int16_t getNumber_Room();
};

class ManageRoom
{
    private:
    vector<Room> Database_Room;
    void show_Status_Room();
    void show_Available_Room();
    void book_Room(int16_t number_Room);
    void check_In(int16_t number_Room);
    void check_Out(int16_t number_Room);
    void add_Room();
    public:
    ManageRoom();

};
#endif