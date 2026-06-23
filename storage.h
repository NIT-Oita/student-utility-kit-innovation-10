#ifndef STORAGE_H
#define STORAGE_H
#include "task.h"
/*
 * 課題一覧を保存する
 *
 * 成功:1
 * 失敗:0
 */
int save_tasks(const Task list[], int count);
/*
 * 課題一覧を読み込む
 *
 * 成功:1
 * 失敗:0
 */
int load_tasks(Task list[], int *count);
/*
 * 次に使用するIDを取得する
 */
int get_next_id(const Task list[], int count);
#endif