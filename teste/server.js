var express = require("express");
var app = express();

app.get("/", function (req, res) {
    res.send("first page"); 
});

app.get("/listar", function (req, res) {
    var text = '{ "alunos" : [' +
                '{ "id":"12" , "digital":"0xff" },' +
                '{ "id":"13" , "digital":"0xf8" },' +
                '{ "id":"15" , "digital":"0xffff" } ]}';
    var obj = JSON.parse(text);
    res.json(obj);
});

app.get("/salvar", function (req, res) {
    res.render("salvo a presenca");
});

app.listen(3000, function () {
    console.log("servidor levantado");
});
