#include <stdio.h>  
#include <stdint.h>

int printStudents(uint32_t att, unsigned a){
    return att & (1 << a);
}

int main(void)
{
    uint32_t attendance = 0;
    int option;
    int attendee = 0;
    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        if (option == 1)
        {
            printf("Which student do u want to set\n");
            scanf("%d", &attendee);
            attendance |= (1<<attendee-1);
            
        }
        else if (option == 2)
        {
            printf("Which student do u want to clear\n");
            scanf("%d", &attendee);
            attendance &= ~(1<<attendee-1);
        }
        else if (option == 3)
        {
           for (int i = 0; i<32; i++){
                printf("%d", printStudents(attendance, i));
        }
        printf("\n");
        }
        else if (option ==4)
        {
            printf("Which student do u want to change\n");
            scanf("%d", &attendee);

            attendance ^=(1<<attendee-1);
        }
        

        else if(option == 5){
            break;
        }

        else{
            printf("Choose a valid option.\n");
        }
    }
    return 0;
}
