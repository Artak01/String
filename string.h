#include <cstddef>
#ifndef STRING_H
#define STRING_H

class String{
    public:
        String();
        String(const char*);
        String(const String&);
        String(String&&) noexcept;
        ~String();
        const String& operator=(const String& rhs);
        String& operator=(String&& rhs) noexcept;
        size_t size();
        const char* c_str() const;
        String& append (const String& str);
        String& append (const char* s);
        char& at(size_t pos);
        char& back();
        char& front();
        void clear();
        bool empty() const noexcept;


        String operator+(const String& str);
        String operator+(const char* stri);
        String& operator+=(const String& str);
        String& operator+=(const char* str);
        friend std::ostream& operator<<(std::ostream& os, const String& myString);
        friend std::istream& operator>>(std::istream& is, String& myString);
        explicit operator const char*();
        explicit operator int();

    private:
        size_t m_size;
        char* m_arr;
};

bool operator== (const String& lhs, const String& rhs);
bool operator== (const char* lhs, const String& rhs);

#endif // String_h
