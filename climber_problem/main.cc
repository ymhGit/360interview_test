#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define H_ARRAYSIZE(a) \
((sizeof(a) / sizeof(*(a))) / \
static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

struct mountain{
    int begin;
    int end;
    int height;
};

//全局变量，表示输入是否有效
bool isValidInput=true;

//char转int，可以处理大于10的，超过int最大值会出错
//使用**作为参数，是因为指针要向前移动，需要更改指针的指向
int charToInt(const char **pchar){
    int result = 0;
    isValidInput = false;
    if ( pchar != nullptr && *pchar != nullptr) {
        while ((*pchar)[0] < '0' || (*pchar)[0] > '9') {
            (*pchar)++;
        }
        while ((*pchar)[0] >= '0' && (*pchar)[0] <= '9') {
            result *=10;
            result +=(*pchar)[0] -'0';
            (*pchar)++;
        }
        isValidInput = true;
    }
    //异常输入，返回0，isValidInput为false
    return result;
}

//求解步长，遇到山峰要climb up和climb down
int resolve(const char* input)
{
    if (input == NULL) {
        return 0;
    }
    
    //读取输入数据数量
    int mountainNums = charToInt( &input);
    
    if(!mountainNums)
        return 0;
    
    //存储输入数据
    vector<mountain*> mountainData;
    mountainData.resize(mountainNums);
    
    int begin=0,end=0,height=0;
    
    //最右边的点(x,0)
    int rightPointX = 0;
    
    for(int i = 0 ; i != mountainNums ; i++){
        // 开辟内存存储mountain数据
        mountain *pm=(mountain *)malloc(sizeof(mountain));
        int temp=0;
        temp=charToInt( &input );
        if (isValidInput) {
            pm->begin = temp;
        }else{
            delete pm;
            break;
        }
        temp=charToInt( &input );
        if (isValidInput) {
            pm->end = temp;
        }else{
            delete pm;
            break;
        }
        temp=charToInt( &input );
        if (isValidInput) {
            pm->height = temp;
        }else{
            delete pm;
            break;
        }
        
        mountainData[i]=pm;
        if (pm->end > rightPointX) {
            rightPointX = pm->end;
        }
    }
    
    //创建柱的数量，rightPointX+2，y轴移动rightPointX+1次
    int *maxHeight = new int[rightPointX+2];

    for(int i=0 ; i!=rightPointX+2 ; i++)
	maxHeight[i]=0;
  
    //计算每一个柱的最大高度
    for (auto iter = mountainData.cbegin(); iter != mountainData.cend(); iter++) {
        begin = (*iter)->begin;
        end = (*iter)->end;
        height = (*iter)->height;
        for (; begin < end; begin++) {
            if (maxHeight[begin+1] < height) {
                maxHeight[begin+1] = height;
            }
        }
    }
    
    //结果＝x轴移动长度＋y轴移动长度
    int result = rightPointX;
    
    for (int i=1; i < rightPointX+2; i++) {
//        cout<<maxHeight[i]<<"--"<<maxHeight[i-1]<<endl;
        //y轴移动长度
        result += abs(maxHeight[i]-maxHeight[i-1]);
//        cout<<"result="<<result<<endl;
    }
    
    //回收内存
    for (auto iter = mountainData.cbegin(); iter != mountainData.cend(); ) {
        delete (*iter);
        mountainData.erase(iter);
    }
    
    //回收内存
    delete [] maxHeight;
    return result;
}

int main(int argc, char* argv[])
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        "6\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3\n9,11,2",
        "0\n123dsas",
        "1\n1,12,10"
        //TODO please add more test case here
    };
    
    //"1\n1,a,b"会使程序出错，源于对输入不合法的判定失败，暂没想到怎么处理
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20,27,0,32};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    cout<<"accept"<<endl;
    return 0;
}
