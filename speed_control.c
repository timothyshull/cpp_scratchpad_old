#include <math.h>
#include <assert.h>

// (section_distance / s) * 3600
int gps(int s, double* x, int sz)
{
    if (sz <= 1) { return 0; }
    double max = 0.0;
    double avg;
    for (int i = 1; i < sz; ++i) {
        // avg = (x[i] - x[i - 1]) / s * 3600;
        avg = (3600 * (x[i] - x[i - 1])) / s;
        if (avg > max) { max = avg; }
    }
    return (int) floor(max);
}

int main()
{
    double x[8] = {0.0, 0.23, 0.46, 0.69, 0.92, 1.15, 1.38, 1.61};
    assert(gps(20, x, 8) == 41);

    double x1[14] = {0.0, 0.11, 0.22, 0.33, 0.44, 0.65, 1.08, 1.26, 1.68, 1.89, 2.1, 2.31, 2.52, 3.25};
    assert(gps(12, x1, 14) == 219);

    double x2[17] = {0.0, 0.18, 0.36, 0.54, 0.72, 1.05, 1.26, 1.47, 1.92, 2.16, 2.4, 2.64, 2.88, 3.12, 3.36, 3.6, 3.84};
    assert(gps(20, x2, 17) == 80);

    double x3[16] = {0.0, 0.01, 0.36, 0.6, 0.84, 1.05, 1.26, 1.47, 1.68, 1.89, 2.1, 2.31, 2.52, 2.73, 2.94, 3.15};
    assert(gps(14, x3, 16) == 90);
    return 0;
}