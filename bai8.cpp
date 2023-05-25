/*
* File: bai8.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description:  rút, nộp tiền và kiểm tra số dư trong tài khoản.
*/

#include<stdio.h>
#include<stdint.h>
#include<string>
using namespace std;

// class ngan hang
class NganHang
{
    private:
    uint32_t SO_TAI_KHOAN;
    string TEN_TAI_KHOAN;
    uint32_t SO_DU;
    public:
    NganHang (uint32_t soTaiKhoan,string tenTaiKhoan, uint32_t soDu);
    void rutTien(uint32_t soTienRut);
    void nopTien(uint32_t soTienNop);
    void kiemTraSoDu();
};

NganHang::NganHang(uint32_t soTaiKhoan,string tenTaiKhoan, uint32_t soDu)
{
    this->SO_TAI_KHOAN = soTaiKhoan;
    this->TEN_TAI_KHOAN = tenTaiKhoan;
    this->SO_DU = soDu;
}

/*
* Class:  NganHang
* Function: rutTien
* Description: rut tien trong tai khoan
* Input:
*   uint32_t soTienRut
* Output:
*   return: khong co
*/

void NganHang::rutTien(uint32_t soTienRut)
{
    printf("\n****rut tien****\n");
    if(soTienRut > this->SO_DU)
    {
        printf("so du trong tai khoan khong du\n");
        return;
    }
    this->SO_DU = this->SO_DU - soTienRut;
    printf("so tai khoan: %d\n",this->SO_TAI_KHOAN);
    printf("ten tai khoan: %s\n",this->TEN_TAI_KHOAN.c_str());
    printf("so tien ban rut la: %d\n",soTienRut);
}

/*
* Class:  NganHang
* Function: nopTien
* Description: nop tien trong tai khoan
* Input:
*   int32_t soTienNop
* Output:
*   return: khong co
*/

void NganHang::nopTien(uint32_t soTienNop)
{
    printf("\n*****nop tien*****\n");
    printf("so tai khoan: %d\n",this->SO_TAI_KHOAN);
    printf("ten tai khoan: %s\n",this->TEN_TAI_KHOAN.c_str());
    this->SO_DU += soTienNop;
    printf("so tien ban nop la: %d\n",soTienNop);
}

/*
* Class:  NganHang
* Function: kiemTraSoDu()
* Description: kiem tra so du trong tai khoan
* Input:
*   khong co
* Output:
*   return: khong co
*/

void NganHang::kiemTraSoDu()
{
    printf("\n*****kiem tra so du******\n");
    printf("so tai khoan: %d\n",this->SO_TAI_KHOAN);
    printf("ten tai khoan: %s\n",this->TEN_TAI_KHOAN.c_str());
    printf("so du ban la: %d\n",this->SO_DU);
}

int main()
{
    NganHang nh(1022,"thanh",30000);
    nh.rutTien(20000);
    nh.nopTien(50000);
    nh.kiemTraSoDu();

}