#include <stdio.h>
#include <string.h>

struct Person  GetUserInput() ;

// create struct with person1 variable
struct Person {
	char name[50];
	int citNo;
	float salary;
} person1;

int main(int argc, char *argv[]) {
	// assign value to name of person1
	strcpy(person1.name, "George Orwell");
	// assign values to other person1 variables
	person1.citNo = 1984;
	person1. salary = 2500;
	// print struct variables
	printf("\nName: %s\n", person1.name);
	printf("\nCitizenship No.: %d\n", person1.citNo);
	printf("\nSalary: %.2f\n", person1.salary);
	printf("\n\n");
	struct Person person2 = GetUserInput();
	printf("\n\nNew Person Information Output\n");
	printf("\nName: %s\n", person2.name);
	printf("\nCitizenship No.: %d\n", person2.citNo);
	printf("\nSalary: %.2f\n", person2.salary);
	printf("\n\n");
	return 0;
}

struct Person  GetUserInput() {
	struct Person person2;
	printf("\nEnter the persons first name - ");
	scanf("%s",  person2.name);
	printf("\nEnter the persons citizenship number - ");
	scanf("%d", &person2.citNo);
	printf("\nEnter the persons salary - ");
	scanf("%f", &person2.salary);
	// assign values to other person1 variables
	return person2;
}
