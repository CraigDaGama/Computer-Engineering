#include<stdio.h>
#include<string.h>
int main(void)
{
    FILE *El;
        El=fopen("test.txt","w");
            if(El==NULL)
            {
                printf("\nFile does not exist...");
            }
            else
            {
                printf("\nFile opened successfully...");
            }
fclose(El);
}
