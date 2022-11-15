function construireClavier(taille)
{
  let clavier = new Array(taille);
  let touche;
  for (let i = 0; i < 9; i++)
  {
    clavier[i] = -1;
    nombreAleatoire = Math.floor(Math.random() * 9);
    if (clavier[nombreAleatoire] !== -1)
    {
      clavier[nombreAleatoire] = i;
    } else
    {
      while (clavier[nombreAleatoire] === -1)
      {
        if (nombreAleatoire > 15)
        {
          nombreAleatoire = 0;
        }
        if (clavier[nombreAleatoire] !== -1)
        {
          clavier[nombreAleatoire] = i;
        }
        nombreAleatoire++;
      }
    }
    touche = '<input type="button" class="touche ';
    touche += '"value="' + nombreAleatoire + '"/>';
    console.log(touche); // valeurs aléatoires mais mauvais affichage
  }
  for (let i = 0; i < taille; i++)
  {
    $("#clavier").append(touche);
  }
}
function saisirMdp()
{

}
function effacer()
{
  $("#effacer").val() + " ";
}
function valider()
{
  let mdpBon = "1234";
  let idBon = "cdaguenet";
  let mdpEntree = $("#motDePasse").val();
  let idEntree = $("#identifiant").val();
  if (mdpEntree === mdpBon && idEntree === idBon)
  {
    alert("Vous êtes connecté à la banque");
    window.open("https://www.labanquepostale.fr/particulier/connexion-espace-client.html");
  } else
  {
    alert("Connexion refusée");
  }
}
$(document).ready(function ()
{
  construireClavier(16);
  $("#identifiant").val("");
  $("#motDePasse").val("");
});
$(function ()
{
  $("#effacer").click(effacer);
  $("#valider").click(valider);
});