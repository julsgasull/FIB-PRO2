#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Parell {
    int x;
    int y;
};

struct Equip {
    int nom;
    int punts;
    int golsfets;
    int golsrebuts;
};

vector<Equip> result(const vector< vector<Parell> >& m){
    int n = (int) m.size();
    vector<Equip> r (n);
    
    for(int i = 0; i < n; ++i){
        r[i].nom = i+1;
        r[i].punts = 0;
        r[i].golsfets = 0;
        r[i].golsrebuts= 0;
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j){
                r[i].golsfets += m[i][j].x;
                r[j].golsfets += m[i][j].y;
                r[i].golsrebuts += m[j][i].x;
                r[j].golsrebuts += m[j][i].y;
                
                if(m[i][j].x == m[i][j].y){
                    r[i].punts += 1;
                    r[j].punts += 1;
                }
                else if(m[i][j].x > m[i][j].y) r[i].punts += 3;
                else r[j].punts += 3;
            }
        }
    }
    
    return r;
}

void readMatrix(vector< vector<Parell> >& m){
    int rows = (int) m.size();
    int columns = (int) m[0].size();
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            cin >> m[i][j].x >> m[i][j].y;
        }
    }
}

void printTeams(vector<Equip> r){
    int rows = (int) r.size();
    for(int i = 0; i < rows; ++i){
        cout << r[i].nom << ' ' << r[i].punts << ' ' << r[i].golsfets << ' ' << r[i].golsrebuts << endl;
    }
}

bool comp(Equip a, Equip b){
    if(a.punts != b.punts) return a.punts > b.punts;
    else if(a.golsfets - a.golsrebuts != b.golsfets - b.golsrebuts){
        return a.golsfets - a.golsrebuts > b.golsfets - b.golsrebuts;
    } else return a.nom < b.nom;
}

int main(){
    // Create the matrix
    int n; cin >> n;
    vector< vector<Parell> > m (n, vector<Parell> (n));
    readMatrix(m);
    
    // Compute the result
    vector<Equip> r (n);
    r = result(m);
    
    // Sort
    sort(r.begin(),r.end(),comp);
    
    // Print
    printTeams(r);
    
}
