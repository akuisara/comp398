var MongoClient = require('mongodb').MongoClient;

var programmingLang = ["Ada", "Python", "C++", "C#", "Objective-C", "Ruby",
"Java", "JavaScript", "C", "Scala", "Racket", "PHP", "HTML", "Scheme",
"Swift", "CSS", "SQL", "CoffeeScript", "Bash", "Fortran", "Perl", "Lisp",
"LaTeX", "Maple", "MATLAB", "R"];

var wheatonLang = ["English", "Chinese", "Japanese", "French", "German",
"Italian", "Arabic", "Russian", "Spanish", "Latin", "Anglo-Saxon English",
"Ancient Greek"];

var collectionList = [];
var lenOne = programmingLang.length;
var lenTwo = wheatonLang.length;
for (var i = 0; i < 2500; i++) {
    var indexOne = Math.floor((Math.random() * Number(lenOne))+ 1);
    var indexTwo = Math.floor((Math.random() * Number(lenTwo))+ 1);
    collectionList.push("{\"index\": \""+i+"\", \"programming\": \""+programmingLang[indexOne]+"\", \"foreign\": \""+wheatonLang[indexTwo]+"\"}");
};
collectionList.push("{\"index\": \""+2500+"\", \"programming\":\""+programmingLang[0]+"\", \"foreign\":\""+wheatonLang[0]+"\"}");

var text = "{\"Collection\": [" + collectionList + "]}";
var obj = JSON.parse(text);
// console.log(obj.Collection);

var uri = 'mongodb://localhost:27017/hw14';

MongoClient.connect(uri, function(err, db) {
    if(err) throw err;

    var programmingLang = db.collection('programmingLang');

    programmingLang.insert(obj.Collection, function(err, result) {    
        if(err) throw err;

        programmingLang.find({ }).toArray(function (err, docs) {
            if(err) throw err;

            docs.forEach(function (doc) {
                console.log('Month ' + doc['index'] + ', wanna learn ' + doc['programming'] + ' in ' + doc['foreign'] + '?');
            });

            db.close(function (err) {
                if(err) throw err;
            });
        });
    });
});