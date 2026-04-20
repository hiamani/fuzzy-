// Local imports
#include "structs.h"

void fuzzy_assist(t_fuzzy *f, void *b, long m, long a, char *s) {
    if (m == 1) {
        sprintf(s, "I am inlet %ld", a);
    } else {
        sprintf(s, "I am outlet %ld", a);
    }
}
