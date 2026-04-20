#ifndef FUZZY_DSP
#define FUZZY_DSP

#include "ext_mess.h"

// Local includes
#include "structs.h"

void fuzzy_perform64(
    t_fuzzy *f, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags,
    void *userparam
);

void fuzzy_dsp64(t_fuzzy *f, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags);

#endif
