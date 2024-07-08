#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

void name_function();
void pass_function();

int main()
{
    int choice;
    scanf("%d", &choice);
    
    while(choice == 1 || choice == 2)
    {
        switch(choice)
        {
            case 1: name_function();
            break;
            case 2: pass_function();
            break;
        }

        scanf("%d", &choice);
        if(choice != 1 || choice != 2) exit(0);
    }
    
    return 0;
}


void name_function()
{   
    char first_name[21];
    char middle_name[21];
    char last_name[21];
    char full_name[64];

    scanf("%s%s%s", first_name, middle_name, last_name);

    strcpy(full_name, last_name);
    strcat(full_name, ", ");
    strcat(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, middle_name);
    
    printf("%s\n", full_name);
}

void pass_function()
{
    char pass[100];
    scanf("%s", pass);

    int length = strlen(pass);
    int lower = 0, upper = 0, digit = 0, punct = 0;

    for(int i = 0; i<length; i++)
    {
        if(islower(pass[i]))  lower = 1;
        if(isupper(pass[i]))  upper = 1; 
        if(isdigit(pass[i]))  digit = 1;
        if(ispunct(pass[i]))  punct = 1;
    }

    if(length <6)  printf("Password too short\n");
    if(length>14)  printf("Password too long\n");
    if(lower == 0) printf("Password missing lowercase letter\n");
    if(upper == 0) printf("Password missing uppercase letter\n");
    if(digit == 0) printf("Password missing digit\n");
    if(punct == 0) printf("Password missing punctuation\n");
    else printf("Valid password\n");

}

