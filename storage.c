#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

/*
 * 課題一覧をファイルへ保存する
 */
int save_tasks(const Task list[], int count)
{
    FILE *fp;
    int i;
    fp = fopen(SAVE_FILE, "w");

    if (fp == NULL) {
        return 0;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp,
                "%d|%s|%d|%d\n",
                list[i].id,
                list[i].title,
                list[i].deadline,
                list[i].done);
    }

    fclose(fp);
    return 1;
}

/*
 * ファイルから課題一覧を読み込む
 */
int load_tasks(Task list[], int *count)
{
    FILE *fp;
    char line[256];
    int n = 0;
    fp = fopen(SAVE_FILE, "r");

    if (fp == NULL) {
        *count = 0;
        return 0;
    }

    while (n < MAX_TASKS &&
           fgets(line, sizeof(line), fp) != NULL) {
        char *field;
        /*
         * 改行削除
         */
        line[strcspn(line, "\r\n")] = '\0';
        /*
         * ID
         */
        field = strtok(line, "|");

        if (field == NULL) {
            continue;
        }

        list[n].id = atoi(field);
        /*
         * タイトル
         */
        field = strtok(NULL, "|");

        if (field == NULL) {
            continue;
        }

        strncpy(list[n].title,
                field,
                TITLE_LEN - 1);

        list[n].title[TITLE_LEN - 1] = '\0';
        /*
         * 期限
         */
        field = strtok(NULL, "|");

        if (field == NULL) {
            continue;
        }

        list[n].deadline = atoi(field);
        /*
         * 完了状態
         */
        field = strtok(NULL, "|");

        if (field == NULL) {
            continue;
        }

        list[n].done = atoi(field);
        n++;
    }

    fclose(fp);
    *count = n;
    return 1;
}

/*
 * 次に使うIDを取得する
 */
int get_next_id(const Task list[], int count)
{
    int i;
    int max_id = 0;

    for (i = 0; i < count; i++) {

        if (list[i].id > max_id) {
            max_id = list[i].id;
        }

    }
    return max_id + 1;
}