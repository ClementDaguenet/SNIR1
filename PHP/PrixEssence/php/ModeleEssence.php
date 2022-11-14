<?php

require_once 'Modele.php';

class ModeleEssence extends Modele
  {

  public function ObtenirPrix()
    {
    try
      {
      $requete = $this->_bdd->prepare("select * from prixEssence ;");
      $requete->execute();
      $valeurs = array();
      $prix = array();
      while ($ligne = $requete->fetch())
        {
        $prix["gazoil"] = floatval($ligne['gazoil']);
        $prix["super95"] = floatval($ligne['super95']);
        $prix["super98"] = floatval($ligne['super98']);
        $prix["brent"] = floatval($ligne['brent']);
        $valeurs[$ligne['annee']] = $prix;
        }
      header('Content-Type: application/json');
      return json_encode($valeurs);
      } catch (PDOException $exc)
      {
      die("<br/> Pb ObtenirPrix :" . $exc->getMessage());
      }
    }

  }
