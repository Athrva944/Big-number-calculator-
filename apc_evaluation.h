#ifndef APC_EVALUATION_H
#define APC_EVALUATION_H

#include "dlist.h"

void slice(char *expression, Dlist_t **var1, Dlist_t **var2);
Dlist_t *apc_evaluation_sum(Dlist_t **var1, Dlist_t **var2, char operator);
Dlist_t *apc_evaluation_mul(Dlist_t **var1, Dlist_t **var2, char operator);
void apc_evaluation_power(Dlist_t **var1, Dlist_t **var2);
int apc_evaluation_div(Dlist_t **var1, Dlist_t **var2, char operator);
int check_greater(Dlist_t **var1, Dlist_t **var2);

#endif

