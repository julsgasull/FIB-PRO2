#include <iostream>
#include "BinTreeIOEst.hh"
using namespace std;


void read_bintree_est(BinTree<Estudiant>& a) {
    Estudiant p;
    p.llegir();
    if (p.consultar_DNI() != 0) {
        BinTree<Estudiant> treeleft;
        read_bintree_est(treeleft);
        BinTree<Estudiant> treeright;
        read_bintree_est(treeright);
        a = BinTree<Estudiant>(p, treeleft, treeright);
    }
}

void write_bintree_est(const BinTree<Estudiant>& a) {
    if(not a.empty()) {
        Estudiant p = a.value();
        write_bintree_est(a.left());
        cout << ' ';
        p.escriure();
        write_bintree_est(a.right());
    }
    else cout << ' ' << 0;
}
