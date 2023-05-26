/*
* File: bai7.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description: tính tuổi của người và kiểm tra xem một ngày nhất định có phải là ngày nghỉ lễ hay không.
*/

#include<stdio.h>
#include<stdint.h>
#include<time.h>

// khai bao mang 2 chieu ngay va thang nghi le trong nam
uint8_t arrayHoliday[][2]={ {10,3}, {30,4}, {1,5}, {2,9}}; 

class Time
{
    private:
    uint8_t DAY;
    uint8_t MONTH;
    uint16_t YEAR;
    public:
    Time (uint8_t day=1, uint8_t month=1, uint16_t year=1900);
    void setDay(uint8_t day);
    uint8_t getDay();
    void setMonth(uint8_t month);
    uint8_t getMonth();
    void setYear(uint16_t YEAR);
    uint16_t getYear();
    void isHoliday();
};

Time::Time(uint8_t day, uint8_t month, uint16_t year)
{
    Time::DAY = day;
    Time::MONTH = month;
    Time::YEAR = year;
}

/*
* Class: Time
* Function: setDay
* Description: thay doi ngay
* Input:
*   uint8_t day
* Output:
*   return: khong co
*/

void Time::setDay(uint8_t day)
{
    Time::DAY = day;
}

/*
* Class: Time
* Function: getDay()
* Description: lay ngay
* Input:
*   khong co
* Output:
*   return: ngay
*/

uint8_t Time::getDay()
{
    return this->DAY;
}

/*
* Class: Time
* Function: setMonth
* Description: thay doi thang
* Input:
*   uint8_t month
* Output:
*   return: khong co
*/

void Time::setMonth(uint8_t month)
{
    this->MONTH = month;
}

/*
* Class: Time
* Function: getMonth()
* Description: lay thang
* Input:
*   khong co
* Output:
*   return: thang
*/

uint8_t Time::getMonth()
{
    return this->MONTH;
}

/*
* Class: Time
* Function: setYear
* Description: thay doi nam
* Input:
*   uint16_t year
* Output:
*   return: khong co
*/

void Time::setYear(uint16_t year)
{
    this->YEAR = year;
}

/*
* Class: Time
* Function: getYear()
* Description: lay ngay
* Input:
*   khong co
* Output:
*   return: nam
*/

uint16_t Time::getYear()
{
    return this->YEAR;
}

/*
* Class: Time
* Function: isHoliday()
* Description: kiem tra co phai ngay le khong
* Input:
*   khong co
* Output:
*   return: khong co
*/

void Time::isHoliday()
{
    uint8_t status = 0;
    for(int i=0; i<4; i++)
    {
        if(Time::DAY == arrayHoliday[i][0] && Time::MONTH == arrayHoliday[i][1])
        {
            printf("%d/%d is holiday\n",Time::DAY,Time::MONTH);
            status = 1;
            break;
        }
    }
    if(status == 0)
    printf("%d/%d is not holiday\n",Time::DAY,Time::MONTH);

}

class People
{
    private:
    Time BORN;  // khai bao bien kieu ngay thang nam sinh
    public:
    People(Time born);
    uint8_t calculateAge();
};

People::People(Time born)
{
    this->BORN = born;
}

/*
* Class: People
* Function: calculateAge()
* Description: tinh tuoi
* Input:
*   khong co
* Output:
*   return: khong co
*/

uint8_t People::calculateAge()
{
    time_t current;
    time(&current);
    tm *timeCurrent = localtime(&current);
    printf("%d\n",timeCurrent->tm_year +1900);
    uint8_t age = (timeCurrent->tm_year +1900 ) - this->BORN.getYear() -1;
    if((BORN.getMonth() > (timeCurrent->tm_mon +1) ) || (BORN.getMonth() == (timeCurrent->tm_mon +1) && BORN.getDay() >= timeCurrent->tm_mday))
    {
        age++;
    }
    return age;
}

int main()
{
    Time t(29,5,2000);
    People pp(t);
    printf("%d\n",pp.calculateAge());
    t.isHoliday();
}