// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

var Raw = { };

function parse(value) {
  var value$1 = value.mutationWithError;
  var value$2 = value$1.errors;
  return {
          mutationWithError: {
            errors: !(value$2 == null) ? value$2.map((function (value) {
                      var value$1 = value.field;
                      var tmp;
                      switch (value$1) {
                        case "FIRST" :
                            tmp = /* FIRST */-24399856;
                            break;
                        case "SECOND" :
                            tmp = /* SECOND */382368628;
                            break;
                        case "THIRD" :
                            tmp = /* THIRD */225952583;
                            break;
                        default:
                          tmp = /* `FutureAddedValue */[
                            -31101740,
                            value$1
                          ];
                      }
                      return {
                              message: value.message,
                              field: tmp
                            };
                    })) : undefined
          }
        };
}

function serialize(value) {
  var value$1 = value.mutationWithError;
  var value$2 = value$1.errors;
  var errors = value$2 !== undefined ? value$2.map((function (value) {
            var value$1 = value.field;
            var field = typeof value$1 === "number" ? (
                value$1 !== 225952583 ? (
                    value$1 >= 382368628 ? "SECOND" : "FIRST"
                  ) : "THIRD"
              ) : value$1[1];
            var value$2 = value.message;
            return {
                    message: value$2,
                    field: field
                  };
          })) : null;
  var mutationWithError = {
    errors: errors
  };
  return {
          mutationWithError: mutationWithError
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

var Normal = {
  Raw: Raw,
  query: "mutation   {\nmutationWithError  {\nerrors  {\nmessage  \nfield  \n}\n\n}\n\n}\n",
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables,
  Z__INTERNAL: Z__INTERNAL
};

var Raw$1 = { };

function parse$1(value) {
  var value$1 = value.mutationWithError;
  var value$2 = value$1.errors;
  return {
          mutationWithError: {
            errors: !(value$2 == null) ? value$2.map((function (value) {
                      var value$1 = value.field;
                      var tmp;
                      switch (value$1) {
                        case "FIRST" :
                            tmp = /* FIRST */-24399856;
                            break;
                        case "SECOND" :
                            tmp = /* SECOND */382368628;
                            break;
                        case "THIRD" :
                            tmp = /* THIRD */225952583;
                            break;
                        default:
                          throw Caml_builtin_exceptions.not_found;
                      }
                      return {
                              message: value.message,
                              field: tmp
                            };
                    })) : undefined
          }
        };
}

function serialize$1(value) {
  var value$1 = value.mutationWithError;
  var value$2 = value$1.errors;
  var errors = value$2 !== undefined ? value$2.map((function (value) {
            var value$1 = value.field;
            var field = value$1 !== 225952583 ? (
                value$1 >= 382368628 ? "SECOND" : "FIRST"
              ) : "THIRD";
            var value$2 = value.message;
            return {
                    message: value$2,
                    field: field
                  };
          })) : null;
  var mutationWithError = {
    errors: errors
  };
  return {
          mutationWithError: mutationWithError
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

var ByConfig = {
  Raw: Raw$1,
  query: "mutation   {\nmutationWithError  {\nerrors  {\nmessage  \nfield  \n}\n\n}\n\n}\n",
  parse: parse$1,
  serialize: serialize$1,
  serializeVariables: serializeVariables$1,
  makeVariables: makeVariables$1,
  makeDefaultVariables: makeDefaultVariables$1,
  Z__INTERNAL: Z__INTERNAL$1
};

var Raw$2 = { };

function parse$2(value) {
  var value$1 = value.mutationWithError;
  var value$2 = value$1.errors;
  return {
          mutationWithError: {
            errors: !(value$2 == null) ? value$2.map((function (value) {
                      var value$1 = value.field;
                      var tmp;
                      switch (value$1) {
                        case "FIRST" :
                            tmp = /* FIRST */-24399856;
                            break;
                        case "SECOND" :
                            tmp = /* SECOND */382368628;
                            break;
                        case "THIRD" :
                            tmp = /* THIRD */225952583;
                            break;
                        default:
                          throw Caml_builtin_exceptions.not_found;
                      }
                      return {
                              message: value.message,
                              field: tmp
                            };
                    })) : undefined
          }
        };
}

function serialize$2(value) {
  var value$1 = value.mutationWithError;
  var value$2 = value$1.errors;
  var errors = value$2 !== undefined ? value$2.map((function (value) {
            var value$1 = value.field;
            var field = value$1 !== 225952583 ? (
                value$1 >= 382368628 ? "SECOND" : "FIRST"
              ) : "THIRD";
            var value$2 = value.message;
            return {
                    message: value$2,
                    field: field
                  };
          })) : null;
  var mutationWithError = {
    errors: errors
  };
  return {
          mutationWithError: mutationWithError
        };
}

function serializeVariables$2(param) {
  
}

function makeVariables$2(param) {
  
}

function makeDefaultVariables$2(param) {
  
}

var Z__INTERNAL$2 = {
  graphql_module: 0
};

var ByDirective = {
  Raw: Raw$2,
  query: "mutation   {\nmutationWithError  {\nerrors  {\nmessage  \nfield  \n}\n\n}\n\n}\n",
  parse: parse$2,
  serialize: serialize$2,
  serializeVariables: serializeVariables$2,
  makeVariables: makeVariables$2,
  makeDefaultVariables: makeDefaultVariables$2,
  Z__INTERNAL: Z__INTERNAL$2
};

exports.Normal = Normal;
exports.ByConfig = ByConfig;
exports.ByDirective = ByDirective;
/* No side effect */
