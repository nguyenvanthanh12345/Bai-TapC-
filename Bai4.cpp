/*
* File: bai4.cpp
* Author: Nguyen Van Thanh
* Date: 25/05/2023
* Description: tính chỉ số BMI, so sánh tuổi và trọng lượng của các động vật khác nhau
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>

// class animal

class Animal
{
    private:
    char NAME[20];
    uint8_t AGE;
    uint16_t WEIGHT; // KG
    float HEIGHT;  //cm

    public:
    char *getName();
    uint8_t getAge();
    uint16_t getWeight();
    Animal(char name[]='\0',uint8_t age=0, uint8_t weight=0);
    float bmi();
};

// class CompareAnimal

class CompareAnimal
{
    private:
    Animal ANIMAL_A;
    Animal ANIMAL_B;

    public:
    CompareAnimal(Animal animalA, Animal animalB);
    bool compareAge();
    bool compareWeight();
    
};


Animal::Animal(char name[],uint8_t age, uint8_t weight)
{
    strcpy(Animal::NAME,name);
    Animal::AGE= age;
    Animal::WEIGHT = WEIGHT;
}

/*
* Class: Animal
* Function: bmi
* Description: tinh bmi
* Input:
*   khong co
* Output:
*   return: bmi
*/

float Animal::bmi()
{
    return this->WEIGHT/(this->HEIGHT * this->HEIGHT);
}

/*
* Class: Animal
* Function: getAge
* Description: lay tuoi
* Input:
*   khong co
* Output:
*   return: tuoi
*/

uint8_t Animal::getAge()
{
    return Animal::AGE;
}

/*
* Class: Animal
* Function: getWeight
* Description: lay tuoi
* Input:
*   khong co
* Output:
*   return: tuoi
*/

uint16_t Animal::getWeight()
{
    return Animal::WEIGHT;
}

/*
* Class: Animal
* Function: getName()
* Description: lay ten
* Input:
*   khong co
* Output:
*   return: ten
*/

char *Animal::getName()
{
    return Animal::NAME;
}


CompareAnimal::CompareAnimal(Animal animalA, Animal animalB)
{
    this->ANIMAL_A = animalA;
    this->ANIMAL_B = animalB;
}

/*
* Class: CompareAnimal
* Function: compareAge()
* Description: so sanh tuoi
* Input:
*   khong co
* Output:
*   return: true hoac false
*/

bool CompareAnimal::compareAge()
{
    if(this->ANIMAL_A.getAge() == this->ANIMAL_B.getAge()) return true;
    else return false;
}

/*
* Class: CompareAnimal
* Function: compareWeight()
* Description: so sanh can nang
* Input:
*   khong co
* Output:
*   return: true hoac false
*/

bool CompareAnimal::compareWeight()
{
    if(this->ANIMAL_A.getWeight() == this->ANIMAL_B.getAge()) return true;
    else return false;
}

int main()
{

}