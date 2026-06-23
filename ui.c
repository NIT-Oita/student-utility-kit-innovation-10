#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "logic.h"
#ifdef _WIN32
#include <windows.h>
#endif

void init_console(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}
/*
 * メニュー表示
 */
void show_menu(void)
{
    printf("\n====================\n");
    printf(" 課題管理アプリ\n");
    printf("====================\n");
    printf("1. 課題を登録する\n");
    printf("2. 課題一覧を見る\n");
    printf("3. 完了状態を変更する\n");
    printf("4. 課題を削除する\n");
    printf("5. 保存する\n");
    printf("6. 読み込む\n");
    printf("0. 終了する\n");
    printf("--------------------\n");
    printf("番号を入力してください: ");
}

/*
 * 整数入力共通処理
 */
static int read_int_line(void)
{
    char line[64];
    int value;

    if (fgets(line, sizeof(line), stdin) == NULL) {
        return -1;
    }

    if (sscanf(line, "%d", &value) != 1) {
        return -1;
    }
    return value;
}

int input_choice(void)
{
    return read_int_line();
}

int input_id(void)
{
    printf("IDを入力してください: ");
    return read_int_line();
}

/*
 * 課題入力
 */
int input_task(Task *t)
{
    char line[TITLE_LEN];
    int y;
    int m;
    int d;

    printf("課題名: ");

    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    line[strcspn(line, "\r\n")] = '\0';

    /*
     * 保存形式で使用するため
     * 区切り文字は禁止
     */
    if (strchr(line, '|') != NULL) {
        printf("'|'は使用できません\n");
        return 0;
    }

    strncpy(t->title,
            line,
            TITLE_LEN - 1);

    t->title[TITLE_LEN - 1] = '\0';

    printf("期限(例 2026 6 30): ");

    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 0;
    }

    if (sscanf(line,
               "%d %d %d",
               &y,
               &m,
               &d) != 3) {

        printf("期限入力エラー\n");
        return 0;
    }

    if (m < 1 || m > 12 ||
        d < 1 || d > 31) {

        printf("日付が不正です\n");
        return 0;
    }

    t->deadline = y * 10000 + m * 100 + d;
    return 1;
}

/*
 * 期限表示変換
 */
static void format_deadline(int deadline,
                            char *out,
                            int size)
{
    if (deadline == 0) {
        snprintf(out, size, "未設定");
    } else {
        snprintf(out,
                 size,
                 "%04d/%02d/%02d",
                 deadline / 10000,
                 (deadline / 100) % 100,
                 deadline % 100);
    }
}

/*
 * 一覧表示
 */
void show_tasks(const Task list[], int count)
{
    int i;

    if (count == 0) {
        printf("登録された課題はありません\n");
        return;
    }

    printf("\nID  課題名                 期限        状態\n");
    printf("----------------------------------------------\n");

    for (i = 0; i < count; i++) {
        char date[32];
        format_deadline(list[i].deadline,
                        date,
                        sizeof(date));
        printf("%-3d %-20s %-12s %s",
               list[i].id,
               list[i].title,
               date,
               list[i].done ? "完了" : "未完了");

        if (is_overdue(&list[i])) {
            printf(" [期限切れ]");
        }
        printf("\n");
    }
    printf("----------------------------------------------\n");
}

void show_error(void)
{
    printf("不正な番号です\n");
}