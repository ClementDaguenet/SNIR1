<?php

require_once 'ModeleEssence.php';

$unPrix = new ModeleEssence();

if (filter_input(INPUT_SERVER, 'REQUEST_METHOD') == 'GET')
  {
  $action = filter_input(INPUT_GET, "action");
  switch ($action)
    {
    case 'obtenirPrix':
      echo $unPrix->ObtenirPrix();
      break;
    }
  }