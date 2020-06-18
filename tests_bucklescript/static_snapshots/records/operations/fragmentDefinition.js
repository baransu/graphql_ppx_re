// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


function deepMerge(json1, param) {
  return json1;
}

var GraphQL_PPX = {
  deepMerge: deepMerge
};

var query = "fragment ListFragment on Lists   {\nnullableOfNullable  \nnullableOfNonNullable  \n}\n";

var Raw = { };

function parse(value) {
  var value$1 = value.nullableOfNullable;
  var value$2 = value.nullableOfNonNullable;
  return {
          nullableOfNullable: !(value$1 == null) ? value$1.map((function (value) {
                    if (!(value == null)) {
                      return value;
                    }
                    
                  })) : undefined,
          nullableOfNonNullable: !(value$2 == null) ? value$2.map((function (value) {
                    return value;
                  })) : undefined
        };
}

var verifyArgsAndParse = parse;

function serialize(value) {
  var value$1 = value.nullableOfNonNullable;
  var nullableOfNonNullable = value$1 !== undefined ? value$1.map((function (value) {
            return value;
          })) : null;
  var value$2 = value.nullableOfNullable;
  var nullableOfNullable = value$2 !== undefined ? value$2.map((function (value) {
            if (value !== undefined) {
              return value;
            } else {
              return null;
            }
          })) : null;
  return {
          nullableOfNullable: nullableOfNullable,
          nullableOfNonNullable: nullableOfNonNullable
        };
}

var name = "ListFragment";

var Z__INTERNAL = {
  graphql: 0,
  graphql_module: 0
};

var ListFragment = {
  query: query,
  Raw: Raw,
  parse: parse,
  verifyArgsAndParse: verifyArgsAndParse,
  serialize: serialize,
  name: name,
  Z__INTERNAL: Z__INTERNAL
};

var Raw$1 = { };

function parse$1(value) {
  var value$1 = value.nullableOfNonNullable;
  return {
          nullableOfNonNullable: !(value$1 == null) ? value$1.map((function (value) {
                    return value;
                  })) : undefined
        };
}

var verifyArgsAndParse$1 = parse$1;

function serialize$1(value) {
  var value$1 = value.nullableOfNonNullable;
  var nullableOfNonNullable = value$1 !== undefined ? value$1.map((function (value) {
            return value;
          })) : null;
  return {
          nullableOfNonNullable: nullableOfNonNullable
        };
}

var Z__INTERNAL$1 = {
  graphql: 0,
  graphql_module: 0
};

var Another = {
  query: "fragment Another on Lists   {\nnullableOfNonNullable  \n}\n",
  Raw: Raw$1,
  parse: parse$1,
  verifyArgsAndParse: verifyArgsAndParse$1,
  serialize: serialize$1,
  name: "Another",
  Z__INTERNAL: Z__INTERNAL$1
};

var query$1 = "fragment FragmentWithArgs on Lists   {\nlistWithArg(arg1: $arg1)  \n}\n";

var Raw$2 = { };

function parse$2(value) {
  var value$1 = value.listWithArg;
  return {
          listWithArg: !(value$1 == null) ? value$1.map((function (value) {
                    if (!(value == null)) {
                      return value;
                    }
                    
                  })) : undefined
        };
}

function verifyArgsAndParse$2(_arg1, value) {
  return parse$2(value);
}

function serialize$2(value) {
  var value$1 = value.listWithArg;
  var listWithArg = value$1 !== undefined ? value$1.map((function (value) {
            if (value !== undefined) {
              return value;
            } else {
              return null;
            }
          })) : null;
  return {
          listWithArg: listWithArg
        };
}

var name$1 = "FragmentWithArgs";

var Z__INTERNAL$2 = {
  graphql: 0,
  graphql_module: 0
};

var FragmentWithArgs = {
  query: query$1,
  Raw: Raw$2,
  parse: parse$2,
  verifyArgsAndParse: verifyArgsAndParse$2,
  serialize: serialize$2,
  name: name$1,
  Z__INTERNAL: Z__INTERNAL$2
};

var query$2 = "fragment InlineListFragment on Lists   {\nnullableOfNullable  \nnullableOfNonNullable  \n}\n";

var Raw$3 = { };

function parse$3(value) {
  var value$1 = value.nullableOfNullable;
  var value$2 = value.nullableOfNonNullable;
  return {
          nullableOfNullable: !(value$1 == null) ? value$1.map((function (value) {
                    if (!(value == null)) {
                      return value;
                    }
                    
                  })) : undefined,
          nullableOfNonNullable: !(value$2 == null) ? value$2.map((function (value) {
                    return value;
                  })) : undefined
        };
}

var verifyArgsAndParse$3 = parse$3;

function serialize$3(value) {
  var value$1 = value.nullableOfNonNullable;
  var nullableOfNonNullable = value$1 !== undefined ? value$1.map((function (value) {
            return value;
          })) : null;
  var value$2 = value.nullableOfNullable;
  var nullableOfNullable = value$2 !== undefined ? value$2.map((function (value) {
            if (value !== undefined) {
              return value;
            } else {
              return null;
            }
          })) : null;
  return {
          nullableOfNullable: nullableOfNullable,
          nullableOfNonNullable: nullableOfNonNullable
        };
}

var name$2 = "InlineListFragment";

