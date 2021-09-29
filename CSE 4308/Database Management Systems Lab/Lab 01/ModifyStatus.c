#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementation of Structure
struct project_attributes
{
    int project_id ;
    int employe_number ;
    char project_name[101] ;
    char employer_name[101] ;
    int estimated_completion_time ;
    int estimated_budget ;
    char status[101] ;
};

struct project_attributes data;
int size ;

int size = sizeof(data);

FILE *fptr ;

// Adding data
void addData()
{
    system("cls");
    fseek(fptr, 0, SEEK_END);

    char input ;

    do
    {
        printf("\nEnter the Project-id : ");
        scanf("%d",&data.project_id);

        printf("\nEnter the Project-name : ");
        scanf("%s",data.project_name);

        printf("\nEnter the employer name : ");
        scanf("%s",data.employer_name);

        printf("\nEnter the estimated-budget : ");
        scanf("%d",&data.estimated_budget );

        printf("\nEnter the estimated completion time of the project(months) : ");
        scanf("%d",&data.estimated_completion_time);

        printf("\nEnter the number of employees : ");
        scanf("%d",&data.employe_number);

        printf("\nEnter the status of the project : ");
        scanf("%s",data.status);


        fwrite(&data, size, 1, fptr);

        printf("\n Want to add another data of another employee ? (Y/N) ");
        fflush(stdin);

        scanf("%c", &input);

    }while(input == 'y' || input == 'Y');

}


// Display data
void displayData()
{
    system("cls");


    rewind(fptr);

    printf("\nproject_id\t\tproject_name\t\temployer_name\t\t"
           "\testimated_budget($)\t\tETA(months)\t\t"
           "\tno._of_employees\t\tstatus\n",
           data.project_id, data.project_name, data.employer_name,data.estimated_budget,data.estimated_completion_time,data.employe_number, data.status);

    printf("\n");

    while (fread(&data, size, 1, fptr) == 1)
        printf("\n%d\t\t%s\t\t%s\t%d\t\t%d\t\t%d\t\t%s",
               data.project_id, data.project_name, data.employer_name,data.estimated_budget,data.estimated_completion_time,data.employe_number, data.status);

    printf("\n\n\n\t");
    system("pause");
}


void modifyData()
{
    system("cls");
    int project_number;
    char input;

    do
    {
        printf("\nEnter the project id to modify the status : ");
        scanf("%d",&project_number);

        rewind(fptr);

        // While File is open
        while (fread(&data, size, 1, fptr) == 1)
        {

            if ( project_number == data.project_id)
            {
                printf("\nModify the status of the project :");
                scanf("%s", data.status);
                fseek(fptr, -size, SEEK_CUR);
                fwrite(&data, size, 1, fptr);
                break;

            }
        }

        // Asking for modifying new data
        printf("\nWant to modify another project status (Y/N) ?");
        fflush(stdin);
        scanf("%c", &input);

    }while (input == 'y' || input == 'Y');


}


int main()
{
    int select ;

    // For opening file
    fptr = fopen("data.txt", "rb+");

    // Will show error when file is unable to open.

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
        printf("BUILD COLUMN OF ATTRIBUTES BY ADDING DATA------------------------------------------------------------------------->INPUT(1)\n");
        printf("DISPLAY THE DATAS OF THE COLUMN---------------------------------------------------------------------------------- >INPUT(2)\n");
        printf("MODIFY THE STATUS OF THE PROJECTS HAVING BUDGETS GREATER THAN 60,000$ TO 'ongoing' BY SELECTING THE PROJECT_ID---->INPUT(3)\n") ;
        printf("EXIT THE PROGRAM-------------------------------------------------------------------------------------------------->INPUT(4)\n");
        printf("PLEASE ENTER ANY COMMAND ! \n");
        fflush(stdin);
        scanf("%d",&select);


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
            modifyData() ;
        }

        else if (select == 4)
        {
            fclose(fptr);
            exit(0);
        }

        else
            printf(" CANNOT PROCESS THE REQUEST, PLEASE FOLLOW THE INSTRUCTIONS---->\n");

    }

    return 0;
}
