# Matt_daemon
Introduction to daemons


**Usage :**
- [x] L’exécutable devra se nommer Matt_daemon.
- [ ] Le programme va se lancer uniquement avec les droits root.
- [ ] Votre programme devra s’exécuter en tâche de fond à la façon d’un vrai daemon.
- [ ] Le daemon va devoir écouter sur le port 4242.
- [ ] Pour la journalisation de votre daemon, il sera impératif de créer une classe appe-léeTintin_reporter(celle-ci pourra vous re-servir dans de futurs projets).
- [ ] Tout ce que le daemon fait doit être visible dans un fichier de logmatt_daemon.logavec timestamp (sous la forme [ DD / MM / YYYY - HH : MM : SS]) situé dansle dossier /var/log/matt_daemon/.
- [ ] Vous avez la possibilité de créer plusieurs fichiers de logs si vous le souhaitez.
- [ ] Une seule instance du daemon doit pouvoir être lancée.
- [ ] Lors de la tentative de lancement d’un second daemon alors qu’une instance decelui-ci est déjà en cours, un message d’erreur indiquant une tentative de créa-tion/ouverture de fichier surmatt_daemon.lock doit être visible.
- [ ] Un fichiermatt_daemon.lock doit être créé dans /var/lock/ au lancement du dae-mon.
- [ ] À la fermeture du daemon le fichier matt_daemon.lock doit être effacé.
- [ ] La fermeture du programme doit se faire par l’envoi d’une simple chaîne de carac-tère "quit" sur le socket ouvert.
- [ ] Toute autre chaîne de caractère doit être inscrite dans le fichier de log.
- [ ] Seuls 3 clients peuvent se connecter en simultané sur le daemon.
- [ ] Lorsque le daemon reçoit un signal, il doit l’intercepter et l’inscrire dans le fichiermatt_daemon.logavec un message explicite, puis quitter proprement.

**Des idées de bonus :**
- [ ] Créer un client graphique pour interagir avec le daemon .
- [ ] Ajouter des fonctions utilitaires à votre daemon (création d’un remote shell parexemple !).
- [ ] Chiffrer l’envoi et la réception des données (implique un client, logiquement).
- [ ] Archivage avancé des logs.
- [ ] Envoi de mail suivant des règles de filtrages choisis.
- [ ] Créer un système d’authentification pour se connecter au daemon (via client gra-phique/remote shell).
- [ ] Utilisation de systèmes de chiffrement avancé (clé publique/privée).