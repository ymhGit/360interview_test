#include "ini_parser.h"


namespace qh
{
    
    //判断是否是字母
     bool IsLetter(char& c)
    {
        if(c>='a'&&c<='z')
            return true;
        if(c>='A'&&c<='Z')
            return true;
        return false;
    }
    //判断是否是数字
     bool IsDigital(char& c)
    {
        if(c>='0'&&c<='9')
            return true;
        return false;
    }
    //是否是合法的标识符 /
     bool IsIdentifier(char& c)
    {
        if(IsLetter(c) || IsDigital(c) || '_'==c || '.'==c || ' '==c || '-'==c)
            return true;
        return false;
    }
  
    
    bool Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator = "\n", const std::string& key_value_seperator = "=")
    
    {
        
        return true;
    }

}