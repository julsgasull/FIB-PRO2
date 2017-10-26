#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Parell {
	int x;
	int y;
}

struct Equip {
	int nom;
	int punts;
	int golsfets;
	int golsrebuts;
}

void llegeix(vector< vector< Parell > >& M){
	int f = M.size();
	int c = M[0].size();
	
	for (int i = 0; i < f; i++){
		for (int j = 0; j < c; j++){
			cin >> M[i][j].x >> M[i][j].y;
		}
	}
}

vector<Equip> resultat(const vector< vector<Parell> >& M) {
	int n = M.size();
	vector<Equip> r(n);
	
	//incicialitzo cada equip a 0
	for (int i = 0; i < n i++) {
		r[i].nom = i + 1;
		r[i].punts = 0;
		r[i].golsfets = 0;
		r[i].golsrebuts = 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				//sumar gols
				r[i].golsfets += M[i][j].x;
				r[j].golsfets += M[i][j].y;
				r[i].golsrebuts += M[i][j].x;
				r[j].golsrebuts += M[i][j].y;
				
				//punts
					//empat
				if (M[i][j].x == M[i][j].y) {
					++r[i].punts;
					++r[j].punts;
				}
					//no empat
				else if (M[i][j].x > M[i][j].y) r[i].punts += 3;
				else r[j].punts += 3;
			}
		}
	}
	
	return r;
}

bool comp(Equip a, Equip b) {
	
	if (a.punts != b.punts) return a.punts > b.punts;
	
	else if ((a.golsfets - a.golsrebuts) != (b.golsfets - b.golsrebuts)) {
		return (a.golsfets - a.golsrebuts) > (b.golsfets - b.golsrebuts);
	}
	
	else return a.nom < b.nom;
}

void treureEquips(vector<Equip> r) {
	int f = r.size();
	for (int i = 0; i < f; i++) {
		cout << r[i].nom << ' ' << r[i].punts << ' ' << r[i].golsfets << ' ' << r[i].golsrebuts << endl;
	}
}

int main(){
	//Matriu
	int n;
	cin >> n;
	vector< vector<Parell> > M (n, vector<Parell> (n));
	llegeix(M);

	//comptar variables
	vector<Equip> r(n);
	r = resultat(M); 
	
	//ordeno
	sort(r.begin(),r.end,comp);
	
	//treure
	treureEquips(r);
}
