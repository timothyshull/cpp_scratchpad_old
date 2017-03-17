int P(...) {
    /* try to parse the alternative A1 A2 ... An */
    if (A1(...)) {
        if (!A2(...)) Error("Missing A2"); ...
        if (!An(...)) Error("Missing An");
        return 1;
    }
    /* try to parse the alternative B1 B2 ... */
    if (B1(...)) {
        if (!B2(...)) Error("Missing B2"); ...
        return 1;
    }
    ...
    /* failed to find any alternative of P */
    return 0;
}
// Fig.1.15: ACtemplateforthegrammarruleP → A1A2...An|B1B2...|...