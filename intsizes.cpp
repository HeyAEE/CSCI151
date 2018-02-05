#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    printf("%zu\n", sizeof(int64_t));
    printf("%s\n", PRId64);
    printf("INT32_MIN size: %+"PRId64"\n", INT32_MIN);
    printf("INT_FAST32_MIN size: %+"PRId64"\n", INT_FAST32_MIN);
    printf("INT_LEAST32_MIN size: %+"PRId64"\n", INT_LEAST32_MIN);
    int64_t n = 7;
    printf("%+"PRId64"\n", n);
}
