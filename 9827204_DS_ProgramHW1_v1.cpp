/* 
�C�ӦW�r������@��NODE ���ꦨ���u��LINK LIST 
�M���즹LINK LIST���̫�@��NODE 
���Τ@��POINETR,tail ���V�o��NODE  
�A��TAIL->NEXT ���V��LINK LIST���Y,head �o�˴N�ꦨ�@��F 
�A�ӴN�O���w�۱����H�F ����@��COUNTER ���o��LIST���Y( tail->next ) 
�ˬd�o��COUNTER�O�h�� �p�G�j��0 �N-1���᩹�U��NODE��
�p�G���쪺COUNTER��0 �N���i�Ӫ�POINTER���V�U�@�� (�۱�) 
��M���o�Ǥ��e�n���ˬd�@�U��i�Ӫ�POINTER->NEXT �O���O�����i�Ӫ�POINTER 
�p�G�O �N��ܳo�ӤH�O�Ʀs�� �p�G���O �N�O�٦��H�n�۱� 

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
    
    //printf( "����������������INPUT����������������\n" ) ; 
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
      tail->next = head ; /////���ڱ����Y///////�|�ܦ��L�a��LINK LIST!!!!!!!!!! 
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
          head = NULL ; //////////////////�Χ��n������~////////////// 
          return ;
     } /////////////////�Ѥ@�ӤH�o~ 
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




















