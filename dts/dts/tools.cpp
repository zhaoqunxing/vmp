#include <cstdio>
#include <io.h>
#include <vector>
#include <string>
#include "tools.h"
#include "global.h"
using namespace std;

//����ֵ��
//       ERR��nums����ʮ�������ִ�
//       OK��nums��ʮ�������ִ�
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

//����ֵ��
//       ERR��num����ʮ������
//       OK��num��ʮ��������
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
    //�ļ����  
    long hFile = 0;  
    //�ļ���Ϣ  
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