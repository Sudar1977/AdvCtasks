#include <stdio.h>
#include <stdlib.h>
/*
 * Для заданных натуральных чисел N и K требуется вычислить количество чисел от 1 до N, имеющих в двоичной записи ровно K нулей.
 * Например, если N=8 и K=1, то мы можем записать все числа от 1 до 8 в двоичной системе счисления: 1, 10, 11, 100, 101, 110, 111 и 1000.
 * Откуда видно, что только числа 10, 101 и 110 имеют ровно один ноль в записи, т.е. правильный ответ – 3.
 * */
int perevod(int chislo);
int colichestvo(int, int k);
int main() {

    int chislo = 0, n_chislo = 0, n_zero = 0;

    scanf("%d %d", &chislo, &n_zero);
    n_chislo = colichestvo(chislo, n_zero);
    printf("\n%d ", n_chislo);

    return 0;
}
int colichestvo(int chislo, int n_zero) {             // подсчет чисел (n_dig)  в которых  (n_zero) кол_во нулей в двоичной форме.
    int i = 1, n_dig = 0;

    while(chislo >= i) {
        if(perevod(i) == n_zero) {
            n_dig++;
            //printf("i = %d\n", i);
        }
        i++;
    }
    return n_dig;
}
int perevod(int n) {                             // фукнция подсчета цифры 0 в двоичной форме числа n
    int chast=0, ost=0, n0=0;
    chast=n;

    if(chast==2) {
        return 1;
    }
    else if(chast==1) {
        return 0;
    }
    while(chast>1) {
        ost=chast%2;
        chast/=2;
        if(ost == 0) {
            n0++;
        }
    }
    return n0;
}
