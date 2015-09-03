#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
using namespace qh;
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

#ifdef WIN32
    system("pause");
#endif
    
    char *p = new char[6];
    p[0] = 'h';
    p[1] = 'e';
    p[2] = 'l';
    p[3] = 'l';
    p[4] = 'o';
    p[5] = '\0';
    std::cout<<"strlen(p)="<<strlen(p)<<std::endl;

    //test ctor
    string str1;
    std::cin>>str1;
    std::cout<<"str1= "<<str1<<",    str1.size()="<<str1.size()<<std::endl;
    string str2(p);
    std::cout<<"str2= "<<str2<<",    str2.size()="<<str2.size()<<std::endl;
    string str3(p,5);
    std::cout<<"str3.c_str()= "<<str3.c_str()<<std::endl;
    std::cout<<"str3.data()= "<<str3.data()<<std::endl;
    
    //test opeartor
    std::cout<<"str1==str3 ? "<<std::boolalpha<<(str1==str3)<<std::endl;
    std::cout<<"str1!=str3 ? "<<std::boolalpha<<(str1!=str3)<<std::endl;
	
    string str4 = str1+str2;
    std::cout<<"str1+str2= "<<str4<<std::endl;
    str1 += ",world!";
    std::cout<<"str1 += ,world = "<<str1<<std::endl;

    
    str1="hello,world";
    str2="hello,worle";
    std::cout<<"str1= "<<str1<<",    str1.size()="<<str1.size()<<std::endl;
    std::cout<<"str2= "<<str2<<",    str1.size()="<<str2.size()<<std::endl;
    std::cout<<"str1 < str2 ? "<<std::boolalpha<<(str1 < str2)<<std::endl;
    std::cout<<"str1 <= str2 ? "<<std::boolalpha<<(str1 <= str2)<<std::endl;
    std::cout<<"str1 > str2 ? "<<std::boolalpha<<(str1 > str2)<<std::endl;
    std::cout<<"str1 >= str2 ? "<<std::boolalpha<<(str1 >= str2)<<std::endl;
    
    for (int i=0 ; i!=str1.size(); i++) {
        std::cout<<"str1["<<i<<"] = "<<(str1[i])<<std::endl;
    }
    //throw exception
    //std::cout<<"str1[12] = "<<(str1[12])<<std::endl;

    return 0;
}

