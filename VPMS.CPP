#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
int twowheelcount=0,fourwheelcount=0,truckcount=0;
int entry,anything;
long amount=0,transaction=0;
void display();
void repeat();
void getcar()
{
cout<<"car space available\t"<<(5-fourwheelcount)<<"\n";
}
void getbike()
{
cout<<"bike space available\t"<<(5-twowheelcount)<<"\n";
}
void gettruck()
{
cout<<"truck space available\t"<<(5-truckcount)<<"\n";
}

class bike
{
public:
int status;
char nplate[20];
float sec;
int min;
clock_t first,second;
begtime()
{
 first=clock();
}
endtime()
{
 second=clock();
}
caltime()
{
 clrscr();
 sec= difftime(second,first)/CLK_TCK;
 min=sec/60;
  cout<<"vehicle parked for"<<min<<"min\n";
}
calamount()
{
amount=min*5;
cout<<"the total payable amount is"<<amount;
transaction=transaction+amount;
}
bike()
{
status=0;
}
void add()
{
status=1;
}
void remove()
{
status=0;
}
};
class car
{
public:
int status;
char nplate[20];
float sec;
int min;
clock_t first,second;
begtime()
{
 first=clock();
}
endtime()
{
 second=clock();
}
caltime()
{
clrscr();
 sec= difftime(second,first)/CLK_TCK;
 min=sec/60;
  cout<<"vehicle parked for"<<min<<"min\n";
}
calamount()
{
amount=min*10;
cout<<"the total payable amount is"<<amount;
transaction=transaction+amount;
}
car()
{
status=0;
}
void add()
{
status=1;
}
void remove()
{
status=0;
}
};
class truck
{
public:
int status;
char nplate[20];
float sec;
int min;
clock_t first,second;
begtime()
{
 first=clock();
}
endtime()
{
 second=clock();
}
caltime()
{
 clrscr();
 sec= difftime(second,first)/CLK_TCK;
 min=sec/60;
  cout<<"vehicle parked for"<<min<<"min\n";
}
calamount()
{
amount=min*20;
cout<<"the total payable amount is"<<amount;
transaction=transaction+amount;
}
truck()
{
status=0;
}
void add()
{
status=1;
}
void remove()
{
status=0;
}
};
    //to display space box
void display()
{
 clrscr();
 line(20,30,80,30);
 line(20,30,20,100);
 line(20,100,80,100);
 line(80,30,80,100);
 outtextxy(50,50,"1");
 line(100,30,160,30);
 line(100,30,100,100);
 line(100,100,160,100);
 line(160,30,160,100);
 outtextxy(130,50,"2");
 line(180,30,240,30);
 line(180,30,180,100);
 line(180,100,240,100);
 line(240,30,240,100);
 outtextxy(210,50,"3");
 line(260,30,320,30);
 line(260,30,260,100);
 line(260,100,320,100);
 line(320,30,320,100);
 outtextxy(290,50,"4");
 line(340,30,400,30);
 line(340,30,340,100);
 line(340,100,400,100);
 line(400,30,400,100);
 outtextxy(370,50,"5");
}
	//initial display message
