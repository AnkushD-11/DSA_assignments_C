/* Write a program to calculate difference between Start time & End time of an event. Time is
expressed as hr-min-sec. Final result to be produced in seconds.*/

#include<stdio.h>
struct TIME{
    int hours;
    int minutes;
    int seconds;
};

int timetosecs(const struct TIME *time)
{
    return time->hours* 3600 + time->minutes*60 + time->seconds;
}

int main(){
    struct TIME starttime, endtime;

    printf("Enter starting time: ");
    scanf("%d %d %d", &starttime.hours, &starttime.minutes, &starttime.seconds);

    printf("Enter ending time: ");
    scanf("%d %d %d", &endtime.hours, &endtime.minutes, &endtime.seconds);

    int startSeconds = timetosecs(&starttime);
    int endSeconds = timetosecs(&endtime);
    int differenceSeconds = endSeconds - startSeconds;

    printf("Time difference: %d seconds\n", differenceSeconds);
    return 0;

}
