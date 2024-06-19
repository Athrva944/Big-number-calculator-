/* Name: Atharva kothawade */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc_evaluation.h"
#include "dlist.h"

void slice(char *expression, Dlist_t **var1, Dlist_t **var2) {
    int idx = strlen(expression) - 1;
    char operator, buff[4] = {'0', '0', '0', '0'};
    int slice_flag = 0, op_flag = 0, sum = 0;
    int jdx = 3, minus_flag = 0, high_flag;
    Dlist_t *Result = NULL;

    while (idx >= 0) {
	if (idx == 0) {
	    if (expression[idx] == '-') {
		minus_flag = 1;
		break;
	    }
	}
	if (expression[idx] != '+' && expression[idx] != '-' && expression[idx] != '*' && expression[idx] != '/' && expression[idx] != '%' && expression[idx] != '^') {
	    if (slice_flag == 4) {
		if (op_flag == 0) {
		    sum = atoi(buff);
		    dl_insert_first(var1, sum);
		}
		if (op_flag == 1) {
		    sum = atoi(buff);
		    dl_insert_first(var2, sum);
		}
		slice_flag = 0;
		for (jdx = 0; jdx < 4; jdx++) buff[jdx] = '0';
		jdx = 3;
	    }
	    buff[jdx] = expression[idx];
	    --jdx;
	    ++slice_flag;
	} else {
	    if (slice_flag != 0) {
		sum = atoi(buff);
		dl_insert_first(var1, sum);
	    }
	    operator = expression[idx];
	    op_flag = 1;
	    slice_flag = 0;
	    for (jdx = 0; jdx < 4; jdx++) buff[jdx] = '0';
	    jdx = 3;
	}
	--idx;
    }
    sum = atoi(buff);
    dl_insert_first(var2, sum);

    if (operator == '+' || operator == '-') {
	if (operator == '-') high_flag = check_greater(var1, var2);
	Result = apc_evaluation_sum(var1, var2, operator);
	if (operator == '-') {
	    if (high_flag == 1) printf("\nResult = -");
	    else printf("\nResult = ");
	} else {
	    printf("\nResult = ");
	}
	dl_print_list(Result);
	printf("\n");
    }

    if (operator == '*') {
	Result = apc_evaluation_mul(var1, var2, operator);
	printf("\nResult : ");
	dl_print_list(Result);
    }

    if (operator == '/') {
	int count = apc_evaluation_div(var1, var2, operator);
	printf("\nResult is %d\n", count);
    }

    if (operator == '%') {
	apc_evaluation_div(var1, var2, operator);
    }

    if (operator == '^') {
	apc_evaluation_power(var1, var2);
    }
}

void apc_evaluation_power(Dlist_t **var1, Dlist_t **var2) {
    Dlist_t *ptr1 = *var1, *Result = *var2;
    while (ptr1->data - 1) {
	Result = apc_evaluation_mul(var2, &Result, '*');
	ptr1->data = ptr1->data - 1;
    }
    printf("\nResult : ");
    dl_print_list(Result);
}

int check_greater(Dlist_t **var1, Dlist_t **var2) {
    Dlist_t *ptr1 = *var1, *ptr2 = *var2;
    int count1 = 0, count2 = 0, high_flag = 0, flag = 0;

    while (ptr1 != NULL) {
	++count1;
	ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
	++count2;
	ptr2 = ptr2->next;
    }

    ptr1 = *var1;
    ptr2 = *var2;

    if (count2 > count1) {
	if (ptr2->data == 0) {
	    while (ptr2 != NULL) {
		if (ptr2->data == 0) {
		    --count2;
		    ptr2 = ptr2->next;
		} else {
		    if (ptr2->data < ptr1->data && count2 == count1) flag = 1;
		    break;
		}
		if (count2 == 0) flag = 1;
	    }
	}
	if (flag == 1) {
	    Dlist_t *tmp = *var1;
	    *var1 = *var2;
	    *var2 = tmp;
	    high_flag = 1;
	}
    } else if (count1 == count2) {
	Dlist_t *tmp1 = *var1, *tmp2 = *var2;
	if (tmp2->data <= tmp1->data) {
	    while (tmp2->data >= tmp1->data && tmp1->next != NULL) {
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	    }
	    if (tmp1->next != NULL && tmp2->data < tmp1->data) {
		Dlist_t *tmp = *var1;
		*var1 = *var2;
		*var2 = tmp;
		high_flag = 1;
	    } else if (tmp1->next == NULL && tmp2->data < tmp1->data) {
		Dlist_t *tmp = *var1;
		*var1 = *var2;
		*var2 = tmp;
		high_flag = 1;
	    }
	}
    }
    return high_flag;
}

