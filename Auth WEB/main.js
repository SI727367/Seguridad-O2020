var Express = require('express');
var bodyParser = require('body-parser');

var {JsonDB} = require('node-json-db');
var {Config} = require('node-json-db/dist/lib/JsonDBConfig');
var uuid = require('uuid');
var speakeasy = require('speakeasy');

var app = Express();

var db = new JsonDB(new Config("base-datos", true, false, '/'));

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.get('/',(req, res) =>{
    res.sendFile('main.html', {root: __dirname});
});

app.post('/registro', (req, res)=> {
    const id = uuid.v4();
    const path = `/user/${id}`;
    const temp_secret = speakeasy.generateSecret();
    res.json({ id, secret: temp_secret.base32 })
    db.push(path, { id, temp_secret });      
});
        
app.post('/sesion', (req, res)=>{
  const { userId, token } = req.body;
  const path = `/user/${userId}`;
  const user = db.getData(path);
  console.log({ user })
  const { base32: secret } = user.temp_secret;
  const verified = speakeasy.totp.verify({
    secret,
    encoding: 'base32',
    token
  });
  if (verified) {
    db.push(path, { id: userId, secret: user.temp_secret });
    res.json({ verified: true })
  } else {
    res.json({ verified: false})
  }
});

const port = 3000;
app.listen(port, () => {
  console.log(`Aplicación corriendo: ${port}.`);
});