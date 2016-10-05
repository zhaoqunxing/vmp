#include <cstdio>
#include <io.h>
#include <vector>
#include <string>
#include "tools.h"
#include "global.h"
using namespace std;

//返回值：
//       ERR，nums不是十进制数字串
//       OK，nums是十进制数字串
INT checkFormatOfDecNums(const string & nums)
{
	UINT index =0;
	while(index < nums.size())
	{
		if('0' > nums[index] || '9' < nums[index])
		{
			return ERR;
		}
		++index;
	}
	return OK;
}

//返回值：
//       ERR，num不是十进制数
//       OK，num是十进制数字
INT checkFormatOfDecNum(char num)
{
	if('0' > num || '9' < num)
	{
		return ERR;
	}
	return OK;
}

void getFiles( string path, vector<string>& files )  
{  
    //文件句柄  
    long hFile = 0;  
    //文件信息  
    struct _finddata_t fileinfo;  
    string p;  
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)  
    {  
        do  
        {  
            if((fileinfo.attrib &  _A_SUBDIR))  
            {  
				continue;
                //if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
                //    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
            }  
            else  
            {  
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
            }  
        }while(_findnext(hFile, &fileinfo)  == 0);  
        _findclose(hFile);  
    }  
}  