#include <iostream>
#include "string.h"
#include <cstring>


String::String()
    :m_arr {nullptr}
    ,m_size {}  
{}

String::String(const char* ptr)
    :m_size {strlen(ptr)}
    ,m_arr {new char[m_size]}
{
    for(int i = 0; i < m_size; ++i) {
        m_arr[i] = ptr[i];
    }
}

String::String(const String& other)
    :m_size {other.m_size}
    ,m_arr {new char[m_size]}
{
    for(int i = 0; i < m_size; ++i) { 
        m_arr[i] = other.m_arr[i];
    }
}

String::String(String&& other) noexcept 
    :m_arr {other.m_arr}
    ,m_size {other.m_size}
{
    other.m_arr = nullptr;
    other.m_size = 0;
}

String::~String()
{
    delete[] m_arr;
    m_arr = nullptr;
}

const String& String::operator=(const String& rhs)
{
    if (this != &rhs) {
        m_size = rhs.m_size;
        delete[] m_arr;
        m_arr = new char[m_size];
        for(int i = 0; i < m_size; ++i) {
            m_arr[i] = rhs.m_arr[i];
        }
    }
    return *this;
}

String& String::operator=(String&& rhs) noexcept 
{
    if (this != &rhs) {
        m_size = rhs.m_size;
        delete[] m_arr;
        m_arr = rhs.m_arr;
        rhs.m_arr = nullptr;
        rhs.m_size = 0;
    }
    return *this;
}

size_t String::size() const
{
    size_t size = strlen(m_arr) + 1;
    return size;
}

const char* String::c_str() const
{
    if (m_arr == nullptr){
        throw std::invalid_argument("Error");
    }
    return m_arr;
}

String& String::append (const String& str){
    size_t size = m_size + str.m_size;
    char* new_arr = new char[size];
    for(int i = 0; i < m_size; ++i){
        new_arr[i] = m_arr[i];
    }
    int k = 0;
    for(int i = m_size; i < size; ++i){
        new_arr[i] = str.m_arr[k];
        ++k;
    }
    
    new_arr[size] = '\0';
    
    delete[] m_arr;
    m_arr = new_arr;
    m_size = size;
    return *this;
}
String& String::append (const char* s){
    size_t size = m_size + strlen(s);
    char* new_arr = new char[size]; 
    for(int i = 0; i < m_size; ++i){
        new_arr[i] = m_arr[i];        
    }
    for(int i = 0; i < strlen(s) + 1; ++i){
        new_arr[i + m_size] = s[i];
    } 
    new_arr[size] = '\0';
    delete[] m_arr;
    m_arr = new_arr;
    m_size = size;
    for(int i = 0; i < m_size; ++i){
        std::cout << m_arr[i];
    }
    std::cout << std::endl;
    return *this;
}

char& String::at(size_t pos) const
{
    if (pos < 0 || pos >= m_size){
        throw std::invalid_argument("Invalind index!");
    }
    return m_arr[pos];
}

char& String::back() const
{
    if(m_size == 0){
        throw std::invalid_argument("Error!");
    }
    return m_arr[m_size - 1];
}

char& String::front() const
{
    if(m_size == 0){
        throw std::invalid_argument("Error!");
    }
    return m_arr[0];
}

void String::clear(){
    m_size = 0;
    delete[] m_arr;
    m_arr = nullptr;
}

bool String::empty() const noexcept{
    if (m_size){
        return false;
    }
    return true;
}


String String::operator+(const String& str)
{
    return this->append(str);
}

String String::operator+(const char* stri)
{
    return this->append(stri); 
}

String& String::operator+=(const String& str)
{
    this->append(str);
    return *this;
}

String& String::operator+=(const char* str)
{
    this->append(str);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& myString)
{
    os << myString;
    return os;
}

std::istream& operator>>(std::istream& is, String& str)
{
    int size = 50;
    str.m_size = size;
    delete[] str.m_arr;
    str.m_arr = new char[str.m_size];
    is.getline(str.m_arr, str.m_size);    
    return is;
}

String::operator const char*()
{
    return m_arr;
}

String::operator int()
{
    try
    {
        int x = atoi(m_arr);
        return x;
    }
    catch(...)
    {
        return 0;
    }
    return 0;
}

bool operator== (const String& lhs, const String& rhs)
{
    return (strcmp(lhs.c_str(), rhs.c_str()) == 0);
}












