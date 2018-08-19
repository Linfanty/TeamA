/*************************************************************************
	> File Name: serverfun.h
	> Author: 
	> Mail: 
	> Created Time: 2018年08月17日 星期五 08时32分50秒
 ************************************************************************/

#ifndef _SERVERFUN_H
#define _SERVERFUN_H
#endif
extern MYSQL *mysql;


typedef struct smessage
{
	int  type;  

	int  user_ID;

	char ac_number[30];
	char user_name[30];
	char user_password[30];
	char message[50];          //聊天信息

	int  si_ID;

	int  group_ID;
	char  fileblock;
	int   blocknum;
}smg;

struct rmessage
{
	int type;
	int user_ID;
	char f_sum[200];
	char message[50];
	char f_id[200];
	char f_name[200];
	char f_state[200];
	int f_num;
};

//多线程用法

typedef struct date
{
	char *message;
	int connfd;
}dcan;


//ZH_CE系函数
int database(char *ac,char *pa,char *usr);   //将创建的用户信息写入数据库函数

//void analyse(char *message,int connfd);
void analyse(void *wokao);         //多线程用法

void zhuce_sr(smg *ff,cJSON *user,int connfd);

void denglu_sr(smg *ff,cJSON *user,int connfd);

int bidatabase(char *ac,char *pa,int *user_ID,int connfd);

void friend_f5_sr(smg *ff,cJSON *user,int connfd);

int fetch_state_byID(int *num,int *xb,int connfd);

int fetch_friend_byID(int user_ID,int *num,int *xb);

void chat_pn_sr(smg *ff,cJSON *user,int connfd); //向好友发送聊天信息