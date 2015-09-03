#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
        //
        if ( !s) {
            this->data_ = 0;
            len_ = 0;
        }
        else{
            this->len_ = strlen(s);
            this->data_ = new char[len_+1];
            strcpy(this->data_, s);
        }
    }

    string::string( const char* s, size_t len )
    {
        if ( !s) {
            this->data_ = 0;
            len_ = 0;
        }
        else{
            this->len_ = len;
            this->data_ = new char[len_+1];
            memcpy(this->data_, s ,len);
            this->data_[len] = '\0';
        }
    }

    string::string( const string& rhs )
    {
        if ( !rhs.data_) {
            this->data_ = 0;
        }
        else {
            this->data_ = new char [strlen(rhs.data_)+1];
            strcpy(this->data_, rhs.data_);
        }
    }

    string& string::operator = ( const string& rhs )
    {
        if (this != &rhs ) {
            delete[] this->data_;
            if( !rhs.data_ ){
                this->data_ = 0;
                this->len_ = 0;
            }else {
                this->data_ = new char [strlen(rhs.data_)+1];
                strcpy(this->data_, rhs.data_);
                this->len_ = rhs.len_;
            }
        }
        return *this;
    }

    string::~string()
    {
        if( !this->data_){
            delete[] this->data_;
            this->data_ = 0;
        }
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return this->data_;
    }

    const char* string::c_str() const
    {
        return this->data_;
    }

    char& string::operator[]( size_t index )
    {
        if ( index <= len_) {
            return this->data_[index];
        }
        throw ;
    }
    
    bool string::operator == (const string& rhs)
    {
        if (len_ != rhs.len_) {
            return false;
        }
        return strcmp(this->data_, rhs.data_) ? false:true;
    }
    
    bool string::operator != (const string& rhs)
    {
        return !(*this == rhs);
    }
    
    bool string::operator < (const string& rhs)
    {
        if (this->len_ < rhs.len_) {
            return true;
        }else if(this->len_ > rhs.len_){
            return false;
        }else{
            char *p1 = this->data_;
            char *p2 = rhs.data_;
            while (*p1 != '\0' && *p2 != '\0') {
                if (*p1 < *p2) {
                    return true;
                }else if(*p1 > *p2){
                    return false;
                }
                p1++;
                p2++;
            }
            
            if (*p1 =='\0' && *p2 !='\0') {
                return true;
            }else return false;
        }
    }
    
    bool string::operator <= (const string& rhs)
    {
        if (*this < rhs || *this == rhs) {
            return true;
        }else return false;
    }
    
    bool string::operator > (const string& rhs)
    {
        return !(*this <= rhs);
    }
    
    bool string::operator >= (const string& rhs)
    {
        return  !(*this < rhs);
    }
    
    string string::operator + (const string& rhs)
    {
        string newStr(*this);
        return newStr += rhs;
        
    }
    
    string& string::operator += (const string& rhs)
    {
        if ( rhs.data_) {
            this->len_ =strlen(this->data_) + strlen(rhs.data_);
            char *temp = new char[this->len_ +1];
            strcpy(temp, this->data_);
            strcat(temp, rhs.data_);
            temp[this->len_ ]='\0';
            delete[]    this->data_;
            this->data_=temp;
        }
        return *this;
    }
    
    std::istream& operator >> (std::istream & is , string &str)
    {
        char charInput[256];
        is >> charInput;
        str.len_ = strlen(charInput);
        str.data_ = new char[str.len_+1];
        strcpy(str.data_, charInput);
        return is;
    }
    
    std::ostream& operator << (std::ostream & os , string &str)
    {
        if(str.data_ != nullptr)
            os << str.data_;
        return os;
    }
}
