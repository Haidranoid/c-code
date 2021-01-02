#include <stdio.h>

int challenge_enums(int argc, char *argv[]) {
    enum companies {
        GOOGLE,
        FACEBOOK,
        XEROX,
        YAHOO,
        EBAY,
        MICROSOFT
    };

    enum companies xerox = XEROX;
    enum companies google = GOOGLE;
    enum companies ebay = EBAY;

    printf("%i\n", xerox);
    printf("%i\n", google);
    printf("%i\n", ebay);

    return 0;
}