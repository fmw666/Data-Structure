#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int n;
    if((fp=fopen("input.txt", "r"))==NULL)
    {
        printf("Error: txt file can't open!\n");
        exit(1);
    } 
    else 
    {
        while(fscanf(fp,"%d",&n) != EOF);
    }

    char str[10];
    int result[10] = {0};
    for(int i=1; i<=n; i++)
    {
        sprintf(str, "%d", i);
        for(int j=0; str[j]; j++)
            result[str[j]-'0']++;
    }

    if((fp=fopen("output.txt", "w"))==NULL)
    {
        printf("Error: txt file can't open!\n");
        exit(1);
    } 
    for(int i=0; i<10; i++)
        fprintf(fp, "%d\n", result[i]);
    fclose(fp);

    return 0;
}