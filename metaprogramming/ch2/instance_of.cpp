template<typename T>
struct instance_of {
    using type = T;

    instance_of(int = 0) {}
};

// initialize global constants
const instance_of<int> I_INT = instance_of<int>(); // ok but cumbersome
const instance_of<double> I_DOUBLE = 0;            // also fine.

// const empty object workaround
struct empty {
    empty() {}
};

// compiler warning
const empty EMPTY;


struct working_empty {
    working_empty(int = 0) {}
};

const working_empty WORKING_EMPTY = 0;

int main() {


    return 0;
}

