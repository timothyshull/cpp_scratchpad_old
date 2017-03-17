#include <iostream>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char *argv[]) {
    // Parameter checking...
    try {
        // Turn the args into absolute paths using native formatting
//        path src_dir("/tmp");
        path src_file("foo.txt");
//        path src_full_path = src_dir / src_file;

//        path dest_dir("/tmp");
        path dest_file("foo.txt");
//        path dest_full_path = dest_dir / dest_file;

//        path src = complete(path(argv[1], native));
//        path dst = complete(path(argv[2], native));

        path src = complete(src_file);
        path dst = complete(dest_file);

        copy_file(src, dst);
    }
    catch (exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}


//#include <iostream>
//#include <string>
//#include <boost/filesystem.hpp>
//
//
//int main() {
//    boost::filesystem::path p (__FILE__);
//
//    std::string new_filename = p.leaf() + ".foo";
//    p.remove_leaf() /= new_filename;
//    std::cout << p << '\n';
//
//    return 0;
//}