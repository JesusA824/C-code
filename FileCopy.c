#include <stdio.h>
#include <stdlib.h>

int main(){
   char ch, source[30], destination[30];
   FILE *s, *d;

printf("Enter the name of the source file to copy from: \n");
scanf("%s",source);

   s = fopen("copytxt.txt", "r");

 
   if( s == NULL )
   {
      printf("This file does not exist in your directory...\n");
      exit(0);
   }
 
printf("Enter the name of the destination file: \n ");
   scanf("%s",destination);
   d = fopen(destination, "w");
 
   if( d == NULL )
   {
      fclose(s);
      printf("Cannot create this destination file...\n");
      exit(0);
   }
   while( ( ch = fgetc(s) ) != EOF )
      fputc(ch, d);
 
   printf("The file was copied!.\n");

   fclose(s);
   fclose(d);
 
return 0;
}
