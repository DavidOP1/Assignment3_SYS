#include "Assignment3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxWord 30
#define Textlen 1024
int checkWave(char[]);
int strlength(char s[]);
int main(){
      char word[Textlen];
     char Text[Textlen];
     char Input[Textlen];
     //dont forget to free the malloc used 
     fgets(word,maxWord,stdin);  
     while(checkWave(Input)){
      // printf("test= %s\n",Text);
        fgets(Input,Textlen,stdin);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
       strcat(Text,Input);
     }
     printf("Gematria Sequences:");
     GematriaSeq(Text,word);
     printf("\n");
     printf("Atbash Sequences:");
     AtbashSeq(Text,word);
     printf("\n");
     printf("Anagram Sequences:");
     AnagramSeq(Text,word);
     printf("\n");
return 0;
}
int checkWave(char input[]){
  int letter=0;
   for(int i=0;i<strlength(input);i++){
     letter=input[i];
      if(letter==126) return 0;
   }return 1;
}
