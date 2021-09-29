#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of the employee
struct employee_attributes
{

    int employee_id ;
    char name[101] ;
    char blood_group[101] ;
    char gender[101] ;
    int age ;
    int project_id ;
    char team_leader[101] ;
    char role[101] ;
};

struct employee_attributes data;
int size ;


int size = sizeof(data);

FILE *fptr ;

// Function to add the records
void addData()
{
    system("cls");
    fseek(fptr, 0, SEEK_END);
    char input;

    do
    {
        printf("\nEnter the Employee-id : ");
        scanf("%d",&data.employee_id);

        printf("\nEnter the name : ");
        scanf("%s",data.name);

        printf("\nEnter age : ");
        scanf("%d",&data.age);

        printf("\nEnter blood-group : ");
        scanf("%s",data.blood_group);

        printf("\nEnter the project-id : ");
        scanf("%d",&data.project_id);

        printf("\nEnter team-leader : ");
        scanf("%s",data.team_leader);

        printf("\nEnter role : ");
        scanf("%s",data.role);


        fwrite(&data, size, 1, fptr);

        printf("\nWant to add another data of another employee ? (Y/N) ");
        fflush(stdin);

        scanf("%c",&input);

    } while(input == 'y' || input == 'Y');

}


// Function to display the record
void displayData()
{
    system("cls");

    // sets pointer to start
    // of the file
    rewind(fptr);

    printf("\nemployee_id\t\tname\t\tblood_group\t\t"
           "\tgender\t\tproject_id\t\t"
           "\tteam_leader\t\trole\n",
           data.employee_id, data.name, data.blood_group,data.gender,data.project_id,data.team_leader, data.role);

    printf("\n");

    while (fread(&data, size, 1, fptr) == 1)
        printf("\n%d\t\t%s\t\t%s\t%s\t\t%d\t\t%s\t\t%s",
               data.project_id, data.name, data.blood_group, data.gender,data.project_id,data.team_leader,data.role);

    printf("\n\n\n\t");
    system("pause");
}



void searchData()
{

    system("cls");
    int employe_id;
    char input ;

    do
    {
        printf("\nEnter employee-id: ");
        scanf("%d", &employe_id);

        rewind(fptr);

        // While File is open
        while (fread(&data, size, 1, fptr) == 1)
        {
            // Compare the employee name
            // with ename
            if ( data.employee_id == employe_id )
            {

                printf("\nemployee_id\t\tname\t\tblood_group\t\t"
                       "\tgender\t\tproject_id\t\t"
                       "\tteam_leader\t\trole\n",
                       data.employee_id, data.name, data.blood_group,data.gender,data.project_id,data.team_leader, data.role);

                printf("\n");


                fseek(fptr, -size, SEEK_CUR);
                fwrite(&data, size, 1, fptr);
                break;
            }
        }

        // Ask for modifying another record
        printf("\nWant to search another employee-id ? (Y/N) ");
        fflush(stdin);
        scanf("%c", &input);

    } while(input == 'y' || input == 'Y');
}

int main()
{
    int select ;

    // opening the file
    fptr = fopen("data.txt", "rb+");

    // showing error if file is
    // unable to open.
    if (fptr == NULL)
    {
        fptr = fopen("data.txt", "wb+");
        if (fptr == NULL)
        {
            printf("Warning!!! File cannot be opened --->");
            exit(1);
        }
    }

    while (1)
    {

        system("cls");
        printf("BUILD COLUMN OF ATTRIBUTES BY ADDING DATA--------->INPUT(1)\n");
        printf("DISPLAY THE DATAS OF THE COLUMN------------------->INPUT(2)\n");
        printf("SEARCH EMPLOYEE BY ID----------------------------->INPUT(3)\n") ;
        printf("EXIT THE PROGRAM---------------------------------->INPUT(4)\n");
        printf("ENTER YOUR COMMAND///////////////////\n");
        fflush(stdin);
        scanf("%d", &select);


        // Calling Function after judging inputs
        if (select == 1)
        {
            addData() ;
        }
        else if (select == 2)
        {
            displayData();
        }
        else if(select == 3 )
        {
            searchData() ;
        }

        else if (select == 4)
        {
            fclose(fptr);
            exit(0);
        }

        else
            printf("CANNOT PROCESS THE REQUEST, PLEASE FOLLOW THE INSTRUCTIONS--->\n");
    }

    return 0;
}
