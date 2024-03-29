var chart;
var couleurs = ["#1f77b4", "#aec7e8", "#ff7f0e", "#ffbb78", "#2ca02c"];
var options = {};
options.chart = {
  renderTo: 'essenceChart',
  height: 500,
  marginTop: 70,
  marginLeft: 100,
  marginRight: 100,
  backgroundColor: '#F9F9F9',
  type: 'line'
};
options.credits = {
  enabled: false
};
options.colors = couleurs;
options.title = {
  text: "Évolution du prix de l'essence et du baril de pétrole",
  margin: 10
};
options.tooltip = {
  formatter: function ()
    {
      return "Année : " + this.x + "Prix : " + this.y + " €";
    }
};
options.yAxis = [
  {
    title: {
      text: "Gazoil & Super 95 98 (€)"
    },
    labels: {
      formatter: function ()
        {
          return this.value + ' €';
        },
      style: {
        color: '#000'
      }
    }
  },
  {
    title: {
      text: "Baril brent ($US)"
    },
    labels: {
      formatter: function ()
        {
          return this.value + ' $';
        },
      style: {
        color: '#8C564B'
      }
    },
    opposite: true
  }
];
options.xAxis = {
  categories: [],
  crosshair: true,
  labels: {
    rotation: -45,
    y: 20
  }
};
options.series = [
  {
    name: 'Gazoil (€)',
    data: []
  },
  {
    name: 'Super 95 (€)',
    data: []
  },
  {
    name: 'Super 98 (€)',
    data: []
  },
  {
    name: 'Baril de pétrole ($US)',
    yAxis: 1,
    data: []
  }
];
// Avec BDD
$.getJSON('php/Controleur.php',
        {
          action: 'obtenirPrix'
        })
        .done(function (data)
          {
            $.each(data, function (annee, prix)
              {
                options.series[0].data.push(prix.gazoil);
                options.series[1].data.push(prix.super95);
                options.series[2].data.push(prix.super98);
                options.series[3].data.push(prix.brent);
                options.xAxis.categories.push(annee);
              });
            chart = new Highcharts.Chart(options);
          })
        .fail(function (jqXHR, textStatus, errorThrown)
          {
            console.log("parametre : " + JSON.stringify(jqXHR));
            console.log("status : " + textStatus);
            console.log("erreur : " + errorThrown);
          });
// Avec JSON
//$.getJSON('json/prixEssence.json', function (prixEssence)
//  {
//    $.each(prixEssence, function (annee, prix)
//      {
//        options.series[0].data.push(prix.gazoil);
//        options.series[1].data.push(prix.super95);
//        options.series[2].data.push(prix.super98);
//        options.series[3].data.push(prix.brent);
//        options.xAxis.categories.push(annee);
//      });
//    chart = new Highcharts.Chart(options);
//  });