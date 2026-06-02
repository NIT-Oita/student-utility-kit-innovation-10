#include <stdio.h>
#include "storage.h"

#define FILE_NAME "tasks.csv"

void save_tasks(Task list[], int count)
{
    FILE *fp = fopen(FILE_NAME, "w");

    if (fp == NULL) {
        printf("ファイルを開けません\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp,
                "%d,%s,%s,%d,%d\n",
                list[i].id,
                list[i].title,
                list[i].deadline,
                list[i].priority,
                list[i].done);
    }

    fclose(fp);
}

void load_tasks(Task list[], int *count)
{
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        *count = 0;
        return;
    }

    *count = 0;

    while (*count < MAX_TASKS &&
           fscanf(fp,
                  "%d,%63[^,],%10[^,],%d,%d\n",
                  &list[*count].id,
                  list[*count].title,
                  list[*count].deadline,
                  &list[*count].priority,
                  &list[*count].done) == 5) {

        (*count)++;
    }

    fclose(fp);
}