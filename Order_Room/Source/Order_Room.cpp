#include<Order_Room.hpp>

Room::Room(int16_t number_Room)
{
    this->NUMBER_ROOM = number_Room;
    this->IS_BOOKED = false;
    this->IS_CLEAN = true;
}

bool Room::get_Is_booked()
{
    return this->IS_BOOKED;
}

bool Room::get_Is_clean()
{
    return this->IS_CLEAN;
}

bool Room::isAvailable()
{
    return !this->IS_BOOKED && this->IS_CLEAN;
}

void Room::book_Room()
{
    this->IS_BOOKED = true;
}

void Room::check_In()
{
    this->IS_BOOKED = true;
    this->IS_CLEAN = true;
}

void Room::check_Out()
{
    this->IS_BOOKED =false;
    this->IS_CLEAN = false;
}

int16_t Room::getNumber_Room()
{
    return this->NUMBER_ROOM;
}


ManageRoom::ManageRoom()
{
    int16_t key;
    int16_t number_Room;
    while(1)
    {
        do
        {
            cout <<"\n**************menu**************" << endl;
            cout <<"1. dat phong" << endl;
            cout <<"2. check in" << endl;
            cout <<"3. check out" << endl;
            cout <<"4. danh sach" << endl;
            cout <<"5. them phong" << endl;
            cout <<"0. thoat" << endl;
            cout <<"vui long nhap chuc nang" << endl;
            cin >> key;
        }
        while(key < 0 && key >4);
        if(key == 0) break;
        switch(key)
        {
            case 1:
            {
                this->show_Status_Room();
                INPUT_TYPE("nhap so phong: ",number_Room, NO_CHECK, NO_SHOW);
                this->book_Room(number_Room);
                break;
            }
            case 2:
            {
                this->show_Status_Room();
                INPUT_TYPE("nhap so phong: ",number_Room, NO_CHECK, NO_SHOW);
                this->check_In(number_Room);
                break;
            }
            case 3:
            {
                this->show_Status_Room();
                INPUT_TYPE("nhap so phong: ",number_Room, NO_CHECK, NO_SHOW);
                this->check_Out(number_Room);
                break;
            }
            case 4:
            {
                this->show_Available_Room();
                break;
            }
            case 5:
            {
                this->add_Room();
                break;
            }
            
        }
    }
}

void ManageRoom::add_Room()
{
    int16_t quantity;
    int16_t number_Room;
    static int16_t i_cout =1;
    INPUT_TYPE("nhap so luong phong: ",quantity, quantity <= 0, "loi so luong phong\n");
    for(int i=0 ; i< quantity; i++)
    {
        Room room(i_cout);
        Database_Room.push_back(room);
        i_cout++;
    }
}

void ManageRoom::show_Available_Room()
{
    cout<<"********danh sach phong*************"<< endl;
    cout<< "SO PHONG\t DAT PHONG \t DON DEP \t SAN SANG" << endl;
    string s_Is_Booked;
    string s_Is_Clean;
    string s_Is_Available;
    for(Room room : Database_Room)
    {
        if(room.isAvailable() == true) s_Is_Available = "san sang";
        else s_Is_Available = "chua san sang";
        if(room.get_Is_booked() == true) s_Is_Booked ="da dat";
        else s_Is_Booked = "chua dat";
        if(room.get_Is_clean() == true) s_Is_Clean = "da don";
        else s_Is_Clean = "chua don"; 
        cout<< room.getNumber_Room()<<"\t\t" << s_Is_Booked << "\t"<<s_Is_Clean << "\t\t"<<s_Is_Available<< endl;
    }
}

void ManageRoom::show_Status_Room()
{
    for(Room room : Database_Room)
    {
        cout << "|" << room.getNumber_Room();
        if(room.get_Is_booked() == true ) cout<<": day |";
        else cout <<": trong|";
        if(room.isAvailable()== true) cout <<" sang sang";
        else cout <<" chua san";
    }
}

void ManageRoom::book_Room(int16_t number_Room)
{
    uint8_t status = 0;
    for(int i=0; i< Database_Room.size(); i++)
    {
        if(Database_Room[i].getNumber_Room() == number_Room) 
        {
            if(Database_Room[i].get_Is_booked() != false)
            {
                Database_Room[i].book_Room();
                break;
            }
            else
            {
                cout <<"phong da dat" << endl;
            }
            status = 1;
            break;
        }
    }
    if(status == 0) cout << "khong tim thay so phong" << endl;
}

void ManageRoom::check_In(int16_t number_Room)
{
    uint8_t status = 0;
    for(int i=0; i< Database_Room.size(); i++)
    {
        if(Database_Room[i].getNumber_Room() == number_Room) 
        {
            if(Database_Room[i].isAvailable() == true)
            {
                Database_Room[i].check_In();
                cout <<"da check in"<<endl;
            }
            else cout<<"phong chua san sang" <<endl;
            status = 1;
            break;
        }
    }
    if(status == 0) cout << "khong tim thay so phong" << endl;
}

void ManageRoom::check_Out(int16_t number_Room)
{
    uint8_t status = 0;

    for(int i=0; i< Database_Room.size(); i++)
    {
        if(Database_Room[i].getNumber_Room() == number_Room) 
        {
            if(Database_Room[i].get_Is_booked() == true)
            {
                Database_Room[i].check_Out();
                cout <<"da check out"<<endl;
            }
            else cout <<"phong chua check in" << endl;
            status = 1;
            break;
        }
    }
    if(status == 0) cout << "khong tim thay so phong" << endl;
}