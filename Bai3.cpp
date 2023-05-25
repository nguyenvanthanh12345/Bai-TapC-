/*
* File: bai3.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description: tính chu vi và diện tích của hình tròn
*/

#include<stdio.h>
#include<stdint.h>
#define pi 3.14

// class hinh tron
class HinhTron
{
    private:
    uint16_t R;

    public:
    HinhTron(int r=0);
    void setR(uint16_t r);
    uint16_t getR();
    float dienTich();
    float chuVi();
};

HinhTron::HinhTron(int r)
{
    HinhTron::R = r;
}
/*
* Class: HinhTron
* Function: Chuvi
* Description: tinh chu vi
* Input:
*   khong co
* Output:
*   return: chu vi 
*/
float HinhTron::chuVi()
{
    return 2*pi*HinhTron::R;
}

/*
* Class: HinhTron
* Function: dienTich
* Description: tinh dien tich
* Input:
*   khong co
* Output:
*   return: dien tich
*/

float HinhTron::dienTich()
{
    return pi*(HinhTron::R^2);
}

int main()
{

}