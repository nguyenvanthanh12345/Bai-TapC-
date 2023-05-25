/*
* File: bai7.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description: tính toán cơ bản như cộng, trừ, nhân và chia.
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>

// class phan so
class PhanSo
{
    private:
    int TU_SO;
    int MAU_SO;

    public:
    PhanSo(int tuSo=0, int mauSo=1);
    int getTuSo();
    int getMauSo();
};

PhanSo::PhanSo(int tuSo, int mauSo)
{
    this->TU_SO = tuSo;
    this->MAU_SO = mauSo;
}

/*
* Class: phanso
* Function: getTuSo()
* Description: lay tu so
* Input:
*   khong co
* Output:
*   return: tu so
*/

int PhanSo::getTuSo()
{
    return this->TU_SO;
}
 
/*
* Class: phanso
* Function: getMauSo()
* Description: lay mau so
* Input:
*   khong co
* Output:
*   return: mau so
*/

int PhanSo::getMauSo()
{
    return this->MAU_SO;
}

//class phep tinh
class PhepTinh
{
    private:
    PhanSo A;
    PhanSo B;

    public:
    PhepTinh(PhanSo a, PhanSo b);
    float cong();
    float tru();
    float nhan();
    float chia();
};

PhepTinh::PhepTinh(PhanSo a, PhanSo b)
{
    this->A = a;
    this->B = b;
}

/*
* Class: PhepTinh
* Function: cong()
* Description: cong phan so
* Input:
*   khong co
* Output:
*   return: ket qua phep cong phan so
*/

float PhepTinh::cong()
{
    return (this->A.getTuSo()/this->A.getMauSo()) + (this->B.getTuSo() / this->B.getMauSo());
}

/*
* Class: PhepTinh
* Function: tru()
* Description: Tru phan so
* Input:
*   khong co
* Output:
*   return: ket qua phep tru phan so
*/

float PhepTinh::tru()
{
    return (this->A.getTuSo()/this->A.getMauSo()) - (this->B.getTuSo() / this->B.getMauSo());
}

/*
* Class: PhepTinh
* Function: nhan()
* Description: nhan phan so
* Input:
*   khong co
* Output:
*   return: ket qua phep nhan phan so
*/

float PhepTinh::nhan()
{
    return (this->A.getTuSo()/this->A.getMauSo()) * (this->B.getTuSo() / this->B.getMauSo());
}

/*
* Class: PhepTinh
* Function: chia()
* Description: chia phan so
* Input:
*   khong co
* Output:
*   return: ket qua phep chia phan so
*/

float PhepTinh::chia()
{
    return (this->A.getTuSo()/this->A.getMauSo()) / (this->B.getTuSo() / this->B.getMauSo());
}

int main()
{
    PhanSo a(1,2), b(5,7);
    PhepTinh ps(a,b);
    printf("%f",ps.cong());
}