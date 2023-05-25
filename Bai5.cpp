/*
* File: bai5.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description: in thông tin của người đó và tính tuổi của người đó
*/

#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<time.h>
#include<string>
using namespace std;

// class People
class People
{
    private:
    uint8_t DAY;
    uint8_t MONTH;
    uint16_t YEAR;
    string NAME;
    string ADDRESS;
    public:
    People(string name,string address,uint8_t day, uint8_t month, uint16_t year);
    uint8_t getDay();
    uint8_t getMonth();
    uint16_t getYear();
    void setName(string name);
    string getName();
    void setAddress(string address);
    string getAddress();
    void printPeople();
    uint8_t calculateAge();
};

People::People(string name,string address,uint8_t day, uint8_t month, uint16_t year)
{
    this->DAY = day;
    this->MONTH = month;
    this->YEAR = year;
    this->NAME = name;
    this->ADDRESS = address;
}

/*
* Class: People
* Function: getDay()
* Description: lay ngay
* Input:
*   khong co
* Output:
*   return: ngay
*/

uint8_t People::getDay()
{
    return this->DAY;
}

/*
* Class: People
* Function: getMonth()
* Description: lay thang
* Input:
*   khong co
* Output:
*   return: thang
*/

uint8_t People::getMonth()
{
    return this->MONTH;
}

/*
* Class: People
* Function: getYear()
* Description: lay nam
* Input:
*   khong co
* Output:
*   return: nam
*/

uint16_t People::getYear()
{
    return this->YEAR;
}

/*
* Class: People
* Function: setName
* Description: thay doi ten
* Input:
*   string name
* Output:
*   return: khong co
*/

void People::setName(string name)
{
    this->NAME = name;
}

/*
* Class: People
* Function: getName()
* Description: lay ten
* Input:
*   khong co
* Output:
*   return: ten
*/

string People::getName()
{
    return this->NAME;
}

/*
* Class: People
* Function: setAddress
* Description: thay doi dia chi
* Input:
*   string address
* Output:
*   return: khong co
*/

void People::setAddress(string address)
{
    this->ADDRESS = address;
}

/*
* Class: People
* Function: getAddress()
* Description: lay dia chi
* Input:
*   khong co
* Output:
*   return: dia chi
*/

string People::getAddress()
{
    return this->ADDRESS;
}

/*
* Class: People
* Function: printPeople()
* Description: in thong tin
* Input:
*   khong co
* Output:
*   return: khong co
*/

void People::printPeople()
{
    printf("ten : %s\n",this->NAME.c_str());
    printf("tuoi : %d\n",this->calculateAge());
    printf("dia chi : %s\n",this->ADDRESS.c_str());
}

/*
* Class: People
* Function: calculateAge()
* Description: tinh tuoi
* Input:
*   khong co
* Output:
*   return: tuoi
*/

uint8_t People::calculateAge()
{
    time_t current;
    time(&current);
    tm *timeCurrent = localtime(&current);
    //printf("%d\n",timeCurrent->tm_year +1900);
    uint8_t age = (timeCurrent->tm_year +1900 ) - this->YEAR -1;
    if((this->MONTH > (timeCurrent->tm_mon +1) ) || (this->MONTH == (timeCurrent->tm_mon +1) && this->DAY >= timeCurrent->tm_mday))
    {
        age++;
    }
    return age;
}

int main()
{
    People People("thanh","bui ram",20,12,2000);
    People.printPeople();
}