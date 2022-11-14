function remplirTable()
{
$.getJSON('php/Controleur.php', {action: 'obtenirPrix'})
  .done(function (donnees, stat, xhr)
  {
  $('#essence').DataTable({
  data: donnees,
  columns: [
    {title: "Année"},
    {title: "Gazoil"},
    {title: "Super 95"},
    {title: "Super 98"},
    {title: "Brent"}
  ],
  lengthMenu: [[5, 10, 15, 25, 50, 100, - 1], [5, 10, 15, 25, 50, 100, "Tous"]],
  pageLength: 5,
  language: {
  lengthMenu: "Afficher _MENU_ lignes par page",
          info: "page _PAGE_ sur _PAGES_",
          infoEmpty: "Pas de résultat",
          search: "Recherchez: ",
          paginate: {
          first: "Premier",
          last: "Dernier",
          next: "Suivant",
          previous: "Précédent"
          }
        }
      }
    );
  })
  .fail(function (xhr, text, error){
    console.log("param : " + JSON.stringify(xhr));
    console.log("status : " + text);
    console.log("error : " + error);
  });
}

$(document).ready(function (){
  remplirTable();
});