import fs from 'fs';
import ReactDOM from 'react-dom/server';
import React from 'react';
import Html from './helpers/Html';
import ApiClient from './helpers/ApiClient';
import createHistory from 'react-router/lib/createMemoryHistory';
import createStore from './redux/create';

const client = new ApiClient({});
const history = createHistory('/');
  
const store = createStore(history, client);

const assets = require('../webpack-assets.json');
// mop: no idea how to set a proper basepath :S
assets.javascript.main = assets.javascript.main.substr(1);
assets.styles.main = assets.styles.main.substr(1);

let src = '<!doctype html>\n' +
      ReactDOM.renderToString(<Html assets={assets} store={store}/>);

fs.writeFile(__dirname + '/../static/index.html', src, err => {
  if (err) {
    console.error(err);
  } else {
    console.log('Dump successful');
  }
});
