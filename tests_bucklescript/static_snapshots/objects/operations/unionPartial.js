// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


var Raw = { };

function parse(value) {
  var value$1 = value.dogOrHuman;
  var typename = value$1["__typename"];
  var tmp;
  if (typename === "Dog") {
    var value$2 = value$1.barkVolume;
    var value$3 = value$1.name;
    tmp = /* `Dog */[
      3406428,
      {
        name: value$3,
        barkVolume: value$2
      }
    ];
  } else {
    tmp = /* `FutureAddedValue */[
      -31101740,
      value$1
    ];
  }
  return {
          dogOrHuman: tmp
        };
}

function serialize(value) {
  var value$1 = value.dogOrHuman;
  var tmp;
  if (value$1[0] >= 3406428) {
    var value$2 = value$1[1];
    var value$3 = value$2.barkVolume;
    var value$4 = value$2.name;
    tmp = {
      __typename: "Dog",
      name: value$4,
      barkVolume: value$3
    };
  } else {
    tmp = value$1[1];
  }
  return {
          dogOrHuman: tmp
        };
}

function serializeVariables(param) {
  
}

function makeVariables(param) {
  
}

function makeDefaultVariables(param) {
  
}

var Z__INTERNAL = {
  graphql_module: 0
};

var MyQuery = {
  Raw: Raw,
  query: "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\nname  \nbarkVolume  \n}\n\n}\n\n}\n",
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables,
  Z__INTERNAL: Z__INTERNAL
};

exports.MyQuery = MyQuery;
/* No side effect */
