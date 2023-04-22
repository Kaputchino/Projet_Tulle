BEGIN TRANSACTION;
DROP TABLE IF EXISTS "personne";
CREATE TABLE IF NOT EXISTS "personne" (
										  "idPersonne"	INTEGER NOT NULL,
										  "nom"	TEXT NOT NULL,
										  "prenom"	TEXT NOT NULL,
										  "adresse"	TEXT NOT NULL,
										  "email"	TEXT NOT NULL,
										  "password"	TEXT NOT NULL,
										  "role"	TEXT NOT NULL,
										  CONSTRAINT "personne_PK" PRIMARY KEY("idPersonne")
	);

DROP TABLE IF EXISTS "trajet";
CREATE TABLE IF NOT EXISTS "trajet" (
										"idTrajet"	INTEGER NOT NULL,
										"villeDepart"	TEXT NOT NULL,
										"villeArrivee"	TEXT NOT NULL,
										"horaireDepart"	TEXT NOT NULL,
										"horaireArrivee"	TEXT NOT NULL,
										"poids"	REAL NOT NULL,
										"prix"	REAL NOT NULL,
										"statut"	INTEGER NOT NULL,
										"idChauffeur"	INTEGER,
										CONSTRAINT "trajet_chauffeur_FK" FOREIGN KEY("idChauffeur") REFERENCES "personne"("idPersonne")
	);
DROP TABLE IF EXISTS "colis";
CREATE TABLE IF NOT EXISTS "colis" (
									   "idColis"	INTEGER NOT NULL,
									   "poids"	REAL NOT NULL,
									   "villeArivee"	TEXT NOT NULL,
									   "dataAjout"	TEXT NOT NULL,
									   "statut"	INTEGER NOT NULL,
									   "idTrajet"	INTEGER,
									   CONSTRAINT "colis_PK" PRIMARY KEY("idColis")
	CONSTRAINT "trajet_colis_FK" FOREIGN KEY("idTrajet") REFERENCES "trajet"("idTrajet")
	);
