#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void get_time(char* buffer, int format){
    time_t rawTime;
    struct tm *current_time;
    time(&rawTime);
    current_time = localtime(&rawTime);
    if(format == 1)
        strftime(buffer, 50, "%H:%M:%S", current_time);
    else
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
}
int take_format(){
    int format;
    printf("\nChoose The Time Format :");
    printf("\n1. 24 Hours Format");
    printf("\n1. 12 Hours Format(Default)");
    printf("\nEnter choice (1/2) :");
    scanf("%d", &format);
    return format;
}
void get_date(char* buffer){
    time_t rawTime;
    struct tm *current_time;
    time(&rawTime);
    current_time = localtime(&rawTime);
    strftime(buffer, 50, "%d %B %Y (%A)", current_time);
}
void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main(){
    char time[50];
    char date[50];
    int format = take_format();
    while(1){
        get_time(time, format);
        get_date(date);
        clear_screen();
        printf("Current Time : %s\n",time);
        printf("Date (Day) : %s\n",date);
        sleep(1);
    }
    return 0;
}