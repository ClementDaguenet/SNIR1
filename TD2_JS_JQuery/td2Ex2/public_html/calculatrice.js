function calcul()
{
  let val1;
  let val2;

  val1 = window.document.forms["calculatrice"].val1.value;
  val2 = window.document.forms["calculatrice"].val2.value;
  window.document.forms["calculatrice"].resu.value = val1 * val2;
}