
"use strict";

let Gprmc = require('./Gprmc.js');
let Gpgsa = require('./Gpgsa.js');
let Sentence = require('./Sentence.js');
let Gpgsv = require('./Gpgsv.js');
let Gpgga = require('./Gpgga.js');
let GpgsvSatellite = require('./GpgsvSatellite.js');

module.exports = {
  Gprmc: Gprmc,
  Gpgsa: Gpgsa,
  Sentence: Sentence,
  Gpgsv: Gpgsv,
  Gpgga: Gpgga,
  GpgsvSatellite: GpgsvSatellite,
};
