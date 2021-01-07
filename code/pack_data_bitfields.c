#include <stdio.h>
#include <stdbool.h>

struct pack_struct {
    unsigned int : 3;
    unsigned int f1: 1;
    unsigned int f2: 1;
    unsigned int f3: 1;
    unsigned int type: 8;
    unsigned int index: 18;
};

struct box {
    unsigned int : 4;
    bool box_opaque: 1;
    unsigned int box_color: 3;

    unsigned int : 2;
    bool border_shown: 1;
    unsigned int border_color: 3;
    unsigned int border_style: 2;
};

int pack_data_bitfields(int argc, char *argv[]) {
    struct pack_struct pack_data;
    pack_data.type = 152;

    printf("%zd\n", sizeof (pack_data));
    unsigned int type = pack_data.type;

    return 0;
}