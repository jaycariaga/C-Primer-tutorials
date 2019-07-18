
#include <stdio.h>
#include <stdbool.h>
#include <string.h> //needed for string comparisons
#define getName(var)  #var


//current problem running: on searching via struct variable "roll", returning elements past first index returns something out of bounds.
//refer to function "elementchangestudent()"

struct student
{
    char firstname[50];
    int roll;
    char lastname[50];
}ok; //sets a "structure variable" s

//list of functions for structure student
void printStudentPointer(struct student *a, int);
void printStudentdot(struct student a[], int);
void elementchangestudent(int size, struct student * a); //* needed to call onto the value of the structure itself
struct student returninfo();

struct student returninfo(){
	
	printf("hello world");
}

void printStudentPointer(struct student *s, int size) 
{ 
  printf("\nThis is for printing thru pointers\n");
 for(int i=0; i<size; ++i){
  printf("Student_id : %d\n"
         "First Name  : %s\n"
         "Last Name: %s\n",
          s->roll, s->firstname, s->lastname);
  s++;  
 }
}

void printStudentdot(struct student s[], int size){
  printf("\nThis is for printing thru the dot operator.\n");
  for(int i=0; i < size ; ++i){
  printf("Student_id : %d\n"
         "First Name  : %s\n"
         "Last Name: %s\n",
          s[i].roll, s[i].firstname, s[i].lastname);

  }
}

//asks user what value to change from which id, and changes it if matches
//where student s is a structural array and size is the element size of s
//call the function in main with: "elementchangestudent(&s, size);
void elementchangestudent(int size, struct student * s){ //* pointer needed for updating schematics
  int i = 0;
  bool truth = false;
  int answer; //used for id checking through an array of structures

//asks for ID (the "roll" variable of struct student)
  printf("\nID of student: ");
  scanf("%d", &answer);

//searches for match of item:
  for(; i < size ; ++i){
	int rollcall = s[i].roll;   //(*s)->roll;
        if(answer == rollcall){
	   printf("%d matches with: ", answer);
	   printf("%d \n", s[i].roll);
	   truth = true; //validation to allow user to change 'firstname' of item with matching id
	  printf("Student_id : %d\n"
         "First Name  : %s\n"
         "Last Name: %s\n",
          s[i].roll, s[i].firstname, s[i].lastname); //shows matching id details
	   break;
	}
	else{
	   printf("\n%d does not match with: ",answer);
	   printf("%d\n", rollcall);
 	}
	  
  } //end of for loop

	if(truth){ //success in finding the id using input
	 //code to change firstname
	  printf("\nEnter the new firstname: ");
	  scanf("%s", s[i].firstname);
	  //(*s)->firstname = newfirst;
	  printf("Success");
	}

}



void main(){
  //bool continue = true; //for while loop compare
  int counter = 0; //for indexing thru array struct
  char check; //meant for boolean
  int size = 3; //a fixed set for array size

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
	//printf("\nContinue? (Y,n): "); //meant to find a way to add new structure variables using a while loop (does not work yet)
        //scanf("%s",check);
	//if(check == "n")
	//   continue = false;
    } //end of while loop

	
        int truesize = sizeof(s)/sizeof(s[0]); //finds the size (equivalent to variable size)
	printStudentPointer(s, truesize); //works

	printStudentdot(s, truesize); //works too

	elementchangestudent(truesize, s); //&s as a dereferencing for the pointer in the function call.
	printStudentdot(s, truesize); //checks to see the final result



}