int apc_evaluation_div(Dlist_t **var1, Dlist_t **var2, char operator) {
    unsigned long long int count = 0;
    int flag = 0, high_flag, stop = 0;
    Dlist_t *Result = NULL, *temp_var2 = *var2;
    high_flag = check_greater(var1, var2);

    while (1) {
	if (flag == 0) {
	    if (high_flag == 1) {
		flag = 2;
		break;
	    }
	    flag = 1;
	}

	Result = apc_evaluation_sum(var1, &temp_var2, '-');
	stop = check_greater(var1, &Result);

	if (stop == 0) {
	    ++count;
	    printf("%lld\n", count);
	    dl_delete_list(&temp_var2);
	    temp_var2 = Result;
	} else {
	    break;
	}
    }

    if (operator == '%') {
	printf("\nRemainder is ");
	dl_print_list(*var1);
	printf("\n");
    }

    if (operator == '/') {
	if (flag == 2) {
	    return 0;
	} else {
	    return count + 1;
	}
    }
    return 0;
}

Dlist_t *apc_evaluation_mul(Dlist_t **var1, Dlist_t **var2, char operator) {
    Dlist_t *Result1 = NULL, *Result2 = NULL, *ptr1 = *var1, *ptr2 = *var2, *last;
    int idx = 0, carry = 0, result, num, flag = 0, jdx;

    dl_insert_first(&Result2, 0);
    while (ptr1->next != NULL) ptr1 = ptr1->next;
    while (ptr2->next != NULL) ptr2 = ptr2->next;

    last = ptr2;
    while (ptr1 != NULL) {
	while (ptr2 != NULL) {
	    if (ptr2->next == NULL) {
		for (jdx = 0; jdx < idx; jdx++) dl_insert_first(&Result1, 0);
	    }
	    num = ptr1->data * ptr2->data;
	    result = num + carry;
	    carry = 0;
	    if (result >= 10000) {
		carry = result / 10000;
		result = result % 10000;
	    }
	    dl_insert_first(&Result1, result);
	    if (ptr2->prev == NULL && carry != 0) dl_insert_first(&Result1, carry);
	    ptr2 = ptr2->prev;
	}
	++idx;
	if (flag == 0) {
	    Result2 = Result1;
	    flag = 1;
	} else {
	    Result2 = apc_evaluation_sum(&Result1, &Result2, '+');
	}
	dl_delete_list(&Result1);
	ptr2 = last;
	ptr1 = ptr1->prev;
	carry = 0;
    }
    return Result2;
}

Dlist_t *apc_evaluation_sum(Dlist_t **var1, Dlist_t **var2, char operator) {
    Dlist_t *ptr1 = *var1, *ptr2 = *var2, *Result = NULL;
    int carry = 0, result;

    while (ptr1->next != NULL) ptr1 = ptr1->next;
    while (ptr2->next != NULL) ptr2 = ptr2->next;

    while (ptr1 != NULL || ptr2 != NULL) {
	if (ptr1 == NULL) {
	    if (operator == '+') result = ptr2->data + carry;
	    else result = ptr2->data + carry;
	    carry = 0;
	    if (result >= 10000) {
		result = result - 10000;
		carry = 1;
	    }
	    dl_insert_first(&Result, result);
	    ptr2 = ptr2->prev;
	    continue;
	}

	if (ptr2 == NULL) {
	    if (operator == '+') result = ptr1->data + carry;
	    else result = ptr1->data + carry;
	    carry = 0;
	    if (result >= 10000) {
		result = result - 10000;
		carry = 1;
	    }
	    dl_insert_first(&Result, result);
	    ptr1 = ptr1->prev;
	    continue;
	}

	if (operator == '+') result = ptr1->data + ptr2->data + carry;
	if (operator == '-') result = ptr1->data - ptr2->data - carry;

	carry = 0;

	if (result >= 10000) {
	    result = result - 10000;
	    carry = 1;
	} else if (result < 0) {
	    result = 10000 + result;
	    carry = 1;
	}

	dl_insert_first(&Result, result);
	ptr1 = ptr1->prev;
	ptr2 = ptr2->prev;
    }

    if (carry == 1 && operator == '+') {
	dl_insert_first(&Result, carry);
    }

    return Result;
}

