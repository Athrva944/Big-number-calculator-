/* Name: Atharva kothawade */

#include <stdio.h>
#include "dlist.h"
#include "apc_evaluation.h"

int main() {
    char expression[1024];
    Dlist_t *var1 = NULL, *var2 = NULL;
    scanf("\n%[^\n]", expression);
    slice(expression, &var1, &var2);
    return 0;
}

