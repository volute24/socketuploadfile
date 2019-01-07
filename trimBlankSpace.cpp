#include <stdio.h>
#include<ctype.h>
#include <string.h>
#include <stdlib.h>

void length()
{
	int arr[] = {1,2,3,4,5};
	char c[] = "hello world";
	printf("array of length:%d\n",sizeof(arr)/sizeof(int));
	printf("chacter of length:%d\n",sizeof(c)/sizeof(char));	
}

//时间复杂度O(n)
int trimBlankSpace(char *src)
{
    char *pTmp = src;
    unsigned int iSpace = 0;
 
    while (*src != '\0') 
	{
        if (*src != ' ')
		{
            *pTmp++ = *src;
        } 
		else 
		{
            iSpace++;
        }
 
        src++;
    }
    *pTmp = '\0';
    return iSpace;
}

//时间复杂度 O2
int delspace()
{
	char s1[] ="NI h a o zho  ng qiu";
	int n=strlen(s1);

	printf("strlen(s1)=%d\n",n);
	int i=0;
	int space = 0;
	int j=0;
	for(i=0;i<n;i++)
	{

		//判断当前字符是否是空格
		if(isspace(s1[i+space]))
		{
			space+=1;
			j=(i+space);
			//判断当前字符后续是否有连续空格
			while(s1[j]==' ')
			{
				j++;
				space+=1;
			}
		}

		//将后续字符往前挪动
		s1[i] = s1[i+space];
	}
	
	printf("%s\n",s1);
	
}
int main(int argc,char* argv[])
{

	length();
	
	char *dst =NULL;
	char *p;
	int spacenum = 0;
	char s[]="hello wo rld";
	int cnt = strlen(s);
	dst = s;
	dst = (char *)malloc(cnt);
	free(dst);
	dst = NULL;
	//free(dst);
	//删除空格 O(n)
	printf("dst of strlen:%d\ndst:%s,strlen(s):%d\n",strlen(dst),dst,cnt);
	spacenum = trimBlankSpace(dst);
	printf("trim blank space after:%s\n space num:%d\n",dst,spacenum);
	//删除空格 O2
	delspace();
	
	return 0;
}