var Z__INTERNAL$3 = {
  graphql: 0,
  graphql_module: 0
};

var InlineFragment = {
  query: query$2,
  Raw: Raw$3,
  parse: parse$3,
  verifyArgsAndParse: verifyArgsAndParse$3,
  serialize: serialize$3,
  name: name$2,
  Z__INTERNAL: Z__INTERNAL$3
};

var Raw$4 = { };

var query$3 = "query MyQuery($arg1: String)  {\nl1: lists  {\n...ListFragment   \n}\n\nl2: lists  {\n...ListFragment   \n...ListFragment   \n}\n\nl3: lists  {\nnullableOfNullable  \n...ListFragment   \n...ListFragment   \n}\n\nl4: lists  {\nnullableOfNullable  \n...InlineListFragment   \n}\n\nl5: lists  {\n...FragmentWithArgs   \n}\n\n}\nfragment FragmentWithArgs on Lists   {\nlistWithArg(arg1: $arg1)  \n}\nfragment InlineListFragment on Lists   {\nnullableOfNullable  \nnullableOfNonNullable  \n}\nfragment ListFragment on Lists   {\nnullableOfNullable  \nnullableOfNonNullable  \n}\n";

function parse$4(value) {
  var value$1 = value.l2;
  var value$2 = value.l3;
  var value$3 = value$2["nullableOfNullable"];
  var value$4 = value.l4;
  var value$5 = value$4["nullableOfNullable"];
  return {
          l1: parse(value.l1),
          l2: {
            frag1: parse(value$1),
            frag2: parse(value$1)
          },
          l3: {
            nullableOfNullable: !(value$3 == null) ? value$3.map((function (value) {
                      if (!(value == null)) {
                        return value;
                      }
                      
                    })) : undefined,
            frag1: parse(value$2),
            frag2: parse(value$2)
          },
          l4: {
            nullableOfNullable: !(value$5 == null) ? value$5.map((function (value) {
                      if (!(value == null)) {
                        return value;
                      }
                      
                    })) : undefined,
            inlineFragment: parse$3(value$4)
          },
          l5: parse$2(value.l5)
        };
}

function serialize$4(value) {
  var value$1 = value.l5;
  var l5 = serialize$2(value$1);
  var value$2 = value.l4;
  var value$3 = value$2.nullableOfNullable;
  var l4 = [serialize$3(value$2.inlineFragment)].reduce(deepMerge, {
        nullableOfNullable: value$3 !== undefined ? value$3.map((function (value) {
                  if (value !== undefined) {
                    return value;
                  } else {
                    return null;
                  }
                })) : null
      });
  var value$4 = value.l3;
  var value$5 = value$4.nullableOfNullable;
  var l3 = [
      serialize(value$4.frag1),
      serialize(value$4.frag2)
    ].reduce(deepMerge, {
        nullableOfNullable: value$5 !== undefined ? value$5.map((function (value) {
                  if (value !== undefined) {
                    return value;
                  } else {
                    return null;
                  }
                })) : null
      });
  var value$6 = value.l2;
  var l2 = [
      serialize(value$6.frag1),
      serialize(value$6.frag2)
    ].reduce(deepMerge, (function (prim) {
          return { };
        }));
  var value$7 = value.l1;
  var l1 = serialize(value$7);
  return {
          l1: l1,
          l2: l2,
          l3: l3,
          l4: l4,
          l5: l5
        };
}

function serializeVariables(inp) {
  var a = inp.arg1;
  return {
          arg1: a !== undefined ? a : undefined
        };
}

function makeVariables(arg1, param) {
  return serializeVariables({
              arg1: arg1
            });
}

function makeDefaultVariables(param) {
  return serializeVariables({
              arg1: undefined
            });
}

var Z__INTERNAL$4 = {
  graphql_module: 0
};

var MyQuery = {
  Raw: Raw$4,
  query: query$3,
  parse: parse$4,
  serialize: serialize$4,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables,
  Z__INTERNAL: Z__INTERNAL$4
};

var Raw$5 = { };

var query$4 = "query   {\nlists  {\n...ListFragment   \n}\n\n}\nfragment ListFragment on Lists   {\nnullableOfNullable  \nnullableOfNonNullable  \n}\n";

function parse$5(value) {
  return {
          lists: parse(value.lists)
        };
}

function serialize$5(value) {
  var value$1 = value.lists;
  var lists = serialize(value$1);
  return {
          lists: lists
        };
}

function serializeVariables$1(param) {
  
}

function makeVariables$1(param) {
  
}

function makeDefaultVariables$1(param) {
  
}

var Z__INTERNAL$5 = {
  graphql_module: 0
};

var MyQuery2 = {
  Raw: Raw$5,
  query: query$4,
  parse: parse$5,
  serialize: serialize$5,
  serializeVariables: serializeVariables$1,
  makeVariables: makeVariables$1,
  makeDefaultVariables: makeDefaultVariables$1,
  Z__INTERNAL: Z__INTERNAL$5
};

exports.GraphQL_PPX = GraphQL_PPX;
exports.ListFragment = ListFragment;
exports.Another = Another;
exports.FragmentWithArgs = FragmentWithArgs;
exports.InlineFragment = InlineFragment;
exports.MyQuery = MyQuery;
exports.MyQuery2 = MyQuery2;
/* No side effect */
