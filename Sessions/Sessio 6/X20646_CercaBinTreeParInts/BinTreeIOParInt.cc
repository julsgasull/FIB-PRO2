#include <iostream>
#include "BinTreeIOParInt.hh"
using namespace std;

void read_bintree_parint(BinTree<ParInt>& a) {
    
    ParInt p;
    if (p.llegir()) {
        BinTree<ParInt> treeleft;
        read_bintree_parint(treeleft);
        BinTree<ParInt> treeright;
        read_bintree_parint(treeright);
        a = BinTree<ParInt>(p, treeleft, treeright);
    }
}


void write_bintree_parint(const BinTree<ParInt>& a) {
    if (not a.empty()) {
        ParInt p = a.value();
        write_bintree_parint(a.left());
        cout << " ";
        p.escriure();
        write_bintree_parint(a.right());
    }
    else cout << ' ' << 0;
}

