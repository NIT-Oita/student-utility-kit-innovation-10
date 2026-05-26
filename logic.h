#ifndef LOGIC_H 
#define LOGIC_H 
#define MAX_TASKS 100 
typedef struct { 
    int  id; 
    char title[64]; 
    char deadline[11];  /* YYYY-MM-DD */ 
    int  priority;      /* 1..5      */
    int  done;          /* 0 or 1    */ 
} Task; 
int  task_urgency(const Task *t, const char *today); 
void task_sort(Task *list, int n); 
#endif
