# Revue schéma du 07/03/2025

## Généralités

* Nettoyez le projet
    * Virez les fichiers temporaires qu'on a créé au début
* Concertez vous pour revoir l'organisation du projet :
    * Un dossier par sous-projet (led, battery, rf)
    * Dans chaque sous-projet, un dossier hardware contenant le kicad
    * Pas de projets dans ```.zip``` !!
* Configurez des fichiers ```.gitignore``` dans les différents dossiers
* Commencez à organiser le ```README``` :
    * Mettez vos noms
    * Expliquez la hierarchie du projet
    * Je vois que dans certains dossiers il y a des ```README``` : ajoutez un lien dans le ```README``` principal
* Installez ```STM32CubeMX```
    * Je veux voir un fichier ```.ioc``` dans chaque projet

## Schéma veste lumineuse LEDS

* Je reçois le message suivant en ouvrant le schéma, ça ne devrait pas arriver : faites un fichier ```.gitignore```

```
Schematic '/home/laurentf/Documents/ensea/git/2025_1A/24_25_Projet_1A_Veste_Lumineuse/LED/veste lumineuse_LEDS/veste lumineuse_LEDS.kicad_sch' is already open by 'lamya' at 'LAMYAESDIRI'.
```

* C'est très incomplet
* Je vous rappelle le planning :
    * **10/02** prise en main projet/git/composants...
        > (vacances février)
    * **03/03** schéma
    * **10/03** revue + schéma
        > (2 semaines sans projet)
    * **31/03** placement/routage
    * **07/04** revue + routage, fichers de fab = **deadline stricte**
* Avancez pendant le week-end !

## Schéma RF

* Le projet de devrait pas être dans un fichier ```.zip```

* C'est très incomplet
* Je vous rappelle le planning :
    * **10/02** prise en main projet/git/composants...
        > (vacances février)
    * **03/03** schéma
    * **10/03** revue + schéma
        > (2 semaines sans projet)
    * **31/03** placement/routage
    * **07/04** revue + routage, fichers de fab = **deadline stricte**
* Avancez pendant le week-end !

## Schéma battery

* Je ne vois pas le fichier schéma mais que la backup, faudra regarder ça lundi
    * Apparemment c'est ma version de kicad qui fait des blagues
* BQ25185DLHR :
    * EP à la masse
    * GND vers le bas
    * ISET/ILIM
* Connecteur stlink, plutot utiliser :
    * Symbole : ```Conn_ST_STDC14```
    * Footprint : ```Connector_PinHeader_1.27mm:PinHeader_2x07_P1.27mm_Vertical_SMD```
* Connecteur USB à cabler :
    * VBUS = tension d'alimentation (ce sera donc l'entrée du ```BQ25185DLHR```)
    * CC1/CC2 : Resistance de 5.1k à la masse
    * Ajoutez composant ```USBLC6-2SC6``` (```Package_TO_SOT_SMD:SOT-23-6```)
    * Cablez D+ et D- vers le STM32
* MCU OK, on réorganisera un peu lundi
    * C7 : 4.7uF
    * Connectez LED_STATUS au STM32