#Ce document est le readme pour la partie batterie de la veste lumineuse.

Elle est traitée par Clément Servaes et Léonard Navizet

## L'objectif de ce projet est de créer un PCB qui gère l'état de charge de la batterie ainsi que la distribution de la puissance vers les autres modules de la veste lumineuse.

##Explications des différents raisonnements et choix des composants:
Nous n'avons pas choisis nos composant actifs mais dimentioné nos composants passif.

Voici la bill of material qui est une liste des composants utilisés dans le projet :
![Bill of Material](Images/Bill_material.png)

Donc nous allons résumer le fonctiononement des composants utilisé et expliquer le choix des composants associé:
### 🟦 1. [STM32]
- **Référence :STM32G431KBTx**  
- **Fonction :Microcontroleur**  
- **Où il est utilisé :**

---

### 🟨 2. [Nom du composant]
- **Référence :**  
- **Fonction :**  
- **Où il est utilisé :**

---

### 🟥 3. [Nom du composant]
- **Référence :**  
- **Fonction :**  
- **Où il est utilisé :**

---

# Après avoir choisi nos composants, on s'est dirigé vers kicad ou nous avons créer notre PCB. 

Nous avons commencé par déterminer tout les pins que notre STM32 aurait besoin pour la programmation des fonctionnalitées voulue, la gestion de la puissance d'alimentation et les LEDs de statut .
Nous avons ensuite configuré les éléments du programmeur. La prochaine étape a été de comprendre la documentation du composant BQ25185DLHR afin de savoir quelles entrées et sorties étaient nécessaires ainsi que la 
protections des voies de programmation. Nous avons enfin établi avec l'aide de notre encadrant la liste des composants nécessaire à l'inclusion d'un port USB-C. C'est pour cela que nous avons inclu le composant
USBLC6-2SC6 pour permettre au PCB de communiquer en USB-c avec l'ordinateur.


























# Codage de la STM32

Le code de la STM32 est composé en 2 paries. La première est une fonction qui lit la tension de la batterie et l'autre décide comment ragir.

Il faut tout d'abbord bien configurer tout les PINS correctement (VBAT et SYS réglé en ADC1 et 2 single-ended, CE et les 2 STAT en GPIO Output)

## Explication du code

La première étape est de lire la tension de la batterie.
Nous avons créer un utils.c avec la fonction read_analog_input codée ci-dessous.

![Code-read](Images/Code-read.png)

La raw_value récupère la valeur envoyé par la STM. Nous avons mesuré la tension au même moment pour étalonner la variable voltage (4.04 V corresponds à 1596 au PIN).
Cela nous permet de mesurer la tension de la batterie et de l'afficher sur le teerminal.





