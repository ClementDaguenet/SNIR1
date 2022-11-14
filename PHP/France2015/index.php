
<?php

require_once './config.inc.php';

$lesPays= new Pays();
$data = array();
$data = $lesPays->ObtenirListe('b','en');
$data = $lesPays->Obteniralpha2('b','en');
?>