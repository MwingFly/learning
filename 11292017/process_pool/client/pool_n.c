#include"func.h"
void send_n(int new_fd,char *buf,int len)
{
        int ret;
        int total = 0;
        while(total<len)
        {
                ret = send(new_fd,buf+total,len-total,0); //socket���������д�С�ģ����շ��ͷ��ͷ����Ե�socket����������64K��������շ������ٶȲ�ƥ�䣬��ô�ᵼ�½������ݷ��������������ͷ��ɹ����͵����ݲ�����Ԥ�����ͳ��ȣ�
                total += ret;
        }
}
void recv_n(int new_fd,char *buf,int len)
{
        int ret;
        int total = 0;
        while(total<len)
        {
                ret = recv(new_fd,buf+total,len-total,0);
                total += ret;
        }
}