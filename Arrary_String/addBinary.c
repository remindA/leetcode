/*
 * =====================================================================================
 *
 *       Filename:  addBinary.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/24/2018 10:33:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

char *addBinary(char *a, char *b)
{
    char c;
    int i, j;
    char *sum;
    size_t carry;
    size_t len_a;
    size_t len_b;
    size_t len_sum;
    if(NULL == a || NULL == b) {
        return NULL;
    }
    carry = 0;
    len_a = strlen(a);
    len_b = strlen(b);
    len_sum = len_a > len_b ? len_a : len_b;
    /* 字符串翻转 */
    for(i = 0; i < (len_a >> 1); i++) {
        c = a[i];
        a[i] = a[len_a - i -1];
        a[len_a - i - 1] = c;
    }
    for(i = 0; i < (len_b >> 1); i++) {
        c = b[i];
        b[i] = b[len_b - i -1];
        b[len_b - i - 1] = c;
    }
    /*
     * +1: '\0'
     * +1: carry保留
     */
    sum = (char *)calloc(sizeof(char), len_sum + 1 + 1);
    if(NULL == sum) {
        perror("calloc");
        return NULL;
    }
    /*
     * 进位
     */
    c = 0;
    for(i = 0; i <= len_sum; i++) {
        if(i < len_a) {
            c += a[i] - '0';
        }
        if(i < len_b) {
            c += b[i] - '0';
        }
        switch(c) {
            case 0:
                if(i < len_sum) {
                    sum[i] = c + '0';
                }
                c = 0;
                break;
            case 1:
                sum[i] = c + '0';
                c = 0;
                break;
            case 2:
                sum[i] = '0';
                c = 1;
                break;
            case 3:
                sum[i] = '1';
                c = 1;
                break;
            default:
                printf("c = %d, this should not happen.\n", c);
                break;
        }
    }
    len_sum = strlen(sum);
    /* sum翻转 */
    for(i = 0; i < (len_sum >> 1); i++) {
        c = sum[i];
        sum[i] = sum[len_sum - i - 1];
        sum[len_sum - i - 1] = c;
    }
    return sum;
}















