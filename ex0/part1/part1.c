#include <stdio.h>#include <stdlib.h>int log2Integer(int x);int main() {    printf("Enter size of input:\n");    int len;    const int flag = scanf("%d", &len);    if ((flag < 1) || (len <= 0)){        printf("Invalid size\n");        return 0;    }    int* nums_arr = (int*) malloc(len * sizeof(int));    // Check if the memory has been successfully    // allocated by malloc or not    if (nums_arr == NULL) {        //fprintf(stderr,"Memory not allocated.\n");        return 0;    }    printf("Enter numbers:\n");    for (int i = 0; i < len; i++){        if (scanf("%d", &nums_arr[i]) < 1) {  //ignore whitespaces..            fprintf(stdout, "Invalid number\n");            free(nums_arr);            return 0;        }    }    unsigned int power_sum = 0;    for (unsigned int j = 0; j < len; ++j){        int tmp = log2Integer(nums_arr[j]);        if (tmp < 0) continue;        printf("The number %u is a power of 2: %u = 2^%u\n", nums_arr[j], nums_arr[j], tmp);        power_sum += tmp;    }    printf("Total exponent sum is %u\n", power_sum);    free(nums_arr);    return 0;}int log2Integer(int x){    // returns -1 if the number is not power of tow.    // returns for valid number x:  ln(x)/ln(2).    if (x <= 0) return -1;    int pow = -1;    unsigned num_bits = 0;    while (x && (num_bits < 1)){        num_bits += x & 1;        pow += 1;        x >>= 1;    }    if (x)        return -1;    else        return pow;}