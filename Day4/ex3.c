#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// IMPORTANT
// The program doesnt check for wrong input for the fromDeci()
// int checkDecimal(char* str);

// Checks input in other bases
int checkBaseToDeci(char* str);

// To return char for a value.
char reVal(int num);

// To return value of a char.
int val(char c);

//Reverse a string
void strev(char *str);

char* fromDeci(char res[], int base, int inputNum);

int toDeci(char *str, int base);


int main(void)
{
    while(EOF){
    
        int answer;
        printf("Choose your option: \n");
        printf("From decimal to any base - type 1.\n");
        printf("From any base to decimal - type 2.\n");
        scanf("%d", &answer);
        if (answer == 1)
        {

            int number;
            int baseOut;
            char res[sizeof(int)*8];



            printf("Enter the number and the output base: \n");
            scanf("%d %d", &number, &baseOut);

            char str[sizeof(int)*8];
            sprintf(str, "%d", number);

            
            printf("Equivalent of %d in base %d is %s.\n", number, baseOut, fromDeci(res, baseOut, number));
            printf("\n");
    
            
        }
        else if (answer == 2)
        {
            char str[sizeof(int)*8];
            int base;
            printf("Enter the number and the input base: \n");
            scanf("%s %d", str, &base);

            if(checkBaseToDeci(str) == -1){
                printf("Wrong input.\n");
            }
            else{
                printf("Decimal equivalent of %s in base %d is %d\n", str, base, toDeci(str, base));
                printf("\n");
            }

        }
        else{
            printf("Invalid option.\n");
            printf("\n");
        }

    }
    

    return 0;
}



int checkBaseToDeci(char* str){
    int length = strlen(str);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(str[i]) ==0)
        {
            count++;
        }
        if (isalpha(str[i]) == 0)
        {
            count++;
        }        
    }
    if (count > strlen(str))
    {
        return -1; 
    }
    return 0;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}


int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}


void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;  
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
 
    // Reverse the result
    strev(res);
 
    return res;
}

int toDeci(char *str, int base)
{
    int len = strlen(str);
    int power = 1; 
    int num = 0;  
    int i;
 
    
    for (i = len - 1; i >= 0; i--)
    {
        
        if (val(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}
