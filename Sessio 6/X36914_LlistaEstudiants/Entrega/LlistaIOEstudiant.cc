#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l){
    Estudiant est;
    est.llegir();
    while(est.consultar_DNI() != 0){
        l.push_back(est);
        est.llegir();
    }
}

void EscriureLlistaEstudiant(list<Estudiant>& l){
    for(list<Estudiant>::iterator it = l.begin(); it != l.end(); ++it){
        (*it).escriure();
    }
}
