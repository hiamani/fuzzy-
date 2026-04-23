// Local imports
#include "structs.h"

void fuzzy_assist(t_fuzzy *f, void *b, long m, long a, char *str) {
    if (m == 1) {
        switch (a) {
        case 0:
            sprintf(str, "(signal) input");
            break;
        case 1:
            sprintf(str, "(signal) gain");
            break;
        }
    } else {
        sprintf(str, "(signal) output");
    }
}
