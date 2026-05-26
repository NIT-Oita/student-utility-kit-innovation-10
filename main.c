#include <stdio.h>
#include <string.h>
#include "logic.h"

/* UI関数（ui.cにある想定） */
void show_menu(void);
int input_choice(void);
void input_task(Task *t);
void show_tasks(Task *list, int n);

#define MAX 100

int main(void)
{
    Task list[MAX];
    int count = 0;
    int choice;

    char today[11] = "2026-01-01"; // 仮（本当は入力でもOK）

    while (1) {

        show_menu();
        choice = input_choice();

        if (choice == 0) break;

        /* ① 追加 */
        if (choice == 1) {
            if (count >= MAX) {
                printf("これ以上追加できません\n");
                continue;
            }

            input_task(&list[count]);
            list[count].id = count;
            list[count].done = 0;
            count++;
        }

        /* ② 表示（順位付け） */
        else if (choice == 2) {
            task_sort(list, count);
            show_tasks(list, count);
        }

        else {
            printf("入力エラー\n");
        }
    }

    return 0;
}