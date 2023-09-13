#include "utilities.h"

int is_diferente(const char* s1, const char* s2){
    if (strcmp(s1, s2) == 0)
        return 0;
    return 1;
}
