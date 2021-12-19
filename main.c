#include "Assignment3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxWord 30
#define Textlen 1024
int strlength(char s[]);
int main(){
    //  char word[Textlen]="bee";
    //  char Text[Textlen];
    //  char Input[Textlen]="I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee –OUCH!! It stung me!! vvy y v v~";
      char word[Textlen];
     char Text[Textlen];
     char Input[Textlen];
     //dont forget to free the malloc used 
     scanf("%s",word);
     //printf("%s",word);
     while(Text[strlength(Text)-1]!='~'){
       strcat(Text," ");
       scanf("%s",Input);
       strcat(Text,Input);
     }
     //printf("text= %s",Text);
     printf("Gematria Sequences: ");
     GematriaSeq(Text,word);
     printf("\n");
     printf("Atbash Sequences: ");
     AtbashSeq(Text,word);
     printf("\n");
     printf("Anagram Sequences: ");
     AnagramSeq(Text,word);
     printf("\n");
return 0;
}

