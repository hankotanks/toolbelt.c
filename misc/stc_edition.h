#include <stdio.h>

#define STDC_EDITION_89 0L
#define STDC_EDITION_90 1L
#define STDC_EDITION_94 199409L
#define STDC_EDITION_99 199901L
#define STDC_EDITION_11 201112L
#define STDC_EDITION_17 201710L
#define STDC_EDITION_23 202311L

#ifdef __STDC__
#define STDC_EDITION STDC_EDITION_89
#ifdef __STDC_VERSION__
#ifdef STDC_EDITION
#undef STDC_EDITION
#endif // STDC_EDITION
#define STDC_EDITION STDC_EDITION_90
#if(__STDC_VERSION__ >= STDC_EDITION_94)
#ifdef STDC_EDITION
#undef STDC_EDITION
#endif // STDC_EDITION
#define STDC_EDITION STDC_EDITION_94
#endif // 199409L
#if(__STDC_VERSION__ >= STDC_EDITION_99)
#ifdef STDC_EDITION
#undef STDC_EDITION
#endif // STDC_EDITION
#define STDC_EDITION STDC_EDITION_99
#endif // 199901L
#if(__STDC_VERSION__ >= STDC_EDITION_11)
#ifdef STDC_EDITION
#undef STDC_EDITION
#endif // STDC_EDITION
#define STDC_EDITION STDC_EDITION_11
#endif // 201112L
#if(__STDC_VERSION__ >= STDC_EDITION_17)
#ifdef STDC_EDITION
#undef STDC_EDITION
#endif // STDC_EDITION
#define STDC_EDITION STDC_EDITION_17
#endif // 201710L
#if(__STDC_VERSION__ >= STDC_EDITION_23)
#ifdef STDC_EDITION
#undef STDC_EDITION
#endif // STDC_EDITION
#define STDC_EDITION STDC_EDITION_23
#endif // 202311L
#endif // __STDC_VERSION__
#endif // __STD__

#define STDC_EDITION_SUPPORTED(x) (STDC_EDITION >= (x))

void stdc_edition_check() {
#if(STDC_EDITION_SUPPORTED(STDC_EDITION_23))
    printf("Most recent edition is C23.\n");
    return;
#endif
#if(STDC_EDITION_SUPPORTED(STDC_EDITION_17))
    printf("Most recent edition is C17.\n");
    return;
#endif
#if(STDC_EDITION_SUPPORTED(STDC_EDITION_11))
    printf("Most recent edition is C11.\n");
    return;
#endif
#if(STDC_EDITION_SUPPORTED(STDC_EDITION_99))
    printf("Most recent edition is C99.\n");
    return;
#endif
#if(STDC_EDITION_SUPPORTED(STDC_EDITION_94))
    printf("Most recent edition is C94.\n");
    return;
#endif
#if(STDC_EDITION_SUPPORTED(STDC_EDITION_90))
    printf("Most recent edition is C90.\n");
    return;
#endif
#if(STDC_EDITION_SUPPORTED(STDC_EDITION_89))
    printf("Most recent edition is C89.\n");
    return;
#endif
}