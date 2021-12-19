#include "Assignment3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxWord 30
#define Textlen 1024
int strlength(char s[]);
int main(){
      char word[Textlen];
     char Text[Textlen];
     char Input[Textlen];
     //dont forget to free the malloc used 
     fgets(word,maxWord,stdin);  
     while(Text[strlength(Text)-1]!='~'){
       strcat(Text," ");
       fgets(Input,Textlen,stdin);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
       strcat(Text,Input);
     }
     printf("Gematria Sequences: ");
     GematriaSeq(Text,word);
     printf("\n");
     printf("Atbash Sequences: ");
     AtbashSeq(Text,word);
     printf("\n");
     printf("Anagram Sequences: ");
     AnagramSeq(Text,word);
return 0;
}

