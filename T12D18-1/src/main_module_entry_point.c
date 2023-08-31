#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#if Quest1
    print_log(print_char, Module_load_success_message);
#endif
#if Quest2
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    char *a[10] = {Documents};
    for (int i = 0; i < Documents_count; i++) {
        // char *avail;
        //         availability_mask[i] ? avail = "available" : (avail = "unavailable");
        printf("[%-15s : %d]", a[i], availability_mask[i]);
        if (i != Documents_count - 1) printf("\n");
    }

    free(availability_mask);
#endif
    return 0;
}
