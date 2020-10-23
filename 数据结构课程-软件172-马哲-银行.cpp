#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define n 3
int vip1=0;
int y,z;
float sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
float i1=0,i2=0,i3=0,i4=0,i5=0;
float ave1=0,ave2=0,ave3=0,ave4=0,ave5=0;

struct List
{
  int A[n+1];           
  int len;              
}L;
struct Lnode
{           
  int data;
  Lnode *next;
};
struct Linkqueue
{       
  Lnode *front;
  Lnode *rear;
}Q;

//1.初始化线性
void Initshuzu()        
{
  for(int i=1;i<=n;i++)
  L.A[i]=0;             
  L.len=0;
}

//13.初始化等待队列
 void Initqueue()     
{
  Q.front=Q.rear=(Lnode *)malloc(sizeof(Lnode));
  Q.front->next=NULL;
}

 //11.等待客户进等待队列
void Enqueue(Linkqueue *Q,int elem)  
{
   Lnode *s;
   s=(Lnode *)malloc(sizeof(Lnode));
   s->data=elem;
   s->next=NULL;
   Q->rear->next=s;
   Q->rear=s;
}

//12.等待队列客户出队
int Dlqueue(Linkqueue *Q) 
{
   Lnode *t;
   int x;
   if(Q->front==Q->rear)
   {
	   printf("队列为空！\n");
	   exit(1);
   }
   else
   {
	   t=Q->front->next;
       Q->front->next=t->next;
       x=t->data;
       free(t);
	   return x;
   }
}

//2.输出办理业务的客户数组
void printl()    
{ 
	int i;
    printf("正在办理业务的顾客编号为：  一号柜台       二号柜台       三号柜台\n");
	printf("                             ");
    for( i=1;i<=L.len;i++)
	{
		printf("%d号客户        ",L.A[i]);
      
	}
	printf("\n"); 
}

//3.输出办理业务排队客户队列
void print2()       
{   int i=0;
    printf("正在等候办理业务的顾客编号为：");
    Lnode *s=Q.front->next;
    while(s!=NULL)
	{
		printf("%d ",s->data);
        s=s->next;
	    i++;
	}
	printf("\n您的前面一共有%d人在排队，请您稍候！",i);
	printf("\n");
}

//4.顾客到达事件算法
void daoda(int x)   
{   
	int i=L.len+1;
	if (L.len<n)   
		{	L.A[i]=x;
			i++;
			L.len++;
	   }
   
    else
    Enqueue(&Q,x);

}

//5.顾客离开事件算法
void likai(int x)        
{  
	int i=0;
	do
	{
		if(x>L.len)
		{	
			printf("输入有误！\n请重新输入：");
			scanf("%d",&x);
		}
		else
		   for(i=0;i<=L.len;i++)
		   {
				if(i==x)
				{
					 printf("尊敬的%d号顾客您好！\n",x);
					 L.A[i]=0;
					 L.len--;
					 if(Q.front!=Q.rear)
					 {
						int y=Dlqueue(&Q);
						L.A[i]=y;
						 L.len++;
					 }
				}

		   }
	}while(i==0);
}

//6.判断输入的柜台号是否正确
int  guitai( )             
{
	int y=0;
    printf("请输入你所办理业务的柜台号（1-3）：\n");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("你输入的柜台号有误，请重新输入！\n");
        printf("请输入你所办理业务的柜台号（1-3）：\n");
	    scanf("%d",&y);
	}
	else
		printf(" 你所办理业务的柜台为%d.\n",y);
	return y;
    
}

//7.判断输入的分数是否正确
int  pingfeng( )             
{
	int y=0;
    printf("请输入你评分（1-5）：\n                    1分…………非常不满意;\n                    2分…………比较不满意；\n                    3分…………一般满意；\n                    4分…………比较满意；\n                    5分…………非常满意。\n");
	printf("请输入：");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("你输入评分有误，请重新输入！\n");
        printf("请输入你的评分（1-5）：\n");
	    scanf("%d",&y);
	}
	else
	    printf(" 你的评分为%d.\n",y);
	return y;
    
}

//8.主评分函数
void mygrade()                   
{  
	printf("为了改善服务质量，请你对我们的服务进行评价。谢谢！\n");
	z=guitai( );
	y=pingfeng( );
    switch (z)              
   {
		case 1:                  
			{
			sum1+=y;
			i1++;
			ave1=sum1/i1;
	        printf(" %d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢！！！\n",z,ave1);
			break;
			}
		case 2:                  
			{
			sum2+=y;
			i2++;
			ave2=sum2/i2;
	        printf(" %d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢！！！\n",z,ave2);
			break;
			}
        case 3:                  
			{
			sum3+=y;
			i3++;
			ave3=sum3/i3;
	        printf(" %d号柜台的平均满意度为%0.2f。感谢你的评分，谢谢！！！\n",z,ave3);
			break;
			}
		
		default : printf("你的输入有误，请重新输入！\n");

	}
    getch();
}

