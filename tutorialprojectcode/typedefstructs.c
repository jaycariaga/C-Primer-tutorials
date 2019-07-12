#include <stdio.h>

//a sample of code that implements structures as VARIABLES using typedef and
//the dot operator for callbacks (POINTERS are not used in this occasion)

typedef struct student
{
    char name[50];
    int roll;
    float marks;
}stud;

void printStudent(stud s[], int size);

void printStudent(stud s[], int size){
  printf("Displaying Information:\n\n");
    // displaying information
    for(int i=0; i<size; i++)
    {
        printf("\nRoll number: %d\n",i+1);
        printf("Name: %s \n", s[i].name);
        printf("Marks: %.1f",s[i].marks);
        printf("\n");
    }
}

int main()
{
    int size = 2;
    stud s[size];

    printf("Enter information of students:\n");
    // storing information
    for(int i=0; i<sizeof(s)/sizeof(stud); i++)
    {
        s[i].roll = i+1;
        printf("\nFor roll number%d,\n",s[i].roll);
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter marks: ");
        scanf("%f",&s[i].marks);
        printf("\n");
    }

    // displays data inside the main method

    //for(int i=0; i<sizeof(s)/sizeof(stud); ++i)
    //{
    //    printf("\nRoll number: %d\n",i+1);
    //    printf("Name: %s \n", s[i].name);
     //   printf("Marks: %.1f",s[i].marks);
     //   printf("\n");
    //}
    printStudent(s, sizeof(s)/sizeof(stud)); 
//sizeof(s)/sizeof(stud) is equivalent to int size
    printf("HI"); //just to test if code sees through

    return 0;
}
