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

FILE *fptr, *fptr2 ;

// Adding data
void addData()
{
    system("cls");
    fseek(fptr, 0, SEEK_END);
    char input;

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

        printf("\nWant to add another data of another employee ? (Y/N) ");
        fflush(stdin);

        scanf("%c", &input);

    }while(input == 'y' || input == 'Y');
}


// Display data
void displayData()
{
    system("cls");

    // sets pointer to start
    // of the file
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


void deleteData()
{
    system("cls");
    int budget ;
    char input;

    do
    {
        printf("\nEnter the budget($) for removing project containing such budget : ");
        scanf("%d",&budget);

        fptr2 = fopen("temp.txt", "wb");
        rewind(fptr);

        while (fread(&data, size, 1, fptr)== 1)
        {
            if ( budget > data.estimated_budget)
                fwrite(&data, size, 1, fptr2);
        }

        fclose(fptr);
        fclose(fptr2);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fptr = fopen("data.txt", "rb+");

        printf("\nWant to delete another project containing budget under 60,000$ (Y/N) ?");
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
        // Clearing console and asking the
        // user for input
        system("cls");
        printf("BUILD COLUMN OF ATTRIBUTES BY ADDING DATA--------->INPUT(1)\n");
        printf("DISPLAY THE DATAS OF THE COLUMN------------------->INPUT(2)\n");
        printf("DELETE PROJECTS WITH BUDGETS UNDER 60,000$-------->INPUT(3)\n") ;
        printf("EXIT THE PROGRAM---------------------------------->INPUT(4)\n");
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
            deleteData() ;
        }

        else if (select == 4)
        {
            fclose(fptr);
            exit(0);
        }

        else
            printf("CANNOT PROCESS THE REQUEST, PLEASE FOLLOW THe INSTRUCTIONS---> \n");
    }

    return 0;
}
