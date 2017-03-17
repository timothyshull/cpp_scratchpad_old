#include <assert.h>
#include <printf.h>

// TODO: come back to this
long long maxRot(long long n)
{
    if (n == 0) { return 0; }
    long long max_mult = 1;
    int place_count = 0;
    while (max_mult <= n) {
        max_mult *= 10;
        ++place_count;
    }
    long long vals[place_count];
    long long current_mult = max_mult / 10;
    vals[0] = (n % current_mult) * (max_mult / current_mult) + (n / current_mult);
    current_mult /= 10;
    printf("%lld\n", vals[0]);
    int t = 1;
    // to rotate use previous in vals and rotate = (p % mult) * mult + (p / mult)
    while (current_mult) {
        vals[t] = (vals[t - 1] % current_mult) * (max_mult / current_mult) + (vals[t - 1] / current_mult);
        printf("%lld\n", vals[t]);
        current_mult /= 10;
        ++t;
    }

    long long max = 0;
    for (int i = 0; i < place_count; ++i) {
        if (vals[i] >= 0) { max = vals[i]; }
    }
    return max;
}

int main()
{
    assert(maxRot(38458215) == 85821534);
    assert(maxRot(195881031) == 988103115);
    assert(maxRot(896219342) == 962193428);
    assert(maxRot(69418307) == 94183076);
    return 0;
}