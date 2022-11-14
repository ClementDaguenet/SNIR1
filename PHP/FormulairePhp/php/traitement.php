<?php

echo "Données envoyées via la méthode post<br/><br/>";

$mdp1 = $_POST["mdp1"];
$mdp2 = $_POST["mdp2"];
require_once './fonctions.inc.php';
if (verifierDoubleMotPasse($mdp1, $mdp2)) {
    echo '';
}
require_once './fonctions.inc.php';
afficherCookie();

echo "Nom : " . filter_input(INPUT_POST, "nom") . "<br/>";
echo "Prénom : " . filter_input(INPUT_POST, "prenom") . "<br/>";
echo "Ville : " . filter_input(INPUT_POST, "ville") . "<br/>";
echo "Email : " . filter_input(INPUT_POST, "email", FILTER_VALIDATE_EMAIL) . "<br/>";
echo "Site : " . filter_input(INPUT_POST, "site") . "<br/>";
echo "Sexe : " . filter_input(INPUT_POST, "sexe") . "<br/>";
echo "Photo : " . filter_input(INPUT_POST, "photo") . "<br/>";
echo "OS : " . filter_input(INPUT_POST, "se") . "<br/>";
echo "Version : " . filter_input(INPUT_POST, "version") . "<br/>";
echo "Java : " . filter_input(INPUT_POST, "java") . "<br/>";
echo "C : " . filter_input(INPUT_POST, "c") . "<br/>";
echo "PHP : " . filter_input(INPUT_POST, "php") . "<br/>";
echo "Autre : " . filter_input(INPUT_POST, "autre") . "<br/>";
echo "Login : " . filter_input(INPUT_POST, "login") . "<br/>";
echo "Mot de passe : " . filter_input(INPUT_POST, "mdp1") . "<br/>";

$nom = filter_input(INPUT_POST, "nom");
$prenom = filter_input(INPUT_POST, "prenom");
$infos = array(
    "Nom" => $nom,
    "Prénom" => $prenom
);

$infos2 = serialize($infos);
setcookie("informations", $infos2, 0, "/");

echo "<pre>";
print_r($_POST);
echo"</pre>";
