<?php

require_once 'Modele.php';

class ModeleEssence extends Modele
  {

  public function ObtenirPrix()
    {
    try
      {
      $requete = $this->_bdd->query("select * from prixEssence ;");
      $valeurs = array();
      while ($ligne = $requete->fetch())
        {
        $prix = array();
        $prix["annee"] = intval($ligne['annee']);
        $prix["gazoil"] = floatval($ligne['gazoil']);
        $prix["super95"] = floatval($ligne['super95']);
        $prix["super98"] = floatval($ligne['super98']);
        $prix["brent"] = floatval($ligne['brent']);
        array_push($valeurs, $prix);
        }
      header('Content-Type: application/json');
      return json_encode($valeurs);
      } catch (PDOException $exc)
      {
      die("<br/> Pb ObtenirPrix :" . $exc->getMessage());
      }
    }

  }
