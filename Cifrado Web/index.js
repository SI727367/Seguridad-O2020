var express = require('express');
var app = express();
var multer = require('multer');
var fs = require('fs');
var Cryptr = require('cryptr');
var alert = require('alert');

const upload = multer({dest: './subidos'});

app.get('/',(req, res) =>{
    res.sendFile('index.html', {root: __dirname});
  });

  app.post('/subida', upload.single('archivo'), (req, res) =>
  {
     alert('enviado');
     res.send();
  });

  app.post('/mostrarenviados', (root,res)=>{
    fs.readdir('subidos', (err, files) => {
        res.send(files);
  });
  });

  app.post('/vercifrados', (root,res)=>{
    fs.readdir('cifrados', (err, files) => {
    alert(files);
    res.send();
  });
  });
  
  app.post('/verdecifrados', (root,res)=>{
    fs.readdir('decifrados', (err, files) => {
      res.send(files);
    res.send();
  });
  });

  app.post('/cifrar', (req, res)=>{
    const cryptr = new Cryptr('eljeviestkubwe');
    const encryptedString = cryptr.encrypt('./subidos/secretioso.txt');
    const decryptedString = cryptr.decrypt(encryptedString);
    fs.writeFile('./cifrados/protegido.txt', encryptedString, 'ascii', function(err) { 
      if (err) {
        console.log(err);
      } else {
        alert('encriptado');
        res.send();
      }
    });
    
  });
  
  app.post('/decifrar', (req,res)=>{
    const cryptr = new Cryptr('eljeviestkubwe');
    var data = fs.readFileSync('./subidos/secretioso.txt');
    const encryptedString = cryptr.encrypt(data); 
    const decryptedString = cryptr.decrypt(encryptedString); 
    fs.writeFile('./decifrados/decifrado.txt', decryptedString, 'ascii', function(err) { 
      if (err) {
        console.log(err);
      } else {
        alert('decifrado');
        res.send();
      }
    });
    });

    const port = 8000;
app.listen(port, () => {
  console.log(`App is running on PORT: ${port}.`);
});
