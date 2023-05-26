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
        if(diem < 0 && diem > 10) printf("nhap sai diem %s\n",#diem)

// xay dung enum kieu gioi tinh
typedef enum
{
    NAM,
    NU
}TypeGioiTinh;

// xay dung enum kieu hoc luc
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
    TypeHocLuc HOC_LUC;

    public:
    SinhVien();    // khi khoi tao object khong truyen tham so nao thi vao contructor nay
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
    float tinhDiemTrungBinh();
    TypeHocLuc tinhHocLuc();
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
    SinhVien::TRUNG_BINH_CONG = SinhVien::tinhDiemTrungBinh();
    SinhVien::HOC_LUC = SinhVien::tinhHocLuc();

}

SinhVien::SinhVien()
{
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

float SinhVien::tinhDiemTrungBinh()
{
    return (TOAN+LY+HOA)/3;
}

TypeHocLuc SinhVien::tinhHocLuc()
{
    if(getDiemTrungBinh() >=8) return GIOI;
    else if(getDiemTrungBinh() >= 6,5) return KHA;
    else if(getDiemTrungBinh() >= 5) return TRUNG_BINH; 
    else return YEU;
}

float SinhVien::getDiemTrungBinh()
{
    return this->TRUNG_BINH_CONG;
}

TypeHocLuc SinhVien::getHocLuc()
{
    return this->HOC_LUC;
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
    SinhVien::GIOI_TINH = gioiTinh;
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
    SinhVien::TOAN = toan;
    this->TRUNG_BINH_CONG = this->tinhDiemTrungBinh(); // cap nhat lai diem trung binh
    this->HOC_LUC = this->tinhHocLuc(); //cap nhat lai hoc luc
}

float SinhVien::getToan()
{
    return SinhVien::TOAN;
}

void SinhVien::setLy(float ly)
{
    SinhVien::LY = ly;
    this->TRUNG_BINH_CONG = this->tinhDiemTrungBinh(); // cap nhat lai diem trung binh
    this->HOC_LUC = this->tinhHocLuc(); //cap nhat lai hoc luc
}

float SinhVien::getLy()
{
    return SinhVien::LY;
}

void SinhVien::setHoa(float hoa)
{
    SinhVien::HOA = hoa;
    this->TRUNG_BINH_CONG = this->tinhDiemTrungBinh(); // cap nhat lai diem trung binh
    this->HOC_LUC = this->tinhHocLuc(); //cap nhat lai hoc luc
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
    void timKiemSinhVien();        
    void thayDoiThongTinSinhVien();
    void sapXepSinhVienTheoDiemTrungBinh();
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
            cout<<"3. xoa sinh vien theo id\n";
            cout<<"4. tim kiem sinh vien theo ten\n";
            cout<<"5. thay doi thong tin sinh vien\n";
            cout<<"6. sap xep sinh vien theo diem trung binh";
            cout<<"0. thoat\n";
            cout<<"vui long nhap thong tin\n";
            scanf ("%d",&phim);
        }
        while(phim < 0 || phim >6);
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
            case 4:
            {
                Menu::timKiemSinhVien();
                break;
            }
            case 5:
            {
                Menu::thayDoiThongTinSinhVien();
                break;
            }
            case 6:
            {
                Menu::sapXepSinhVienTheoDiemTrungBinh();
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

/*
* Class:  menu
* Function: hienThiSinhVien()
* Description: hien thi danh sach sinh vien
* Input:
*   khong co
* Output:
*   return:khong co
*/

void Menu::hienThiSinhVien()
{
    string s_gioiTinh;
    string s_hocLuc;
    cout<<"ID\tTEN\tGIOI TINH\tTUOI\tTOAN\tLY\tHOA\t TRUNG BINH\t HOC LUC\n";
    for(SinhVien sv:Database)
    {
        if(sv.getGioiTinh() == NAM) s_gioiTinh = "nam";
        else s_gioiTinh = "nu";
        
        if(sv.getHocLuc() == GIOI) s_hocLuc = "gioi" ;
        else if(sv.getHocLuc() == KHA) s_hocLuc ="kha";
        else if(sv.getHocLuc() == TRUNG_BINH) s_hocLuc ="trung binh";
        else if(sv.getHocLuc() == YEU) s_hocLuc ="yeu";

        printf("%d\t %s\t     %s\t %d\t %0.1f\t %0.1f\t %0.1f\t     %0.1f\t    %s\n", sv.getId(), sv.getTen().c_str(), s_gioiTinh.c_str(), sv.getTuoi(), sv.getToan(), sv.getLy(), sv.getHoa(), sv.getDiemTrungBinh(), s_hocLuc.c_str());
    }
}

/*
* Class:  menu
* Function: xoaSinhVien()
* Description: xoa sinh vien theo id
* Input:
*   khong co
* Output:
*   return:khong co
*/
void Menu::xoaSinhVien()
{
    uint16_t id;
    uint8_t status=0;
    printf("\n*****xoa sinh vien******\n");
    printf("nhap id sinh vien can xoa:");
    scanf("%d",&id);
    for(int i=0; i < Database.size(); i++)
    {
        if(Database[i].getId() == id)
        {
            status=1;
            printf("tim thay:\n");
            printf("ID\tTEN\n");
            printf("%d\t %s\n",Database[i].getId(), Database[i].getTen().c_str());
            Database.erase(Database.begin() + i);    //xoa sinh vien
        }
    }
    if(status == 0) printf("khong tim thay id : %d\n",id);
}


/*
* Class:  menu
* Function: timKiemSinhVien()
* Description: tim kiem sinh vien theo ten sinh vien
* Input:
*   khong co
* Output:
*   return:khong co
*/
void Menu::timKiemSinhVien()
{
    uint8_t status = 0;
    string name;
    printf("\n*****tim kiem sinh vien*******\n");
    cout <<"nhap ten can tim kiem:";
    cin >> name;
    printf("\nID\tTEN\n");
    for(int i =0; i < Database.size(); i++)
    {
        if(name.compare(this->Database[i].getTen()) == 0 ) // so sanh ten trong danh sach sinh vien
        {
            printf("%d\t %s\n",Database[i].getId(), Database[i].getTen().c_str());
            status = 1;
        }
    }
    if(status == 0) printf("khong tim thay ten: %s\n",name.c_str());
}

/*
* Class:  menu
* Function: thayDoiThongTinSinhVien()
* Description: thay doi thong tin sinh vien theo id
* Input:
*   khong co
* Output:
*   return:khong co
*/

void Menu::thayDoiThongTinSinhVien()
{
    uint8_t status = 0;
    uint8_t phim =0;
    uint16_t id;
    printf("\n******thay doi thong tin sinh vien*******\n");
    printf("nhap id sinh vien thay doi : \n");
    scanf("%d",&id);
    uint8_t i;
    for(i= 0; i < Database.size(); i++)
    {
        if(Database[i].getId() == id)
        {            
            status =1;
            break;
        }
    }
    if(status == 0)
    {
        printf("Khong tim thay id: %d\n",id);
        return;                                     // neu khong tim thay id thi thoat khoi function
    }
    do
    {
        do 
        {
        cout <<"1. Thay doi ten\n";
        cout <<"2. thay doi gioi tinh\n";
        cout <<"3. thay doi tuoi\n";
        cout <<"4. thay doi diem toan\n";
        cout <<"5. thay doi diem ly\n";
        cout <<"6. thay doi diem hoa\n";
        cout <<"0. thoat\n";
        cout <<"vui long chon chuc nang\n";
        scanf("%d",&phim);
        }
        while(phim < 0 || phim > 6);
        switch (phim)
        {
            case 1:
            {
                string ten;
                printf("nhap ten: \n");
                cin >> ten;
                Database[i].setTen(ten);
                break;
            }
            case 2:
            {
                string s_GioiTinh;
                printf("nhap gioi tinh : \n");
                cin >> s_GioiTinh;
                if(s_GioiTinh.compare((char*)"nam") == 0) Database[i].setGioiTinh(NAM);

                else if(s_GioiTinh.compare((char*)"nu") == 0) Database[i].setGioiTinh(NU);

                else printf("nhap sai gioi tinh \n");
                break;
            }
            case 3:
            {
                uint8_t tuoi;
                printf("nhap tuoi: ");
                scanf("%d",&tuoi);
                Database[i].setTuoi(tuoi);
                break;
            }
            case 4:
            {
                uint8_t toan;
                printf("nhap toan: ");
                scanf("%d",&toan);
                CHECK_DIEM(toan);
                Database[i].setToan(toan);
                break;
            }
            case 5:
            {
                uint8_t ly;
                printf("nhap ly: ");
                scanf("%d",&ly);
                CHECK_DIEM(ly);
                Database[i].setLy(ly);
                break;
            }
            case 6:
            {
                uint8_t hoa;
                printf("nhap hoa: ");
                scanf("%d",&hoa);
                CHECK_DIEM(hoa);
                Database[i].setHoa(hoa);
                break;
            }
            default: printf("nhap sai chuc nang \n");
        }
    } 
    while (phim !=0);
}

void Menu::sapXepSinhVienTheoDiemTrungBinh()
{
    SinhVien sv1;
    for(int i=0; i < Database.size() -1 ; i++)
    {
        for(int k=i+1; k < Database.size(); k++)
        {
            if(Database[i].getDiemTrungBinh() > Database[k].getDiemTrungBinh())
            {
                sv1 = Database[i];
                Database[i] = Database[k];  // object i bang object k
                Database[k] = sv1;
            }
        }
    }
}

int main()
{
    Menu menu;
    
    
}