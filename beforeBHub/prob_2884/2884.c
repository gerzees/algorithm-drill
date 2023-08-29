#include <stdio.h>

int main(void)
{
    int hour,minute, new_hour, new_minute;
    scanf("%d%d", &hour, &minute);
    if(minute>=45){
        new_hour = hour;
        new_minute=minute-45;
    }
    else if(hour>0){
        new_hour=hour-1;
        new_minute=60-(45-minute);
    }
    else{
        new_hour=23;
        new_minute=60-(45-minute);
    }
    printf("%d %d", new_hour, new_minute);
        
    return 0;
}