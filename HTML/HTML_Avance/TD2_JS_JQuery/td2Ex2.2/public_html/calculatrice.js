function calcul() {
  let valeur = $(this).val();
  if (valeur === "=") {
    $("#ecran").val(eval($("#ecran").val()));
  } else {
    $("#ecran").val($("#ecran").val() + valeur);
  }
  if (valeur === "C") {
    $("#ecran").val(" ");
  }
}

$(document).ready(function () {
  $(".touche").click(calcul);
});