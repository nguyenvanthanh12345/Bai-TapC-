/*
* File: bai10.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description:in thông tin sách, mượn sách và trả sách.
*/

#include<stdio.h>
#include<stdint.h>
#include<string>
#include<vector>
using namespace std;

// xay dung kieu du lieu trang thai muon sach hay tra sach

typedef enum
{
    KHONG_MUON,
    MUON
}TrangThai;

class Sach
{
    private:
    uint16_t ID;
    string TEN;
    string TAC_GIA;
    uint16_t NAM_XUAT_BAN;
    uint16_t SO_LUONG;
    TrangThai TRANG_THAI;     // khai bao kieu du lieu trang thai muon sach hay tra sach
    public:
    Sach(string ten,string tacGia, uint16_t namXuatBan,uint16_t soluong);
    uint16_t getId();
    void setTen(string ten);
    string getTen();
    void setTacGia(string tacGia);
    string getTacGia();
    void setNamXuatBan(uint16_t namXuatban);
    uint16_t getNamXuatBan();
    void setSoLuong(uint16_t soLuong);
    uint16_t getSoluong();
    void setTrangThaiSach(TrangThai trangThai);
    TrangThai getTrangThaiSach();
};

Sach::Sach(string ten,string tacGia, uint16_t namXuatBan,uint16_t soluong)
{
    static uint16_t id=0;
    Sach::ID = id;
    id++;
    Sach::TEN = ten;
    Sach::TAC_GIA = tacGia;
    Sach::NAM_XUAT_BAN = namXuatBan;
    Sach::SO_LUONG = soluong;
    Sach::TRANG_THAI =KHONG_MUON;
}

/*
* Class:  Sach
* Function: getId()
* Description: lay so id sach
* Input:
*   khong co
* Output:
*   return: id
*/

uint16_t Sach::getId()
{
    return Sach::ID;
}

/*
* Class:  Sach
* Function: setTen
* Description: set ten sach
* Input:
*   string ten
* Output:
*   return: khong co
*/

void Sach::setTen(string ten)
{
    Sach::TEN = ten;
}

/*
* Class:  Sach
* Function: getTen()
* Description: lay ten sach
* Input:
*   khong co
* Output:
*   return: ten sach
*/


string Sach::getTen()
{
    return Sach::TEN;
}

/*
* Class:  Sach
* Function: setTacGia
* Description: set ten tac gia
* Input:
*   string tacGia
* Output:
*   return: khong co
*/

void Sach::setTacGia(string tacGia)
{
    Sach::TAC_GIA = tacGia;
}

/*
* Class:  Sach
* Function: getTacGia()
* Description: lay ten tac gia
* Input:
*   khong co
* Output:
*   return: ten tac gia
*/

string Sach::getTacGia()
{
    return Sach::TAC_GIA;
}

/*
* Class:  Sach
* Function: setNamXuatBan
* Description: set nam xuat ban sach
* Input:
*   uint16_t namXuatBan
* Output:
*   return: khong co
*/

void Sach::setNamXuatBan(uint16_t namXuatBan)
{
    Sach::NAM_XUAT_BAN = namXuatBan;
}

/*
* Class:  Sach
* Function: getNamXuatBan()
* Description: lay nam xuat ban sach
* Input:
*   khong co
* Output:
*   return: nam xuat ban
*/

uint16_t Sach::getNamXuatBan()
{
    return Sach::NAM_XUAT_BAN;
}

/*
* Class:  Sach
* Function: setSoLuong
* Description: set so luong sach
* Input:
*   uint16_t soLuong
* Output:
*   return: khong co
*/

void Sach::setSoLuong(uint16_t soLuong)
{
    Sach::SO_LUONG = soLuong;
}

/*
* Class:  Sach
* Function: getTen()
* Description: lay ten sach
* Input:
*   khong co
* Output:
*   return: ten sach
*/

uint16_t Sach::getSoluong()
{
    return Sach::SO_LUONG;
}

void Sach::setTrangThaiSach(TrangThai trangThai)
{
    Sach::TRANG_THAI = trangThai;
}

TrangThai Sach::getTrangThaiSach()
{
    return Sach::TRANG_THAI;
}

class Menu
{
    private:
    vector <Sach> Database;
    public:
    void themSach(Sach sach);
    void inThongTin();
    void muonSach(uint16_t id);
    void traSach(uint16_t id);
};

void Menu::inThongTin()
{
    string s_TrangThai;
    printf("id\t ten sach\t tac gia\t nam xuat ban\t so luong\t trang thai\n");
    for(Sach sach : Database)
    {
        if(sach.getTrangThaiSach() == KHONG_MUON) s_TrangThai = "khong muon";
        else s_TrangThai = "muon";
        printf("%d \t %s \t %s \t %d \t %d \t %s\n",sach.getId(), sach.getTen().c_str(), sach.getTacGia().c_str(), sach.getNamXuatBan(), sach.getSoluong(), s_TrangThai.c_str());
    }
}
void Menu::themSach(Sach sach)
{
    Database.push_back(sach);
}
void Menu::muonSach(uint16_t id)
{
    //Database[1].setTrangThaiSach(MUON);
    uint8_t status=0;
    for(int i =0; i < Database.size(); i++)
    {
        if(Database[i].getId() == id) 
        {
            if(Database[i].getTrangThaiSach() == MUON)
            {
                printf("Sach hien tai da muon\n");
            }
            else
            {
                printf("Muon sach co so Id: %d\n",id);
                Database[i].setTrangThaiSach(MUON);
            }
            status = 1;
        }
    }
    if(status == 0) printf("khong tim thay sach so id %d muon muon\n",id);
}

void Menu::traSach(uint16_t id)
{
    uint8_t status=0;
    for(int i =0; i < Database.size(); i++)
    {
        if(Database[i].getId() == id) 
        {
            if(Database[i].getTrangThaiSach() == KHONG_MUON)
            {
                printf("sach hien tai khong muon\n");
            }
            else
            {
                printf("tra sach co so Id: %d\n",id);
                Database[i].setTrangThaiSach(KHONG_MUON);
            }
            status = 1;
        }
    }
    if(status == 0) printf("khong tim thay sach so id %d muon tra\n",id);
}

int main()
{
    Sach sach1("tao", "thanh", 2000, 12), sach2("tao", "thanh", 2000, 12), sach3("tao", "thanh", 2000, 12);
    Menu menu;
    menu.themSach(sach1);
    menu.themSach(sach2);
    menu.themSach(sach3);
    menu.inThongTin();
    menu.muonSach(1);
    menu.inThongTin();
    
}