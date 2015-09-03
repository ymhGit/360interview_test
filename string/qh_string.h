#ifndef QIHOO_STRING_H_
#define QIHOO_STRING_H_

#include <iostream>
#include <stdlib.h>

namespace qh
{
    class string {
    public:
        //ctor
        string();
        string(const char* s);
        string(const char* s, size_t len);
        string(const string& rhs);

        string& operator=(const string& rhs);

        //dtor
        ~string();

        //get
        size_t size() const;
        const char* data() const;
        const char* c_str() const;

        // set & get

        //old
        //char* operator[](size_t index);
        
        //new
        char& operator[](size_t index);
        
        
        //operator
        bool operator == (const string& rhs);
        bool operator != (const string& rhs);
        bool operator < (const string& rhs);
        bool operator <= (const string& rhs);
        bool operator > (const string& rhs);
        bool operator >= (const string& rhs);
        string operator + (const string& rhs);
        string& operator += (const string& rhs);
        
        friend std::istream& operator >> (std::istream & is , string &str);
        friend std::ostream& operator << (std::ostream & os , string &str);
    private:
        char*  data_;
        size_t len_;
    };
}




#endif


