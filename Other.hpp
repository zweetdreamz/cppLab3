//
// Created by Павел Разуваев on 11/8/18.
//

#ifndef CPPLAB3_OTHER_HPP
#define CPPLAB3_OTHER_HPP

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <fstream>
#include <cstring>

using namespace std;

void showVector(vector<int> &v) {

    for (auto it = v.begin(); it != v.end(); ++it) {

        cout << *it << endl;

    }

}

vector<string> editVector(vector<string> &v) {

    for (int i = 0; i < v.size(); i++) {

        if ((v[i][0] == '\"') && (v[i][v[i].size() - 1] == '\"')) {

            v[i].pop_back();
            v[i].erase(0, 1);

        }

    }

    return v;

}

vector<string> stringParse(string s) {

    vector<string> lines;
    regex rgx{"(?:^|,) *((?:[^\",]*?)|(?:\"[^\"]*?\"))(?=$|,)"};
    copy(sregex_token_iterator{s.begin(), s.end(), rgx, 1}, {}, back_inserter(lines));
    lines = editVector(lines);
    return lines;

}

string stringCheckCommas(string s) {

    if (s.find(',') != -1) {

        s.push_back('\"');
        s.insert(0, "\"");

    }

    return s;

}

vector<vector<string>> dataAddR(vector<vector<string>> Data) {

    Data[Data.size() - 1][Data[Data.size() - 1].size() - 1] += "\r";

    return Data;

}

string stringCreate(vector<string> v) {

    string s;

    for (auto it = v.begin(); it != v.end(); ++it) {

        s += stringCheckCommas(*it) + ',';

    }

    s.pop_back();
    return s;

}

#endif //CPPLAB3_OTHER_HPP
