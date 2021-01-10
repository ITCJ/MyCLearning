#include <stdio.h>
#include <stdlib.h>

//用小写，我们学校出题经常用大写，并且不加分号
struct student
{
    int num;
    char name[20];
    struct student *next;
};                                  //注意

int main()
{
    struct student *head, *pThis, *pNext;

    head = pThis = pNext = (struct student *) malloc(sizeof(struct student));
    scanf("%d %s", &head -> num, &head -> name);

    while (pNext -> num >= 0)
    {
        pThis -> next = pNext;
        pThis = pNext;
        pNext = (struct student *) malloc( sizeof(struct student) );
        scanf("%d %s", &pNext -> num, &pNext -> name);
    }

    pThis -> next = NULL;
    return 0;
}