## Usage
> make bonus && ./so_long maps/map_of_your_choice.ber

#### Guideline

###### ETAPE 1

Parsing de la map
_________________

Pour parser la map, on fait un gnl du fichier source pour analyser chacune des
lignes du fichier

On a plusieurs conditions a respecter

- La map doit etre entoure de mur (1)
- Il doit y avoir au moins 1 collectible (c)
- Il doit y avoir au moins 1 sortie (e)
- Il doit y avoir 1 seule spawn de joueur (p)
- Les espaces vident sont represente par des '0'

Pour le parsing on verifie donc que la premiere ligne de contient que des 1

Ensuite pour les autres lignes il doit y avoir 1 en premier char et 1 en dernier char

La derniere ligne ne doit contenir que des 1

Entre temps pendant le parsing des murs on garde 3 variables correspondant au nombre
de (p) (c) et (e)

Si a la fin du parsing une de ses conditions n'est pas respecte on exit le programme.
Sinon on cree nos differents tableaux


_______________

##### ETAPE 2

ALLOCATION DES TABLEAUX

Le premier tableau correspond a la map entiere dans lequel on se deplace avec les axes X et Y
(malloc a char par ligne * nombre de ligne + 1)

Le deuxieme tableau dans lequel chaque index aura pour valeur la position d'un collectible
(malloc a variable c + 1)

Idem pour le troisieme tableau mais avec la position des sorties
(malloc a variable e + 2) -> l'index 0 correspondra a un ON OFF (voir plus bas)

_______________

###### ETAPE 3

UTILISATION DES TABLEAUX

Apres chaque input de l'user, on compare la position actuel du personnage avec la position
de chaque collectible present dans la tableau collectible

Des que l'user se trouve sur la meme position qu'un collectible, la valeur de sa position dans
le tableau deviens -1 (la position etant possible ca veut dire que le collectible a ete pris)
et on incremente une variable (current_collectible)

Lorsque (current_collectible) == (total_collectible) ca veut dire qu'on a tout ramasse, on peut
donc sortir du niveau.

La valeur de l'index 0 du 3eme tableau devient ON, on commence donc a comparer maintenant la
position de notre joueur avec celle des differentes sorties, si elles correspondent.

On libere tout l'espace memoire et on quitte le jeu.

_____________

##### ETAPE BONUS 1

ANIMATION

Un simple int qui va de 0 a 1 000 000 000 et qui une fois a 1 000 000 000 change le sprite,
 l'int se reinitialise a chaque fois, ou toutes les 0.3 sec si on arrive a implementer TIME

____________

##### ETAPE BONUS 2

APPARITION ENNEMI

Si plusieurs sorties, on fait spawn nombresDeSortie - 1 ennemis, a l'emplacement de
toutes les sorties sauf la plus proche du spawn

Ca permet d'avoir un nombre variable d'ennemi et de predefinir leur spawn

===================

COMPORTEMENT ENNEMI

L'ennemi doit toujours se rapprocher de la position du joueur, disons que le joueur
se situe en X = 1 et Y = 2 (POS = 11) (pour un tableau de 5 sur 5)

Et que l'ennemi se situe x = 3 et Y = 3 (pos = 18) son objectif va etre de se
rapprocher du joueur, pour se faire il va regarder quel est le moyen le plus rapide
d'obtenir une position similaire a celle du joueur.

Dans notre cas avec un tableau de 5 sur 5, modifier x (se deplacer a gauche ou a droite) 
incremente ou decremente la position de 1, alors que modifier y (monter ou descendre)
augmente ou diminue la position de 5

L'ennemi devra donc decrementer son axe Y de 1, pour se rapprocher du joueur le plus rapidement possible.

L'ennemi attendra l'input du joueur pour se deplacer, le jeu se deroule en tour par tour ou chaque input represente un tour.

______________

______________


1920x1080

1920 / colonne (x) = pixel en largeur pour chaque item
1080 / lignes (y) = pixel en longueur pour chaque item

Chaque input de deplacement du joueur et de l'ia sera egal a :
- Cas W = Yplayer -= 1920 / Y 
- Cas S = Yplayer += 1920 / Y
- Cas A = Xplayer -= 1080 / X
- Cas D = Xplayer += 1080 / X
