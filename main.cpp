#include <drogon/HttpAppFramework.h>

using namespace std;

int main() {
    drogon::app().addListener("0.0.0.0", 8080).run();
    return 0;
}