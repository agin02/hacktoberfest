#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
  
int z = 0, i = 0, j = 0, c = 0; 
  
char a[16], ac[20], stk[15], act[10];  
  
void check() 
{ 
    strcpy(ac,"REDUCE TO E -> ");   
      
    for(z = 0; z < c; z++)  
    { 
        if(stk[z] == '4')  
        { 
            printf("%s4", ac); 
            stk[z] = 'E'; 
            stk[z + 1] = ' '; 
              
            printf("$%s	%s$	", stk, a);  
        } 
    } 
          
    for(z = 0; z < c - 2; z++) 
    { 
        if(stk[z] == '2' && stk[z + 1] == 'E' &&  
                                stk[z + 2] == '2')  
        { 
            printf("%s2E2", ac); 
            stk[z] = 'E'; 
            stk[z + 1] = ' '; 
            stk[z + 2] = ' '; 
            printf("$%s	%s$	", stk, a); 
            i = i - 2; 
        } 
          
    } 
          
    for(z=0; z<c-2; z++) 
    { 
        if(stk[z] == '3' && stk[z + 1] == 'E' &&  
                                stk[z + 2] == '3')  
        { 
            printf("%s3E3", ac); 
            stk[z]='E'; 
            stk[z + 1]=' '; 
            stk[z + 1]=' '; 
            printf("$%s	%s$	", stk, a); 
            i = i - 2; 
        } 
    } 
    return ; 
} 
  
int main() 
{ 
    printf("GRAMMAR is -E->E+E\nE->E*E\nE->(E)\nE->id\n");    
      
    strcpy(a,"32423");  
      
    c=strlen(a);  
      
    strcpy(act,"SHIFT");  
      
    printf("stack input action");  
      
    printf("$	%s$	", a);  
      
    for(i = 0; j < c; i++, j++)  
    { 
        printf("%s", act);  
          
        stk[i] = a[j];    
        stk[i + 1] = ' ';
          
        a[j]=' '; 
          
        printf("$%s	%s$	", stk, a);  
          
        check();  
    } 
      
    check();  
      
    if(stk[0] == 'E' && stk[1] == ' ')  
        printf("Accept"); 
    else 
        printf("Reject"); 
} 