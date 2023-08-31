#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int* answ = (int*)malloc(15 * sizeof(int));
    va_list ap;
    va_start(ap, document_count);
    for (int i = 0; i < document_count; ++i) {
        char* elem = va_arg(ap, char*);
        answ[i] = validate(elem);
    }
    va_end(ap);
    return answ;
}

// int main() {
//
//     int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
//     printf("%d\n", availability_mask[0]);
//     char *a[10] = {Documents};
//     for (int i = 0; i < 4; i++) {
//         printf("[%-15s : %d]",a[i], availability_mask[i]);
//         printf("\n");
//     }
//
//     free(availability_mask);
//     return 0;
// }
