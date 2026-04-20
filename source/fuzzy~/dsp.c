#include "ext_mess.h"
#include "ext_obex.h"
#include "ext_proto.h"
#include <math.h>

// Local includes
#include "structs.h"

void fuzzy_perform64(
    t_fuzzy *f, t_object *dsp64, double **ins, long numins, double **outs, long numouts, long sampleframes, long flags,
    void *userparam
) {
    // DSP I/O
    double *in1  = ins[0];
    double *in2  = ins[1];
    double *out1 = outs[0];

    for (int i = 0; i < sampleframes; i++) {
        double drive = in2[i];
        double x     = in1[i] * drive;

        if (x > 0) {
            out1[i] = 1 - exp(-x);
        } else {
            out1[i] = exp(x) - 1;
        }
    }
}

void fuzzy_dsp64(t_fuzzy *f, t_object *dsp64, short *count, double samplerate, long maxvectorsize, long flags) {
    object_method(dsp64, gensym("dsp_add64"), f, fuzzy_perform64, 0, NULL);
}
