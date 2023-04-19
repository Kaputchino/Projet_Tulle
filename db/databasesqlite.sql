------------------------------------------------------------
--        Script SQLite  
------------------------------------------------------------


------------------------------------------------------------
-- Table: colis
------------------------------------------------------------
CREATE TABLE colis(
	idColis        INTEGER NOT NULL ,
	poids          REAL NOT NULL ,
	villeArivee    TEXT NOT NULL ,
	dataAjout      TEXT NOT NULL ,
	statut         INTEGER NOT NULL,
	CONSTRAINT colis_PK PRIMARY KEY (idColis)
);


------------------------------------------------------------
-- Table: trajet
------------------------------------------------------------
CREATE TABLE trajet(
	idTrajet          INTEGER NOT NULL ,
	villeDepart       TEXT NOT NULL ,
	villeArrivee      TEXT NOT NULL ,
	horaireDepart     TEXT NOT NULL ,
	horaireArrivee    TEXT NOT NULL ,
	poids             REAL NOT NULL ,
	prix              REAL NOT NULL ,
	statut            INTEGER NOT NULL ,
	idColis           INTEGER,
	CONSTRAINT trajet_PK PRIMARY KEY (idTrajet)

	,CONSTRAINT trajet_colis_FK FOREIGN KEY (idColis) REFERENCES colis(idColis)
);


------------------------------------------------------------
-- Table: personne
------------------------------------------------------------
CREATE TABLE personne(
	idPersonne    INTEGER NOT NULL ,
	nom           TEXT NOT NULL ,
	prenom        TEXT NOT NULL ,
	adresse       TEXT NOT NULL ,
	email         TEXT NOT NULL ,
	password      TEXT NOT NULL ,
	role          TEXT NOT NULL ,
	idTrajet      INTEGER,
	CONSTRAINT personne_PK PRIMARY KEY (idPersonne)

	,CONSTRAINT personne_trajet_FK FOREIGN KEY (idTrajet) REFERENCES trajet(idTrajet)
);


