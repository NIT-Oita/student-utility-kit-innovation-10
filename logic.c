#include <time.h>
#include "logic.h"

/*
 * 今日の日付をYYYYMMDD形式で取得する
 */
int today_as_int(void)
{
    time_t now;
    struct tm *t;
    now = time(NULL);
    t = localtime(&now);

    if (t == NULL) {
        return 0;
    }

    return (t->tm_year + 1900) * 10000
         + (t->tm_mon + 1) * 100
         + t->tm_mday;
}

/*
 * 期限切れ判定
 *
 * 未完了かつ期限が今日より前なら1を返す
 */
int is_overdue(const Task *t)
{
    /*
     * 完了済みは期限切れ扱いしない
     */
    if (t->done) {
        return 0;
    }
    /*
     * 期限未設定も期限切れ扱いしない
     */
    if (t->deadline == 0) {
        return 0;
    }

    return t->deadline < today_as_int();

}

/*
 * 期限順に並べ替える
 */
void task_sort(Task list[], int count)
{
    int i;
    int j;
    int min;
    Task tmp;

    for (i = 0; i < count - 1; i++) {

        min = i;
        for (j = i + 1; j < count; j++) {

            if (list[j].deadline < list[min].deadline) {
                min = j;
            }
        }

        if (min != i) {

            tmp = list[i];
            list[i] = list[min];
            list[min] = tmp;
        }
    }
}

/*
 * 完了状態を切り替える
 */
int task_toggle_done(Task list[], int count, int id)
{
    int i;
    for (i = 0; i < count; i++) {

        if (list[i].id == id) {
            list[i].done = !list[i].done;
            return 1;
        }
    }
    return 0;
}

/*
 * 課題を削除する
 */
int task_delete(Task list[], int *count, int id)
{
    int i;
    int j;

    for (i = 0; i < *count; i++) {

        if (list[i].id == id) {

            for (j = i; j < *count - 1; j++) {
                list[j] = list[j + 1];
            }

            (*count)--;
            return 1;
        }
    }
    return 0;
}