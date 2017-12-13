#include"func.h"
int main(int argc,char **argv)
{       
        if(4!=argc)
        {
                printf("error argcs\n");
                return -1;
        }
        int sfd = socket(AF_INET,SOCK_STREAM,0);
        if(-1==sfd)
        {
                perror("socket");
                return -1;
        }
        int num = atoi(argv[3]);
        struct sockaddr_in ser;
        bzero(&ser,sizeof(ser));
        ser.sin_port = htons(atoi(argv[2]));
        ser.sin_addr.s_addr = inet_addr(argv[1]);
        ser.sin_family = AF_INET;
        int ret = bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
        if(-1==ret)
        {
                perror("bind");
                return -1;
        }
        ret = listen(sfd,num);
        if(-1==ret)
        {
                perror("listen");
                return -1;
        }
        //ע����������sfd�ʹ����õ��ӽ��̶�Ӧ�ĸ����̶˵Ĺܵ�
        int epfd  = epoll_create(1);
        if(-1==epfd)
        {
                perror("epoll_create");
                return -1;
        }
        struct epoll_event eve,eves[num+1];  //num�����ӵ��ӽ��̵Ĺܵ���һ��sfd
        bzero(&eve,sizeof(eve));
        eve.events = EPOLLIN;
        eve.data.fd = sfd;
        ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&eve);
        if(-1==ret)
        {
                perror("epoll_ctl");
                return -1;
        }
        //�����ӽ���
        pchild p = (pchild)calloc(num,sizeof(child));
        make_child(p,num);
        for(int i=0;i<num;i++)
        {
                bzero(&eve,sizeof(eve));
                eve.events = EPOLLIN;
                eve.data.fd = p[i].fds;
                epoll_ctl(epfd,EPOLL_CTL_ADD,p[i].fds,&eve);
        }
        int new_fd;
        int flag;
        int j = 0;
        int i;
        while(1)
        {
                memset(eves,0,(num+1)*sizeof(eve));
                //bzero(eves,(num+1)*sizeof(eve));
                ret = epoll_wait(epfd,eves,num+1,-1);
                if(ret>0)
                {
                        for(i=0;i<ret;i++)
                        {
                                if(eves[i].data.fd == sfd)
                                {
                                        new_fd = accept(sfd,NULL,NULL);
                                        //printf("new_fd =%d\n",new_fd);
                                        for(j=0;j<num;j++)
                                        {
                                                if(p[j].status == 0)
                                                {
                                                        break;
                                                }
                                        }
                                        send_fd(p[j].fds,new_fd);
                                        p[j].status = 1;
                                        close(new_fd);  //new_fd�Ѿ����͸������ӽ��̣�main���̲�����Ҫnew_fd
                                        //printf("find leisure process , and send new_fd success\n");
                                }
                                for(j=0;j<num;j++)
                                {
                                        if(eves[i].data.fd == p[j].fds)
                                        {
                                                read(p[j].fds,&flag,sizeof(int));
                                                p[j].status = 0;
                                                //printf("p[%d].fds = %d , is not busy\n",j,p[j].fds);
                                        }
                                }
                        }
                }
        }
        return 0;
}