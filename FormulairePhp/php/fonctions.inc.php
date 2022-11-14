<?php

function verifierDoubleMotPasse($mdp1, $mdp2) {
    $retour = FALSE;
    if ($mdp1 == $mdp2) {
        $retour = TRUE;
    } else {
        $retour = FALSE;
    }
    return $retour;
}

function afficherCookie() {
    echo 'Cookie :<br/>';
    if (!isset($_COOKIE['informations'])) {
        echo 'Cookie vide';
    } else {
        $infos = unserialize($_COOKIE['informations']);
        foreach ($infos as $champs => $valeur) {
            echo "$champs : $valeur <br/>";
        }
        echo '<br/>';
    }
}

function obtenirNom() {
    $nom = "";
    if (isset($_COOKIE['informations'])) {
        $infos = unserialize($_COOKIE['informations']);
        $nom = $infos['Nom'];
        echo "<label class = 'position_label' for = 'nom'>Nom :</label>
    <input type = 'text' id = 'nom' name = 'nom' class = 'position_input' required = 'required' value=$nom/><br/><br/>";
    } else {
        echo "<label class = 'position_label' for = 'nom'>Nom :</label>
    <input type = 'text' id = 'nom' name = 'nom' class = 'position_input' required = 'required'/><br/><br/>";
    }
}

function obtenirPrenom() {
    $prenom = "";
    if (isset($_COOKIE['informations'])) {
        $infos = unserialize($_COOKIE['informations']);
        $prenom = $infos['Prénom'];
        echo "<label class = 'position_label' for = 'prenom'>Prénom :</label>
    <input type = 'text' id = 'prenom' name = 'prenom' class = 'position_input' required = 'required' value=$prenom/><br/><br/>";
    } else {
        echo "<label class = 'position_label' for = 'prenom'>Prénom :</label>
    <input type = 'text' id = 'prenom' name = 'prenom' class = 'position_input' required = 'required'/><br/><br/>";
    }
}