//9.vip用户认证
void vip(int x)               
 {  
	 int i,a; 
	 a=x;
	 char ch[3];
     int k=0;
	 switch(a)
	 {
	 case 1:
		 {
			 printf("请输入你的卡号：");
		     scanf("%d",&i);
             printf("请您输入五位密码：");
			 while(ch[k-1]!=' ')
			 {   
				 ch[k]=getch();
	             k++;
                 printf("*");
			 }
			 if(i==100&&ch[0]=='1'&&ch[1]=='1'&&ch[2]=='1'&&ch[3]=='1')
			 {
				 printf("\n尊敬的VIP用户您好，请您直接到VIP区办理业务！\n");
			     vip1++;
			 }
			 else if(i==200&&ch[0]=='2'&&ch[1]=='2'&&ch[2]=='2'&&ch[3]=='2')
			 {
				 printf("\n尊敬的VIP用户您好，请您直接到VIP区办理业务！\n");
				 vip1++;
			 }
			 else if(i==300&&ch[0]=='3'&&ch[1]=='3'&&ch[2]=='3'&&ch[3]=='3')
			 {
				 printf("\n尊敬的VIP用户您好，请您直接到VIP区办理业务！\n");
				 vip1++;
			 }
			 else if(i==400&&ch[0]=='4'&&ch[1]=='4'&&ch[2]=='4'&&ch[3]=='4')
			 {
				 printf("\n尊敬的VIP用户您好，请您直接到VIP区办理业务！\n");
				 vip1++;
			 }
			 else if(i==500&&ch[0]=='5'&&ch[1]=='5'&&ch[2]=='5'&&ch[3]=='5')
			 {
				 printf("\n尊敬的VIP用户您好，请您直接到VIP区办理业务！\n");
			     vip1++;
			 }
			 else printf("\n你的输入有误！\n");
			 break;
		 }
	 default : break;		
	 }	 
 }

//10.时间函数
void time()         
{ 
    time_t timep;
    time (&timep);
     printf("                      现在时刻：%s",ctime(&timep));
}

//14.主函数