void repeat()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\TC\\BGI");
 settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
 outtextxy(150,80,"SELECT YOUR ACTION");
 outtextxy(150,90,"1.PARK NOW");
 outtextxy(150,100,"2.CHECKOUT");
 outtextxy(150,110,"3.SEE TRANSACTION");
 outtextxy(150,120,"4.EXIT");
 getcar();
 getbike();
 gettruck();
}
int enter()
	  //for getting the space number from user
{
  cin>>entry;
  if(entry<0||entry>5)
  {
  cout<<"invalid entry";
  enter();
  }
  else
  {
  entry=entry-1;
  return(entry);
  }
}
void nospace()
	   //to display if all spaces is full
 {
 printf("SORRY, no space available");
 cout<<"press any key to continue";
 cin>>anything;
 repeat();
}
void incomplete()
	//if the code to remove vehicle doesnot exist yet
{
  printf("action incomplete! the code you entered doesnot exist\n");
  cout<<"press any key to continue\n";
  cin>>anything;
}
int main()
{
FILE *fb,*fc,*ft;
fb=fopen("C:\\TURBOC3\\bike","a");
fc=fopen("C:\\TURBOC3\\car","a");
ft=fopen("C:\\TURBOC3\\truck","a");
  int a,t,i,first;
  bike b[5];
  car c[5];
  truck h[5];
 clrscr();
 int gm,gd=DETECT;
 initgraph(&gd,&gm,"..//BGI");
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
 repeat();
 while(1)
 {
 scanf("%d",&a);
 switch(a)
 {
   case 1:
   clrscr();
   setcolor(BLACK);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
   outtextxy(150,60,"PLEASE SELECT YOUR VEHICLE TYPE");
   outtextxy(150,80,"1.FOUR WHEELER");
   outtextxy(150,90,"2.TWO WHEELER");
   outtextxy(150,100,"3.HEAVY VEHICLES/TRUCKS");
   outtextxy(150,110,"4.EXIT");
   scanf("%d",&first);
   switch(first)
   {
     case 1:
     if(fourwheelcount<5)
     {
     display();
     if(c[0].status==0)
	 {
	 outtextxy(30,60,"Empty");
	 }
	  else
	 {
	 outtextxy(30,60,"full");
	 }
	 if(c[1].status==0)
	 {
	 outtextxy(110,60,"Empty");
	 }
	 else
	 {
	 outtextxy(110,60,"full");
	 }
	 if(c[2].status==0)
	 {
	 outtextxy(190,60,"Empty");
	 }
	 else
	 {
	 outtextxy(190,60,"full");
	 }
	 if(c[3].status==0)
	 {
	 outtextxy(270,60,"Empty");
	 }
	 else
	 {
	 outtextxy(270,60,"full");
	 }
	 if(c[4].status==0)
	 {
	 outtextxy(350,60,"Empty");
	 }
	 else
	 {
	   outtextxy(350,60,"full");
	 }

     cout<<"enter the space available which you want\n";
     entry=enter();
     if(c[entry].status==1)
     {
     clrscr();
     setcolor(BLACK);
     cout<<"space already taken";
     delay(2000);
     }
     else
     {
     clrscr();
       setcolor(BLACK);
     c[entry].add();
     c[entry].begtime();
     fourwheelcount++;
     cout<<"enter the identification number of car\n";
     cin>>c[entry].nplate;
     cout<<"press any key to continue\n";
     cin>>anything;
     }
     repeat();
     }
     else
     {
     nospace();
     }
     break;
     case 2:
     display();
     if(twowheelcount<5)
     {
      if(b[0].status==0)
	 {
	 outtextxy(30,60,"Empty");
	 }
	  else
	 {
	 outtextxy(30,60,"full");
	 }
	 if(b[1].status==0)
	 {
	 outtextxy(110,60,"Empty");
	 }
	 else
	 {
	 outtextxy(110,60,"full");
	 }
	 if(b[2].status==0)
	 {
	 outtextxy(190,60,"Empty");
	 }
	 else
	 {
	 outtextxy(190,60,"full");
	 }
	 if(b[3].status==0)
	 {
	 outtextxy(270,60,"Empty");
	 }
	 else
	 {
	 outtextxy(270,60,"full");
	 }
	 if(b[4].status==0)
	 {
	 outtextxy(350,60,"Empty");
	 }
	 else
	 {
	   outtextxy(350,60,"full");
	 }
      cout<<"enter the space available which you want\n";
      entry=enter();
      if(b[entry].status==1)
      {
      clrscr();
	setcolor(BLACK);
      cout<<"space already taken";
      delay(2000);
      }
      else
      {
      clrscr();
	setcolor(BLACK);
      b[entry].add();
      b[entry].begtime();
      twowheelcount++;
      cout<<"enter the identification number of the bike\n";
      cin>>b[entry].nplate;
      cout<<"press any key to continue\n";
      cin>>anything;
      }
     repeat();
     }
     else
     {
     nospace();
     }
     break;

     case 3:
     if(truckcount<5)
     {
      display();
       if(h[0].status==0)
	 {
	 outtextxy(30,60,"Empty");
	}
	  else
	 {
	 outtextxy(30,60,"full");
	 }
	 if(h[1].status==0)
	 {
	 outtextxy(110,60,"Empty");
	 }
	 else
	 {
	 outtextxy(110,60,"full");
	 }
	 if(h[2].status==0)
	 {
	 outtextxy(190,60,"Empty");
	 }
	 else
	 {
	 outtextxy(190,60,"full");
	 }
	 if(h[3].status==0)
	 {
	 outtextxy(270,60,"Empty");
	 }
	 else
	 {
	 outtextxy(270,60,"full");
	 }
	 if(h[4].status==0)
	 {
	 outtextxy(350,60,"Empty");
	 }
	 else
	 {
	   outtextxy(350,60,"full");
	 }
      cout<<"enter the space available which you want\n";
      entry=enter();
      if(h[entry].status==1)
      {
      clrscr();
	setcolor(BLACK);
      cout<<"space already taken";
      delay(2000);
      }
      else
      {
      clrscr();
	setcolor(BLACK);
      h[entry].add();
      h[entry].begtime();
      truckcount++;
      cout<<"enter the identification number of the truck\n";
      cin>>h[entry].nplate;
      cout<<"press any key to continue\n";
      cin>>anything;
      }
      repeat();
     }
     else
     {
     nospace();
     }
     break;
     default:
     return(0);

   }
   break;

   case 2:
   clrscr();
     setcolor(BLACK);
   outtextxy(150,50,"which vehicle you want to remove");
   outtextxy(160,60,"1.bike");
   outtextxy(160,70,"2.car");
   outtextxy(160,80,"3.truck");
   cin>>t;
    switch(t)
    {
    case 1:
    clrscr();
    cout<<"enter your parking code\n";
    cin>>i;
    i--;
    if(b[i].status==1)
     {
     b[i].remove();
     b[i].endtime();
     b[i].caltime();
     b[i].calamount();
     twowheelcount--;
     cout<<"\nbike removed\n";
     cout<<"the removed bike has number plate\t"<<b[i].nplate;
     fprintf(fb,"%s\t",b[i].nplate);
     fprintf(fb,"%f\n",b[i].sec);
     cout<<"\npress any key to continue\n";
     cin>>anything;
     }
     else
     {
     incomplete();
     }
     repeat();
     break;
     case 2:
     clrscr();
       setcolor(BLACK);
     cout<<"enter your parking code\n";
     cin>>i;
     i--;
     if(c[i].status==1)
     {
     c[i].remove();
     c[i].endtime();
     c[i].caltime();
     c[i].calamount();
     fourwheelcount--;
     cout<<"\ncar removed\n";
     cout<<"the removed car has number plate\t"<<c[i].nplate;
     fprintf(fc,"%s\t",c[i].nplate);
     fprintf(fc,"%f\n",c[i].sec);
     cout<<"\npress any key to continue\n";
     cin>>anything;
     }
     else
     {
     incomplete();
     }
     repeat();
     break;
     case 3:
     clrscr();
       setcolor(BLACK);
     cout<<"enter your parking code\n";
     cin>>i;
     i--;
     if(h[i].status==1)
     {
     h[i].remove();
     h[i].endtime();
     h[i].caltime();
     h[i].calamount();
     truckcount--;
     cout<<"\ntruck removed\n";
     cout<<"the removed truck has number plate\t"<<h[i].nplate;
     fprintf(ft,"%s\t",h[i].nplate);
     fprintf(ft,"%f\n",h[i].sec);
     cout<<"\npress any key to continue\n";
     cin>>anything;
     }
     else
     {
     incomplete();
     }
     repeat();
     break;
     default:
     repeat();
     exit(0);
     break;
   }
   break;

   case 3:
   clrscr();
   setcolor(BLACK);
   cout<<"the total transaction of today is"<<transaction;
   getch();
   repeat();
   break;

   default:
   exit(0);
   break;
}
 getch();
}
  fclose(fb);
  fclose(fc);
  fclose(ft);
}


