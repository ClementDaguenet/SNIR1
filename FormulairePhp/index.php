<html>
    <head>
        <title>Formulaire - TD1 exo1</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="css/lib.css" rel="stylesheet" type="text/css"/>
        <script src="js/libs/jquery/jquery.min.js"></script>
        <script src="js/formulaire.js"></script>
    </head>
    <body>
        <form action="php/traitement.php" method="post" id="inscription">
            <fieldset id="formulaire">
                <legend>Formulaire d'inscription</legend>
                <fieldset id="civilite">
                    <legend>Civilités</legend>
                    <?php
                    require_once 'php/fonctions.inc.php';
                    obtenirNom();
                    require_once 'php/fonctions.inc.php';
                    obtenirPrenom();
                    ?>
                    <label class="position_label" for="ville">Ville :</label>
                    <select id="ville" class="position_input" name="ville">
                        <option value="Autre">Autre</option>
                        <option value="Le Mans">Le Mans </option>
                        <option value="Paris">Paris</option>
                    </select><br/><br/>
                    <label class="position_label" for="mail">Email :</label>
                    <input pattern = "(^[a-z]{1,}[a-z0-9._]{1,}@[a-z]{1,}\.[a-z]{2,4}$)" title="xxxxx@yyyyy.zzz" type="text" name="email" class="position_input" id="mail"/><br/><br/>
                    <label class="position_label" for="site">Site :</label>
                    <input type="url" class="position_input" id="site" name="site"/><br/><br/>
                    <label class="position_label">Sexe :</label>
                    <input type="radio" class="position_input" name="sexe" id="sexe1" value="1" checked="checked"/>
                    <label class="position_label2" for="sexe1">Masculin</label><br/>
                    <input type="radio" class="position_input" name="sexe" id="sexe2" value="2" />
                    <label class="position_label2" for="sexe2">Féminin</label><br/>
                    <input type="radio" class="position_input" name="sexe" id="sexe3" value="3" />
                    <label class="position_label2" for="sexe3">Je ne souhaite pas le dire</label><br/><br/>
                    <label class="position_label" for="photo">Photo :</label>
                    <input type="file" class="position_input" id="photo" name="photo"/><br/><br/>
                </fieldset>
                <fieldset id="savoirs">
                    <legend>Savoirs</legend>
                    <label class="position_label" for="se">Système d'exploitation :</label>
                    <select id="se" class="position_input2" name="se">
                        <option value="">Choisir un Système</option>
                        <option value="WIN">Windows</option>
                        <option value="LIN">Linux</option>
                        <option value="MAC">Mac Os</option>
                    </select>
                    <label for="version" id="label-version" >Version :</label>
                    <select id="version" name="version"></select><br/><br/>
                    <label class="position_label">Langages de programmation :</label><br/><br/>
                    <label for="java" class="position_label">JAVA</label>
                    <input type="checkbox" class="position_input3" name="java" id="java" /><br/>
                    <label for="c" class="position_label">C</label>
                    <input type="checkbox" class="position_input3" name="c" id="c" /><br/>
                    <label for="php" class="position_label">PHP</label>
                    <input type="checkbox" class="position_input3" name="php" id="php" /><br/>
                    <label for="autre" class="position_label">Autre</label>
                    <input type="checkbox" class="position_input3" name="autre" id="autre" /><br/>
                </fieldset>
                <fieldset id="connexion">
                    <legend>Paramètres de connexion</legend>
                    <label class="position_label" for="login">Login :</label>
                    <input type="text" id="login" name="login" class="position_input" required="required"/><br/><br/>
                    <label class="position_label" for="mdp">Mot de passe :</label>
                    <input type="password" id="mdp" name="mdp1" class="position_input" required="required"/><br/><br/>
                    <label class="position_label" for="confirmation">Confirmation :</label>
                    <input type="password" id="confirmation" name="mdp2" class="position_input" required="required"/><br/><br/>
                </fieldset>
                <input type="submit" name="inscription" id="validInscription" value="Inscription" />
                <input type="reset" name="clean" id="clean" value="Effacer les informations de ce formulaire" />
            </fieldset>
        </form>
    </body>
</html>
