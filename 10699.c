#include <stdio.h>
#include <time.h>

int main(void) {
    time_t utc_now = time(NULL);
    struct tm *kst = gmtime(&(time_t){utc_now + 9 * 60 * 60}); // KST = UTC + 9 hours
    printf("%04d-%02d-%02d\n", // %04d for year, %02d for month and day with leading zeros
        kst->tm_year + 1900,   // tm_year is years since 1900
        kst->tm_mon + 1,       // tm_mon starts from 0 so add 1 for 1-12 range
        kst->tm_mday);         // 1~31 for day of the month
    return 0;
}