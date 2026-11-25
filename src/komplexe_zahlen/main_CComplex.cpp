#include "komplexe_zahlen/CComplexReader.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::istringstream;

int main() {
    istringstream eingabe(
        "3+4i\n"
        "-1-2i\n"
        "6-8i\n"
        "-2+0i\n"
        "0+3i\n"
        "3+4i\n"
    );

    CComplexReader reader;
    reader.constant_reader(eingabe);
    reader.sortiere_vektor();

    for (const auto& zahl : reader.get_komplexe_zahlen()) {
        cout << zahl << '\n';
    }

    return 0;
}
