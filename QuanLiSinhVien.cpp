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

// nhap du lieu dau vao va kiem tra du lieu dau vao
#define INPUT_TYPE(text, var, check)  \
        do                             \
        {                              \
            cout << text;              \
            cin >> var;                 \
            if(check) cout<< "nhap sai vui long nhap lai\n"; \
        }                               \
        while(check)                  

// kiem tra du lieu diem
#define CHECK_DIEM(diem)  diem < 0 || diem >10

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
    uint16_t ID;
    string TEN;
    TypeGioiTinh GIOI_TINH;
    int16_t TUOI;
    float TOAN;
    float LY;
    float HOA;
    float TRUNG_BINH_CONG;
    TypeHocLuc HOC_LUC;

    public:
    SinhVien();    // khi khoi tao object khong truyen tham so nao thi vao contructor nay
    SinhVien(string ten, TypeGioiTinh gioiTinh, uint8_t tuoi, float toan, float ly, float hoa);
    uint16_t getId();
    void setTen(string ten);
    string getTen();
    void setTuoi(int16_t tuoi);
    int16_t getTuoi();
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

uint16_t SinhVien::getId()
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

void SinhVien::setTuoi(int16_t tuoi)
{
    SinhVien::TUOI = tuoi;
}

int16_t SinhVien::getTuoi()
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

//class menu
class Menu
{
    private:
    vector <SinhVien> Database;
    void hienThiSinhVien(SinhVien sv);
    bool compareString(const string character1, const string character2 );
    bool checkTen(const string ten);
    public:
    Menu();
    void themSinhVien();
    void inDanhSachSinhVien();
    void xoaSinhVien();        
    void timKiemSinhVien();        
    void thayDoiThongTinSinhVien();
    void sapXepSinhVienTheoDiemTrungBinh();
    void sapXepSinhVienTheoTen();
};

