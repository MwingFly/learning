#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char szBuf[32],szBuf2[50];
    printf("Input string:");
	//fflush(stdout);	//Ҫˢ�±�׼��������ſ�����������Ļ����ʾ��Input  string��
//fflush����linux�е�ʱ��ֻ��fflush(stdout)��Ч��
    int iRet=read(0,szBuf,sizeof(szBuf));
    szBuf[iRet]=0;	//read����������ָ�뷽ʽ�������ݣ������Զ��ڻ��������0������ǡ�
    sprintf(szBuf2,"The string is:%s",szBuf);
    write(1,szBuf2,strlen(szBuf2));
    return 0;
}
