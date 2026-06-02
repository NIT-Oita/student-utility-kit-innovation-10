#include <stdio.h>
#include <string.h> 
#include <time.h> 
#include "logic.h" 
static int days_between(const char *a, 
                        const char *b) { 
    struct tm ta = {0}, tb = {0}; 
    sscanf(a, "%d-%d-%d", &ta.tm_year, &ta.tm_mon, &ta.tm_mday); 
    sscanf(b, "%d-%d-%d", &tb.tm_year, &tb.tm_mon, &tb.tm_mday); 
    ta.tm_year -= 1900; ta.tm_mon -= 1; 
    tb.tm_year -= 1900; tb.tm_mon -= 1; 
    double d = difftime(mktime(&ta), mktime(&tb));
    return (int)(d / 86400); 
} int task_urgency(const Task *t, const char *today) { 
    int days_left = days_between(t->deadline, today); 
    return (t->priority * 10) - days_left; 
}
