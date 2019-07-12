
#include <stdio.h>
#include <stdbool.h>  //NEEDED for boolean variables and using .c instead of .cpp

struct student
{
    char firstname[50];
    int roll;
    char lastname[50];
}ok; //sets a "structure variable" s

void printStudentPointer(struct student *a, int);
void printStudentdot(struct student a[], int);

void printStudentPointer(struct student *s, int size) 
{ 
 for(int i=0; i<size; ++i){
  printf("Student_id : %d\n"
         "First Name  : %s\n"
         "Last Name: %s\n",
          s->roll, s->firstname, s->lastname);
  s++;  
 }
}

void printStudentdot(struct student s[], int size){
  for(int i=0; i < size ; ++i){
  printf("Student_id : %d\n"
         "First Name  : %s\n"
         "Last Name: %s\n",
          s[i].roll, s[i].firstname, s[i].lastname);

}

}

void main(){
  //bool continue = true; //for while loop compare
  int counter = 0; //for indexing thru array struct
  char check; //meant for boolean
  int size = 2; //a fixed set for array size

  struct student s[size]; //variable structure array 's' created
      
   //stores info
    while(counter < size){
	printf("Enter info of this student:\n");
        s[counter].roll = counter+1;
        printf("\nFor identification number%d,\n",s[counter].roll);
        printf("Enter first name: ");
        scanf("%s",s[counter].firstname);
        printf("\nEnter last name: ");
        scanf("%s",s[counter].lastname);
        printf("\n");
	counter++;
	//printf("\nContinue? (Y,n): ");
        //scanf("%s",check);
	//if(check == "n")
	//   continue = false;
    }
        int truesize = sizeof(s)/sizeof(s[0]);
	printStudentPointer(s, truesize); //works

	printStudentdot(s, truesize); //works too
}

