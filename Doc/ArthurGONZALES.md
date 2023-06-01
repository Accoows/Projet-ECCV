### Historique du projet :

Au début du projet, l'objectif était de créer une voiture amphibie. Cependant, après avoir constaté que ce concept n'était pas réalisable, nous avons décidé de nous réorienter vers une idée plus simple et réalisable. Ainsi, le projet est devenu un engin à chenilles télécommandé, l'ECCV. Après avoir confirmé que ce serait le projet final, chacun s'est vu attribuer une tâche. La mienne était de réaliser en partie la programmation/système de l'engin.

### La réalisation du projet s'est déroulée en plusieurs étapes.

### Début le 17 mars

Au cours des premières semaines de préparation du projet, j'ai concentré mes efforts sur la recherche de composants qui répondraient au mieux à nos attentes pour le projet que nous avions imaginé. Tout d'abord, j'ai examiné les fondements du projet et son objectif, qui était de créer un objet ou autre dispositif offrant une connexion radiofréquence. Pour notre utilisation et la polyvalence du système, j'ai choisi une carte WiFi ESP8266. Avec cette carte, nous pouvons créer une télécommande sans fil utilisable par toutes les personnes possédant un smartphone. La seconde carte utilisée simultanément est un pont H L298N, qui, comme son nom l'indique, est un pont H. Cette carte nous permet de régler individuellement la puissance et la vitesse de deux moteurs de manière indépendante, ce qui correspond parfaitement à nos exigences. Les autres composants restent standards, et la conception de la partie en 3D de "l'engin" est réalisée par Alec et Jules.

### À partir du 12 avril environ

Jules, Alec et moi-même avons commencé à réfléchir à la meilleure façon d'utiliser l'ESP8266 afin qu'il soit compatible avec l'utilisation d'un smartphone (comme mentionné précédemment). Après des recherches, nous avons décidé d'adopter un système basé sur Blynk. Il s'agit d'un service web et d'une application permettant de configurer une interface directement sur un appareil connecté afin de contrôler à distance des systèmes. J'ai alors approfondi mes connaissances sur le fonctionnement précis du système Blynk, sur la manière de l'utiliser et de l'intégrer à la carte ESP8266, ainsi que sur la façon de faire fonctionner les moteurs à partir du smartphone. Après de nombreux échecs avec les moteurs et la carte ESP8266, j'ai finalement réussi à obtenir un programme plus ou moins simple et fonctionnel. Les nombreux échecs sont principalement survenus en raison de modules qui n'étaient pas adaptés.
En cherchant, j'ai découvert que le système Blynk pouvait se suffire à lui-même en utilisant le module Blynk-Edgent pour la mise en place d'un réseau Wi-Fi local.

### A partir de mi-mai

Nous avons ensuite réussi à obtenir un système fonctionnel qui correspondait à notre vision du projet. Nous avons continué à optimiser, dans la mesure du possible, le programme Arduino de l'engin chenillé pour qu'il s'exécute correctement. Une fois que le programme Arduino était terminé et fonctionnel, j'ai ajouté des annotations aux endroits intéressants afin de mieux comprendre le fonctionnement du programme. L'assemblage a ensuite été réalisé par Jules, Alec et moi-même, afin de concrétiser enfin la vision du concept initial.

### Problèmes rencontrés

Lors de l'écriture du programme et de l'assemblage des composants, j'ai malheureusement rencontré quelques problèmes, ce qui est courant en programmation. Tout d'abord, parlons du système principal appelé "Blynk". Initialement, j'avais prévu d'utiliser des modules spécialement conçus pour ESP8266 afin d'établir une connexion entre la carte et le serveur Blynk. Cependant, après de nombreuses recherches et des difficultés liées à l'intégration de la bibliothèque Blynk dans l'environnement de développement Arduino IDE, j'ai réalisé qu'un autre système de la bibliothèque Blynk correspondait parfaitement à ma vision du programme. J'ai donc décidé d'utiliser le module appelé "BlynkEdgent". Ce module permet de créer un réseau local sur la carte Wi-Fi, ce qui permet de configurer la carte pour se connecter au serveur.
Le deuxième problème matériel est en réalité dû à un défaut de conception de la carte WiFi ESP8266. Après quelques semaines de développement du programme, des problèmes de soudure sont apparus, tels que des résistances qui se détachent, des pins qui se retirent et même une puce qui s'est détachée. Nous avons donc décidé de commander une nouvelle carte pour remédier à cette mésaventure (en espérant que cela ne se reproduise pas à nouveau...)

### Conclusion

Le projet ECCV était ambitieux dès le départ, mais nous avons réussi à réaliser une partie importante du développement. Malgré le revers lié à la puissance insuffisante des moteurs, le projet reste en grande partie viable, même si certains ajustements devront être effectués. Je pense qu'un temps supplémentaire aurait permis de résoudre une partie substantielle des problèmes restants.

### Arthur GONZALES
