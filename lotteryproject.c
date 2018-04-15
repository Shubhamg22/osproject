#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void *func(void *arg);
void *func1(void *ars);
void *func2(void *art);
int bt1=1;
int bt2=1;
int bt3=1;
int i;
int s[100];
pthread_t p1,p2,p3;
void starter();
int main()
{

printf("\nProcess P1 has highest Priority and It's given lottery tickets from 1 to 50\n");
printf("\nProcess P2 has priority higher than P3 but lower P1 and It's given lottery tickets from 51 to 90\n");
printf("\nProcess P3 has lowest priority among them and It's given lottery tickets from 90 to 100\n");
printf("\nInitially process P1 burst time is %d\n",bt1);
printf("\nInitially process P2 burst time is %d\n",bt2);
printf("\nInitially process P3 burst time is %d\n",bt3);
printf("\nTime slice has been set to 1\n");
sleep(2);
starter();

}
void starter()
{
sleep(2);
printf("\nGenerating Lottery Ticket\n");
while(bt1!=0 || bt2!=0 || bt3!=0)
{
int a=rand()%100;
sleep(1);
printf("\n Lottery Ticket Generted is :  %d \n",a);

if(a>0 && a<49)
{
pthread_create(&p1,NULL,func,(void *)a);

pthread_join(p1,NULL);
}
else if(a>50 && a<90)
{
pthread_create(&p2,NULL,func1,(void *)a);

pthread_join(p2,NULL);
}
else
{
pthread_create(&p3,NULL,func2,(void *)a);

pthread_join(p3,NULL);
}
}
if(bt1==0 && bt2==0 && bt3==0){
printf("\n All the processess have completed functionalities\n");
exit(0);
}
}
void *func(void *arg)
{

//goto x;
if(bt1!=0)
{
bt1=bt1-1;
printf("\nProcess p1 Burst time is reduced to %d\n",bt1);
 starter();
pthread_exit(NULL);
}
else
{

starter();
pthread_exit(NULL);
}
}
void *func1(void *ars)
{


if(bt2!=0)
{
bt2=bt2-1;
printf("\nProcess p2 Burst time is reduced to %d\n",bt2);
starter();
pthread_exit(NULL);
}
else
{
starter();
pthread_exit(NULL);
}
}
void *func2(void *art)
{
if(bt3!=0)
{
bt3=bt3-1;
printf("\nProcess p3 Burst time is reduced to %d\n",bt3);
starter();
pthread_exit(NULL);}
else
{

starter();
pthread_exit(NULL);
}
}
