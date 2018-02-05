#include <stdio.h>
#include <stdint.h>
#include <wchar.h>

int main(void)
{
    printf("PTRDIFF_MIN    = %td\n", PTRDIFF_MIN);
    printf("PTRDIFF_MAX    = %+td\n", PTRDIFF_MAX);
    printf("SIZE_MAX       = %zu\n", SIZE_MAX);
    printf("SIG_ATOMIC_MIN = %+jd\n",(intmax_t)SIG_ATOMIC_MIN);
    printf("SIG_ATOMIC_MAX = %+jd\n",(intmax_t)SIG_ATOMIC_MAX);
    printf("WCHAR_MIN      = %+jd\n",(intmax_t)WCHAR_MIN);
    printf("WCHAR_MAX      = %+jd\n",(intmax_t)WCHAR_MAX);
    printf("WINT_MIN       = %jd\n", (intmax_t)WINT_MIN);
    printf("WINT_MAX       = %jd\n", (intmax_t)WINT_MAX);
}
