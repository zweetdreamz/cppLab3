#include "Parser.h"

int main() {

    remove("/Users/zirael/Проекты/C++/cppLab3/table.csv");
    remove("/Users/zirael/Проекты/C++/cppLab3/OneLineTable.csv");
    CSVParser parser("/Users/zirael/Проекты/C++/cppLab3/Mountains.csv");
    parser.Parse();
    parser.SaveTo();
    OneLineData line = parser.getColumn(1);
    line.Data[1] = "true";
    line.SaveTo();

    return 0;

}