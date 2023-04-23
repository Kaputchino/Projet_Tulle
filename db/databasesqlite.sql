BEGIN TRANSACTION;
DROP TABLE IF EXISTS "personne";
CREATE TABLE IF NOT EXISTS "personne" (
										  "idPersonne"	INTEGER NOT NULL,
										  "nom"	Varchar(50) NOT NULL,
	"prenom"	Varchar(50) NOT NULL,
	"adresse"	Varchar(250) NOT NULL,
	"email"	Varchar(50) NOT NULL,
	"password"	Varchar(264) NOT NULL,
	"role"	Varchar(264) NOT NULL,
	CONSTRAINT "personne_PK" PRIMARY KEY("idPersonne" AUTOINCREMENT)
	);
DROP TABLE IF EXISTS "colis";
CREATE TABLE IF NOT EXISTS "colis" (
									   "idColis"	INTEGER NOT NULL,
									   "poids"	Double NOT NULL,
									   "villeArivee"	Varchar(264) NOT NULL,
	"dataAjout"	Varchar(50) NOT NULL,
	"statut"	Smallint NOT NULL,
	"idTrajet"	Int,
	"idDispatcher"	INTEGER,
	CONSTRAINT "colis_PK" PRIMARY KEY("idColis" AUTOINCREMENT),
	FOREIGN KEY("idDispatcher") REFERENCES "personne"("idPersonne"),
	CONSTRAINT "colis_trajet_FK" FOREIGN KEY("idTrajet") REFERENCES "trajet"("idTrajet")
	);
DROP TABLE IF EXISTS "trajet";
CREATE TABLE IF NOT EXISTS "trajet" (
										"idTrajet"	INTEGER NOT NULL,
										"villeDepart"	Varchar(264) NOT NULL,
	"villeArrivee"	Varchar(264) NOT NULL,
	"horaireDepart"	Varchar(264) NOT NULL,
	"horaireArrivee"	Varchar(264) NOT NULL,
	"poids"	Double NOT NULL,
	"prix"	Double NOT NULL,
	"statut"	Smallint NOT NULL,
	"idPersonne"	Int,
	CONSTRAINT "trajet_PK" PRIMARY KEY("idTrajet" AUTOINCREMENT),
	CONSTRAINT "trajet_personne_FK" FOREIGN KEY("idPersonne") REFERENCES "personne"("idPersonne")
	);
COMMIT;
