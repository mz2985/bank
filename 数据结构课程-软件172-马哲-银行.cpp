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

//1.��ʼ������
void Initshuzu()        
{
  for(int i=1;i<=n;i++)
  L.A[i]=0;             
  L.len=0;
}

//13.��ʼ���ȴ�����
 void Initqueue()     
{
  Q.front=Q.rear=(Lnode *)malloc(sizeof(Lnode));
  Q.front->next=NULL;
}

 //11.�ȴ��ͻ����ȴ�����
void Enqueue(Linkqueue *Q,int elem)  
{
   Lnode *s;
   s=(Lnode *)malloc(sizeof(Lnode));
   s->data=elem;
   s->next=NULL;
   Q->rear->next=s;
   Q->rear=s;
}

//12.�ȴ����пͻ�����
int Dlqueue(Linkqueue *Q) 
{
   Lnode *t;
   int x;
   if(Q->front==Q->rear)
   {
	   printf("����Ϊ�գ�\n");
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

//2.�������ҵ��Ŀͻ�����
void printl()    
{ 
	int i;
    printf("���ڰ���ҵ��Ĺ˿ͱ��Ϊ��  һ�Ź�̨       ���Ź�̨       ���Ź�̨\n");
	printf("                             ");
    for( i=1;i<=L.len;i++)
	{
		printf("%d�ſͻ�        ",L.A[i]);
      
	}
	printf("\n"); 
}

//3.�������ҵ���Ŷӿͻ�����
void print2()       
{   int i=0;
    printf("���ڵȺ����ҵ��Ĺ˿ͱ��Ϊ��");
    Lnode *s=Q.front->next;
    while(s!=NULL)
	{
		printf("%d ",s->data);
        s=s->next;
	    i++;
	}
	printf("\n����ǰ��һ����%d�����Ŷӣ������Ժ�",i);
	printf("\n");
}

//4.�˿͵����¼��㷨
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

//5.�˿��뿪�¼��㷨
void likai(int x)        
{  
	int i=0;
	do
	{
		if(x>L.len)
		{	
			printf("��������\n���������룺");
			scanf("%d",&x);
		}
		else
		   for(i=0;i<=L.len;i++)
		   {
				if(i==x)
				{
					 printf("�𾴵�%d�Ź˿����ã�\n",x);
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

//6.�ж�����Ĺ�̨���Ƿ���ȷ
int  guitai( )             
{
	int y=0;
    printf("��������������ҵ��Ĺ�̨�ţ�1-3����\n");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("������Ĺ�̨���������������룡\n");
        printf("��������������ҵ��Ĺ�̨�ţ�1-3����\n");
	    scanf("%d",&y);
	}
	else
		printf(" ��������ҵ��Ĺ�̨Ϊ%d.\n",y);
	return y;
    
}

//7.�ж�����ķ����Ƿ���ȷ
int  pingfeng( )             
{
	int y=0;
    printf("�����������֣�1-5����\n                    1�֡��������ǳ�������;\n                    2�֡��������Ƚϲ����⣻\n                    3�֡�������һ�����⣻\n                    4�֡��������Ƚ����⣻\n                    5�֡��������ǳ����⡣\n");
	printf("�����룺");
	scanf("%d",&y);
	if(y<1||y>5)
	{
		printf("�����������������������룡\n");
        printf("������������֣�1-5����\n");
	    scanf("%d",&y);
	}
	else
	    printf(" �������Ϊ%d.\n",y);
	return y;
    
}

//8.�����ֺ���
void mygrade()                   
{  
	printf("Ϊ�˸��Ʒ�����������������ǵķ���������ۡ�лл��\n");
	z=guitai( );
	y=pingfeng( );
    switch (z)              
   {
		case 1:                  
			{
			sum1+=y;
			i1++;
			ave1=sum1/i1;
	        printf(" %d�Ź�̨��ƽ�������Ϊ%0.2f����л������֣�лл������\n",z,ave1);
			break;
			}
		case 2:                  
			{
			sum2+=y;
			i2++;
			ave2=sum2/i2;
	        printf(" %d�Ź�̨��ƽ�������Ϊ%0.2f����л������֣�лл������\n",z,ave2);
			break;
			}
        case 3:                  
			{
			sum3+=y;
			i3++;
			ave3=sum3/i3;
	        printf(" %d�Ź�̨��ƽ�������Ϊ%0.2f����л������֣�лл������\n",z,ave3);
			break;
			}
		
		default : printf("��������������������룡\n");

	}
    getch();
}

//9.vip�û���֤
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
			 printf("��������Ŀ��ţ�");
		     scanf("%d",&i);
             printf("����������λ���룺");
			 while(ch[k-1]!=' ')
			 {   
				 ch[k]=getch();
	             k++;
                 printf("*");
			 }
			 if(i==100&&ch[0]=='1'&&ch[1]=='1'&&ch[2]=='1'&&ch[3]=='1')
			 {
				 printf("\n�𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
			     vip1++;
			 }
			 else if(i==200&&ch[0]=='2'&&ch[1]=='2'&&ch[2]=='2'&&ch[3]=='2')
			 {
				 printf("\n�𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
				 vip1++;
			 }
			 else if(i==300&&ch[0]=='3'&&ch[1]=='3'&&ch[2]=='3'&&ch[3]=='3')
			 {
				 printf("\n�𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
				 vip1++;
			 }
			 else if(i==400&&ch[0]=='4'&&ch[1]=='4'&&ch[2]=='4'&&ch[3]=='4')
			 {
				 printf("\n�𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
				 vip1++;
			 }
			 else if(i==500&&ch[0]=='5'&&ch[1]=='5'&&ch[2]=='5'&&ch[3]=='5')
			 {
				 printf("\n�𾴵�VIP�û����ã�����ֱ�ӵ�VIP������ҵ��\n");
			     vip1++;
			 }
			 else printf("\n�����������\n");
			 break;
		 }
	 default : break;		
	 }	 
 }

//10.ʱ�亯��
void time()         
{ 
    time_t timep;
    time (&timep);
     printf("                      ����ʱ�̣�%s",ctime(&timep));
}

//14.������

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
      printf("\n********************************��ӭ�����й�����******************************************\n");
	  printf("\n                                                                                      \n");
      printf("                            1      �˿͵���\n");
      printf("                            2      �˿��뿪\n");
      printf("                            3      �鿴ҵ�����\n");
      printf("                            4      �鿴�Ŷ����\n");
	  printf("                            5      ϵͳ��ѯ\n");
      printf("                            6      �˳�\n\n");
	  time();
      printf("\n                          ��ʾ���밴�س���������һ������\n");
	  printf("\n                                                                                      \n");
	  printf("********************************��ӭ�����й�����******************************************\n");
	  printf("�����룺");
      scanf("%d",&c);
	  switch(c)
	  {
	  case 1:
		  {
			  system("cls");
		      printf("\n*********************************�˿͵������*****************************************\n\n");
		      int k=0;
	          int a; 
	          printf("��ѡ������û����ͣ�VIP�û��밴 1;\n                    ��ͨ���û��밴2;\n                    �����û��밴3;\n");
		      printf("�����룺");
	          scanf("%d",&a);
	          if (a==1)
			  {  
				  vip(a);
				  getch();
			  } 
			  else if(a==2)
			  {	
				  v++;            //��ͨ���˿ͼ���
				  printf("�𾴵���ͨ���û������ҵ���Ϊ%d.\n",v);
				  daoda(v);
				  if(v==1)
				  {
					  a1=time(NULL);     //v=1�Ŀͻ�����ʱ��
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
					  printf("���Ժ��ú�,лл��");
					  system("pause");
				  }
			  }
            else if(a==3)
                           {	
				  v++;            //��ͨ���˿ͼ���
				  printf("�𾴵������û������ҵ���Ϊ%d.\n",v);
				  daoda(v);
				  if(v==1)
				  {
					  a1=time(NULL);     //v=1�Ŀͻ�����ʱ��
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
					  printf("���Ժ��ú�,лл��");
					  system("pause");
				  }
			  }
			  system("cls");
			  break;
		  }
	  case 2:
		  {
			  system("cls");
              printf("\n************************************�˿��뿪����******************************************\n\n");
              printf("�������뿪�˿͵ñ�ţ�\n");
              scanf("%d",&x);
              likai(x);
              mygrade() ;
	          w++;
	          if(x=1)
			  {
				  end=time(NULL);
		          A[0]=difftime(end,a1);
		          printf("                     ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a1));
			  }
			  else if(x=2)
			  {
				  end=time(NULL);
		          A[1]=difftime(end,a2);
		          printf("                     ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a2));
			  }
			  else if(x=3)
			  {
		          end=time(NULL);
		          A[2]=difftime(end,a3);
		          printf("                     ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a3));
			  }
	          else if(x=4)
			  {
		          end=time(NULL);
		          A[3]=difftime(end,a4);
		          printf("                     ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a4));
			  }
	          else if(x=5)
			  {
		          end=time(NULL);
		          A[4]=difftime(end,a5);
		          printf("                    ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a5));
			  }
	          else if(x=6)
			  {
		          end=time(NULL);
		          A[5]=difftime(end,a6);
		          printf("                    ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a6));
			  }
	         else if(x=7)
			 {
		          end=time(NULL);
		          A[6]=difftime(end,a7);
		          printf("                    ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a7));
			 }
	         else if(x=8)
			 {
		          end=time(NULL);
		          A[7]=difftime(end,a8);
		          printf("                    ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a8));
			 }
	         else if(x=9)
			 {
		          end=time(NULL);
		          A[8]=difftime(end,a9);
		          printf("                    ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a9));
			 }
	         else if(x=10)
			 {
		          end=time(NULL);
		          A[9]=difftime(end,a10);
		          printf("                    ������ҵ������ʱ��Ϊ %0.2f ��.\n",difftime(end,a10));
			 }
			 allsum+=A[0];
			 getch();
			 system("cls");
			 break;
		  }
	  case 3:
		  {   
			  system("cls");
	          printf("\n***********************************ҵ���ѯ����*******************************************\n\n");
              printl();
	          getch();
	          system("cls");
              break;
	   
		  }
	  case 4:
		  {
			  system("cls");
	          printf("\n**********************************�ŶӲ�ѯ����*******************************************\n\n");
              print2();
	          getch();
	          system("cls");
              break;
		  }
	  case 5:
		  {   
			  system("cls");
	          printf("\n*************************************ϵͳ��ѯ����*****************************************\n\n");
		      char cool[3];
		      int i=0,k=0;
		      printf("��������Ŀ��ţ�");
		      scanf("%d",&i);
              printf("����������λ���룺");
		      while(cool[k-1]!=' ')
			  {   
				  cool[k]=getch();
	              k++;
                  printf("*");
			  }
			  if(i==000&&cool[0]=='1'&&cool[1]=='1'&&cool[2]=='1'&&cool[3]=='1')
			  {	
				  average=allsum/w;
		          printf("\n�������� %d λ��ͨ�û���%d λvip�û��ɹ�����ҵ��!",w,vip1);
		          printf("\n��ͨ�û�ҵ������ܹ���ʱ %0.2f��,ƽ����ʱ %0.2f��\n",allsum,average);
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
	  default: printf("�����������������룺\n");
		  getch();
		  system("cls");
    }
  }
}
