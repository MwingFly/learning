#include"func.h"
void send_fd(int fds,int fd)
{
        struct msghdr msg;
        struct iovec iov[2];
        char buf1[6] = "hello";
        char buf2[6] = "world";
        iov[0].iov_base = buf1;
        iov[0].iov_len = strlen(buf1);
        iov[1].iov_base = buf2;
        iov[1].iov_len = strlen(buf2);

        struct cmsghdr *cmsg;
        int len = CMSG_LEN(sizeof(int));   //����Ҫ���ݵ���һ�����ε�������
        cmsg = (struct cmsghdr*)calloc(1,len);
        cmsg->cmsg_len = len;
        cmsg->cmsg_level = SOL_SOCKET;
        cmsg->cmsg_type = SCM_RIGHTS;
        int *fdptr;
        fdptr = (int *)CMSG_DATA(cmsg);
        *fdptr = fd;

        bzero(&msg,sizeof(msg));
        msg.msg_iov = iov;
        msg.msg_iovlen = 2;
        msg.msg_control = cmsg;
        msg.msg_controllen = len;

        int ret = sendmsg(fds,&msg,0);
        if(-1==ret)
        {
                perror("sendmsg");
                return ;
        }
        free(cmsg);
        return ;
}
void read_fd(int fds,int *fd)
{
        struct msghdr msg;
        bzero(&msg,sizeof(msg));
        //char buf1[6] = "";
        char buf1[6] = {0};
        //char buf2[6] = "";
        char buf2[6] = {0};
        struct iovec iov[2];
        iov[0].iov_base = buf1;
        //iov[0].iov_len = strlen(buf1);
        //�ʼ����Ϊ����д�˳��ȣ�ǰ��ֱ�Ӹ�ֵ��""�������ӽ�����read_fd��ʱ���ܹ���ס���ȴ�����main���̽��յ��µ�new_fd���͹�������ǰ����д��С���Ӳ��Թ���������Լ�����Ŷ�λ�����������������ˣ��������ں˿�����Ϣ������ԭ��Ҳ��������߱���Ҫ�����ݣ����ż��������ǲ����ܽ��յ����淢�������ݣ�
        iov[0].iov_len = sizeof(buf1);
        iov[1].iov_base = buf2;
        //iov[1].iov_len = strlen(buf2);
        iov[1].iov_len = sizeof(buf2);

        struct cmsghdr *cmsg;
        int len = CMSG_LEN(sizeof(int));
        cmsg = (struct cmsghdr*)calloc(1,len);
        cmsg->cmsg_len = len;
        cmsg->cmsg_level = SOL_SOCKET;
        cmsg->cmsg_type = SCM_RIGHTS;

        bzero(&msg,sizeof(msg));
        msg.msg_iov = iov;
        msg.msg_iovlen = 2;
        msg.msg_control = cmsg;
        msg.msg_controllen = len;

        int ret = recvmsg(fds,&msg,0);
        if(-1==ret)
        {
                perror("recvmsg");
                return ;
        }
        *fd = *(int *)CMSG_DATA(cmsg);
        //printf("buf1=%s buf2=%s\n",buf1,buf2);
        free(cmsg);
        return;
}