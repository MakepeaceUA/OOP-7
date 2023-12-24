#include<iostream>
using namespace std;


class MyString
{
    char* str;
    int size;
    static int count;

public:
    MyString()
    {
        size = 80;
        str = new char[size + 1];
        count++;
    }

    MyString(const MyString& copy)
    {
        size = copy.size;
        str = copy.str;
        count++;
    }

    MyString(int Size)
    {
        size = Size;
        str = new char[size + 1];
        count++;
    }

    MyString(const char* arr)
    {
        size = strlen(arr);
        str = new char[size + 1];
        strcpy_s(str, size + 1, arr);
        count++;
    }

    void Input()
    {
        cout << "Input string:";
        cin.getline(str, size + 1);
    }

    void Output()
    {
        if (str == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        cout << "String: " << str << "\n\n\n";
    }

    static int GetCount()
    {
        return count;
    }

    /* ~MyString()
     {
         delete[] str;
         count--;
     }*/

    MyString operator++() 
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 2];
        
        strcpy_s(new_str, sz + 2, str);
        
        new_str[sz] = 'x';
        new_str[sz + 1] = '\0';
        
        delete[] str;
        str = new_str;
        
        return *this;
    }

    MyString operator--()
    {
        int sz = strlen(str);
        str[sz - 1] = '\0';
        
        return *this;
    }

    MyString operator+(int value) 
    {
        int sz = strlen(str);
        char* new_str = new char[sz + 1 + value];

        strcpy_s(new_str, sz + 1 + value, str);
        
        for (int i = 0; i < value; i++)
        {
            new_str[sz + i] = 'x';
        }
        
        new_str[sz + value] = '\0';
        
        return MyString(new_str);
    }

    MyString operator-(int value) 
    {
        int sz = strlen(str);
        str[sz - value] = '\0';
        
        return *this;
    }
};

int MyString::count = 0;

int main()
{
    MyString obj1;
    MyString obj2(20);
    MyString obj3("Hello");
    
  /*  MyString obj4 = obj3;
    MyString obj5(obj3);*/

    obj1.Input();
    obj1.Output();
    obj2.Input();
    obj2.Output();
    obj3.Output();
    
    ++obj3;
    obj3.Output();
    --obj3;
    obj3.Output();
    
    MyString obj4 = obj3 + 3;
    obj4.Output();
    MyString obj5 = obj3 - 3;
    obj5.Output();

    cout << "Count: " << MyString::GetCount();
}