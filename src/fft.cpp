#include "fft.h"
#include <complex.h>
#include <fftw3.h>

fftw_complex* fft(int N) {
    fftw_complex* in;
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    for (int i = 0; i < N; i++) {
        in[i][0] = sin(0.1*i);
        in[i][1] = 0.0;
    }

    fftw_complex* out;
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    fftw_plan p;

    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(p);

    for (int i = 0; i < N; i++)
        printf("freq: %3d %+9.5f %+9.5f I\n", i, out[i][0], out[i][1]);

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    return out;
}