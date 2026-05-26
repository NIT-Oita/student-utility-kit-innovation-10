
#include <stdio.h>
#include "logic.h"
int load_tasks(const char *path,
                Task *list, int max) {
    FILE *fp = fopen(path, "r");
    if (!fp) return 0;        /* ファイルがまだ無い */

    char line[256];
    fgets(line, sizeof line, fp);   /* ヘッダ行を読み飛ばす */

    int n = 0;
    while (n < max &&
            fscanf(fp, "%d,%63[^,],%10[^,],%d,%d\n",
                &list[n].id, list[n].title,
                list[n].deadline,
                &list[n].priority,
                &list[n].done) == 5) {
        n++;
    }
    fclose(fp);
    return n;
}