int main()            
{
	system("color 3f");                            
    system("mode con: cols=90 lines=30"); 
	time_t  a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,end;   
	double  b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b10=0,allsum=0,average=0,xi=0;
	double A[10]={0,0,0,0,0,0,0,0,0,0};
    int c,x,v=0,w=0;
    Initshuzu();
    Initqueue();
    double sum=0;
    while(1)
	{  
      printf("\n********************************欢迎光临中国银行******************************************\n");
	  printf("\n                                                                                      \n");
      printf("                            1      顾客到达\n");
      printf("                            2      顾客离开\n");
      printf("                            3      查看业务办理\n");
      printf("                            4      查看排队情况\n");
	  printf("                            5      系统查询\n");
      printf("                            6      退出\n\n");
	  time();
      printf("\n                          提示：请按回车键进行下一步操作\n");
	  printf("\n                                                                                      \n");
	  printf("********************************欢迎光临中国银行******************************************\n");
	  printf("请输入：");
      scanf("%d",&c);
	  switch(c)
	  {
	  case 1:
		  {
			  system("cls");
		      printf("\n*********************************顾客到达界面*****************************************\n\n");
		      int k=0;
	          int a; 
	          printf("请选择你的用户类型：VIP用户请按 1;\n                    普通卡用户请按2;\n                    特殊用户请按3;\n");
		      printf("请输入：");
	          scanf("%d",&a);
	          if (a==1)
			  {  
				  vip(a);
				  getch();
			  } 
			  else if(a==2)
			  {	
				  v++;            //普通卡顾客计数
				  printf("尊敬的普通卡用户，你的业务号为%d.\n",v);
				  daoda(v);
				  if(v==1)
				  {
					  a1=time(NULL);     //v=1的客户到达时间
					  system("pause");
				  }	
				  else if(v==2)
				  {
					  a2=time(NULL);
					  system("pause");
				  }
				  else if(v==3)
				  {
					  a3=time(NULL);
				      system("pause");
				  }
				  else if(v==4)
				  {
					  a4=time(NULL);
				      system("pause");
				  }
		          else if(v==5)
				  {
				      a5=time(NULL);
				      system("pause");
				  }
				  else if(v==6)
				  {
				      a6=time(NULL);
				      system("pause");
				  }
		          else if(v==7)
				  {
				      a7=time(NULL);
				      system("pause");
				  }
		          else if(v==8)
				  {
				      a8=time(NULL);
				      system("pause");
				  }
		   
		          else if(v==9)
				  {
				      a9=time(NULL);
				      system("pause");
				  }
		          else if(v==10)
				  {
				      a10=time(NULL);
				      system("pause");
				  }
		          else 
				  {
					  printf("请稍候拿号,谢谢！");
					  system("pause");
				  }
			  }
            else if(a==3)
                           {	
				  v++;            //普通卡顾客计数
				  printf("尊敬的特殊用户，你的业务号为%d.\n",v);
				  daoda(v);
				  if(v==1)
				  {
					  a1=time(NULL);     //v=1的客户到达时间
					  system("pause");
				  }	
				  else if(v==2)
				  {
					  a2=time(NULL);
					  system("pause");
				  }
				  else if(v==3)
				  {
					  a3=time(NULL);
				      system("pause");
				  }
                                  else 
				  {
					  printf("请稍候拿号,谢谢！");
					  system("pause");
				  }
			  }
			  system("cls");
			  break;
		  }
	  case 2:
		  {
			  system("cls");
              printf("\n************************************顾客离开界面******************************************\n\n");
              printf("请输入离开顾客得编号：\n");
              scanf("%d",&x);
              likai(x);
              mygrade() ;
	          w++;
	          if(x=1)
			  {
				  end=time(NULL);
		          A[0]=difftime(end,a1);
		          printf("                     您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a1));
			  }
			  else if(x=2)
			  {
				  end=time(NULL);
		          A[1]=difftime(end,a2);
		          printf("                     您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a2));
			  }
			  else if(x=3)
			  {
		          end=time(NULL);
		          A[2]=difftime(end,a3);
		          printf("                     您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a3));
			  }
	          else if(x=4)
			  {
		          end=time(NULL);
		          A[3]=difftime(end,a4);
		          printf("                     您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a4));
			  }
	          else if(x=5)
			  {
		          end=time(NULL);
		          A[4]=difftime(end,a5);
		          printf("                    您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a5));
			  }
	          else if(x=6)
			  {
		          end=time(NULL);
		          A[5]=difftime(end,a6);
		          printf("                    您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a6));
			  }
	         else if(x=7)
			 {
		          end=time(NULL);
		          A[6]=difftime(end,a7);
		          printf("                    您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a7));
			 }
	         else if(x=8)
			 {
		          end=time(NULL);
		          A[7]=difftime(end,a8);
		          printf("                    您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a8));
			 }
	         else if(x=9)
			 {
		          end=time(NULL);
		          A[8]=difftime(end,a9);
		          printf("                    您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a9));
			 }
	         else if(x=10)
			 {
		          end=time(NULL);
		          A[9]=difftime(end,a10);
		          printf("                    您办理业务所用时间为 %0.2f 秒.\n",difftime(end,a10));
			 }
			 allsum+=A[0];
			 getch();
			 system("cls");
			 break;
		  }
	  case 3:
		  {   
			  system("cls");
	          printf("\n***********************************业务查询界面*******************************************\n\n");
              printl();
	          getch();
	          system("cls");
              break;
	   
		  }
	  case 4:
		  {
			  system("cls");
	          printf("\n**********************************排队查询界面*******************************************\n\n");
              print2();
	          getch();
	          system("cls");
              break;
		  }
	  case 5:
		  {   
			  system("cls");
	          printf("\n*************************************系统查询界面*****************************************\n\n");
		      char cool[3];
		      int i=0,k=0;
		      printf("请输入你的卡号：");
		      scanf("%d",&i);
              printf("请您输入五位密码：");
		      while(cool[k-1]!=' ')
			  {   
				  cool[k]=getch();
	              k++;
                  printf("*");
			  }
			  if(i==000&&cool[0]=='1'&&cool[1]=='1'&&cool[2]=='1'&&cool[3]=='1')
			  {	
				  average=allsum/w;
		          printf("\n至今已有 %d 位普通用户，%d 位vip用户成功办理业务!",w,vip1);
		          printf("\n普通用户业务办理总共用时 %0.2f秒,平均用时 %0.2f秒\n",allsum,average);
			  }
			  getch();
	          
			  break;
		  }
		 return 0;
		  
		  getch();
		  system("cls");
	  case 6:
		 return 0;
		  getch();
		  system("cls");
	  default: printf("输入有误！请重新输入：\n");
		  getch();
		  system("cls");
    }
  }
}
