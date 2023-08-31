#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    int l = 0;
    int t = 0;
    time_t current_time = time(NULL);
    struct tm* u;
    char time_string[9];
    u = localtime(&current_time);
    while (Log_prefix[l] != '\0') {
        print(Log_prefix[l]);
        l++;
    }
    print(' ');
    strftime(time_string, sizeof(time_string), "%H:%M:%S", u);

    while (time_string[t] != '\0') {
        print(time_string[t]);
        t++;
    }
    print(' ');
    while (*message != '\0') {
        print(*message);
        message++;
    }
}

// int main (){
//     print_log(print_char, "govno");
//     return 0;
// }
