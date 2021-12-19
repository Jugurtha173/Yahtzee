# Yahtzee (C++)

## Arborescence
### 1) /Yahtzee
le projet contient les fichiers suivant :
	<pre>
	├── de.cpp
	├── de.h
		Classe pour representer les dés,
		avec une valeur qui represente sa face,
		la méthode "roll" pour lancer le dé,
		qui lui affecteras une valeur entre un min et un max donné,
		qu'on peut donc modifier si on veux customiser le jeu,
	</pre>
	<pre>
	├── figure.cpp
	├── figure.h
		Classe abstraite pour representer les figures,
		avec un nom,
		les points qu'on peut rapporter selon les dés lancés,
		les points quand le joueur auras choisis la figure,
		un boolean pour dire si la figure a été utilisé ou pas,
		une méthode virtual pure "eval" qui calcule les points qu'on peut rapporter selon les dés lancés.
	</pre>
	<pre>
	├── figureInferieur.cpp
	├── figureInferieur.h
		Classe pour representer les figures de la partie inférieure,
		hérite de la classe figure,
		dont hérite les classes :
			- chance
			- identique
			- suite
			- figuresMultiple
	</pre>
	<pre>
	├── figureSuperieur.cpp
	├── figureSuperieur.h
		Classe pour representer les figures de la partie supérieure,
		hérite de la classe figure,
		avec une valeur (As => 1).
	</pre>
	<pre>
	├── figuresJeu.h
		classe pour representer les figures qu'on utilisera dans notre partie de jeu,
		qu'on peut donc modifier si on veux customiser le jeu,
		avec un méthode static qui renvoie un tableau de toutes ces figures
	</pre>
	<pre>
	├── joueur.cpp
	├── joueur.h
		Classe pour representer les joueurs
		avec un nom,
		le nombre de tours,
		le total de points pour les figures inférieures et supérieures,
		un tableau de figures qui sont toutes les figures du jeu (figuresJeu),
		un (smart)pointeur sur un objet lancer,
		deux méthodes virtual :
			- chooseDicesToRoll, dans le cas d'un joueur normal, il saisie les indices des dés au clavier.
			- chooseFigure, dans le cas d'un joueur normal, il saisie le nom de la figure au clavier.
	</pre>
	<pre>
	├── IA.cpp
	├── IA.h
		Classe pour representer une IA
		hérite de la classe joueur,
		deux méthodes override :
			 - chooseDicesToRoll, l'IA relance toujours les dés au hasard.
			 - chooseFigure, l'IA choisis la figure qui rapporte le plus de points.
	</pre>	
	<pre>
	├── lancer.cpp
	├── lancer.h
		Classe pour representer un lancer
		avec un tableau de dés,
		le nombre de dés (5),
		le nombre de leurs faces (6),
		qu'on peut donc modifier si on veux customiser le jeu.
	</pre>
	<pre>
	├── partie.cpp
	├── partie.h	
		Classe pour representer une partie,
		avec un tableau de joueur et un lancer
	</pre>
	<pre>
	├── Yahtzee.cpp
		programme principal
	</pre>

### 2) YahtzeeTests:
le projet contient les fichiers de tests du projet Yahtzee.
<pre>
test l'ajout d'un joueur,
un joueur qui gagne des points,
le choix d'une figure uniquement si elle est disponible,
le lancé de dés...
</pre>

### 3) Demo:

Avec une diapo ***Yahtzee.pptx*** pour une petite demo 


### Fonctionnement
<pre>
le programme commence par créer une partie,
avec un nombre de joueurs donné (2 par defaut).

Tant que les joueurs n'ont pas fini (utilisé chacun toutes leurs figures),
un joueur peut jouer trois fois par tour.

Les dés sont lancés à chaque fois,
et chaque figure disponible évalue le nombre de points qu'elle peut rapporter selon les dés,
le joueur peut décider de ralancer les dés qu'il veut (en saisissant leurs indices),
ou décider de ne plus relancer (saisir Entrer),
et choisir directement la figure qu'il veut utilisé (en saisissant son nom).

Une fois la figure choisie, la figure n'est plus disponible,
elle stocke les points qu'elle a rapporter et les ajoute au total de points du joueur.

si le total des de la partie supérieur dépasse les 62 points,
une prime de 35 points se vois ajoutée au total des points du joueur.

Après çà, viens le tours du joueur suivant, et il refait le même sénario.

Quand tous les jouers auront fini,
un tri se fait sur le tableau de joueurs par rapport à leurs total de points,
et le jeu afiche un poduim selon le classement.

FIN DU JEU.
</pre>





