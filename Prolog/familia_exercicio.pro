pai(ivo, eva).
pai(gil, rai).
pai(gil, clo).
pai(gil, ary).

pai(rai, noe).
pai(ary, gal).


mae(ana, eva).
mae(bia, rai).
mae(bia, clo).
mae(bia, ary).

mae(eva, noe).
mae(lia, gal).


homem(ivo).
homem(gil).
homem(tai).
homem(ary).
homem(noe).

mulher(ana).
mulher(bia).
mulher(eva).
mulher(clo).
mulher(lia).
mulher(gal).

gerou(Pai, Filho) :- pai(Pai, Filho).
gerou(Mae, Filho) :- mae(Mae, Filho).

filho(Progenitor, Filho) :- homem(Filho), gerou(Progenitor, Filho).
filha(Progenitor, Filha) :- mulher(Filha), gerou(Progenitor, Filha).

/* Treta: Tenta adicionar na lista de tios e acaba retornando false*/
/*tio(Tio, Sobrinho) :- pai(Pai, Sobrinho), pai(Avo, Pai), pai(Avo, Tio), homem(Tio), Pai \= Tio.*/
/*tio(Tio, Sobrinho) :- homem(Tio), mae(Mae, Sobrinho), mae(Avo, Mae), pai(Avo, Tio), Pai \= Tio.*/

%avo(Avo, Neto) :- pai(Pai, Neto), pai(Avo, Pai).
avo(Avo, Neto) :- pai(Avo, Pai), pai(Pai, Neto).