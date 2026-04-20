#include "ext_obex.h"
#include "ext_proto.h"

// Local imports
#include "dsp.h"
#include "handlers.h"
#include "structs.h"

void *fuzzy_new(t_symbol *s, long argc, t_atom *argv);
void  fuzzy_free(t_fuzzy *f);

static t_class *fuzzy_class = NULL;

void ext_main(void *r) {
    t_class *c = class_new("fuzzy~", (method)fuzzy_new, (method)fuzzy_free, (long)sizeof(t_fuzzy), 0L, A_GIMME, 0);

    class_addmethod(c, (method)fuzzy_assist, "assist", A_CANT, 0);
    class_addmethod(c, (method)fuzzy_dsp64, "dsp64", A_CANT, 0);

    class_dspinit(c);
    class_register(CLASS_BOX, c);
    fuzzy_class = c;
}

void *fuzzy_new(t_symbol *s, long argc, t_atom *argv) {
    t_fuzzy *f = (t_fuzzy *)object_alloc(fuzzy_class);

    if (f) {
        dsp_setup((t_pxobject *)f, 2);
        outlet_new(f, "signal");
    }

    return f;
}

void fuzzy_free(t_fuzzy *o) {
    dsp_free((t_pxobject *)o);
}
