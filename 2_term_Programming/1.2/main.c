#include <stdio.h>

int get_sum(int n_copy) {
    int sum = 0;
    while (n_copy > 0) {
        sum += n_copy % 10;
        n_copy /= 10;
    }
    return sum;
}

int main(void) {
    int i = 10;
    for (; i < 100; ++i) {
        int j = 2, i_sum = get_sum(i);
        for (; j < 10; ++j) {
            if (i_sum == get_sum(i * j)) {
                printf("%i & %i\n", i, i * j);
            }
        }
    }
    return 0;

}
