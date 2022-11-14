
function changerCouleurBordure()
{
    var coul = $("#couleurBordure").val();
    $("#divTest").css("border-color", coul);
}




$(function () {
    /*  gestion bordure */
    $("#couleurBordure").change(changerCouleurBordure);

   

   
});
