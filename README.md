*This project has been created as part of the 42 curriculum by elocufie , srezzaq.*

# 🔄 Push_swap

Projet de l'école 42 consistant à trier une pile de nombres entiers avec un ensemble limité d'opérations, en utilisant le minimum d'instructions possible.

## Description

Push_swap est un algorithme de tri qui utilise deux piles (a et b) et un ensemble restreint d'opérations. L'objectif est de trier les nombres de la pile A en ordre croissant avec le moins de mouvements possible.

### Opérations disponibles

- **sa/sb/ss** : swap - échange les 2 premiers éléments
- **pa/pb** : push - déplace le premier élément d'une pile vers l'autre
- **ra/rb/rr** : rotate - décale tous les éléments vers le haut
- **rra/rrb/rrr** : reverse rotate - décale tous les éléments vers le bas

### Algorithmes implémentés

- **Tiny sort** : Pour 2-3 éléments
- **Simple** : Pour les petites piles
- **Medium** : Tri par chunks pour piles moyennes
- **Radix** : Pour les grandes piles (500+ éléments)
- **Adaptive** : Sélection automatique de l'algorithme optimal

## Instructions

### Compilation

```bash
make	# Compile push_swap
make bonus	# Compile le checker
make clean	# Nettoie les fichiers objets
make fclean # Nettoie tout
make re	# Recompile entièrement
```

### Utilisation

```bash
# Programme principal
./push_swap 3 2 5 1 4
./push_swap "3 2 5 1 4"

# Avec des nombres négatifs
./push_swap -42 0 15 8

# Checker (bonus) - vérifie si une séquence trie correctement
./push_swap 3 2 1 | ./checker 3 2 1
```

### Exemples

```bash
# Test simple
./push_swap 2 1 3
# Output: sa

# Test avec le checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Output: OK

# Compter le nombre d'opérations
./push_swap 5 2 8 1 9 | wc -l
```

## Ressources

* https://www.geeksforgeeks.org/

### Caractéristiques techniques

- **Langage** : C
- **Norme** : Norminette 42
- **Structure de données** : Liste doublement chaînée
- **Gestion mémoire** : Aucune fuite de mémoire
- **Validation** : Entrées complètement validées (doublons, dépassements, caractères invalides)

### Liens utiles


