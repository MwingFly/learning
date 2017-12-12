#include"func.h"
void child_handle(int fds)
{
        int new_fd;
        int flag = 1;
        while(1)
        {
                //printf("wait read new_fd\n");
                read_fd(fds,&new_fd);  //�ӽ��̵ȴ�����main���̷��͹����Ŀͻ����������������newfd;
                sendfile(new_fd);  //��newfd�����ļ����ͻ��ˣ�
                //printf("file send success\n");
                write(fds,&flag,sizeof(int));  //�ļ��������ͨ���ܵ���main���̷���һ�����ݣ�����epoll_wait���ر�new_fd,�����ӽ���״̬��
        }
}
void make_child(pchild p,int num)
{
        int fds[2];
        int ret;
        pid_t pid;
        for(int i=0;i<num;i++)
        {
                ret = socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
                if(-1==ret)
                {
                        perror("socketpair");
                        return ;
                }
                pid = fork();
                if( 0==pid )
                {
                        close(fds[1]);
                        child_handle(fds[0]);
                }
                close(fds[0]);
                p[i].fds = fds[1];
                p[i].pid = pid;
                p[i].status = 0;//�մ����ã�����״̬����æµ��status=0;
        }
}