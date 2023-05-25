/*
* File: quan li sinh vien.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description:quan li sinh vien
*/

#include<stdio.h>
#include<string>
#include<stdint.h>
#include<vector>
#include<iostream>
using namespace std;

// kiem tra tham so truyen vao
#define CHECK_DIEM(diem) \
        if(diem < 0 && diem > 10) printf("nhap sai diem %s",#diem)

typedef enum
{
    NAM,
    NU
}TypeGioiTinh;

typedef enum
{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

//class sinh vien
class SinhVien
{
    private:
    uint8_t ID;
    string TEN;
    TypeGioiTinh GIOI_TINH;
    uint8_t TUOI;
    float TOAN;
    float LY;
    float HOA;
    float TRUNG_BINH_CONG;
    TypeHocLuc HOCLUC;

    public:
    SinhVien(string ten, TypeGioiTinh gioiTinh, uint8_t tuoi, float toan, float ly, float hoa);
    uint8_t getId();
    void setTen(string ten);
    string getTen();
    void setTuoi(uint8_t tuoi);
    uint8_t getTuoi();
    void setGioiTinh(TypeGioiTinh gioiTinh);
    TypeGioiTinh getGioiTinh();
    void setToan(float toan);
    float getToan();
    void setLy(float ly);
    float getLy();
    void setHoa(float hoa);
    float getHoa();
    float getDiemTrungBinh();
    TypeHocLuc getHocLuc();
};

// ham contructor sinh vien
SinhVien::SinhVien(string ten, TypeGioiTinh gioiTinh, uint8_t tuoi, float toan, float ly, float hoa)
{
    static uint8_t id=0;
    SinhVien::ID = id;
    id++;
    SinhVien::TEN = ten;
    SinhVien::GIOI_TINH = gioiTinh;
    SinhVien::TUOI = tuoi;
    SinhVien::TOAN = toan;
    SinhVien::LY = ly;
    SinhVien::HOA = hoa;
    CHECK_DIEM(toan);
    CHECK_DIEM(ly);
    CHECK_DIEM(hoa);
    SinhVien::TRUNG_BINH_CONG = SinhVien::getDiemTrungBinh();
    SinhVien::HOCLUC = SinhVien::getHocLuc();

}

/*
* Class:  SinhVien
* Function: getId()
* Description: lay so id sinh vien
* Input:
*   khong co
* Output:
*   return: id
*/

uint8_t SinhVien::getId()
{
    return SinhVien::ID;
}

/*
* Class:  SinhVien
* Function: getDiemTrungBinh()
* Description: lay diem trung binh
* Input:
*   khong co
* Output:
*   return: diem trung binh
*/

float SinhVien::getDiemTrungBinh()
{
    return (TOAN+LY+HOA)/3;
}

TypeHocLuc SinhVien::getHocLuc()
{
    if(getDiemTrungBinh() >=8) return GIOI;
    else if(getDiemTrungBinh() >= 6,5) return KHA;
    else if(getDiemTrungBinh() >= 5) return TRUNG_BINH; 
    else return YEU;
}

void SinhVien::setTen(string ten)
{
    SinhVien::TEN = ten;
}

string SinhVien::getTen()
{
    return SinhVien::TEN;
}

void SinhVien::setGioiTinh(TypeGioiTinh gioiTinh)
{
    SinhVien::GIOI_TINH;
}

TypeGioiTinh SinhVien::getGioiTinh()
{
    return SinhVien::GIOI_TINH;
}

void SinhVien::setTuoi(uint8_t tuoi)
{
    SinhVien::TUOI = tuoi;
}

uint8_t SinhVien::getTuoi()
{
    return SinhVien::TUOI;
}

void SinhVien::setToan(float toan)
{
    SinhVien::TOAN;
}

float SinhVien::getToan()
{
    return SinhVien::TOAN;
}

void SinhVien::setLy(float ly)
{
    SinhVien::LY = ly;
}

float SinhVien::getLy()
{
    return SinhVien::LY;
}

void SinhVien::setHoa(float hoa)
{
    SinhVien::HOA = hoa;
}

float SinhVien::getHoa()
{
    return SinhVien::HOA;
}

class Menu
{
    private:
    vector <SinhVien> Database;
    public:
    Menu();
    void themSinhVien();
    void hienThiSinhVien();
    void xoaSinhVien();
};

Menu::Menu()
{
    uint8_t phim =0;
    do
    {
        do
        {
            cout<<"\n1. Them sinh vien\n";
            cout<<"2. Hien thi sinh vien\n";
            cout<<"3. xoa sinh vien\n";
            cout<<"0. thoat\n";
            cout<<"vui long nhap thong tin\n";
            scanf ("%d",&phim);
        }
        while(phim < 0 || phim >3);
        switch(phim)
        {
            case 1:
            {
                Menu::themSinhVien();
                break;
            }
            case 2:
            {
                Menu::hienThiSinhVien();
                break;
            }
            case 3:
            {
                Menu::xoaSinhVien();
                break;
            }
        }
    } 
    while (phim != 0);
}

void Menu::themSinhVien()
{
    string ten;
    string s_gioiTinh;
    TypeGioiTinh gioiTinh;
    uint8_t tuoi;
    float toan;
    float ly;
    float hoa;
    printf("****nhap thong tin sinh vien*****\n");
    cout << "Nhap ten: ";
    cin >> ten;
    cout << "nhap gioi tinh(nam/nu): ";
    cin >> s_gioiTinh;
    if(s_gioiTinh.compare("nam")== 0) gioiTinh = NAM;
    else if(s_gioiTinh.compare("nu") == 0) gioiTinh = NU;
    else printf(" nhap sai gioi tinh\n");
    printf("tuoi :");
    scanf("%d",&tuoi);
    printf("toan: ");
    scanf("%f",&toan);
    printf("ly: ");
    scanf("%f",&ly);
    printf("hoa: ");
    scanf("%f",&hoa);
    SinhVien sv(ten,gioiTinh,tuoi,toan,ly,hoa);
    Database.push_back(sv);
}

void Menu::hienThiSinhVien()
{
    string s_gioiTinh;
    cout<<"ID\tTEN\tGIOI TINH\tTUOI\tTOAN\tLY\tHOA\n";
    for(SinhVien sv:Database)
    {
        if(sv.getGioiTinh() == NAM) 
        {
            s_gioiTinh = "nam";
        }
        else 
        {
            s_gioiTinh = "nu";
        }

        printf("%d\t%s\t     %s\t%d\t%0.1f\t%0.1f\t%0.1f\n",sv.getId(),sv.getTen().c_str(),s_gioiTinh.c_str(),sv.getTuoi(),sv.getToan(),sv.getLy(),sv.getHoa());
    }
}

void Menu::xoaSinhVien()
{
    uint16_t id;
    uint8_t status=0;
    printf("\n*****xoa sinh vien******\n");
    printf("nhap id sinh vien can xoa:");
    scanf("%d",&id);
    for(int i=0; i< Database.size(); i++)
    {
        if(Database[i].getId() == id)
        {
            status=1;
            printf("tim thay:\n");
            printf("ID\tTEN\n");
            printf("%d\t %s\n",Database[i].getId(), Database[i].getTen().c_str());
            Database.erase(Database.begin() + i);
        }
    }
    if(status == 0) printf("khong tim thay id : %d\n",id);
}
int main()
{
    Menu menu;
    
    
}