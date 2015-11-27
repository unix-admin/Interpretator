 var data = {
  people: [
    {
      first:"Jeff",
      last: "Adams"
    },
    {
      first:"Eugenia",
      last: "Tyzak"
    }
  ]
};

$( document ).ready(function() {
$.templates({
  peopleTmpl: "#peopleTemplate"
});

$.templates.peopleTmpl.link("#people", data);

$("#add").on("click", function() {
  $.observable(data.people).insert({
    first:"Amos",
    last: "Sanchez"
  });
});

});