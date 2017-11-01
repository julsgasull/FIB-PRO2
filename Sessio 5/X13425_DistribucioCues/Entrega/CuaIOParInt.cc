#include "CuaIOParInt.hh"
#include <iostream>
using namespace std;

void llegirCuaParInt(queue<ParInt>& c){
    ParInt p;
    while(p.llegir()) c.push(p);
}

void escriureCuaParInt(queue<ParInt> c){
    while(!c.empty()) {
        c.front().escriure();
        c.pop();
    }
}
