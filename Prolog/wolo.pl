aless(X,Y) :- name(X,L), name(Y,M), alessx(L,M).

alessx([],[_|_]).
alessx([X|_],[Y|_]) :- X < Y.
alessx([P|Q],[R|S]) :- P = R, alessx(Q,S).

lookup(H,w(H,G,_,_), G) :- !.
lookup(H,w(H1,_,Before,_), G) :- aless(H,H1),
                 lookup(H,Before,G).
lookup(H,w(H1,_,_,After), G) :- not( aless(H,H1)),
                lookup(H,After,G).