#include <stdio.h>
#include "logic.h"

/* ===== メニュー表示 ===== */
void show_menu(void)
{
    printf("\n===== TODO管理 =====\n");
    printf("1. 課題追加\n");
    printf("2. 優先順位表示\n");
    printf("0. 終了\n");
}

/* ===== メニュー入力 ===== */
int input_choice(void)
{
    int x;
    printf("選択: ");
    scanf("%d", &x);
    return x;
}

/* ===== タスク入力 ===== */
void input_task(Task *t)
{
    printf("\n--- 課題入力 ---\n");

    printf("タイトル: ");
    scanf("%63s", t->title);

    printf("締切 (YYYY-MM-DD): ");
    scanf("%10s", t->deadline);

    printf("優先度 (1〜5): ");
    scanf("%d", &t->priority);

    t->done = 0;
}

/* ===== タスク一覧表示 ===== */
void show_tasks(Task *list, int n)
{
    printf("\n===== 優先順位一覧 =====\n");

    for (int i = 0; i < n; i++) {
        printf("%d位 | %s | 締切:%s | 優先度:%d | %s\n",
               i + 1,
               list[i].title,
               list[i].deadline,
               list[i].priority,
               list[i].done ? "完了" : "未完了");
    }
}

/* ===== エラー表示 ===== */
void show_error(void)
{
    printf("入力エラーです\n");
}
