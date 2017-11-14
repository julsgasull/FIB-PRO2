#include <list>
#include <iostream>

using namespace std;

typedef list<int> Li;
typedef list<int>::iterator It;
typedef list<int>::const_iterator CIt;

void llegir(Li &l){
  It it=l.end();
  int x;
  cin>>x;
  while(x!=0){
     l.insert(it,x);
     cin>>x;
  }
}

void escriure(int lon, CIt& it){
  //Pre: Si la lista apuntada por it no es vacia, it apunta a un elemento de la lista; 
  //la lista contiene al menos lon elementos a partir del elemento apuntado por it.
  //Si la lista es vacia lon es 0, y it es la posicion end() de la lista.
  //Post: se escribe por pantalla la sublista que empieza en *it, y contiene los lon 
  //terminos siguientes de la lista apuntada por it. Si la lista es vacia, no se 
  //escribe nada.

  for(int i=0;i<lon;++i){
    cout<<*it<<" "; 
    ++it;
  }
  cout<<endl;
}


pair<int,CIt> max_long_esc(const Li &v){
//Pre: cert.
//Post: el primer componente del resultado es la longitud de la sublista de v mas larga 
//donde todo elemento es menor o igual que su siguiente. El segundo componente apunta a la 
//posicion donde se inicia la sublista de longitud maxima de v. En caso de empate apunta 
//al primer elemento de la escalera de longitud maxima de v mas proxima a v.begin(). Si v 
//es vacia, el primer componente del resultado es 0, y el segundo es v.end().

  pair<int,CIt> res;
  CIt it=v.begin();
  CIt it_ant=v.begin();
  CIt prim=v.begin();
  int tam=0;
  if(it==v.end()){
    res.first=0;
    res.second=v.end();
  }
  else{
    ++it;
    res.second=v.begin();
    res.first=1;
    tam=1;
  }

//Inv: 
//1. v.begin()<=it<=v.end();
//2. Si v no es vacia, it_ant es anterior a it en una posicion. v.begin()<=it_ant<v.end().
//3. tam es el tamaño de la sublista actual, hasta la posicion
//   anterior a it,donde todo elemento es menor o igual a su siguiente. o 0 si v es vacia.
//4. prim apunta a la posicion donde empieza la sublista actual entre v.begin() y it_ant,
//   si v no es vacia.
//5. res.first es la longitud de la sublista creciente mas larga de v desde v.begin()
//   hasta la posición anterior a it, it_ant. Si v es vacia, res.first es 0.
//6. res.second apunta al inicio de la subsista creciente mas larga de v desde v.begin()
//   hasta la anterior a it, o apunta a v.end(), si v es vacia.

  while(it!=v.end()){
    if(*it_ant<=*it){
      ++tam;
      if(res.first<tam){
        res.first=tam;
        res.second=prim;
      }
    }
    else{
      tam=1;
      prim=it;
    }
    ++it;
    ++it_ant;
  }
  return res;
}

int main(){
  list<int> v;
  llegir(v);
  pair<int,CIt> prim_max;
  prim_max=max_long_esc(v);
  escriure(prim_max.first, prim_max.second);
}


/*
Inicializaciones:
Después de las inicializaciones, se cumple el invariable.
Tenemos que considerar dos casos, v vacía o no.

Si v es vacía, it=v.end(), y por tanto se cumple el punto 1 del invariante.
A más, res.first=0 y res.second=v.begin(), y por tanto automaticamente se
cumplen 5 y 6.

Si v no es vacía, it_ant está en la primera posición, y it en la siguiente
o v.end() según el tamaño de v. En cualquier caso se cumplen 1 y 2.

prim es v.begin(), y por tanto apunta a la primera posición de la lista
que empieza y acaba en la posición apuntada por it_ant, cumpliéndose 4.
El punto 3 también se cumple porque el tamaño de la lista actual hasta 
it_ant es 1, i tam se inicializa a 1.
Finalmente, se cumplen 5 y 6, porque la subsista actual solo contiene lo 
apuntado por it_ant, la longitud es 1, y su inicio es la posición v.begin()
que en este caso es igual a la posición it_ant.

Justificación del bucle:
Suponemos que en una iteración cualquiera, al entrar en el bucle se cumple
el invariante. Tras ejecutar las instrucciones del bucle, se ha de volver a
cumplir el invariante.
Los puntos 1 y 2 del invariante se cumplen al salir del bucle, porque al
inicio v.begin()<=it<=v.end(), it!=v.end() (condición de entrada en el bucle), 
v.begin()<=it_ant<v.end(), y it_ant es la posición anterior a it. Dentro del 
bucle sobre estos iteradores únicamente se ejecuta ++it y ++it_ant. Por tanto,
al final de la ejecución del bucle, v.begin()<=it<=v.end(), 
v.begin()<=it_ant<v.end(), y it_ant está en la posición anterior.
Si *it_ant<=*it, entonces la escalera continua al menos hasta la posición
apuntada por it. Claramente le hemos añadido un elemento, y dado que ejecutamos
++tam, se sigue cumpliendo 3, es decir que tam muestra el tamaño de la escalera
actual hasta la posición it. Como ejecutamos al final ++it y ++it_ant, tam
muestra el tamaño de la escalera actual hasta la posición it_ant.
prim apuntaba al inicio de la escalera actual hasta it_ant. Dentro del bucle, 
hemos añadido un elemento a la escalera, i aumentado los iteradores it y it_ant.
Por tanto el punto 4 del invariante se sigue cumpliendo.
En este caso, si res.first<tam, modificamos res.first y res.second, haciendo
que tomen los valores de tam i prim. Se continua cumpliendo los puntos 5 y 6,
dado que res continua teniendo el tamaño máximo y la posición donde empieza
la escalera. Después de incrementar los iteradores it y it_ant, estos máximos
son hasta it_ant.

Si se cumple que *it_ant>*it, ejecutamos tam=1 y prim=it. Finalmente movemos
una posición it_ant y it. En este caso una escalera finaliza en la posición 
it_ant, y otra empieza en it. Hasta ese momento tam era el tamaño de la 
escalera que finaliza en it_ant. Como ahora it_ant se ha movido una posición,
tam=1 es correcto, porque solo estamos considerando la escalera que contiene
el elemento apuntado por el antiguo it or el nuevo it_ant. Dado que ejecutamos
prim=it y it++, el inicio de la nueva escalera está en la posición anterior
a it. En este caso res.first y res.second no cambian, porque la presente escalera
solo contiene un elemento, y es seguro que existe una escalera anterior con
un numero igual o mayor de elementos.

Cota:
La distancia entre it y v.end() decrece en cada iteración.
*/
