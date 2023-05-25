/*
* File: bai1.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description: tính khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba
điểm.
*/
#include<stdio.h>
#include<math.h>
//class toa do diem
class Diem
{
    private:
    int X;
    int Y;

    public:
    Diem (int x=0, int y=0);
    int getX();
    int getY();
};



Diem::Diem(int x, int y)
{
    Diem::X = x;
    Diem::Y = y;
}

/*
* Class: Diem
* Function: getX
* Description: lay diem X
* Input:
*   khong co
* Output:
*   return: diem X 
*/

int Diem::getX()
{
    return Diem::X;
}

/*
* Class: Diem
* Function: getY
* Description: lay diem Y
* Input:
*   khong co
* Output:
*   return: diem Y 
*/

int Diem::getY()
{
    return Diem::Y;
}

// class khoang cach 2 diem trong khong gian
class KhoangCach
{
    private:
    Diem A;
    Diem B;

    public:
    KhoangCach(Diem a, Diem b);
    float khoangCachHaiDiem();
};

KhoangCach::KhoangCach(Diem a, Diem b)
{
    KhoangCach::A = a;
    KhoangCach::B = b; 
}

/*
* Class: KhoangCach
* Function: khoangCachHaiDiem()
* Description: Tinh khoang cach hai diem
* Input:
*   khong co
* Output:
*   return: khoang cach hai diem
*/

float KhoangCach::khoangCachHaiDiem()
{
    return sqrt(pow(this->A.getX() - this->B.getX(),2) + pow (this->A.getY() - this->B.getY(),2));
}

// class tam giac
class TamGiac
{
    private:
    Diem A;
    Diem B;
    Diem C;

    public:
    TamGiac(Diem a, Diem b, Diem c);
    float dienTich();
};

TamGiac::TamGiac(Diem a, Diem b,Diem c)
{
    TamGiac::A = a;
    TamGiac::B = b;
    TamGiac::C = c; 
}

/*
* Class: Tamgiac
* Function: dienTich()
* Description: Tinh dien tich
* Input:
*   khong co
* Output:
*   return: dien tich
*/

float TamGiac::dienTich()
{
    KhoangCach ab(TamGiac::A,TamGiac::B);
    KhoangCach ac(TamGiac::A,TamGiac::C);
    KhoangCach bc(TamGiac::B,TamGiac::C);
    float p = (ab.khoangCachHaiDiem() + ac.khoangCachHaiDiem() + bc.khoangCachHaiDiem())/2;
    return sqrt(p*(p - ab.khoangCachHaiDiem()) * (p - ac.khoangCachHaiDiem()) * (p -bc.khoangCachHaiDiem()) );
}

int main()
{
    Diem a(2,3);
    Diem b(5,6);
    Diem c(9,8);
    TamGiac tg(a,b,c);
    printf("%f",tg.dienTich());
}