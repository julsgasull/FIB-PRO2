void  reorganitzar_in(const T& x)
/* Pre: p.i. = L */
/* Post: el p.i. conté els mateixos elements que L però
reorganitzats de manera que primer apareixen els més petits
o iguals que x, en el mateix ordre que en L, seguits pels 
més grans que x, en el mateix ordre que en L.
L'element actual del p.i. és el primer del més grans que x, si
existeix, sinó es situa a la dreta de tot */