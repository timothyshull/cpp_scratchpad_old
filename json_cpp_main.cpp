#include <iostream>
#include <json/value.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./exe <json_string>" << std::endl;
        exit(EINVAL);
    }

    Json::Value root{argv[1]};

    std::string root_str {root.toStyledString()};

    Json::Value redis {root["redis"]};

    std::cout << root_str << std::endl;

//    std::string redis {root["redis"].toStyledString()};

    std::cout << redis.toStyledString() << std::endl;

    return 0;
}

//int main() {
//    std::ifstream config_doc("config_doc.json", std::ifstream::binary);
//    config_doc >> root;
//
//    Json::Value root;   // 'root' will contain the root value after parsing.
//    std::cin >> root;
//
//    // You can also read into a particular sub-value.
//    std::cin >> root["subtree"];
//
//    // Get the value of the member of root named 'encoding',
//    // and return 'UTF-8' if there is no such member.
//    std::string encoding = root.get("encoding", "UTF-8").asString();
//
//    // Get the value of the member of root named 'plug-ins'; return a 'null' value if
//    // there is no such member.
//    const Json::Value plugins = root["plug-ins"];
//
//    // Iterate over the sequence elements.
//    for (int index = 0; index < plugins.size(); ++index)
//        loadPlugIn(plugins[index].asString());
//
//    // Try other datatypes. Some are auto-convertible to others.
//    foo::setIndentLength(root["indent"].get("length", 3).asInt());
//    foo::setIndentUseSpace(root["indent"].get("use_space", true).asBool());
//
//    // Since Json::Value has an implicit constructor for all value types, it is not
//    // necessary to explicitly construct the Json::Value object.
//    root["encoding"] = foo::getCurrentEncoding();
//    root["indent"]["length"] = foo::getCurrentIndentLength();
//    root["indent"]["use_space"] = foo::getCurrentIndentUseSpace();
//
//    // If you like the defaults, you can insert directly into a stream.
//    std::cout << root;
//
//    // Of course, you can write to `std::ostringstream` if you prefer.
//    // If desired, remember to add a linefeed and flush.
//    std::cout << std::endl;
//}