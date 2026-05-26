
#include <stdio.h>
#include "logic.h"
#include "storage.h"

/* ui関数 */
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

    while (1) {

        show_menu();
        choice = input_choice();

        if (choice == 0) break;

        /* 追加 */
        else if (choice == 1) {
            input_task(&list[count]);
            list[count].id = count;
            list[count].done = 0;
            count++;
        }

        /* 表示 */
        else if (choice == 2) {
            task_sort(list, count);
            show_tasks(list, count);
        }

        /* 保存 */
        else if (choice == 3) {
            save_tasks(list, count);
            printf("保存しました\n");
        }

        /* 読み込み */
        else if (choice == 4) {
            load_tasks(list, &count);
            printf("読み込み完了\n");
        }

        else {
            printf("入力エラー\n");
        }
    }

    return 0;
}
