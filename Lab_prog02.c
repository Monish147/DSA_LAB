//DSA_LAB_PROGRAM_2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//finding pattern in string
void findpat(char *str, char *pat, char *rep){
    int i,m,k,c,j,flag=0;
    char res[100];
    i = m = c = j = 0;
    while ( str[c]!='\0'){
        if (str[m] == pat[i]){ 
            i++;
            m++;
            if ( pat[i]=='\0'){
                for(k=0; rep[k]!='\0'; k++){
                    res[j] = rep[k];
                    j++;
                    flag=1;
                }
                i=0;
                c=m;
            }
        }
        else{
            res[j] = str[c];
            j++;
            c++;
            m = c;
            i=0;
        }
    }
    if(flag==0){
        printf("pattern not found\n");
    }
    else{
        res[j] = '\0';
        printf("\nThe resultant string is:%s\n" ,res);
    }
}

int main(){
    char str[100], pat[100], rep[100];
    scanf("%s %s %s", &str, &pat, &rep);
    findpat(str, pat, rep);
    return 0;
}
