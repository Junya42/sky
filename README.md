## Usage
> make && make bonus && ./so_long maps/map_of_your_choice.ber

![awake](https://user-images.githubusercontent.com/59654989/160252495-a3ff6cf4-4319-4857-99c8-dbcc48d03624.png)

#### Guideline

###### ETAPE 1

Parsing de la map

![solongmap](https://user-images.githubusercontent.com/59654989/160252648-89792a68-a1c8-4ed2-9e86-d338b8b21fc2.PNG)

_________________

Pour parser la map, on fait un get_next_line du fichier source pour analyser chacune des
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

ALLOCATION DU TABLEAU * int

Le premier tableau correspond a la map entiere dans lequel on se deplace avec les axes X et Y
(malloc a char par ligne * nombre de ligne + 1)

_______________

###### ETAPE 3

UTILISATION DU TABLEAU

Apres chaque input de l'user, on compare la position actuel du personnage avec la position
de chaque collectible

Des que l'user se trouve sur la meme position qu'un collectible, la valeur de sa position dans
le tableau deviens 0 (valeur du sol classique car le collectible a ete ramasse)
et on incremente une variable (current_collectible)

Lorsque (current_collectible) == (total_collectible) ca veut dire qu'on a tout ramasse, on peut
donc sortir du niveau.

On libere tout l'espace memoire et on quitte le jeu.

_____________

##### ETAPE BONUS 1

ANIMATION

Pour palier aux problemes de performances avec l'utilisation de boucle while pour faire un semblant d'animation
Je suis passe par la fonction mlx_loop_hook qui tourne en permanence en attendant l'input du joueur.
Je ne fais qu'incremente un int a chaque appel de la fonction et lorsque cette int atteint certaines valeurs
specifique, je switch les images affiche a l'ecran avec le sprite suivant. Pour eviter des problemes d'overflows
je reset la valeur de cette int une fois que j'ai pu parcourir tout mes sprites.

____________

##### ETAPE BONUS 2

APPARITION ENNEMI

Si plusieurs sorties, on fait spawn nombresDeSortie - 1 ennemis, a l'emplacement de
toutes les sorties sauf la plus proche du spawn

Ca permet d'avoir un nombre variable d'ennemi et de predefinir leur spawn

===================

COMPORTEMENT ENNEMI

L'ennemi a pour but de foncer sur le joueur afin d'entrer en contact avec lui et de lui faire perdre la partie

Son ia a ete code comme ceci.

(prenons en compte que tout le jeu se deroule dans un simple tableau d'int)
Si le joueur se situe en x = 5 et y = 3
et que l'ia se situe a un bloc en diagonal de celui de notre joueur

![solongia](https://user-images.githubusercontent.com/59654989/160253029-3cccef0d-8fda-4e10-9255-da60812cc01a.PNG)

L'ia se retrouve avec deux choix, se deplacer d'une case sur la droite ou d'une case vers le bas.
Etant donne que par rapport au tableau, se deplacer d'une case horizontalement correspond a se deplace de + 1 ou - 1
et que se deplacer a la vertical correspondant a se deplacer de + x ou - x (x correspondant au nombre de case par ligne)
Il sera donc plus proche du joueur vis a vis du tableau en se deplacant verticalement plutot qu'horizontalement
meme si visuellement les deux deplacements semble etre egaux.

Elle possede egalement un systeme de pathfinding pour palier au fait que la map puisse egalement comporter des murs.

(PS : la detection du joueur si il se situe en bas a gauche ou en haut a droite de l'ia a ete desactive et remplacer
par un autre systeme pour eviter que l'ia soit trop puissante. A tester sur la map my.ber)

______________

______________

![scoreSolong](https://user-images.githubusercontent.com/59654989/160252574-f189f762-5cd4-4caf-9d47-7994405488d0.PNG)
