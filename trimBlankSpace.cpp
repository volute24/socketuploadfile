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

//ʱ�临�Ӷ�O(n)
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

//ʱ�临�Ӷ� O2
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

		//�жϵ�ǰ�ַ��Ƿ��ǿո�
		if(isspace(s1[i+space]))
		{
			space+=1;
			j=(i+space);
			//�жϵ�ǰ�ַ������Ƿ��������ո�
			while(s1[j]==' ')
			{
				j++;
				space+=1;
			}
		}

		//�������ַ���ǰŲ��
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
	//ɾ���ո� O(n)
	printf("dst of strlen:%d\ndst:%s,strlen(s):%d\n",strlen(dst),dst,cnt);
	spacenum = trimBlankSpace(dst);
	printf("trim blank space after:%s\n space num:%d\n",dst,spacenum);
	//ɾ���ո� O2
	delspace();
	
	return 0;
}

