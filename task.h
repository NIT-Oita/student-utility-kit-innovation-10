#ifndef TASK_H
#define TASK_H
#define MAX_TASKS 100
#define TITLE_LEN 128
#define SAVE_FILE "tasks.dat"

/* 課題1件分の情報 */
typedef struct {
    int id;                 /* 登録番号 */
    char title[TITLE_LEN];  /* 課題名 */
    int deadline;           /* 期限 YYYYMMDD形式 */
    int done;               /* 0:未完了 1:完了 */
} Task;
#endif