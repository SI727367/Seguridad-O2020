const app = require('express')();
const multer = require('multer');
const upload = multer({dest: './Textos'});
const alert = require('alert');
const nacl   = require('tweetnacl');
const util   = require('tweetnacl-util');
const scrypt = require('scryptsy');
const fs     = require('fs');

let salt
let nonce

app.get('/',(req, res) =>{
    res.sendFile('/index.html', {root: __dirname});
});

app.post('/enviar', upload.single('archivo'), (req, res) =>
{
    alert('Su archivo de texto ha sido subido exitosamente');
});

app.post('/cifrar', (req, res)=>{
    var password = "ElJeviestkubwe";
    var texto = fs.readFileSync('./Textos/contrasenas.txt', 'utf-8'); 
    var secret_msg = util.decodeUTF8(texto); 
    
    salt = nacl.randomBytes(16);
    console.log("salt:", salt); 
    let N = 16384; 
    let r = 8; 
    let p = 1; 
    let private = scrypt(password, salt, N, r, p, nacl.secretbox.keyLength);
    console.log(private);

    nonce = nacl.randomBytes(nacl.secretbox.nonceLength);
    console.log("nonce:", nonce);
    let encrypted = nacl.secretbox(secret_msg, nonce, private);

    encrypted = util.encodeBase64(encrypted);

    fs.writeFile('protegido.txt', encrypted, 'ascii', function(err) { 
        if (err) {
          console.log(err);
        } else {
          alert('Su documento se encuentra protegido');
        }
      });
})

app.post('/decifrar', (req, res)=>{
    let password = "ElJeviestkubwe";
/*let salt = new Uint8Array([240,  45, 201, 77, 133,
  227, 227, 148, 57, 175,
   99, 120, 152, 18, 231,
   50]);
let nonce = new Uint8Array([  30, 152, 161, 173, 160, 186,
  175, 197, 228, 136,  25, 159,
   88,  96, 228, 126, 213,  23,
  117, 110, 114, 245, 233, 246]);*/

var texto = fs.readFileSync('./Textos/contrasenas.txt', 'utf-8');
let N = 16384;
let r = 8; 
let p = 1; 
let public = scrypt(password, salt, N, r, p, nacl.secretbox.keyLength);

let content = fs.readFileSync('protegido.txt', 'ascii'); 
console.log(content);
let encrypted = util.decodeBase64(content);

let decrypted = nacl.secretbox.open(encrypted, nonce, public); 
decrypted = util.encodeUTF8(decrypted);
if(String(texto) == String(decrypted)){
  console.log('Firma verificada');
  alert('Firma Verificada');
}
else{
  console.log('Firma errónea');
}
});

app.listen(5000, () => console.log('Servidor en Llínea'));




