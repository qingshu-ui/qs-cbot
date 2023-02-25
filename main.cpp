#include <drogon/HttpAppFramework.h>
#include "src/ws/WebsocketController.h"

using namespace std;

int main() {
    parse_options.ignore_unknown_fields = true;
    print_options.always_print_primitive_fields = true;
    print_options.preserve_proto_field_names= true;

    drogon::app().addListener("0.0.0.0", 8080).run();
    return 0;
}