#include"func.h"
void sendfile(int new_fd)
{
        data d;
        memset(&d,0,sizeof(d));
        d.len = strlen(FILENAME);
        strcpy(d.buf,FILENAME);
        int ret = send(new_fd,&d,4+d.len,0);  //�ȷ����ļ������ͻ��ˣ��ͻ��˻������ļ�������һ���µ���ͬ���ֵ��ļ����ļ����ĳ��ȴ����d.len���棬���Է��ͳ��Ⱦ�Ϊ4+d.len;
        if(-1==ret)
        {
                perror("send");
                return  ;
        }
        int fdr = open(FILENAME,O_RDONLY);
        if(-1==fdr)
        {
                perror("open");
                return ;
        }
        while(memset(&d,0,sizeof(d)),(d.len=read(fdr,d.buf,sizeof(d.buf)))>0)
        {
                send_n(new_fd,(char*)&d,4+d.len);
        }
        int flag = 0;  //��־����Ѿ��������ļ���ͻ��˿��ԶϿ�������
        send(new_fd,&flag,sizeof(int),0);
        close(new_fd);
        close(fdr);
}