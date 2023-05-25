/*
* File: bai9.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description:   chi phí bảo trì, kiểm tra số km đã đi và in thông tin về xe
*/

#include<stdio.h>
#include<stdint.h>
#include<string>
#include<iostream>
using namespace std;
// class Car
class Car
{
    private:
    string MAU_SAC;
    string DONG_CO;
    uint32_t SO_KM;

    public:
    Car(string mauSac, string dongCo, uint16_t soKm);
    void chiPhiBaoChi();
    uint32_t kiemTraSoKm();
    void inThongTin();
};

Car::Car(string mauSac, string dongCo, uint16_t sokm)
{
    Car::MAU_SAC = mauSac;
    Car::DONG_CO = dongCo;
    Car::SO_KM = sokm;
}

/*
* Class:  Car
* Function: kiemTraSoKm
* Description: kiem tra so km
* Input:
*   khong co
* Output:
*   return: so km
*/

uint32_t Car::kiemTraSoKm()
{
    return Car::SO_KM;
}

/*
* Class:  Car
* Function: chiPhiBaoChi()
* Description: in chi phi bao chi
* Input:
*   khong co
* Output:
*   return:  khong co
*/

void Car::chiPhiBaoChi()
{
    printf("*****chi phi bao chi*****\n");
    if(Car::SO_KM <= 1000) printf("chi phi bao chi : %d\n",1000000);
    else if(Car::SO_KM <= 5000) printf("chi phi bao chi : %d\n",2000000);
    else if(Car::SO_KM <= 10000) printf("chi phi bao chi : %d\n",3000000);
    else printf("chi phi bao chi : %d\n",5000000);
}

/*
* Class:  Car
* Function: inThongTin()
* Description: in thong tin
* Input:
*   khong co
* Output:
*   return:  khong co
*/

void Car::inThongTin()
{
    printf("******in thong tin*******\n");
    printf("Mau sac: %s\n",Car::MAU_SAC.c_str());
    printf("dong co : %s\n",Car::DONG_CO.c_str());
    printf("so km: %d\n",Car::SO_KM);
}

int main()
{
    Car car("hong","model2",10000);
    car.inThongTin();
    car.chiPhiBaoChi();
    printf("so km : %d\n",car.kiemTraSoKm());
}