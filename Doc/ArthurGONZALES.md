### La réalisation du projet s'est déroulée en plusieurs étapes.

### Début le 17 mars

Au cours des premières semaines de préparation du projet, j'ai concentré mes efforts sur la recherche de composants qui répondraient au mieux à nos attentes pour le projet que nous avions imaginé. Tout d'abord, j'ai examiné les fondements du projet et son objectif, qui était de créer un objet ou autre dispositif offrant une connexion radiofréquence. Pour notre utilisation et la polyvalence du système, j'ai choisi une carte WiFi ESP8266. Avec cette carte, nous pouvons créer une télécommande sans fil utilisable par toutes les personnes possédant un smartphone. La seconde carte utilisée simultanément est un pont H L298N, qui, comme son nom l'indique, est un pont H. Cette carte nous permet de régler individuellement la puissance et la vitesse de deux moteurs de manière indépendante, ce qui correspond parfaitement à nos exigences. Les autres composants restent standards, et la conception de la partie en 3D de "l'engin" est réalisée par Alec et Jules.

### À partir du 12 avril environ

Jules, Alec et moi-même avons commencé à réfléchir à la meilleure façon d'utiliser l'ESP8266 afin qu'il soit compatible avec l'utilisation d'un smartphone (comme mentionné précédemment). Après des recherches, nous avons décidé d'adopter un système basé sur Blynk. Il s'agit d'un service web et d'une application permettant de configurer une interface directement sur un appareil connecté afin de contrôler à distance des systèmes. J'ai alors approfondi mes connaissances sur le fonctionnement précis du système Blynk, sur la manière de l'utiliser et de l'intégrer à la carte ESP8266, ainsi que sur la façon de faire fonctionner les moteurs à partir du smartphone. Après de nombreux échecs avec les moteurs et la carte ESP8266, j'ai finalement réussi à obtenir un programme plus ou moins simple et fonctionnel. Les nombreux échecs sont principalement survenus en raison de modules qui n'étaient pas adaptés.
En cherchant, j'ai découvert que le système Blynk pouvait se suffire à lui-même en utilisant le module Blynk-Edgent pour la mise en place d'un réseau Wi-Fi local.

### Vers mi-mai

Nous avons ensuite réussi à obtenir un système fonctionnel qui correspondait à notre vision du projet. Nous avons continué à optimiser, dans la mesure du possible, le programme Arduino de l'engin chenillé et à l'intégrer à la base 3D. L'assemblage a ensuite été réalisé par Jules, Alec et moi-même, afin de concrétiser enfin la vision du concept initial.
