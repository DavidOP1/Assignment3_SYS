#include "Assignment3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char bigLetters[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char smallLetters[26]="abcdefghijklmnopqrstuvwxyz";
int checkAtbash(char s[],char word[]);
char *strrev(char s[]);
int wordSumNew(char s[]);
int helpAnagram(char s[],char word[]);
void sort(int arr[],int length);
void swap(int arr[],int i,int j);
void AnagramSeq(char Input[],char word[]){
   int seqMone=0,geoSum=0,wordSum=wordSumNew(word),letter=0,value=0;
   for(int i=0;i<strlength(Input);i++){
       geoSum=0,letter=Input[i];
       if (letter<65||(letter>90&&letter<97)||letter>122)
       {
         continue;
       }
       
       for (int j = i; j < strlength(Input); j++)
       {
         letter=Input[j],value=0;
         //printf("i= %d, letter= %d\n",i,letter);
         //printf("geoSum= %d, %d\n", geoSum,wordSum);
         if(wordSum==geoSum){
            //here print the sequence with ~ at the end
            //printf("~bee");
            char subtext[j-i+1];
            memcpy(subtext,&Input[i],j-i);
            subtext[j-i]='\0';
            if(helpAnagram(subtext,word)==1){
            if (seqMone==0)
            { 
            printf("%s",subtext);
            }else{
              printf("~%s",subtext);
            }
            seqMone+=1;
            break;
            }
         }
         if (letter>=65&&letter<=90)
         {
           value=letter-64;
           geoSum=geoSum+value;
         }
         if (letter>=97&&letter<=122)
         {
           value=letter-96;
           geoSum=geoSum+value;
         }
       }
       
     }
}
int helpAnagram(char s[],char word[]){
  int letter=0,j=0,checkArr=1;
  int *wordArr=(int*) malloc(sizeof(int)*strlength(word));
  int *stringArr=(int*) malloc(sizeof(int)*strlength(word));
 for(int i=0;i<strlength(s);i++){
   letter=s[i];
     if (letter>=65&&letter<=90)
         {
              wordArr[j]=((int)word[j]);
              stringArr[j]=letter;
              j+=1;
         }
         if (letter>=97&&letter<=122)
         {
              wordArr[j]=((int)word[j]);
              stringArr[j]=letter;
              j+=1;
         }
 }sort(wordArr,strlength(word)); sort(stringArr,strlength(word));
  for(int i=0;i<strlength(word);i++){
     if(wordArr[i]!=stringArr[i])return 0;
  }
  free(wordArr);
  free(stringArr);
  return checkArr;
}

void sort(int arr[],int length){
     for(int i=0;i<length;i++){
       for(int j=0;j<length;j++){
          if(arr[j]>arr[i]){
            swap(arr,i,j);
          }
       }
     }
}

void swap(int arr[],int i,int j){
   int temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
}

void GematriaSeq(char Input[],char word[]){
    int seqMone=0,geoSum=0,wordSum=wordSumNew(word),letter=0,value=0;

    for(int i=0;i<strlength(Input);i++){
       geoSum=0,letter=Input[i];
       if (letter<65||(letter>90&&letter<97)||letter>122)
       {
         continue;
       }
       
       for (int j = i; j < strlength(Input); j++)
       {
         letter=Input[j],value=0;
         //printf("i= %d, letter= %d\n",i,letter);
         //printf("geoSum= %d, %d\n", geoSum,wordSum);
         if(wordSum==geoSum){
            //here print the sequence with ~ at the end
            //printf("~bee");
            char subtext[j-i+1];
            memcpy(subtext,&Input[i],j-i);
            subtext[j-i]='\0';
            if (seqMone==0)
            { 
            printf("%s",subtext);
            }else{
              printf("~%s",subtext);
            }
            seqMone+=1;
            break;
         }
         if (letter>=65&&letter<=90)
         {
           value=letter-64;
           geoSum=geoSum+value;
         }
         if (letter>=97&&letter<=122)
         {
           value=letter-96;
           geoSum=geoSum+value;
         }
       }
       
     }
}

void AtbashSeq(char Input[],char word[]){
    int seqMone=0,geoSum=0,wordSum=wordSumNew(word),letter=0;
     //if we reach a not letter we will skip the second loop iteration. and refresh the current sequence
     for(int i=0;i<strlength(Input);i++){
       geoSum=0,letter=Input[i];
       if (letter<65||(letter>90&&letter<97)||letter>122)
       {
         continue;
       }   
       for (int j = i; j < strlength(Input); j++)
       {
         letter=Input[j];
         if(wordSum==geoSum){
            char subtext[j-i+1];
            memcpy(subtext,&Input[i],j-i);
            subtext[j-i]='\0';
            //write a function in which you send the string and it returns 1 if its atbash
            if(checkAtbash(subtext,word)==1){
            if (seqMone==0)
            { 
            printf("%s",subtext);
            }else{
              printf("~%s",subtext);
            }
            seqMone+=1;
            break;
         }
         }
         if (letter>=65&&letter<=90)
         {
           letter=bigLetters[25-(letter-64)+1]; 
           letter=letter-64;
           geoSum=geoSum+letter;
         }
         if (letter>=97&&letter<=122)
         {
           letter=smallLetters[25-(letter-96)+1];
           letter=letter-96;
           geoSum=geoSum+letter;
         }
       }
     }
}

int checkAtbash(char s[],char word[]){
   //char s[] is the string to which we compare the entered word
   //check reversed and not reversed.
   int revCheck=1,regCheck=1,letter=0,j=0,letterWord=0;
   char revWord[strlength(s)];
   for(int i=0;i<strlength(s);i++){
       letter=s[i];
         if (letter>=65&&letter<=90)
         {
          letterWord=word[j];
          letter=bigLetters[25-(letter-1-64)];
          if(letter!=letterWord)  {regCheck=0; break;}
          j++;
         }
        else if (letter>=97&&letter<=122)
         {
          letterWord=word[j];
          letter=smallLetters[25-(letter-1-96)];
          if(letter!=letterWord)  {regCheck=0; break;}
          j++;
         }
   }
   strcpy(revWord,strrev(s));
   for(int i=0;i<strlength(revWord);i++){
       letter=revWord[i];
         if (letter>=65&&letter<=90)
         {
          letterWord=word[j];
          letter=bigLetters[25-(letter-1-64)];
          if(letter!=letterWord) {revCheck=0; break;}
          j++;
         }
        else if (letter>=97&&letter<=122)
         {
          letterWord=word[j];
          letter=smallLetters[25-(letter-96-1)];
          if(letter!=letterWord) {revCheck=0; break;}
          j++;
         }
   }if(revCheck==1||regCheck==1) return 1;
   return 0;
}


int wordSumNew(char s[]){
  int letter=0,wordSum=0;
  for(int i=0;i<strlength(s);i++){
       letter=s[i];
  
        if (letter>=65&&letter<=90)
         {
           wordSum+=letter-64;
         }
         if (letter>=97&&letter<=122)
         {
          wordSum+=letter-96;
         }
     }
     return wordSum;
}


int strlength(char s[]) {
   int c = 0;
   while (s[c] != '\0')
      c++;

   return c;
}




char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlength(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}