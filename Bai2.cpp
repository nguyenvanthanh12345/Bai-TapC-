/*
* File: bai2.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description: tính chu vi, diện tích, đường chéo và kiểm tra xem nó có phải là hình vuông hay không.
*/
#include<stdio.h>
#include<math.h>

// class hinh chu nhat 
class HinhChuNhat
{
    private:
    int DAI;
    int RONG;

    public:
    HinhChuNhat (int dai=0, int rong=0);
    void setDai(int dai);
    int getDai();
    void setRong();
    int getRong();
    int chuVi (void);
    float dienTich(void);
    float duongCheo(void);
    bool kiemTraHinhVuong(void);
};

HinhChuNhat::HinhChuNhat(int dai,int rong)
{
    HinhChuNhat::DAI= dai;
    HinhChuNhat::RONG = rong;
}
/*
* Class: HinhChuNhat
* Function: chuVi
* Description: tinh chu vi
* Input:
*   khong co
* Output:
*   return: chu vi 
*/
int HinhChuNhat::chuVi (void)
{
    return (HinhChuNhat::DAI + HinhChuNhat::RONG)*2;
}

/*
* Class: HinhChuNhat
* Function: dienTich
* Description: tinh dien tich
* Input:
*   khong co
* Output:
*   return: dien tich 
*/

float HinhChuNhat::dienTich (void)
{
    return HinhChuNhat::DAI * HinhChuNhat::RONG;
}

/*
* Class: HinhChuNhat
* Function: duongCheo
* Description: tinh duong cheo
* Input:
*   khong co
* Output:
*   return: duong cheo
*/

float HinhChuNhat::duongCheo (void)
{
    return sqrt(HinhChuNhat::DAI^2 + HinhChuNhat::RONG^2);
}

/*
* Class: HinhChuNhat
* Function: kiemTraHinhVuong
* Description: kiem tra co phai hinh vuong khong
* Input:
*   khong co
* Output:
*   return: true hoac false
*/

bool HinhChuNhat::kiemTraHinhVuong(void)
{
    if(HinhChuNhat::DAI == HinhChuNhat::RONG) return true;
    else return false;
}

int main()
{
    HinhChuNhat cn;
    printf("%d",cn.chuVi());
}