#include <stdio.h>
#include "task.h"
#include "logic.h"
#include "storage.h"
#include "ui.h"

int main(void)
{
    Task list[MAX_TASKS];
    int count = 0;
    int choice;
    int next_id;
    /*
     * Windowsの場合UTF-8表示設定
     */
    init_console();
    /*
     * 起動時に保存データを読み込む
     */
    if (load_tasks(list, &count)) {
        printf("保存データを読み込みました\n");
    }
    /*
     * 次に使うIDを決定
     */
    next_id = get_next_id(list, count);

    while (1) {

        show_menu();
        choice = input_choice();

        switch (choice) {
        /*
         * 終了
         */
        case 0:
            /*
             * 終了前に自動保存
             */
            if (save_tasks(list, count)) {
                printf("データを保存しました\n");
            }
            printf("終了します\n");
            return 0;
        /*
         * 登録
         */
        case 1:

            if (count >= MAX_TASKS) {
                printf("登録上限です\n");
                break;
            }

            if (input_task(&list[count])) {
                list[count].id = next_id++;
                list[count].done = 0;
                count++;
                printf("登録しました\n");
            }

            else {
                printf("登録をキャンセルしました\n");
            }
            break;
        /*
         * 一覧表示
         */
        case 2:
        
            printf("現在の登録件数=%d\n", count);
            task_sort(list, count);
            show_tasks(list, count);
            break;
            /*
            * 完了切替
            */
        case 3:
        {

            int id;


            id = input_id();



            if (task_toggle_done(list, count, id)) {


                printf("状態を変更しました\n");


            }
            else {


                printf("IDが見つかりません\n");


            }



            break;

        }








        /*
         * 削除
         */
        case 4:
        {

            int id;



            id = input_id();




            if (task_delete(list, &count, id)) {


                printf("削除しました\n");


            }
            else {


                printf("IDが見つかりません\n");


            }




            break;

        }







        /*
         * 手動保存
         */
        case 5:



            if (save_tasks(list, count)) {


                printf("保存しました\n");


            }
            else {


                printf("保存に失敗しました\n");


            }



            break;







        /*
         * 手動読み込み
         */
        case 6:



            if (load_tasks(list, &count)) {


                next_id = get_next_id(list, count);



                printf("読み込みました\n");


            }
            else {


                printf("読み込みファイルがありません\n");


            }



            break;







        default:


            show_error();


            break;

        }

    }



    return 0;
}