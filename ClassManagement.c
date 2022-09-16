#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct Birthday{
    int day;
    int month;
    int year;
}Birthday;
typedef struct student{
    char name[10];
    char last_name[10];
    Birthday birthday;
    int age;
}student;
void add_student(student* list_of_students, int numbers_of_students)
void display_student(student* list_of_students, int number_of_students)
void bubble_sort(student* list_of_students, int number_of_students);
int age_calculator(int day, int month, int year);
int main(void)
{
    int number_of_students;
    printf("Type the number of students: ");
    scanf("%i", &number_of_students);
    student list_of_students[number_of_students];

    add_student( list_of_students,  numbers_of_students);


    display_student( list_of_students,  number_of_students);

    
    bubble_sort( list_of_students, number_of_students);
}
void display_student(student* list_of_students, int number_of_students)
{
    printf("NAME    |    LAST NAME    |   BIRTHDAY  \n");
    printf("_________________________________________\n");
    for(int i = 0; i < number_of_students; i++ )
    {
        printf("%s", list_of_students[i].name);
        printf("        %s", list_of_students[i].last_name);
        printf("        %i/%i/%i\n", list_of_students[i].birthday.day, list_of_students[i].birthday.month, list_of_students[i].birthday.year );
    }
}
void add_student(student* list_of_students, int numbers_of_students)
{
    for(int i = 0; i < number_of_students; i++ )
    {
        printf("Type the name of the %ith student: ", i+1);
        scanf("%s", list_of_students[i].name);
        printf("Type the last name of the %ith student: ", i+1);
        scanf("%s", list_of_students[i].last_name);
        printf("Enter the birthday of that student(DD/MM/YYYY): ");
        scanf("%d %d %d", &list_of_students[i].birthday.day, &list_of_students[i].birthday.month, &list_of_students[i].birthday.year);
        list_of_students[i].age = age_calculator( list_of_students[i].birthday.day,  list_of_students[i].birthday.month,  list_of_students[i].birthday.year);
        system("cls");
    }
}
void bubble_sort(student* list_of_students, int number_of_students)
{
    student temp;
    int count = -1;
    while( count != 0 )
    {
        count = 0;
        for( int i = 0; i < number_of_students - 1; i++ )
        {
            if(list_of_students[i].age > list_of_students[i + 1].age)
            {
                temp = list_of_students[i];
                list_of_students[i] = list_of_students[i + 1];
                list_of_students[i + 1] = temp;
                //
                count++;
            }
        }
    }

}
int age_calculator(int day, int month, int year)
{
    day = 16 - day;
    month = 9 - month;
    year = 2022 - year;
    int days = day + (month*31) + (year*365);
    return days;
}
