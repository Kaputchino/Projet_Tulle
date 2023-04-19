#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: personne
#------------------------------------------------------------

CREATE TABLE personne(
        idPersonne Int NOT NULL ,
        nom        Varchar (50) NOT NULL ,
        prenom     Varchar (50) NOT NULL ,
        adresse    Varchar (250) NOT NULL ,
        email      Varchar (50) NOT NULL ,
        password   Varchar (264) NOT NULL ,
        role       Varchar (264) NOT NULL
	,CONSTRAINT personne_PK PRIMARY KEY (idPersonne)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: trajet
#------------------------------------------------------------

CREATE TABLE trajet(
        idTrajet       Int NOT NULL ,
        villeDepart    Varchar (264) NOT NULL ,
        villeArrivee   Varchar (264) NOT NULL ,
        horaireDepart  Varchar (264) NOT NULL ,
        horaireArrivee Varchar (264) NOT NULL ,
        poids          Double NOT NULL ,
        prix           Double NOT NULL ,
        statut         Smallint NOT NULL ,
        idPersonne     Int
	,CONSTRAINT trajet_PK PRIMARY KEY (idTrajet)

	,CONSTRAINT trajet_personne_FK FOREIGN KEY (idPersonne) REFERENCES personne(idPersonne)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: colis
#------------------------------------------------------------

CREATE TABLE colis(
        idColis     Int NOT NULL ,
        poids       Double NOT NULL ,
        villeArivee Varchar (264) NOT NULL ,
        dataAjout   Varchar (50) NOT NULL ,
        statut      Smallint NOT NULL ,
        idTrajet    Int
	,CONSTRAINT colis_PK PRIMARY KEY (idColis)

	,CONSTRAINT colis_trajet_FK FOREIGN KEY (idTrajet) REFERENCES trajet(idTrajet)
)ENGINE=InnoDB;

