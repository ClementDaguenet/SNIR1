/* gestion bordure */
function bordure()
{
  let coul = $("#couleurBordure").val();
  let larg = $("#largeurBordure").val();
  let courb = $("#courbeBordure").val() + "px";
  let style = $("#styleBordure").val();
  $("#divTest").css("border-color", coul);
  $("#divTest").css("border-width", larg);
  $("#divTest").css("border-radius", courb);
  $("#divTest").css("border-style", style);
}
/* gestion ombre */
function ombre()
{
  let hori = $("#ombreDecalH").val() + "px ";
  let verti = $("#ombreDecalV").val() + "px ";
  let dist = $("#ombreDistFlou").val() + "px ";
  let tail = $("#ombreTaille").val() + "px ";
  let coul = $("#ombreCouleur").val();
  let ombre = hori + verti + dist + tail + coul;
  $("#divTest").css("box-shadow", ombre);
}
/* gestion texte */
function texte()
{
  let tail = $("#taille").val() + "px";
  let coul = $("#couleur").val();
  let fontCoul = $("#couleurFond").val();
  $("#divTest").css("font-size", tail);
  $("#divTest").css("color", coul);
  $("#divTest").css("background-color", fontCoul);
}

$(function () {
  $(".bordure").change(bordure);
  $(".ombre").change(ombre);
  $(".texte").change(texte);
});
