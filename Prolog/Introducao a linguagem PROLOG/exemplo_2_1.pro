% pais(Nome, Área, População).
pais(brasil, 9, 130).
pais(china, 12, 1800).
pais(eua, 9, 230).
pais(india, 3, 450). 

dens(P, D) :- pais(P, A, Pop), D is Pop/A.