// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


var Raw = { };

function parse(value) {
  var value$1 = value.variousScalars;
  var value$2 = value$1.int;
  var value$3 = value$1.string;
  return {
          variousScalars: {
            string: value$3,
            int: value$2
          }
        };
}

function serialize(value) {
  var value$1 = value.variousScalars;
  var value$2 = value$1.int;
  var value$3 = value$1.string;
  return {
          variousScalars: {
            string: value$3,
            int: value$2
          }
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
  query: "query   {\nvariousScalars  {\nstring  \nint  \n}\n\n}\n",
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables,
  Z__INTERNAL: Z__INTERNAL
};

var Raw$1 = { };

function parse$1(value) {
  var value$1 = value.variousScalars;
  var value$2 = value$1.nullableString;
  var nullableString = !(value$2 == null) ? value$2 : undefined;
  return {
          variousScalars: {
            nullableString: nullableString
          }
        };
}

function serialize$1(value) {
  var value$1 = value.variousScalars;
  var value$2 = value$1.nullableString;
  var nullableString = value$2 !== undefined ? value$2 : null;
  return {
          variousScalars: {
            nullableString: nullableString
          }
        };
}

function serializeVariables$1(param) {
  
}

function makeVariables$1(param) {
  
}

function makeDefaultVariables$1(param) {
  
}

var Z__INTERNAL$1 = {
  graphql_module: 0
};

var OneFieldQuery = {
  Raw: Raw$1,
  query: "query   {\nvariousScalars  {\nnullableString  \n}\n\n}\n",
  parse: parse$1,
  serialize: serialize$1,
  serializeVariables: serializeVariables$1,
  makeVariables: makeVariables$1,
  makeDefaultVariables: makeDefaultVariables$1,
  Z__INTERNAL: Z__INTERNAL$1
};

var query = "fragment Fragment on VariousScalars   {\nstring  \nint  \n}\n";

var Raw$2 = { };

function parse$2(value) {
  var value$1 = value.int;
  var value$2 = value.string;
  return {
          string: value$2,
          int: value$1
        };
}

var verifyArgsAndParse = parse$2;

function serialize$2(value) {
  var value$1 = value.int;
  var value$2 = value.string;
  return {
          string: value$2,
          int: value$1
        };
}

var name = "Fragment";

var Z__INTERNAL$2 = {
  graphql: 0,
  graphql_module: 0
};

var Fragment = {
  query: query,
  Raw: Raw$2,
  parse: parse$2,
  verifyArgsAndParse: verifyArgsAndParse,
  serialize: serialize$2,
  name: name,
  Z__INTERNAL: Z__INTERNAL$2
};

var Raw$3 = { };

var query$1 = "query   {\nvariousScalars  {\n...Fragment   \n}\n\n}\nfragment Fragment on VariousScalars   {\nstring  \nint  \n}\n";

function parse$3(value) {
  var value$1 = value.variousScalars;
  return {
          variousScalars: parse$2(value$1)
        };
}

function serialize$3(value) {
  var value$1 = value.variousScalars;
  return {
          variousScalars: serialize$2(value$1)
        };
}

function serializeVariables$2(param) {
  
}

function makeVariables$2(param) {
  
}

function makeDefaultVariables$2(param) {
  
}

var Z__INTERNAL$3 = {
  graphql_module: 0
};

var Untitled1 = {
  Raw: Raw$3,
  query: query$1,
  parse: parse$3,
  serialize: serialize$3,
  serializeVariables: serializeVariables$2,
  makeVariables: makeVariables$2,
  makeDefaultVariables: makeDefaultVariables$2,
  Z__INTERNAL: Z__INTERNAL$3
};

var ExternalFragmentQuery = {
  Fragment: Fragment,
  Untitled1: Untitled1
};

var Raw$4 = { };

function parse$4(value) {
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

function serialize$4(value) {
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

function serializeVariables$3(param) {
  
}

function makeVariables$3(param) {
  
}

function makeDefaultVariables$3(param) {
  
}

var Z__INTERNAL$4 = {
  graphql_module: 0
};

var InlineFragmentQuery = {
  Raw: Raw$4,
  query: "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\nname  \nbarkVolume  \n}\n\n}\n\n}\n",
  parse: parse$4,
  serialize: serialize$4,
  serializeVariables: serializeVariables$3,
  makeVariables: makeVariables$3,
  makeDefaultVariables: makeDefaultVariables$3,
  Z__INTERNAL: Z__INTERNAL$4
};

var query$2 = "fragment DogFragment on Dog   {\nname  \nbarkVolume  \n}\n";

var Raw$5 = { };

function parse$5(value) {
  var value$1 = value.barkVolume;
  var value$2 = value.name;
  return {
          name: value$2,
          barkVolume: value$1
        };
}

var verifyArgsAndParse$1 = parse$5;

function serialize$5(value) {
  var value$1 = value.barkVolume;
  var value$2 = value.name;
  return {
          name: value$2,
          barkVolume: value$1
        };
}

var name$1 = "DogFragment";

var Z__INTERNAL$5 = {
  graphql: 0,
  graphql_module: 0
};

var DogFragment = {
  query: query$2,
  Raw: Raw$5,
  parse: parse$5,
  verifyArgsAndParse: verifyArgsAndParse$1,
  serialize: serialize$5,
  name: name$1,
  Z__INTERNAL: Z__INTERNAL$5
};

var Raw$6 = { };

var query$3 = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\n...DogFragment   \n}\n\n}\n\n}\nfragment DogFragment on Dog   {\nname  \nbarkVolume  \n}\n";

function parse$6(value) {
  var value$1 = value.dogOrHuman;
  var typename = value$1["__typename"];
  var tmp = typename === "Dog" ? /* `Dog */[
      3406428,
      parse$5(value$1)
    ] : /* `FutureAddedValue */[
      -31101740,
      value$1
    ];
  return {
          dogOrHuman: tmp
        };
}

function serialize$6(value) {
  var value$1 = value.dogOrHuman;
  return {
          dogOrHuman: value$1[0] >= 3406428 ? serialize$5(value$1[1]) : value$1[1]
        };
}

function serializeVariables$4(param) {
  
}

function makeVariables$4(param) {
  
}

function makeDefaultVariables$4(param) {
  
}

var Z__INTERNAL$6 = {
  graphql_module: 0
};

var Untitled1$1 = {
  Raw: Raw$6,
  query: query$3,
  parse: parse$6,
  serialize: serialize$6,
  serializeVariables: serializeVariables$4,
  makeVariables: makeVariables$4,
  makeDefaultVariables: makeDefaultVariables$4,
  Z__INTERNAL: Z__INTERNAL$6
};

var UnionExternalFragmentQuery = {
  DogFragment: DogFragment,
  Untitled1: Untitled1$1
};

exports.MyQuery = MyQuery;
exports.OneFieldQuery = OneFieldQuery;
exports.ExternalFragmentQuery = ExternalFragmentQuery;
exports.InlineFragmentQuery = InlineFragmentQuery;
exports.UnionExternalFragmentQuery = UnionExternalFragmentQuery;
/* No side effect */
