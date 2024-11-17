/*
Week 3: Introduction to LEX tool
3. Implement the following programs using Lex tool
a. Identification of Vowels and Consonants
b. count number of vowels and consonants
c. Count the number of Lines in given input
d. Recognize strings ending with 00
e. Recognize a string with three consecutive 0’s
*/




#include<stdio.h>
#include<ctype.h>
#define m 100
int main()
{
    FILE *fp = fopen("input.txt", "r");
    FILE *fp2 = fopen("output.txt","w");
    int v=0,co=0,l,c;
    char buffer[m];
    if (fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    int i=0;
    while ((c = fgetc(fp)) != EOF)
    {
        if(c==' ' || c=='\n')
        {
            int j=i;
            if(buffer[j]=='0' && buffer[j-1]=='0')
                fprintf(fp2,"%s - Ends with 00\n",buffer);
            for(int j=0;j<i-1;j++)
            {
                if(buffer[j]=='0')
                {
                    if(buffer[j+1] =='0' && buffer[j+2]=='0')
                    {
                        fprintf(fp2,"%s - Has 3 consecutive 0's\n",buffer);
                        break;
                    }
                    
                }
            }
            i=0;
        }
        else{
            buffer[i]=c;
            i++;
        }
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        {
            fprintf(fp2,"%c - Vowel\n",c);
            v+=1;
        }
        else if(c!=' ' && c!='\n' && !isdigit(c))
        {
            fprintf(fp2,"%c - Consonant\n",c);
            co+=1; 
        }
        if(c=='\n')
        l+=1;
        
    }
    fprintf(fp2,"Number of Vowels - %d\n",v);
    fprintf(fp2,"Number of Consonants - %d\n",co);
    fprintf(fp2,"Number of Lines - %d\n",l+1);
    fclose(fp);
    fclose(fp2);
    
    return 0;
}