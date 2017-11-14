

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

- recórrer l’arbre dret (en postordre)
- visitar l’arrel
