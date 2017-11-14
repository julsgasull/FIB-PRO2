

Estructures de dades lineals i arborecens
=========================================

Estructures de dades lineals
----------------------------
Els seus elements formen una seqüència. (e1, e2, ..., en) on n >= 0.

 - n = 0: estructura buida
 - n = 1: estructura amb 1 element (és el primer i l'últim) no té ni anterior ni posterior
 - n = 2: 2 elements
	 - 1r: no anterior, posterior és el 2n
	 - 2n: no posterior, anterior és el 1r
 - n > 2: tots els elements des de e2 fins a e(n-1) tenen anterior i posterior

Tipus genèrics o parametritzats de dades
----------------------------
```c++
vector<T>, pair<T1,T2>, stack<T>, queue<T>, list<T>, tree<T>.
```
on T,T1 i T2 són paràmetres que representen tipus de dades.


----------

Llistes
=======

Llistes i iteradors
-------------------
**contenidor:** 
estructura de dades on emmagatzemarem objectes d’una forma determinada.

**llista:** 
estructura de dades lineal que permet accedir a qualsevol element sense treure els anteriors. (mitjançant iteradors).
```c++
list<int> l;
```

**iterador:** 
ens permet desplaçar-nos per un contenidor i fer referència als seus elements.
```c++
list<int>::iterator it;
```
L'iterador està associat a la classe, no a la llista -> reutilitzable.

- **begin**:  retorna un iterador que referencia el primer element del contenidor, si és que existeix
```c++
it = l.begin();
```
- **Iteradors constants:** impedeixen modificar l’objecte referenciat per l’iterador. Si la llista és constant -> utilittzem iteradors constants.
```c++
list<Estudiant> l_est;
list<Estudiant>::const_iterator cit = l_est.begin();
```
- Moviment: ++it, --it.
- Contingut: *it.
- **end:** retorna un iterador que referencia a un ele- ment inexistent posterior al darrer element de la llista


| Codi         			| Funcionalitat 										|
| ----------------------|:-----------------------------------------------------:|
| l.begin()         	| return it amb primer element d’l 						|
| l.end()           	| return it element fictici posterior a l'últim d’l 	|
| ++it              	| next element     										|
| --it              	| previous element     									|
| *it               	| contingut element      								|
| it1 = it2         	| assignació     										|
| it1 == it2        	| comparació (=)   										|
| it1 != it2        	| comparació (!=)    									|

Especificació de la classe genèrica Llista
-------------------
```c++
template <class T> class list 
{
	/* 
	Tipus de mòdul : dades
	Descripció del tipus: Estructura lineal que conté
	elements de tipus T, que es pot començar a consultar
	pels extrems, on des de cada element es pot accedir
	a l’element anterior i posterior (si existeixen),
	qualsevol punt.
	*/

	private:
	
	public:
	
	// Constructores
		list(); 
			/* Pre: cert */
			/* Post: El resultat és una llista sense 
			cap element */
		list(const list & original);
			/* Pre: cert */
			d’original */
	
	// Destructora:
	~list();
	
	// Modificadores
	void clear();
		/* Pre: cert */
		/* Post: El paràmetre implícit és una llista
		buida */
	void insert(iterator it, const T& x);
		/* Pre: it referencia algun element existent
		al paràmetre implícit o és igual a l’end()
		d’aquest */
		/* Post: El paràmetre implícit és com el
		paràmetre implícit original amb x davant
		de l’element referenciat per it al paràmetre
		implícit original */
	iterator erase(iterator it);
		/* Pre: it referencia algun element existent
		al paràmetre implícit, que no és buit */
		/* Post: El paràmetre implícit és com el
		paràmetre implícit original sense l’element
		referenciat per l’it original; el resultat
		referencia l’element següent al que
		original */
	void splice(iterator it, list& l);
		/* Pre: l=L, it referencia algun element
		del paràmetre implícit o és igual a l’end()
		d’aquest; el p.i. i l no són el mateix objecte */
		/* Post:  El paràmetre implícit té els seus
		elements originals i els d’l inserits davant
		de l’element referenciat per it; l està buida */
		
	// Consultores
	bool empty() const;
		/* Pre: cert */
		/* Post: El resultat indica si el paràmetre
		implícit té elements o no */
	int size() const;
		/* Pre: cert */
		/* Post: El resultat és el nombre d’elements
		del paràmetre implícit */
};
```

- Atenció: si esborro últim element, l'iterador fa referència a end( ).
- Compilar: `g++ -c elmeuprograma.cc -D_GLIBCXX_DEBUG -I$INCLUSIONS`.

Operacions de llistes
-------------------

- Suma
```c++
int suma_llista_int(const list<int>& l)
	/* Pre: cert */
	/* Post: El resultat és la suma dels elements de
	l */
{
	list<int>::const_iterator it;
	int s = 0;
	for (it = l.begin(); it != l.end(); ++it)
	{
		s += *it;
	}
}
```

- Cerca
```c++
bool pert_llista_int(const list<int>& l, int x)
	/* Pre: cert */
	/* Post: El resultat indica si x hi és o
	no a l */
{
	bool b = false;
	list<int>::const_iterator it = l.begin();
	while (it != l.end() and not b)
	{
	    if (*it == x) b = true;
	    else ++it;
	}
	return b;
}
```
- ...

----------

Estructures arborescents
=======
**Arbre:** 

- estructura de dades no lineal
- els seus elements poden tenir més d’un element successor
- cada element es diu node
- node principal: **arrel**
- nodes/subarbres successors d'arrel: **fills**
- nodes sense successors: **fulles**
- **camí:** successió de nodes des de l'arrel fins a una fulla
- **alçària:** longitud del camí més llarg

**Tipus d'arbres:**
1. Arbre general -> tractarem binari (2 fills)
2. Arbre n-ari: tots els sus subarbres no buits tenen el mateix nombre de fills (siguin buits o no) 

Arbre binari
------------
```c++
template <typename T> class BinTree
{
	/* Tipus de modul: dades
	/* Descripció del tipus: Arbre genèric
	que o bé és buit o bé tot subarbre seu
	té exactament dos fills. */

	public:
	
	BinTree ();
		/* Pre: cert */
		/* Post: El resultat és un arbre
		sense cap element */
	BinTree (const T& x);
		/* Pre:  cert */
		/* Post: El resultat té x com a
		arrel, i els seus fills esquerre
        i dret són buits */
	BinTree (const T& x, const BinTree& left, const BinTree& right);
		/* Pre:  cert */
		/* Post: El paràmetre implícit
		té x com a arrel, left com a fill
		esquerre i right com a fill dret */
	bool empty () const;
		/* Pre: cert */
		/* Post: El resultat indica si el
		paràmetre implícit és buit o no */
	BinTree left () const;
	    /* Pre: El paràmetre implícit no
	    és buit */
	    /* Post: El resultat és el fill
	    esquerre del p.i. */
    BinTree right () const;
	    /* Pre: El paràmetre implícit
	    no és buit */
	    /* Post: El resultat és el fill
	    dret del p.i. */
    const T& value () const;
	    /* Pre: El paràmetre implícit
	    no és buit */
	    /* Post: El resultat és l’arrel
	    del paràmetre implícit */
};
```

Codi
------------

- Alçària:

```c++
int length(const BinTree<int>& a)
	/* Pre: cert */
	/* Post: El resultat és la longitud
	del camí més llarg de l’arrel a una
	fulla de l’arbre a */
{
	int x;
	if (a.empty()) x = 0;
	else {
	    int y = length(a.left());
	    int z = length(a.right());
	    if (y >= z) x = y + 1;
	    else x = z + 1;
	}
	return x; 
}
```

- Mida
```c++
int size(const BinTree<int>& a)
	/* Pre: cert */
	/* Post: El resultat és el nombre
	de nodes de l’arbre a */
{
	int x;
	if (a.empty()) x = 0;
	else x = size(a.left()) + size(a.right()) + 1;
	return x;
}
```

- Cerca de un `int` dins d'un arbre de `int`s:
```c++
bool find(const BinTree<int>& a, int n)
	/* Pre: cert */
	/* Post: El resultat indica si n
	és a l’arbre a */
{
	bool b;
	if (a.empty()) b = false;
	else if (a.value() == n) b = true;
	else
	{
		b = find(a.left(),n)
		if (not b) b = find(a.right(), n);
	}
	return b;
}
```

- Sumar k a tots els nodes d'un arbre de ints

Versió 1:
```cpp
BinTree<int> add(int k, const BinTree<int>& a)
	/* Pre: cert */
	/* Post: El valor de cada node del
	resultat és la suma del valor del node
	corresponent d’a i el valor k */
{
	if (a.empty()) return BinTree<int>();
    else return BinTree<int>(a.value() + k, add(k, a.left()), add(k, a.right()));
}
```

Versió 2:
```cpp
void addVoid(int k, BinTree<int>& a)
	/* Pre: a=A */
	/* Post: El valor de cada node d’a és
	la suma del valor del node corresponent
	d’A i el valor k */
{
    if (not a.empty()) {
	    BinTree<int> a1 = a.left();
	    BinTree<int> a2 = a.right();
	    addVoid(k, a1);
	    addVoid(k, a2);
	    a = BinTree<int>(a.value() + k, a1, a2);
    }
}
```

Recorreguts d'arbres en profunditat
--------------------
![Arbre](https://github.com/julsgasull/PRO2/blob/master/Teoria/Imatges/arbre.png)

1. Preordre (1, 2, 4, 5, 8, 3, 6, 9, 10 i 7.)
> - visitar l’arrel
> - recórrer l’arbre esquerre (en preordre)
> - recórrer l’arbre dret (en preordre)

2. Inordre (4, 2, 8, 5, 1, 9, 6, 10, 3, i 7.)
> - recórrer l’arbre esquerre (en inordre)
> - visitar l’arrel
> - recórrer l’arbre dret (en inordre)

3. Postordre (4, 8, 5, 2, 9, 10, 6, 7, 3, i 1.)
> - recórrer l’arbre esquerre (en postordre)
> - recórrer l’arbre dret (en postordre)
> - visitar l’arrel

```cpp
list<int> preorder(const BinTree<int>& a)
	/* Pre: cert */
	/* Post: El resultat conté els nodes
	d’a en preordre */
{
	list<int> l;
	if (not a.empty())
	{
	    l = preorder(a.left());
	    l.insert(l.begin(),a.value());
	    l.splice(l.end(),preorder(a.right()));
	}
	return l;
}
```
```cpp
void inorder(const BinTree<int>& a, list<int>& l)
	/* Pre: l = L */
	/* Post: l conté L seguit dels nodes
	d’a en inordre */
{
	if (not a.empty())
	{
		inorder(a.left(),l);
	    l.insert(l.end(),a.value());
	    inorder(a.right(),l);
	}
}
```
```cpp
void postorder(const BinTree<int>& a, list<int>& l)
	/* Pre: l = L */
	/* Post: l conté L seguit dels nodes
	d’a en postordre */
{
	if (not a.empty())
	{
		postorder(a.left(),l);
		postorder(a.right(),l);
		l.insert(l.end(),a.value());
	}
}
```

Recorreguts d'arbres en amplada
--------------------
(1, 2, 3, 4, 5, 6, 7, 8, 9, i 10.)
```cpp
void breadth_first_traversal(const BinTree<int>& a, list<int>& l)
	/* Pre: l és buida */
	/* Post: l conté els nodes d’a
	en ordre creixent respecte al
	nivell on es troben, i els de
	cada nivell en ordre d’esquerra
	a dreta */
{
	if (not a.empty())
	{
		queue <BinTree<int> > c;
	    c.push(a);
	    while (not c.empty())
	    {
		    BinTree<int> aux(c.front());
		    l.insert(l.end(),aux.value());
		    if (not aux.left().empty()) c.push(aux.left());
		    if (not aux.right().empty()) c.push(aux.right());
		    c.pop();
		}
	}
}
```


----------

Correctesa de Programes Iteratius i Programació Recursiva
==========================================================

Correctesa de Programes Iteratius
---------------------------------
### Principi d'inducció:
P x significa que x compleix la propietat P.
![Inducció 1](https://github.com/julsgasull/PRO2/blob/master/Teoria/Imatges/induccio.png)
![Inducció 2](https://github.com/julsgasull/PRO2/blob/master/Teoria/Imatges/induccio2.png)

### Correctesa de programes iteratius:
```cpp
/* Pre */ inicialitzacions
while (B) S
/* Post */
```

> 1. Demostrar que **{Pre}Inicialitzacions{Invariant}** . 
> És a dir, si les variables compleixen la precondició, després de realitzar les instruccions d’inicialització abans del bucle, les variables compliran l’invariant.
> 2. Demostrar que **{Invariant i B}S{Invariant}** . 
> És a dir, si les variables compleixen l’invariant i la condició d’entrada al bucle, després d’executar les instruccions d’aquest, es tornarà a complir l’invariant.
> 3. Desmostrar que **{Invariant i not B} -> {Post}**
> És a dir, si les variables compleixen l’invariant però no la condició d’entrada al bucle, llavors han de complir la postcondició.
> 4. Hem d'assegurar que bucle acaba: **funció de fita**. (Aquest paràmetre ha d’apropar-nos cada cop més a la condició d’acabament del bucle, és a dir B.)
> - Invariant -> t pertany a N (per assegurar-nos que si estem en la situació determinada per l’invariant, llavors t té un valor natural). 
> - {Invariant i B i t = T}S{t < T} , per assegurar-nos que t decreix desprès de cada iteració.

### Disseny inductiu d’algoritmes iteratius

La idea és obtenir primer l’invariant, i després les instruccions del bucle. 
> Passos:
> 
> - A partir fonamentalment de la postcondició, que és l’asserció que ens parla del que ha de assolir el bucle, hem de caracteritzar l’invariant. Per això hem de pensar que l’invariant ha de descriure un punt intermig de l’execució del bucle. Una altra manera de veure-ho és pensant que l’invariant és un afebliment de la postcondició, en el sentit de que és la postcondició respecte a la part tractada en l’execució. Per poder afeblir la postcondició necessitarem parlar de noves variables (seran variables locals en el codi), amb les que expressar l’invariant.
> - A partir de l’invariant hem de deduir l’estat en el que l’execució ha acabat. Aquesta serà la condició d’acabament del bucle, i negant aquesta obtindrem la condició B del bucle.
> - Veure quines instruccions necessita el cos del bucle per tal que si a l’entrada d’aquest es compleix l’invariant, al final de l’execució del cos del bucle també es complirà. I donat que cada iteració del bucle ens ha d’apropar al final de l’execució d’aquest, hem de trobar una funció que decreixi en cada iteració.
> - A més hem de veure quines instruccions o inicialitzacions faran que es compleixi l’invariant abans d’entrar al bucle.

### Exemple:

- Codi
```cpp
bool cerca_iter1_vec_int(const vector<int> &v, int x)
	/* Pre: cert */
	/* Post: El resultat ens diu si x és
	un element de v o no */
{
	int i = 0;
	bool ret = false;
	/* Inv: 0 <= i <= v.size(), ret = "l’enter
	x és un element de v[0..i-1]" */
	while(i < v.size() and not ret)
	{ 
		ret = (v[i] == x);
		++i;
	}
	return ret;
```

- **Inicialitzacions.** Inicialment no hem comprovat cap element de v, per tant inicialitzem i a zero, la posició del primer element del vector, satisfent la primera part de l’invariant. Per satisfer la segona, cal posar el valor false a ret, donat que no pot existir l’enter x en un subvector buit v[0 .. -1].

- **Condició de sortida.** Es pot sortir del bucle per dues raons:
	- Si i arriba a ser v.size() vol dir, per l’invariant, que hem explorat tot el vector v i que ret ens diu si l’element x està a v, com es pretén a la postcondició.
	- En cas contrari, com que per l’invariant tenim i <= v.size(), es compleix que i < v.size( ) i per sortir del bucle s’ha de cumplir que ret és cert. Però si abans d’arribar al final del vector v tenim que ret passa a ser true, voldrà dir (de nou per l’invariant) que hem trobat x al subvector v[0..i-1] i que ret ja ens diu que x està a v i també es compleix la postcondició.
- **Cos del bucle.** Abans d’avançar l’índex i, hem de satisfer l’invariant canviant i per i+1. Necessitem que ret contingui la informació de si l’element x es troba al subvec- tor v[0..i]. Com que, si hem entrat al bucle vol dir que ret == false, i per l’invariant tenim que ret conté la informació sobre si x està al subvector v[0..i-1], queda clar que x no està al subvector v[0..i-1] i només ens cal veure si x és igual a v[i], i actualit- zar el valor de ret depenent de si són iguals o no. Un cop que tenim ret modificat, ja podem incrementar i assegurant que satisfem l’invariant. Noteu que, per entrar al bucle, i < v.size(), per tant, marca una posició vàlida del vector i després d’incrementar i es compleix que i <= v.size() (tal com demana l’invariant).

- **Acabament.** A cada volta decreix la distància entre v.size() i l’índex i, perquè incre- mentem i a cadascuna d’elles.


Programació recursiva
----------------------

```cpp
Tipus2 f(Tipus1 x) 
	/* Pre: Q(x) */
	/* Post: R(x,s) */ 
{
	Tipus2 r
	Tipus2 s;
	if (c(x)) s = d(x); 
	else
	{
		r = f(g(x));
		s = h(x,r);
	}
	return s; 
}
```

### Disseny de programes recursius

- Detectar els casos senzills i resoldre’ls sense crides recursives. En definitiva, mirant l’e- xemple abstracte de la secció anterior, consistiria en detectar la condició booleana de l’`if (c(x))` i el conjunt d’instruccions que s’han d’executar si es compleix `d(x)` . En aquests casos senzills, cal assegurar-se de que si les variables compleixen la precondició i la con- dició booleana del if, llavors després d’executar les instruccions (`d(x)` en el exemple) es compleix la postcondició de l’especificació de la funció. Per tant, s’ha de demostrar que `Q(x) i c(x) -> R(x,d(x))`.

- Considerar el cas o casos recursius i resoldre’ls. Per poder generar les instruccions neces- sàries quan no es compleix la condició de l’`if`, hem de fer una crida recursiva a la mateixa funció amb un paràmetre d’entrada menor que l’actual. Per a que aquesta crida pugui fer-se, si x és el paràmetre d’entrada, haurem de demostrar que si `Q(x) i not c(x)`, llavors `g(x)` no és erroni i `g(x)` compleix la precondició de la funció recursiva, es a dir `Q(g(x))` . A partir de aquí, suposem la hipòtesi d’inducció que és l’afirmació: si `g(x)` compleix la precondició `Q(g(x))` , després d’executar la crida recursiva `f(g(x))` , el resultat r compleix la postcondició `R(g(x),r)` . A partir d’aquí hem d’afegir les línies de codi addicionals (`h(x,r)` en aquest cas) que siguin necessàries per a que el codi compleixi la postcondició `R(x, s)` . En altres paraules, hem de demostrar que si x compleix la condició d’entrada i la precondició, i si després de la crida recursiva es compleix la postcondició `R(g(x), r)` llavors també es compleix `R(x,h(x,r))` .Per tant hem de demostrar que `Q(x)i not c(x) i R(g(x), r) -> R(x, h(x, r))`.
- Finalment, hem de raonar sobre les condiciones d’acabament del programa recursiu. És a dir, indicar quin paràmetre, paràmetres, o funció d’aquests, es va fent més petit en cada crida recursiva. En el nostre algoritme recursiu simplificat, si x és el paràmetre d’entrada, la funció del paràmetre x que decreix l’anomenem `t(x)` . D’aquesta manera verificarem que les crides recursives dintre de crides recursives són un nombre finit. Per tant, haurem de demostrar dues coses. Una, que `Q(x) -> t(x) pertany a N`, per assegurar-nos de que la funció que garanteix l’acabament de la recursivitat retorna un natural. L’altre, `Q(x) i not c(x) -> t(g(x)) < t(x)`, per assegurar-nos de que en les crides recursives utilitzem un paràmetre menor que el paràmetre d’entrada.

Al procés descrit se l’anomena inductiu. Un cop generat el codi, podem demostrar la seva correcció utilitzant el principi d’inducció. El que volem demostrar és que tota crida a la funció recursiva compleix la postcondició. Veiem els passos:
- Demostrar que el codi que se executa en els casos bàsics fa que es compleixi la postcondició. Això és equivalent a demostrar P(0) , ja que hem fet zero crides recursives, i demostrem que complim l’especificació. Per tant, P(0) correspon a `R(x, d(x))` .
- Demostrar la correcció del cas recursiu. És a dir hem de demostrar  `Per tot n que pertany a N (P(n) -> P(n+1))`o bé `Per tot y < x (P(y) -> P(x))`. Hem de suposar que la crida recursiva és correcta, és a dir que si `g(x)` és més petit que x i compleix la precondició, llavors `f(g(x))` compleix la postcondició. A partir d’aquí, només queda demostrar que les instruccions posteriors a la crida arriben a la postcondició original. L’enunciat que consisteix en afirmar que la crida recursiva retorna el resultat desitjat (perquè s’ha cridat correctament i acaba) s’anomena hipòtesi d’inducció, i és un element essencial de la demostració.

### Exemples

```cpp
bool piles_iguals(stack<int> &p1, stack<int> &p2)
	/* Pre: p1 = P1 i p2 = P2 */
	/* Post: El resultat ens indica si les
	dues piles inicials P1 i P2 són iguals */ 
{
	bool ret;
	if (p1.empty() or p2.empty()) ret=p1.empty() and p2.empty(); 
	else if (p1.top()!=p2.top()) ret = false;
	else 
	{
		p1.pop();
		p2.pop();
		ret = piles_iguals(p1,p2);
	/* HI: ret="P1 sense l’últim element
	afegit i P2 sense l’últim element afegit
	són dues piles iguals" */ 
	}
	return ret;
}
```
La justificació informal d’aquesta funció recursiva és la següent. 

- Casos senzills.
1. Si alguna de les dues piles és buida, llavors les piles són iguals si les dues són buides. Per tant assignem a ret l’expressió (p1.empty() and p2.empty()).
2. Si les dues piles no són buides, en podem consultar els cims, però si són diferents, llavors les piles no poden ser iguals. Per tant posem ret a fals.

- Cas recursiu. Si les piles no són buides i els cims són iguals, llavors les piles són iguals si coincideixen en la resta d’elements. Això ho podem obtenir, per hipòtesi d’inducció, cridant recursivament a la funció amb les piles sense l’element del cim (podem fer-ho perquè les piles no són buides). Per això assignem a ret el resultat de la crida recursiva.
- Acabament. A cada crida recursiva fem més petita la primera pila (i la segona).

### Immersió o generalització de funcions
**Objectiu:** fer un programa recursiu o millorar el recursiu que ja tenim per fer-lo més eficient.

**Immersió:** és una funció on,

- Introduïm paràmetres addicionals 
i/o
- Introduïm resultats addicionals

Amb això o reforçarem la precondició o afeblirem la postcondició.

**Tipus d'immersió:** per dades i per resultats.

> 

#### Afebliment de postcondició
Amb paràmetres addicionals -> postcondició feble

- Codi original
```c
int suma_vect_int(const vector<int> &v)
/* Pre: v.size()>0 */
/* Post: el valor retornat és la suma de
tots els elements del vector */
```

- Codi posterior
``` c
int i_suma_vect_int(const vector<int> &v, int i) /* Pre: v.size()>0, 0<=i<v.size() */
/* Post: el valor retornat és la suma de
v[0..i] */
{
	int suma;
	if (i == 0) suma = v[0]; 
	else 
	{
		suma= i_suma_vect_int(v,i-1);
		/* HI: "suma" és la suma de v[0..i-1] */ 
		suma += v[i];
	}
	return suma;
}
```
- Codi resolt
```cpp
int suma_vect_int(const vector<int> &v)
	/* Pre: v.size()>0 */
	/* Post: el valor retornat és la suma
	de tots els elements del vector */ 
{
	return i_suma_vect_int(v,v.size()-1); 
}
```

> **SOLUCIÓ**
>-  **Cas senzill.** Si i=0, la postcondició requereix obtenir la suma de v[0..0], que òbviament és v[0] i serà el que retornarem.
> - **Cas recursiu.** Si i!=0, la suma de v[0..i] que ens demanen a la postcondició equival a la suma de v[0..i-1] més v[i]. Per hipòtesi d’inducció, la primera part ja l’hem obtingut amb la crida recursiva i val suma. En conseqüència, el resultat a retornar serà suma+v[i]. La crida és vàlida perquè si i!=0 i apliquem la precondició ens queda que 0 < i o equivalentment 0 <= i-1. L’accés a v[i] és correcte per la precondició.
> - **Acabament.** A cada crida recursiva el valor d’i es fa més petit.

 
#### Reforçament de precondició
**Objectiu:** obtenir funció auxiliar amb precondició original reforçada amb versió feble de postcondició original ->  s’escurça el camí cap a la consecució de l’objectiu que marca la postcondició.

- Codi original
```cpp
int suma_vect_int(const vector<int> &v)
	/* Pre: v.size()>0 */
	/* Post: el valor retornat és la
	suma de tots els elements del vector */
```

- Codi posterior
```cpp
int ii_suma_vect_int(const vector<int> &v, int i, int suma_parcial)
	/* Pre: v.size()>0, 0<=i<=v.size(),
	suma_parcial = suma de v[0..i-1] */
	/* Post: el valor retornat és la suma
	de tots els elements del vector v */ 
{
	int suma;
	if (i == v.size()) suma = suma_parcial;
	else suma= ii_suma_vect_int(v,i+1,suma_parcial+v[i]);
	return suma;
}
```
- Codi resolt
```cpp
int suma_vect_int(const vector<int> &v)
	/* Pre: v.size()>0 */
	/* Post: el valor retornat és la
	suma de tots els elements del vector */ 
{
	return ii_suma_vect_int(v,0,0); 
}
```

> **SOLUCIÓ**
> - **Cas senzill.** Si i=v.size(), per la precondició tenim a suma_parcial la suma de tot el vector, que és el que ens demanen a la postcondició i serà el que retornarem.
> - **Cas recursiu.** Si i!=v.size(), sabem per la precondició de la funció que i < v.size(), per tant i+1<=v.size(). La resta de la precondició de la crida recursiva queda suma_parcial = suma dels elements de v[0..i] o equivalentment suma_parcial = suma dels elements de v[0..i-1] + v[i]. Per la precondició de la funció, la primera part la tenim a la suma_parcial original, de manera que el nou valor de suma_parcial haurà de ser suma_parcial+v[i]. L’accés a v[i] és correcte ja que la precondició diu que 0 <= i i, com ja hem vist, i < v.size().
> - **Acabament.** A cada crida recursiva el valor de v.size()-i es fa més petit.


----------

