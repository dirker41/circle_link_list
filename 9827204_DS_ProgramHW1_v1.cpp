/* 
每個名字對應到一個NODE 先串成直線的LINK LIST 
然後找到此LINK LIST的最後一個NODE 
先用一個POINETR,tail 指向這個NODE  
再把TAIL->NEXT 指向此LINK LIST的頭,head 這樣就串成一圈了 
再來就是指定自殺的人了 先丟一個COUNTER 給這串LIST的頭( tail->next ) 
檢查這個COUNTER是多少 如果大於0 就-1之後往下個NODE丟
如果拿到的COUNTER為0 就把丟進來的POINTER指向下一個 (自殺) 
當然做這些之前要先檢查一下丟進來的POINTER->NEXT 是不是等於丟進來的POINTER 
如果是 就表示這個人是倖存者 如果不是 就是還有人要自殺 

*/ 
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
using namespace :: std ;

typedef char str20[20] ;
typedef char str200[200] ;


struct human {
  int number ;     
  str20 name ;      
  human * next;             
} ;

typedef human *humanptr ;


void Solve_problem() ;
humanptr creat_circle_list( humanptr &head ,const int total ,int counter ) ;
humanptr creat_line_list( humanptr &head,const int total ,int counter ) ;
void Start_shoot( humanptr &head ,const int step ,int counter ) ;
void print_circle( human *head ) ;
void get_no_space_line( str200 &fpname );

ifstream fp;
ofstream outfp;

int main() {
    
    //printf( "↓↓↓↓↓↓↓↓INPUT↓↓↓↓↓↓↓↓\n" ) ; 
    Solve_problem() ;
    
    system("pause") ;
    return 0;
}

void Solve_problem() {
     human *head , *tail;
     head = NULL ;
     int total,step ,counter ;
     char fpname[200];
     printf("Enter the file name:\n") ;
     get_no_space_line( fpname ) ; 
     // scanf( "%s", &fpname );
     //------------file name -----------------
     //strcpy( fpname,"C:\\Users\\a20010329\\Desktop\\work\\DS_homework\\circle_link_list.txt") ;
     
     fp.open(fpname); ////////////////open file
     char outfpname[200] ;
     strcpy( outfpname,fpname) ;
     strcat( outfpname,".out");
     outfp.open( outfpname ) ;
     /////////////////////////ERROR CHECK ///////////////////
     if ( fp == NULL ) {
          printf("File \"%s\" isn't exist !\n",fpname ) ;
          return ;
     }
     ////////////////////////////////////////////////////////
     while ( fp.peek() != EOF ) {           
        fp >> step ;
        fp >> total ;
        tail = creat_circle_list( head,total,1 ) ;
        Start_shoot( tail->next , step , step ) ; 
        
     }
     fp.close() ;///////////////////////close file //////////////////////
     outfp.close();
}

humanptr creat_circle_list( humanptr &head ,const int total ,int counter ) {
      humanptr tail = creat_line_list( head, total ,1 ) ;
      tail->next = head ; /////尾巴接到頭///////會變成無窮的LINK LIST!!!!!!!!!! 
      return tail;
}

humanptr creat_line_list( humanptr &head ,const int total ,int counter ) {     
     str20 name ;     
     head = new human ;
     fp >> name ;
     head->number = counter ;
     strcpy( head->name, name ) ;
     head->next = NULL ;
     if ( counter == total ) return head;
     return creat_line_list( head->next, total ,counter + 1 ) ;
     
}

void Start_shoot( humanptr &head ,const int step ,int counter ) {
     if ( head->next == head ) {
          outfp << head->name << endl;
          //printf("%s\n",head->name ) ;
          delete head ;
          head = NULL ; //////////////////用完要擦屁股~////////////// 
          return ;
     } /////////////////剩一個人囉~ 
     else if ( counter == 0 ) { 
          outfp << head->name  << "=>" ;
          //printf( "%s=>",head->name ) ;
          humanptr temp = head ;
          head = head->next ;
          delete temp ;
          Start_shoot( head, step ,step) ;
     }
     else {
          Start_shoot( head->next , step , counter - 1 ) ;
     }
}

void print_circle( human *head ) {

     printf( "%d ",head->number ) ;
     if ( head->next->number == 1 ) {
          printf( "\n" ) ;
          return ;
     }
     print_circle( head->next ) ;
}////////////////END CODE///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void get_no_space_line( str200 &fpname ) {
       char ch ;
       int i = 0 ;
       scanf( "%c",&ch ) ;
       while( ch != '\n' ){ 
               // ' ', '\f', '\n', '\r', '\t', '\v'
         if( (ch == ' ') || 
             (ch == '\f') || 
             (ch == '\r') || 
             (ch == '\t') || 
             (ch == '\v') ) ;
              // all white space ....
         else {
           fpname[i] = ch ;
           i ++ ;
         }
         scanf( "%c",&ch ) ;
       } // while
       
       fpname[i] = '\0' ;
       
       
}




















