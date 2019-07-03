#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
#include <cstdlib>

using namespace std;
int sum;
void rotate(int figure[],int edges,double angle,int cx,int cy);
void coutf(int xy[]){
    int secondx[60],hourx[60],minutex[60];
    int secondy[60],houry[60],minutey[60];
    int second_hand[4],minute_hand[4],hour_hand[4],edges=2;
    double angle;
    int cx=300,cy=200;
    int max_y = getmaxy();
    int c=xy[0],v=xy[1];
    angle=-6;
    
    second_hand[0]=cx;
    second_hand[1]=max_y-cy;
    second_hand[2]=cx;
    second_hand[3]=max_y-320;

	hour_hand[0]=cx;
	hour_hand[1]=max_y-cy;
	hour_hand[2]=cx;
	hour_hand[3]=max_y-260;
	
	
	minute_hand[0]=cx;
	minute_hand[1]=max_y-cy;
	minute_hand[2]=cx;
	minute_hand[3]=max_y-300;
    
        
    int i=0; 
    int n=0; 
    while(i<=3600){
        if(i%60==0){
             second_hand[0]=cx;
             second_hand[1]=max_y-cy;
             second_hand[2]=cx;
             second_hand[3]=max_y-320;
             minutex[n]=minute_hand[2];
             minutey[n]=minute_hand[3];
             rotate(minute_hand,edges,angle,cx,max_y-cy);
             
             n++;
        }
        i++;
    }
    i=0;
    n=0;
    while(i<=21600*2){
        if(i%720==0){  
             hourx[n]=hour_hand[2];
             houry[n]=hour_hand[3];        
             rotate(hour_hand,edges,angle,cx,max_y-cy);
             n++;
        } 
        i++;                                      
    }   
    
    if(c<12){
         c=c-12;
    }
    if(c==12){
       c=0;  
    }
    
    int l=ceil(xy[1]/12);
    sum=144*l;
    xy[0]=hourx[int(c*5+l)];
    xy[1]=houry[int(c*5+l)];
    xy[2]=minutex[v];
    xy[3]=minutey[v];
}


void rotate(int figure[],int edges,double angle,int cx,int cy){
     double x,y;
     angle= -1*(angle*3.14/180);
     double cos_a=cos(angle);
     double sin_a=sin(angle);     
     for(int i=0;i<edges;i++){
             x=figure[2*i]-cx;
             y=figure[2*i+1]-cy; 
    	     figure[2*i]=int((x*cos_a)-(y*sin_a)+cx+0.5);
             figure[2*i+1]=int((x*sin_a)+(y*cos_a)+cy+0.5);
             
     }
}
void drawClock(int cx,int cy,int r){
     setcolor(GREEN);
     setlinestyle(SOLID_FILL,0,3);
     circle(cx,cy,r);
     int max_y=getmaxy();
     int center[2]={cx,max_y-340};
     for(int i=0;i<60;i++){
        if(i%5==0){
             setcolor(RED);
             circle(center[0],center[1],2);    
        }else{
             circle(center[0],center[1],1);
        }
           
      rotate(center,1,-6,cx,cy);     
     }  
}
int main(){
    int second_hand[4],minute_hand[4],hour_hand[4],edges=2;
    double angle;
    int cx=300,cy=200;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"G:\\Win95\\apps\\Borland\\bc5\\bgi");
    int max_y = getmaxy();
    int xy[]={0,0,0,0};
    system("cls");
    cleardevice();
    angle=-6;
    
    printf("Enter Hour Second >>");
    scanf("%d %d",&xy[0],&xy[1]);
    coutf(xy);
     
    second_hand[0]=cx;
    second_hand[1]=max_y-cy;
    second_hand[2]=cx;
    second_hand[3]=max_y-320;
	
	hour_hand[0]=cx;
	hour_hand[1]=max_y-cy;
	hour_hand[2]=xy[0];
	hour_hand[3]=xy[1];
	
	minute_hand[0]=cx;
	minute_hand[1]=max_y-cy;
	minute_hand[2]=xy[2];
	minute_hand[3]=xy[3];
	
	
	cleardevice();
	setbkcolor(WHITE);
	
	drawClock(cx,max_y-cy,150);
	setlinestyle(SOLID_FILL,0,2);
	
	drawpoly(2,minute_hand);
	drawpoly(2,hour_hand);
	int i=sum;
	int b=0,g=0;
	//while(!kbhit()){
      while(g<=3600){
        setcolor(RED);
        drawpoly(2,second_hand);
        setcolor(GREEN);
        drawpoly(2,minute_hand);
        setcolor(BLUE);
        drawpoly(2,hour_hand);  
        delay(0);  
        setcolor(BLACK);
        drawpoly(2,second_hand);
        rotate(second_hand,edges,angle,cx,max_y-cy);
        i++;
        
        if(i%60==0){
             second_hand[0]=cx;
             second_hand[1]=max_y-cy;
             second_hand[2]=cx;
             second_hand[3]=max_y-320;
             drawpoly(2,minute_hand);
             rotate(minute_hand,edges,angle,cx,max_y-cy);
             b++;
             cout<<b<<endl;
        }
        if(i%720==0){
             i=0;
             drawpoly(2,hour_hand);             
             rotate(hour_hand,edges,angle,cx,max_y-cy);
   
        }       
      g++;                                  
    }
	  getch();
}  



