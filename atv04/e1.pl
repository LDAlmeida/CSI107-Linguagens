progenitor(joao,pedro).
progenitor(maria,pedro).
progenitor(joao,ana).
progenitor(maria,ana).

progenitor(ana,helena).
progenitor(ana,joana).


progenitor(pedro,mario).

progenitor(helena,carlos).
progenitor(mario,carlos).

sexo(joao, masculino).
sexo(pedro, masculino).
sexo(mario, masculino).
sexo(carlos, masculino).

sexo(ana, feminino).
sexo(helena, feminino).
sexo(joana, feminino).

irma(X, Y) :- progenitor(Z, X), progenitor(Z, Y), X \= Y, sexo(X, feminino).
irmao(X, Y) :- progenitor(Z, X), progenitor(Z, Y), X \= Y, sexo(X, masculino).

descendente(X, Y) :- progenitor(Y, X).

mae(X, Y) :- progenitor(X, Y), X \= Y, sexo(X, feminino).
pai(X, Y) :- progenitor(X, Y), X \= Y, sexo(X, masculino).

avo(X, Y) :- pai(Z, Y), pai(X, Z), X \= Y.

tio(X, Y) :- pai(Z, Y), irmao(Z, X), X \= Y.
tio(X, Y) :- mae(Z, Y), irmao(Z, X), X \= Y.

primo(X,Y) :- progenitor(Z,X), progenitor(D, Y), irmao(Z,D), sexo(X, masculino), X \= Y.
primo(X,Y) :- progenitor(Z,X), progenitor(D, Y), irma(Z,D), sexo(X, masculino), X \= Y.
prima(X,Y) :- progenitor(Z,X), progenitor(D, Y), irmao(Z,D), sexo(X, feminino), X \= Y.
prima(X,Y) :- progenitor(Z,X), progenitor(D, Y), irma(Z,D), sexo(X, feminino), X \= Y.


?- progenitor(joao,pedro).

?- progenitor(maria,X).

?- primo(mario,X).

?- tio(X,Y).

?- irmao(X, helena).
?- irma(X, helena).

