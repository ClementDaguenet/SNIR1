<?php

require_once './Modele.php';

class Pays extends Modele {

    public function ObtenirListe($debut) {
        $sql = "select * from pays where `nom_fr_fr` like '{$debut}%' ";
        $reponse = $this->bdd->query($sql);

        $data = array();
        while ($pays = $reponse->fetchObject()) {
            if ($lang == 'fr') {
                array_push($data, $pays->nom_fr_fr);
            }
            if ($lang == 'en') {
                array_push($data, $pays->nom_en_gb);
            }
        }
        return json_encode($data);
    }

    public function ObtenirAlpha2() {
        $sql = "select alpha2 from `pays' where 'nom_fr_fr' = '{$nom}'";
        $reponse=$this->bdd>query($sql);
        $pays=$reponse->fetchObject();
    }

}
