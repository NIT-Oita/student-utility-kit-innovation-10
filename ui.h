#ifndef UI_H
#define UI_H

#include "task.h"



/* WindowsのコンソールをUTF-8表示に設定する */
void init_console(void);



/* メニュー表示 */
void show_menu(void);



/* メニュー番号入力 */
int input_choice(void);



/* 課題入力 */
int input_task(Task *t);



/* ID入力 */
int input_id(void);



/* 課題一覧表示 */
void show_tasks(const Task list[], int count);



/* エラー表示 */
void show_error(void);



#endif