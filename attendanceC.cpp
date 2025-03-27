#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char studname[20][30];
int presentattendance[20]={0};
int absentattendance[20]={0};
int indexnumber=0;

void checkattendance()
{
    int i;
    printf("\n Total present | Total absent \n");
    for(i=0;i<indexnumber;i++)
    {
        printf("%s ", studname[i]); 
        printf("%d %d \n", presentattendance[i], absentattendance[i]); 
    }
}

void addstudent()
{
    int i, num, add;
    if(indexnumber == 0)
    {
        printf("Enter how many students you want to add:");
        fflush(stdin);
        scanf("%d", &num);
        while ((getchar()) != '\n'); 
        for(i = 0; i < num; i++)
        {
            printf("\n Enter %d student name to add in attendanceragister:", i + 1);
            fgets(studname[i], sizeof(studname[i]), stdin);
            studname[i][strcspn(studname[i], "\n")] = '\0'; 
            indexnumber++;
        }
    }
    else
    {
        printf("Enter how many students you want to add:");
        fflush(stdin);
        scanf("%d", &num);
        while ((getchar()) != '\n'); 
        add = indexnumber + num;
        for(i = indexnumber; i < add; i++)
        {
            printf("\n Enter %d student name to add in attendance ragister:", i + 1);
            fgets(studname[i], sizeof(studname[i]), stdin);
            studname[i][strcspn(studname[i], "\n")] = '\0'; 
            indexnumber++;
        }
    }
}

void takeattendance()
{
    int i;
    char ch;
    printf("\n Enter Y for present and N for absent \n");
    for(i = 0; i < indexnumber; i++)
    {
    repeate:
        printf("%d %s is present:", i + 1, studname[i]);
        fflush(stdin);
        scanf(" %c", &ch); 
        if(ch == 'Y' || ch == 'y')
        {
            presentattendance[i] += 1;
        }
        else if(ch == 'N' || ch == 'n')
        {
            absentattendance[i] += 1;
        }
        else
        {
            printf("Invalid character try again \n");
            goto repeate;
        }
    }
}

int main()
{
    int choose;
    do
    {
        printf("\n**********************Main Menu************************\n");
        printf("Enter 1 for add student\n");
        printf("Enter 2 for take attendance \n");
        printf("Enter 3 for check attendance \n");
        printf("Enter 4 for exit \n");
        printf("please choose any menu: ");
        fflush(stdin);
        scanf("%d", &choose);
        switch(choose)
        {
            case 1:
            addstudent();
            break;
            case 2:
            takeattendance();
            break;
            case 3:
            checkattendance();
            break;
            case 4:
            exit(0);
            break;
        }
    }while(choose != 5);
    return 0;
}