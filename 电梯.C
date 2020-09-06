#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include<conio.h>
#include<time.h>
int Rnow=1,Pnow=1,toW,Dy[10]={0,0,0,0,0,0,0,0,0},x[100]={0},timedown=0,timeup=0,timep=0,k=0,y=0;
void * print_a(void *);
void * print_b(void *);

void sleep(int s)
{
  time_t tmp1=time(NULL);
	time_t tmp2=tmp1;
	while(difftime(tmp2,tmp1)<s)//延时s秒后结束
	{
	   tmp2=time(NULL);
	}
}

int main(){
    pthread_t t0;
    pthread_t t1;

    // 创建线程A
    if(pthread_create(&t0, NULL, print_a, NULL) == -1){
        puts("fail to create pthread t0");
        exit(1);
    }

    if(pthread_create(&t1, NULL, print_b, NULL) == -1){
        puts("fail to create pthread t1");
        exit(1);
    }

    // 等待线程结束
    void * result;
    if(pthread_join(t0, &result) == -1){
        puts("fail to recollect t0");
        exit(1);
    }

    if(pthread_join(t1, &result) == -1){
        puts("fail to recollect t1");
        exit(1);
    }


    return 0;
}


// 线程A 方法
void * print_a(void *a){

   int j,w;
   while(1){

scanf("%d",&j);

toW=j;

x[k]=j;

Dy[toW-1]=1;

if(x[k]!=0)

k++;

if(k>2&&x[k-1]<x[k-2]&&x[k-1]>=x[k-3]){w=x[k-2];x[k-2]=x[k-1];x[k-1]=w;}

sleep(1);
          }
    return NULL;

}



void tele(int i,int x) //上楼
{
  int dif,M[10]={0,0,0,0,0,0,0,0,0},j=0;

  dif=x-Rnow;



  switch(dif)
  {

 case -8:;
 case -7:;
 case -6:;
 case -5:;
 case -4:;
 case -3:;
 case -2:Rnow=Pnow-(i-1)/6;printf("现在楼层：%d\n",Rnow);if(i<=2)printf("    状态：closed-accelerate\n");else printf("    状态：closed-move\n");break;
 case -1:Rnow=Pnow-(i-1)/6;printf("现在楼层：%d\n",Rnow);timedown++;
        switch(timedown){
        case 0:;
        case 1:if(i<=2)printf("    状态：closed-accelerate\n");else printf("    状态：closed-move\n");break;
        case 2:;
        case 3:printf("    状态：closed-move\n");break;
        case 4:;
        case 5:printf("    状态：closed-decelerate\n");break;
                         }break;
 case  0:timeup++;printf("现在楼层：%d\n",Rnow);printf("    状态：");Dy[Rnow-1]=0;
        switch(timeup){
        case 0:;
        case 1:;
        case 2:if(Rnow!=1)printf("opening-wait\n");else printf("\n");break;
        case 3:;
        case 4:;
        case 5:;
        case 6:if(Rnow!=1)printf("opened-wait\n");else printf("\n");break;
        case 7:;
        case 8:if(Rnow!=1)printf("closing-wait\n");else printf("\n");break;
             }break;
 case 1:Rnow=(i-1)/5+Pnow;printf("现在楼层：%d\n",Rnow);timep++;
        switch(timep){
        case 0:;
        case 1:if(i<=2)printf("    状态：closed-accelerate\n");else printf("    状态：closed-move\n");break;
        case 2:;
        case 3:printf("    状态：closed-move\n");break;
        case 4:;
        case 5:printf("    状态：closed-decelerate\n");break;}break;
 case 2:;
 case 3:;
 case 4:;
 case 5:;
 case 6:;
 case 7:;
 case 8:Rnow=(i-1)/5+Pnow;printf("现在楼层：%d\n",Rnow);if(i<=2)printf("    状态：closed-accelerate\n");else printf("    状态：closed-move\n");break;
    }

M[Rnow-1]=(M[Rnow-1]+1)%2;
for(j;j<9;j++){
    printf(" %d",M[j]);
}
j=0;
printf("\n");
for(j;j<9;j++){
    printf(" %d",Dy[j]);
}
}

void Tup(int i ,int x)
{

	while(i)
	{
        printf("目标楼层：%d\n运行时间：%d s\n",x,i++);


		tele(i,x);


		printf("\n请输入目标楼层：");

		sleep(1);

		system("cls"); //清屏

	    if(timeup==8)break;
	}

	timeup=0;timep=0;timedown=0;Pnow=Rnow;

}

void Twait()
{
while(1){
if(x[k-1]!=0)
    break;
else{
printf("waiting");
sleep(1);
system("cls");
    }
        }
}

void Swait()
{int i=0;
while(1){
if(x[y]!=0)
    break;
else{
printf("waiting:%d s",i++);
if(i==30)x[y]=1;
sleep(1);
system("cls");
    }
        }
}
// 线程B 方法
void * print_b(void *b){
int i=1;



   while(1)
    {
    Twait();
    Tup(i,x[y]);
     y++;
     Swait();

    }

   return NULL;
}


