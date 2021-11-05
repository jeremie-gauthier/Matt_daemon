# Matt_daemon
Introduction to daemons

**Usage :**
- [x] L’exécutable devra se nommer Matt_daemon.
- [x] Le programme va se lancer uniquement avec les droits root. // REMETTRE LA CONDITION GETUID
- [x] Votre programme devra s’exécuter en tâche de fond à la façon d’un vrai daemon.
- [x] Le daemon va devoir écouter sur le port 4242.
- [x] Pour la journalisation de votre daemon, il sera impératif de créer une classe appelée Tintin_reporter (celle-ci pourra vous re-servir dans de futurs projets).
- [x] Tout ce que le daemon fait doit être visible dans un fichier de log matt_daemon.log avec timestamp (sous la forme [ DD / MM / YYYY - HH : MM : SS]) situé dans le dossier /var/log/matt_daemon/.
- [ ] Vous avez la possibilité de créer plusieurs fichiers de logs si vous le souhaitez. (optional)
- [x] Une seule instance du daemon doit pouvoir être lancée.
- [x] Lors de la tentative de lancement d’un second daemon alors qu’une instance de celui-ci est déjà en cours, un message d’erreur indiquant une tentative de création/ouverture de fichier sur matt_daemon.lock doit être visible.
- [x] Un fichier matt_daemon.lock doit être créé dans /var/lock/ au lancement du daemon.
- [x] À la fermeture du daemon le fichier matt_daemon.lock doit être effacé.
- [x] La fermeture du programme doit se faire par l’envoi d’une simple chaîne de caractère "quit" sur le socket ouvert.
- [x] Toute autre chaîne de caractère doit être inscrite dans le fichier de log.
- [x] Seuls 3 clients peuvent se connecter en simultané sur le daemon.
- [x] Lorsque le daemon reçoit un signal, il doit l’intercepter et l’inscrire dans le fichier matt_daemon.log avec un message explicite, puis quitter proprement.

**Des idées de bonus :**
- [ ] Créer un client graphique pour interagir avec le daemon .
- [ ] Ajouter des fonctions utilitaires à votre daemon (création d’un remote shell par exemple !).
- [ ] Chiffrer l’envoi et la réception des données (implique un client, logiquement).
- [ ] Archivage avancé des logs.
- [ ] Envoi de mail suivant des règles de filtrages choisis.
- [ ] Créer un système d’authentification pour se connecter au daemon (via client graphique/remote shell).
- [ ] Utilisation de systèmes de chiffrement avancé (clé publique/privée).
