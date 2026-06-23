#ifndef LOGIC_H
#define LOGIC_H
#include "task.h"

/* 期限が近い順に並べ替える */
void task_sort(Task list[], int count);

/* 指定IDの完了状態を切り替える */
int task_toggle_done(Task list[], int count, int id);

/* 指定IDの課題を削除する */
int task_delete(Task list[], int *count, int id);

/* 今日の日付をYYYYMMDD形式で取得する */
int today_as_int(void);

/* 期限切れなら1、それ以外は0 */
int is_overdue(const Task *t);

#endif