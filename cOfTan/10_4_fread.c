#include <stdio.h>

typedef struct
{
    int num;
    char name[20];
} student;

int main ()
{
    FILE *fp;
    fp = fopen("student.dat","w+");
    if (fp == NULL)
    {
        printf("file w+ failed!\n");
    }else
    {
        printf("file w+ success!\n");
    }
    
    student stuList[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %s", &stuList[i].num, &stuList[i].name);

        // fprintf(fp, "%d %s\n", stuList[i].num, stuList[i].name);
        if ( fwrite(&stuList[i], sizeof(student), 1, fp) != 1)
            printf("fwrite error!\n");
    }
    
    // fseek(fp, 0, SEEK_SET); 

    // student stuList2[4];
    // for (int i = 0; i < 4; i++)
    // {
    //     fread(&stuList2[i], sizeof(student), 1, fp);
    //     // fscanf(fp, "%d %s", &stuList2[i].num, &stuList2[i].name);

    //     printf("%d\t%s\n", stuList2[i].num, stuList2[i].name);
    // }
    
    fclose(fp);

    return 0;
}