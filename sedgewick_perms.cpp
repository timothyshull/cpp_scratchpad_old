#include <algorithm>
#include <vector>

// from Sedgewick's perms talk -> see wiki heaps algorithm

// Compute all perms of a global array by exchanging each
// element to the end, then recursively permuting the others
template<typename Item_type, typename Visitor_type>
void perms_backtracking(std::vector<Item_type>& v, int n, Visitor_type& visit)
{
    int c;
    if (n == 1) { visit(v); }
    for (c = 1; c <= n; ++c) {
        std::swap(c, n);
        perms_backtracking(v, n - 1, visit);
        std::swap(c, n);
    }
}

// assumes index table v
template<typename Item_type, typename Visitor_type>
void perms_single_exch_r(std::vector<Item_type>& v, int n, Visitor_type& visit)
{
    int c;
    if (n == 1) { visit(v); }
    for (c = 1; c <= n; ++c) {
        perms_single_exch_r(v, n - 1, visit);
        std::swap(v[n][c], n);
    }
}

// Heap's algorithm -> does not need index table
template<typename Item_type, typename Visitor_type>
void heap_r(std::vector<Item_type>& v, int n, Visitor_type& visit)
{
    int c;
    // or if (test(n)) { return; }
    if (n == 1) {
        visit(v);
        return;
    }
    for (c = 1; c <= n; ++c) {
        heap_r(v, n - 1, visit);
        int k{n % 2 ? 1 : c};
        std::swap(k, n);
    }
}

template<typename Item_type, typename Visitor_type>
void heap_i(std::vector<Item_type>& v, int n, Visitor_type& visit)
{
    int i;
    int t;
    int m;
    for (i = 1; i <= n; ++i) {
        p[i] = i;
        c[i] = 1;
    }
    visit(v);
    for (i = 1; i <= n;) {
        if (c[i] < i) {
            int k{n % 2 ? 1 : c};
            std::swap(k, n);
            c[i]++;
            i = 1;
            visit(v);
        } else { c[i++] = 1; }
    }
}

template<typename Item_type, typename Visitor_type>
void improved_heap_r(std::vector<Item_type>& v, int n, Visitor_type& visit)
{
    int c;
    if (n == 3) {
        visit(v);
        p1 = p[1];
        p2 = p[2];
        p3 = p[3];
        p[2] = p1;
        p[1] = p2;
        visit(v);
        p[1] = p3;
        p[3] = p2;
        visit(v);
        p[1] = p1;
        p[2] = p3;
        visit(v);
        p[1] = p2;
        p[3] = p1;
        visit(v);
        p[1] = p3;
        p[2] = p2;
        visit(v);
        return;
    }
    for (c = 1; c <= n; c++) {
        improved_heap_r(v, n - 1, visit);
        int k{n % 2 ? 1 : c};
        std::swap(k, n);
    }
}
