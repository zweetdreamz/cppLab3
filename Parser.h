//
// Created by Павел Разуваев on 11/7/18.
//

#ifndef CPPLAB3_PARSER_H
#define CPPLAB3_PARSER_H

#pragma once

#include "Other.hpp"

class Parser {
public:

    Parser() {}

    Parser(string adress) {
        this->adress = adress;
    }

    Parser(string adress, char sep){
        this->adress = adress;
        separator = sep;
    }

    virtual void Parse() {};

    virtual void SaveTo() {};

protected:

    vector<vector<string>> Data;
    string adress;
    char separator;

};

class CSVParser : protected Parser {
public:

    CSVParser() {}

    CSVParser(string adress) : Parser(adress) {}

    CSVParser(string adress, char sep) : Parser() {}

    virtual void Parse() {

        ifstream in(adress);
        string s;
        if (in.is_open()) {
            while (!in.eof()) {
                getline(in, s);
                Data.push_back(stringParse(s));
            }
        }
        Data = dataAddR(Data);
        in.close();

    }

    virtual void SaveTo() {

        ofstream fout("/Users/zirael/Проекты/C++/cppLab3/table.csv");
        if (fout.is_open()) {
            for (auto it = Data.begin(); it != Data.end(); ++it) {
                fout << stringCreate(*it);
            }
        }
        fout.close();

    }

    unsigned long maxColumn() {

        unsigned long maxColumn = 0;
        for (int i = 0; i < Data.size(); i++) {
            if (Data[i].size() > maxColumn) {
                maxColumn = Data[i].size();
            }
        }
        return maxColumn;

    }

    unsigned long maxRow() {
        return this->Data.size();
    }

    void setCell(int column, int row, float k) {

        if (column >= 0 && column <= maxColumn() && row <= maxRow() && row >= 0) {
            Data[row][column] = to_string(k);
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void setCell(int column, int row, string str) {

        if (column >= 0 && column <= maxColumn() && row <= maxRow() && row >= 0) {
            Data[row][column] = str;
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void setCell(int column, int row, int k) {

        if (column >= 0 && column <= maxColumn() && row <= maxRow() && row >= 0) {
            Data[row][column] = to_string(k);
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void removeColumn(int column) {

        for (auto it = Data.begin(); it != Data.end(); ++it) {
            (*it).erase((*it).begin() + column);
        }

    }

    void removeRow(int row) {

        Data.erase(Data.begin() + row);

    }

    void setColumn(int column, int k) {

        if (column >= 0 && column <= maxColumn()) {
            for (auto it = Data.begin(); it != Data.end(); ++it) {
                (*it)[column] = to_string(k);
            }
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void setColumn(int column, float k) {

        if (column >= 0 && column <= maxColumn()) {
            for (auto it = Data.begin(); it != Data.end(); ++it) {
                (*it)[column] = to_string(k);
            }
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void setColumn(int column, string str) {

        if (column >= 0 && column <= maxColumn()) {
            for (auto it = Data.begin(); it != Data.end(); ++it) {
                (*it)[column] = str;
            }
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void setRow(int row, int k) {

        if (row >= 0 && row <= maxRow()) {
            for (auto it = Data[row].begin(); it != Data[row].end(); ++it) {
                *it = to_string(k);
            }
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void setRow(int row, float k) {

        if (row >= 0 && row <= maxRow()) {
            for (auto it = Data[row].begin(); it != Data[row].end(); ++it) {
                *it = to_string(k);
            }
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void setRow(int row, string str) {

        if (row >= 0 && row <= maxRow()) {
            for (auto it = Data[row].begin(); it != Data[row].end(); ++it) {
                *it = str;
            }
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    void addRow() {

        vector<string> line;
        for (int i = 0; i < this->maxColumn(); i++) {
            line.push_back("");
        }
        Data.push_back(line);

    }

    vector<string> getRow(int row) {

        if (row >= 0 && row <= maxRow()) {
            return Data[row];
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    vector<string> getColumn(int column) {

        if (column >= 0 && column <= maxColumn()) {
            vector<string> line;
            for (auto it = Data.begin(); it != Data.end(); ++it) {
                line.push_back((*it)[column]);
            }
            return line;
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    virtual ~CSVParser() {
        Data.clear();
    }

};

class OneLineData {
public:

    vector<string> Data;

    OneLineData(vector<string> anotherData) {
        Data = anotherData;
    }

    void SaveTo() {

        ofstream fout("/Users/zirael/Проекты/C++/cppLab3/OneLineTable.csv");
        if (fout.is_open()) {
            fout << stringCreate(Data);
        }
        fout.close();

    }

    bool operator==(const OneLineData &rhs) const {
        return Data == rhs.Data;
    }

    bool operator!=(const OneLineData &rhs) const {
        return !(rhs == *this);
    }

    string operator[](const int &index) {

        if (index < Data.size()) {
            return Data[index];
        } else {
            printf("Неверный адрес ячейки \n");
        }

    }

    virtual ~OneLineData() {
        Data.clear();
    }

};

#endif //CPPLAB3_PARSER_H
