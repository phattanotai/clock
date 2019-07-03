#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream.h>
#include <ctime>
#include <dos.h> 


void circle_t(int xc,int yc,int rad,int color){
     int x=0,y=rad,p=1-rad;
     putpixel(xc+x,yc+y,color);
     putpixel(xc+y,yc+x,color);
     putpixel(xc-y,yc+x,color);
     putpixel(xc-x,yc+y,color);
     putpixel(xc-x,yc-y,color);
     putpixel(xc-y,yc-x,color);
     putpixel(xc+y,yc-x,color);
     putpixel(xc+x,yc-y,color);    
     while(x<y){
          x++;
          if(p<0){
               p+=2*x+1;           
          }else{
               y--;
               p+=2*(x-y)+1;                
          }
         putpixel(xc+x,yc+y,color);
         putpixel(xc+y,yc+x,color);
         putpixel(xc-y,yc+x,color);
         putpixel(xc-x,yc+y,color);
         putpixel(xc-x,yc-y,color);
         putpixel(xc-y,yc-x,color);
         putpixel(xc+y,yc-x,color);
         putpixel(xc+x,yc-y,color);                 
     }
}
void clock(int hour,int minute,int second){
     int color=COLOR(127,255,212);
     int x[3],y[3],xc=getmaxx()/2,yc=getmaxy()/2,r=200,r2=140,r3=100,i=0,m,h;
     circle_t(xc,yc,220,9);
     for(int i=90;i<=360+90;i++){
         x[0] = xc + r * cos(i*3.14159/180);
         y[0] = yc + r * sin(i*3.14159/180);
         putpixel(x[0],y[0],RED);
         if(i%30==0){
             circle_t(x[0],y[0],3,3); 
         }else if(i%6==0){
             circle_t(x[0],y[0],1,14);  
         }         
     }
     r=160;
     i=90-(6*second);
     m=90-(6*minute);
     int l,z;
     if(minute<=12){
          l=12-minute;
          z=0*6;          
     }else if(minute<=24){
          l=24-minute; 
          z=1*6;
     }else if(minute<=36){
          l=36-minute;
          z=2*6; 
     }else if(minute<=48){
          l=48-minute;
          z=3*6; 
     }else if(minute<=60){
          l=60-minute; 
          z=4*6;
     }  
     l=12-l;
             
     //int num=minute*60;
     //int z=num/720;
     //z=(int)z*6;
     h=90-(30*hour)-z;    
     while(true){                               
         x[0] = xc +  r * cos(i*3.14159/180);
         y[0] = yc +  r * sin(i*3.14159/180);
         x[1] = xc + r2 * cos(m*3.14159/180);
         y[1] = yc + r2 * sin(m*3.14159/180);
         x[2] = xc + r3 * cos(h*3.14159/180);
         y[2] = yc + r3 * sin(h*3.14159/180); 
         
         setcolor(1); 
         line(xc,yc,x[0],getmaxy()-y[0]);
         setcolor(RED);
         line(xc,yc,x[1],getmaxy()-y[1]);
         setcolor(GREEN);
         line(xc,yc,x[2],getmaxy()-y[2]);
         
         char ho[3];
         char mu[3];
         char se[3];
         itoa(hour,ho,10);
         itoa(minute,mu,10);
         itoa(second,se,10);
         
         setcolor(color);
         outtextxy(getmaxx()/2-33,getmaxy()-30,ho);
         outtextxy(getmaxx()/2-15,getmaxy()-30,":");
         outtextxy(getmaxx()/2-10,getmaxy()-30,mu);
         outtextxy(getmaxx()/2+7,getmaxy()-30,":");
         outtextxy(getmaxx()/2+12,getmaxy()-30,se);
         
         delay(1000);
         second++;  
        
         setcolor(0);
         outtextxy(getmaxx()/2-33,getmaxy()-30,ho);
         outtextxy(getmaxx()/2-15,getmaxy()-30,":");
         outtextxy(getmaxx()/2-10,getmaxy()-30,mu);
         outtextxy(getmaxx()/2+7,getmaxy()-30,":");
         outtextxy(getmaxx()/2+12,getmaxy()-30,se);
         
         if(second==60){second=0;minute++;}
         if(minute==60){minute=0;hour++;}
         if(hour==24){hour=0;}        
        
         line(xc,yc,x[0],getmaxy()-y[0]);
         line(xc,yc,x[1],getmaxy()-y[1]);
         line(xc,yc,x[2],getmaxy()-y[2]);         
         
         if(second%60==0){         
             m=m-6;
             l++;
         }if(l==12){
             h=h-6;
             l=0;            
         }      
         i=i-6;
     }   
     
}
            
int main(){
     int gd=DETECT,gm;
     //initgraph(&gd,&gm,"");
     initwindow(800,600);
     
     //current time gmtime() function return USA time
     /* time_t rewtime;
     struct tm *timer;     
     time(&rewtime);
     timer=gmtime(&rewtime);
     int hour=timer->tm_hour,minute=timer->tm_min,second=timer->tm_sec;
     //hour+=7;
     */
    
     // localtime function 
     time_t rewtime;
     struct tm *timer;     
     rewtime=time(NULL);
     timer=localtime(&rewtime);
     int hour=timer->tm_hour,minute=timer->tm_min,second=timer->tm_sec;
     
     
     //compile time
     /*char time[]=__TIME__;
     char h[3]={time[0],time[1]};
     char m[3]={time[3],time[4]};
     char s[3]={time[6],time[7]};
     int hour=atoi(h),minute=atoi(m),second=atoi(s);
     int xc=250,yc=300,rad=200; */ 
     
     setlinestyle(2, 0, 2); 
     clock(hour,minute,second);
     
     //clock(22,11,40);
     getch();
     closegraph();
     
     
}         
