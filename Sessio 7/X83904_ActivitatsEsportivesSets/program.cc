//
//  program.cc
//  PRO2
//
//  Created by Júlia Gasull Navarro on 11/11/17.
//  Copyright © 2017 Júlia Gasull Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

void readmap(map<string, int> &m)
{
    string str;
    while (cin >> str and str != ".") m[str];
}

void readset(set<string> &s)
{
    string str;
    while (cin >> str and str != ".") s.insert(str);
}

void updatemap(map<string, int> &m, set<string> &s)
{
    for (set<string>::iterator it = s.begin(); it != s.end(); ++it)
    {
        map<string, int>::iterator itmap = m.find(*it);
        ++(*itmap).second;
    }
}

void printmap(map<string, int> &m, int n)
{
    cout << "Totes les activitats:";
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if ((*it).second == n) cout << ' ' << (*it).first;
    }
    cout << endl;
    
    cout << "Cap activitat:";
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if ((*it).second == 0) cout << ' ' << (*it).first;
    }
    cout << endl;
}

int main()
{
    map<string, int> m;
    readmap(m);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        set<string> s;
        readset(s);
        updatemap(m, s);
    }
    printmap(m, n);
}
