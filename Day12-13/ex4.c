#include <stdio.h>
#include <stdint.h>

void Conv(int sValue, char*pBuffer){
    if (sValue>=0)
    {
        *(pBuffer) = ' ';
    }
    else{
        *(pBuffer) = '-';
        sValue = -sValue;
    }
    int i = 0;
    for (i = 5; i > 0; i--)
    {
        *(pBuffer +i) = sValue%10+'0';
        sValue/=10;
    }
    
    *(pBuffer+5) = '\0';
    
}

int main() {
    char buff[5];
    uint16_t num = -26;
    Conv(num, buff);
    printf("%s",buff);


    return 0;
}
