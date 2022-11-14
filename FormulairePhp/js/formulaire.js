function verifierMdp()
{
  var mdp1 = $('#mdp').val();
  var mdp2 = $('#confirmation').val();
  if (mdp1 !== mdp2)
  {
    event.preventDefault(); // Pour empécher l'envoi de données
    alert("Les mots de passe sont différents");
  }
}

function completerVersion()
{
  $("#version").empty();
  var os = $(this).val();
  switch (os)
  {
    case "WIN":
      $("#version").append($("<option>", {value: "seven"}).text("Seven"));
      $("#version").append($("<option>", {value: "w10"}).text("Windows 10"));
      $("#version").append($("<option>", {value: "w11"}).text("Windows 11"));
      $("#version").append($("<option>", {value: "server"}).text("Serveur"));
      break;
    case "LIN":
      $("#version").append($("<option>", {value: "deb"}).text("Debian"));
      $("#version").append($("<option>", {value: "ubu"}).text("Ubuntu"));
      $("#version").append($("<option>", {value: "fed"}).text("Fedora"));
      $("#version").append($("<option>", {value: "suse"}).text("SuSE"));
      $("#version").append($("<option>", {value: "mint"}).text("Mint"));
      break;
    case "MAC":
      $("#version").append($("<option>", {value: "tiger"}).text("Tiger"));
      $("#version").append($("<option>", {value: "leopard"}).text("Leopard"));
      $("#version").append($("<option>", {value: "snow"}).text("Snow Leopard"));
      $("#version").append($("<option>", {value: "lion"}).text("Lion"));
      break;
    default:
      $("#version").empty();
      break;
  }
}

$(document).ready(function ()
{
  $('#inscription').submit(verifierMdp);
  $("#se").change(completerVersion);
});