Menu::Menu()
{
    uint8_t phim =0;
    do
    {
        do
        {
            cout<<"\n1. Them sinh vien\n";
            cout<<"2. in danh sach sinh vien\n";
            cout<<"3. xoa sinh vien theo id\n";
            cout<<"4. tim kiem sinh vien theo ten\n";
            cout<<"5. thay doi thong tin sinh vien\n";
            cout<<"6. sap xep sinh vien theo diem trung binh\n";
            cout<<"7. sap xep sinh vien theo ten\n";
            cout<<"0. thoat\n";
            cout<<"vui long nhap thong tin\n";
            scanf ("%d",&phim);
        }
        while(phim < 0 || phim >7);
        switch(phim)
        {
            case 1:
            {
                Menu::themSinhVien();
                break;
            }
            case 2:
            {
                Menu::inDanhSachSinhVien();
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
            case 7:
            {
                Menu::sapXepSinhVienTheoTen();
                break;   
            }
        }
    } 
    while (phim != 0);
}

/*
* Class:  Menu
* Function: themSinhVien()
* Description: them sinh vien
* Input:
*   khong co
* Output:
*   return:khong co
*/

void Menu::themSinhVien()
{
    string ten;
    string s_gioiTinh;
    TypeGioiTinh gioiTinh;
    int16_t tuoi;
    float toan;
    float ly;
    float hoa;
    printf("****nhap thong tin sinh vien*****\n");
    INPUT_TYPE("nhap ten: ", ten, checkTen(ten));
    INPUT_TYPE("nhap gioi tinh(nam/nu): ", s_gioiTinh, s_gioiTinh.compare("nam") != 0 && s_gioiTinh.compare("nu") != 0);
    INPUT_TYPE("nhap tuoi: ", tuoi, tuoi <= 0);
    INPUT_TYPE("nhap diem toan: ", toan, CHECK_DIEM(toan));
    INPUT_TYPE("nhap diem ly: ", ly, CHECK_DIEM(ly));
    INPUT_TYPE("nhap diem toan: ", hoa, CHECK_DIEM(hoa));
    if(s_gioiTinh.compare("nam")== 0) gioiTinh = NAM;
    else gioiTinh = NU;
    SinhVien sv(ten,gioiTinh,tuoi,toan,ly,hoa);
    Database.push_back(sv);
}

/*
* Class:  Menu
* Function: checkTen
* Description: kiem tra ten nam trong khoang a->Z va A->Z
* Input:
*   string ten
* Output:
*   return: 
            True :ten nam trong khoang a->Z va A->Z
            false: ten nam ngoai khong a->z va A->Z
*/

bool Menu::checkTen(const string ten)
{
    uint16_t smallSize= ten.size();
    uint16_t i=0;
    for( int i=0; i<smallSize; i++)
    {
        if(ten.at(i) < 65 || (ten.at(i) > 90 && ten.at(i) < 97) || ten.at(i) > 122) return true;
    }
    return false;
}

/*
* Class:  Menu
* Function: compareString
* Description: so sanh 2 mang ki tu
* Input:
*   string character1
*   string character2 
* Output:
*   return: 
*           True :character1 lon hon character2
*           false: :character1 nho hon character2
*/

bool Menu::compareString(const string character1, const string character2 )
{
    uint16_t smallSize =0 ;
    uint16_t i=0;

    if(character1.size() <= character2.size()) smallSize = character1.size();
    else smallSize = character2.size();

    for(int i=0; i< smallSize; i++)
    {
        if(character1.at(i) > character2.at(i))
        {
            return true;
        }
        else if (character1.at(i) < character2.at(i))
        {
            return false;
        }
    }
    if(character1.size() <= character2.size()) return true;  // neu hai chu bang nhau thi so sanh size
    else return false;                                       // vd: "th" va "thanh" -> chu "thanh" lon hon
}

/*
* Class:  Menu
* Function: sapXepSinhVienTheoTen()
* Description: sap xep sinh vien theo ten sinh vien
* Input:
*   khong co
* Output:
*   return: 
*           khong co
*/

void Menu::sapXepSinhVienTheoTen()
{
    SinhVien sv;
    for(int i=0 ; i<Database.size() -1 ; i++)
    {
        for(int k=i+1; k<Database.size(); k++)
        {
            if(this->compareString(Database[i].getTen(), Database[k].getTen())) // so sanh ten
            {
                sv = Database[i];
                Database[i] = Database[k];
                Database[k] = sv;
            }
        }
    }
}

/*
* Class:  Menu
* Function: hienThiSinhVien
* Description: hien thi 1 sinh vien
* Input:
*   khong co
* Output:
*   return: 
*           khong co
*/

void Menu::hienThiSinhVien(SinhVien sv)
{
    string s_gioiTinh;
    string s_hocLuc;
    if(sv.getGioiTinh() == NAM) s_gioiTinh = "nam";
    else s_gioiTinh = "nu";

    if(sv.getHocLuc() == GIOI) s_hocLuc = "gioi" ;
    else if(sv.getHocLuc() == KHA) s_hocLuc ="kha";
    else if(sv.getHocLuc() == TRUNG_BINH) s_hocLuc ="trung binh";
    else if(sv.getHocLuc() == YEU) s_hocLuc ="yeu";

    cout << sv.getId() << "\t" << sv.getTen() << "\t" << s_gioiTinh <<"\t" << sv.getTuoi() << "\t" << sv.getToan() << "\t" << sv.getLy() << "\t" << sv.getHoa() << "\t";
    cout<< sv.getDiemTrungBinh() << "\t" << s_hocLuc << endl;
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

void Menu::inDanhSachSinhVien()
{
    string s_gioiTinh;
    string s_hocLuc;
    cout<<"ID\tTEN\tGIOI TINH\tTUOI\tTOAN\tLY\tHOA\t TRUNG BINH\t HOC LUC\n";
    for(SinhVien sv:Database)
    {
        this->hienThiSinhVien(sv);
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
            cout<<"ID\tTEN\tGIOI TINH\tTUOI\tTOAN\tLY\tHOA\t TRUNG BINH\t HOC LUC\n";
            this->hienThiSinhVien(Database[i]);
            cout<<"da xoa\n";
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
    cout<<"ID\tTEN\tGIOI TINH\tTUOI\tTOAN\tLY\tHOA\t TRUNG BINH\t HOC LUC\n";
    for(int i =0; i < Database.size(); i++)
    {
        if(name.compare(this->Database[i].getTen()) == 0 ) // so sanh ten trong danh sach sinh vien
        {
            this->hienThiSinhVien(Database[i]);
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
                INPUT_TYPE("nhap ten: ", ten, checkTen(ten));
                Database[i].setTen(ten);
                break;
            }
            case 2:
            {
                string s_gioiTinh;
                INPUT_TYPE("nhap gioi tinh(nam/nu): ", s_gioiTinh, s_gioiTinh.compare("nam") == 1 && s_gioiTinh.compare("nu") == 1);
                if(s_gioiTinh.compare((char*)"nam") == 0) Database[i].setGioiTinh(NAM);
                else Database[i].setGioiTinh(NU);
                break;
            }
            case 3:
            {
                int16_t tuoi;
                INPUT_TYPE("nhap tuoi: ", tuoi, tuoi <= 0);
                Database[i].setTuoi(tuoi);
                break;
            }
            case 4:
            {
                uint8_t toan;
                INPUT_TYPE("nhap diem toan: ", toan, CHECK_DIEM(toan));
                Database[i].setToan(toan);
                break;
            }
            case 5:
            {
                uint8_t ly;
                INPUT_TYPE("nhap diem ly: ", ly, CHECK_DIEM(ly));
                Database[i].setLy(ly);
                break;
            }
            case 6:
            {
                uint8_t hoa;
                INPUT_TYPE("nhap diem toan: ", hoa, CHECK_DIEM(hoa));
                Database[i].setHoa(hoa);
                break;
            }
        }
    } 
    while (phim !=0);
}

/*
* Class:  menu
* Function: sapXepSinhVienTheoDiemTrungBinh()
* Description: sap xep sinh vien theo diem trung binh
* Input:
*   khong co
* Output:
*   return:khong co
*/

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