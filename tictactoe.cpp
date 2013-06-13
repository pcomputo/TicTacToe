#include<iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;
void board(char a[3][3],int p,char sym,char play1[50],char play2[50])
{
     	
	cout<<"\nTic Tac Toe"<<endl;
         cout<<play1<<"(Player 1)"<<"-"<<play2<<"(Player 2)" <<"\t\t" ;
         
         if(p==0){
            cout<<"Player- "<<play1<<" entered: "<<sym<<endl;
	    cout<<endl;
         }
         else{
            cout<<"Player- "<<play2<<" entered: "<<sym<<endl;
	    cout<<endl;
         }
           
        
	cout<<"     |               |     " << endl;
        cout<<" "<<a[0][0]<<"|"<<a[0][1]<<"  |  "<<a[0][2]<<endl;
	cout<<"_____|_______________|_____" << endl;
	cout<<"     |               |     " << endl;
cout<<""<<a[1][0]<<"|  "<<a[1][1]<<"|  "<<a[1][2]<<endl;
	cout<<"_____|_______________|_____" << endl;
	cout<<"     |               |     " << endl;
cout<<""<<a[2][0]<<"|  "<<a[2][1]<<"|  "<<a[2][2]<<endl;
	cout<<"     |               |     " <<endl<<endl;
}

int check(char a[3][3],int x,int y,char sym)
{
 int flag=0,store;
 //count=store;
 if((a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[2][2]==sym) || (a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[1][1]==sym)){
    cout<<"\ngame won!";
    flag=1;
    exit(0);
 }
 else if((a[0][0]==a[1][0] && a[2][0]==sym && a[2][0]==sym) || (a[0][0]==a[0][1] && a[0][2]==a[0][1] && a[0][2]==sym) ||( a[0][2]==a[1][2] && a[2][2]==sym && a[2][2]==a[0][2]) ||(a[2][0]==a[2][1] && a[2][2]==sym && a[2][2]==a[2][0])|| (a[1][0]==a[1][1] && a[1][2]==sym && a[1][2]==a[1][1])|| (a[0][1]==a[1][1] && a[2][1]==sym && a[2][1]==a[1][1]))
         {
          cout<<"\ngame won!";
          flag=1;
          exit(0);
         }
  
     //store=count;
  if(flag!=1 )
      return 1;
  
}

int main()
{
 int x1,y1,answer,counter=0,count0=1,count1=1,x,y,prev=-1,ass, enter[3][3],p1=0,even=0,alarm=0;
 char symbol,symbol1,symbol2,send;
 char array[3][3],pl1[50],pl2[50];
 float sduration=0,duration=0;
 clock_t start;

 start=clock();


 for(int i=0;i<=2;i++)
     {
      for(int j=0;j<=2;j++){
          array[i][j]=0;
          }

     }

  for(int i=0;i<=2;i++)
     {
      for(int j=0;j<=2;j++){
          enter[i][j]=0;
          }

     }

 cout<<"Enter player 1's name:"<<endl;
 cin>>pl1;
 cout<<"Enter player 2's name:"<<endl;
 cin>>pl2;

  cout<<"\nEnter the symbol for"<<" " <<pl1<<":";
         cin>>symbol1;
    
         cout<<"\nEnter the symbol for "<<" "<<pl2<<":";
         cin>>symbol2;
 z:count0=0;
   count1=0;
 
 cout<<"\nEnter the position(in terms of row followed by column(3x3)):";
 cin>>x1>>y1;
 
 
 if(enter[x1][y1]==0){
  even++;
 
 p1=even%2==0?1:0;
 
 if(p1==0)
    cout<<"\nPlayer "<<pl1<<"'s"<<" turn..."<<endl;
 else
    cout<<"\nPlayer "<<pl2<<"'s"<<"turn..."<<endl;

 
        u: cout<<"Enter the symbol/correct symbol:"<<endl;
         cin>>symbol;
 
         if((p1==0 && symbol==symbol1) || (p1!=0 && symbol ==symbol2))
             goto a;
          else 
             goto u;
            
/* if(prev=0 && symbol=='x')
    cout<<"\nKindly enter O"<<endl;
 else if(prev=1 && symbol=='o')
    cout<<"\nKindly enter X"<<endl;
 ass=(symbol=='x'?--count0:--count1);
 if(count0==0){
     alarm=0;
      prev=0;
   }
   else if(count1==0){
       prev=1;
       alarm=1;
   }  */
   
 a: duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
  if(p1==0){
     
    cout<<"Time taken by-"<<pl1<<" to enter the correct symbol:"<<duration;
   }
 else{
    
    cout<<"Time taken by-"<<pl2<<" to enter the correct symbol:"<<duration;
  }
 counter++;
 cout<<"\nThe counter is:"<<counter;
 
 if(counter>10){
   cout<<"\nGame draw!";
   exit(0);
 }
 send=(symbol=='x'?'X':'O');  
 
    array[x1][y1]=send;
    enter[x1][y1]=1;
    board(array,p1,send,pl1,pl2);
    answer=check(array,x1,y1,send);
    if(answer==1)
       goto z;
  }
 else {
    cout<<"\nKindly do not enter the same coordinates...";
       goto z;
   }
 
 

 
    
    
return 0;

} 
