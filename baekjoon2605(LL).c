#include <stdio.h>
#include <stdlib.h>

/* ERROR Version (Uncompleted) */

typedef struct NODE {
    int value;
    int move;
    struct NODE* next;
} NODE;

int main()
{
    int student_n;
    NODE* head = (NODE*)malloc(sizeof(NODE));
    NODE* line = NULL;

    scanf("%d", &student_n);
    line = (NODE*)malloc(student_n * sizeof(NODE));
    head->next = line;
    int i;
    for (i = 0; i < student_n - 1; i++) {
        line[i].value = i + 1;
        // line[i] = i+1;
        scanf("%d", &(line[i].move));

        line[i].next = &line[i + 1];
        // appended
        NODE* p = line + i;
        if (p->move == 0) {
            continue;
        }

    }
    line[i].value = i+1;


    // test code
    for (int i = 0; i < student_n; i++) {
        printf("%d ", line[i].value);
    }

    head->next = line;
    int j = 0;
    for (; j < student_n - 1; j++) {
        line[j].next = &line[j + 1];
    }
    line[j].next = NULL;

    NODE* t = head->next;

    int i = 0;
    while (t != NULL && i<student_n) {
        if (t->move == 0) {
            t = t->next;
            i++;
            continue;
        }
        int m = t->move;

        //if (i - m == 0)
        //    head->next = &line[i];
        //else
        //    line[i - m - 1].next = &line[i];

        //line[i].next = &line[i - m];

        //if (&line[i + 1] != NULL)
        //    line[i - m].next = &line[i + 1];
        //else
        //    line[i - m].next = NULL;

        t = t->next;
        i++;
    }

    printf("\n\nAnswer(array after ordering):\n");

    t = head->next;
    while (t != NULL) {
        printf("%d ", t->value);
        t = t->next;
    }

    return 0;
}
