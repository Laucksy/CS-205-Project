#include "student.h"

Student::Student() : Ident::Ident('s')
{

}

Student::Student(string f, string l) : Ident::Ident('s')
{
    firstName = f;
    lastName = l;
}

Student::~Student()
{

}
