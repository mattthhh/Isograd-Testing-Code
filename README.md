# Isograd-Testing-Code
Les réponses aux différents exercices sur le test de code par Isograd

## Principe
Les codes sources présents dans ce répo sont des réponses pour les differents concours de code des différents organismes trouvables sur le site [Isograd](https://www.isograd-testingservices.com/). Pour l'instant, les réponses sont uniquement produites en code C, car c'est le langage que je maitrise le mieux, il se peut que certains tests pourront comporteront les réponses dans plusieurs langages, et dans ce cas la, il y aura un dossier pour chaque langage.

## Build
Pour build toutes les sources des réponses aux différents concours, alors il suffit de faire `make` à la racine du projet, qui aura pour but de créer un dossier "build" contenant des sous-dossiers avec le nom de tous les concours de code qui ont été compilés.
Pour compiler les concours de code individuellement, alors il faudra se placer dans le bon dossier puis lancer `make` à l'intérieur de celui ci. Le build va créer des fichiers binaires avec le nom des exercices qui ont été compilés.
