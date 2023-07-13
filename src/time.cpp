
#include <sstream>
#include <ctime>
#include <cstdio>

int main() {
    std::ostringstream buf;
    std::time_t t = std::time(NULL);
    std::tm *ltm = std::localtime(&t);

    buf << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
//    writeFormatted(" " + buf.str(), width, alignLeft);a
    printf("[%s]\n", buf.str().c_str());

    return 0;
}
