[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
module GraphQL_PPX = {
  let deepMerge = (json1, _) => json1;
};
module ListFragment = {
  /**The GraphQL query string*/
  let query = "fragment ListFragment on Lists   {\nnullableOfNullable  \nnullableOfNonNullable  \n}\n";
  module Raw = {
    type t = {
      .
      "nullableOfNullable": Js.Nullable.t(array(Js.Nullable.t(string))),
      "nullableOfNonNullable": Js.Nullable.t(array(string)),
    };
    type nonrec t_Lists = t;
  };
  type t = {
    .
    "nullableOfNullable": option(array(option(string))),
    "nullableOfNonNullable": option(array(string)),
  };
  type nonrec t_Lists = t;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let nullableOfNonNullable = {
      let value = value##nullableOfNonNullable;
      switch (Js.toOption(value)) {
      | Some(value) => Some(value |> Js.Array.map(value => value))
      | None => None
      };
    }
    and nullableOfNullable = {
      let value = value##nullableOfNullable;
      switch (Js.toOption(value)) {
      | Some(value) =>
        Some(
          value
          |> Js.Array.map(value =>
               switch (Js.toOption(value)) {
               | Some(value) => Some(value)
               | None => None
               }
             ),
        )
      | None => None
      };
    };
    {
      "nullableOfNullable": nullableOfNullable,
      "nullableOfNonNullable": nullableOfNonNullable,
    };
  };
  let verifyArgsAndParse = (value: Raw.t) => parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let nullableOfNonNullable = {
      let value = value##nullableOfNonNullable;
      switch (value) {
      | Some(value) =>
        Js.Nullable.return(value |> Js.Array.map(value => value))
      | None => Js.Nullable.null
      };
    }
    and nullableOfNullable = {
      let value = value##nullableOfNullable;
      switch (value) {
      | Some(value) =>
        Js.Nullable.return(
          value
          |> Js.Array.map(value =>
               switch (value) {
               | Some(value) => Js.Nullable.return(value)
               | None => Js.Nullable.null
               }
             ),
        )
      | None => Js.Nullable.null
      };
    };
    {
      "nullableOfNullable": nullableOfNullable,
      "nullableOfNonNullable": nullableOfNonNullable,
    };
  };
  let name = "ListFragment";
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module Another = {
  /**The GraphQL query string*/
  let query = "fragment Another on Lists   {\nnullableOfNonNullable  \n}\n";
  module Raw = {
    type t = {. "nullableOfNonNullable": Js.Nullable.t(array(string))};
    type nonrec t_Lists = t;
  };
  type t = {. "nullableOfNonNullable": option(array(string))};
  type nonrec t_Lists = t;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let nullableOfNonNullable = {
      let value = value##nullableOfNonNullable;
      switch (Js.toOption(value)) {
      | Some(value) => Some(value |> Js.Array.map(value => value))
      | None => None
      };
    };
    {"nullableOfNonNullable": nullableOfNonNullable};
  };
  let verifyArgsAndParse = (value: Raw.t) => parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let nullableOfNonNullable = {
      let value = value##nullableOfNonNullable;
      switch (value) {
      | Some(value) =>
        Js.Nullable.return(value |> Js.Array.map(value => value))
      | None => Js.Nullable.null
      };
    };
    {"nullableOfNonNullable": nullableOfNonNullable};
  };
  let name = "Another";
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module FragmentWithArgs = {
  /**The GraphQL query string*/
  let query = "fragment FragmentWithArgs on Lists   {\nlistWithArg(arg1: $arg1)  \n}\n";
  module Raw = {
    type t = {
      .
      "listWithArg": Js.Nullable.t(array(Js.Nullable.t(string))),
    };
    type nonrec t_Lists = t;
  };
  type t = {. "listWithArg": option(array(option(string)))};
  type nonrec t_Lists = t;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let listWithArg = {
      let value = value##listWithArg;
      switch (Js.toOption(value)) {
      | Some(value) =>
        Some(
          value
          |> Js.Array.map(value =>
               switch (Js.toOption(value)) {
               | Some(value) => Some(value)
               | None => None
               }
             ),
        )
      | None => None
      };
    };
    {"listWithArg": listWithArg};
  };
  let verifyArgsAndParse = (~arg1 as _arg1: [ | `String], value: Raw.t) =>
    parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let listWithArg = {
      let value = value##listWithArg;
      switch (value) {
      | Some(value) =>
        Js.Nullable.return(
          value
          |> Js.Array.map(value =>
               switch (value) {
               | Some(value) => Js.Nullable.return(value)
               | None => Js.Nullable.null
               }
             ),
        )
      | None => Js.Nullable.null
      };
    };
    {"listWithArg": listWithArg};
  };
  let name = "FragmentWithArgs";
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};

module InlineFragment = {
  /**The GraphQL query string*/
  let query = "fragment InlineListFragment on Lists   {\nnullableOfNullable  \nnullableOfNonNullable  \n}\n";
  module Raw = {
    type t = {
      .
      "nullableOfNullable": Js.Nullable.t(array(Js.Nullable.t(string))),
      "nullableOfNonNullable": Js.Nullable.t(array(string)),
    };
    type nonrec t_Lists = t;
  };
  type t = {
    .
    "nullableOfNullable": option(array(option(string))),
    "nullableOfNonNullable": option(array(string)),
  };
  type nonrec t_Lists = t;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let nullableOfNonNullable = {
      let value = value##nullableOfNonNullable;
      switch (Js.toOption(value)) {
      | Some(value) => Some(value |> Js.Array.map(value => value))
      | None => None
      };
    }
    and nullableOfNullable = {
      let value = value##nullableOfNullable;
      switch (Js.toOption(value)) {
      | Some(value) =>
        Some(
          value
          |> Js.Array.map(value =>
               switch (Js.toOption(value)) {
               | Some(value) => Some(value)
               | None => None
               }
             ),
        )
      | None => None
      };
    };
    {
      "nullableOfNullable": nullableOfNullable,
      "nullableOfNonNullable": nullableOfNonNullable,
    };
  };
  let verifyArgsAndParse = (value: Raw.t) => parse(value);
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let nullableOfNonNullable = {
      let value = value##nullableOfNonNullable;
      switch (value) {
      | Some(value) =>
        Js.Nullable.return(value |> Js.Array.map(value => value))
      | None => Js.Nullable.null
      };
    }
    and nullableOfNullable = {
      let value = value##nullableOfNullable;
      switch (value) {
      | Some(value) =>
        Js.Nullable.return(
          value
          |> Js.Array.map(value =>
               switch (value) {
               | Some(value) => Js.Nullable.return(value)
               | None => Js.Nullable.null
               }
             ),
        )
      | None => Js.Nullable.null
      };
    };
    {
      "nullableOfNullable": nullableOfNullable,
      "nullableOfNonNullable": nullableOfNonNullable,
    };
  };
  let name = "InlineListFragment";
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql;
    /**```
Lists {
  nullableOfNullable: [String]
  nullableOfNonNullable: [String!]
  nonNullableOfNullable: [String]!
  nonNullableOfNonNullable: [String!]!
  listWithArg: [String]
}
```*/
    let graphql: graphql = Obj.magic(0);
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module MyQuery = {
  module Raw = {
    type t_l2;
    type t_l3;
    type t_l4;
    type t = {
      .
      "l1": ListFragment.Raw.t,
      "l2": t_l2,
      "l3": t_l3,
      "l4": t_l4,
      "l5": FragmentWithArgs.Raw.t,
    };
    type t_variables = {. "arg1": Js.Nullable.t(string)};
  };
  /**The GraphQL query string*/
  let query =
    (
      (
        (
          (
            (
              (
                (
                  (
                    (
                      (
                        (
                          (
                            (
                              (
                                (
                                  (
                                    "query MyQuery($arg1: String)  {\nl1: lists  {\n..."
                                    ++ ListFragment.name
                                  )
                                  ++ "   \n}\n\nl2: lists  {\n..."
                                )
                                ++ ListFragment.name
                              )
                              ++ "   \n..."
                            )
                            ++ ListFragment.name
                          )
                          ++ "   \n}\n\nl3: lists  {\nnullableOfNullable  \n..."
                        )
                        ++ ListFragment.name
                      )
                      ++ "   \n..."
                    )
                    ++ ListFragment.name
                  )
                  ++ "   \n}\n\nl4: lists  {\nnullableOfNullable  \n..."
                )
                ++ InlineFragment.name
              )
              ++ "   \n}\n\nl5: lists  {\n..."
            )
            ++ FragmentWithArgs.name
          )
          ++ "   \n}\n\n}\n"
        )
        ++ FragmentWithArgs.query
      )
      ++ InlineFragment.query
    )
    ++ ListFragment.query;
  type t_l2 = {
    .
    "frag1": ListFragment.t_Lists,
    "frag2": ListFragment.t_Lists,
  };
  type t_l3 = {
    .
    "nullableOfNullable": option(array(option(string))),
    "frag1": ListFragment.t_Lists,
    "frag2": ListFragment.t_Lists,
  };
  type t_l4 = {
    .
    "nullableOfNullable": option(array(option(string))),
    "inlineFragment": InlineFragment.t_Lists,
  };
  type t = {
    .
    "l1": ListFragment.t,
    "l2": t_l2,
    "l3": t_l3,
    "l4": t_l4,
    "l5": FragmentWithArgs.t,
  };
  type t_variables = {. "arg1": option(string)};
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let l5 = {
      let value = value##l5;
      FragmentWithArgs.verifyArgsAndParse(~arg1=`String, value);
    }
    and l4 = {
      let value = value##l4;
      let inlineFragment = {
        let value: InlineFragment.Raw.t = Obj.magic(value);
        InlineFragment.verifyArgsAndParse(value);
      }
      and nullableOfNullable = {
        let value =
          Obj.magic(
            Js.Dict.unsafeGet(Obj.magic(value), "nullableOfNullable"),
          );
        switch (Js.toOption(value)) {
        | Some(value) =>
          Some(
            value
            |> Js.Array.map(value =>
                 switch (Js.toOption(value)) {
                 | Some(value) => Some(value)
                 | None => None
                 }
               ),
          )
        | None => None
        };
      };
      {
        "nullableOfNullable": nullableOfNullable,
        "inlineFragment": inlineFragment,
      };
    }
    and l3 = {
      let value = value##l3;
      let frag2 = {
        let value: ListFragment.Raw.t = Obj.magic(value);
        ListFragment.verifyArgsAndParse(value);
      }
      and frag1 = {
        let value: ListFragment.Raw.t = Obj.magic(value);
        ListFragment.verifyArgsAndParse(value);
      }
      and nullableOfNullable = {
        let value =
          Obj.magic(
            Js.Dict.unsafeGet(Obj.magic(value), "nullableOfNullable"),
          );
        switch (Js.toOption(value)) {
        | Some(value) =>
          Some(
            value
            |> Js.Array.map(value =>
                 switch (Js.toOption(value)) {
                 | Some(value) => Some(value)
                 | None => None
                 }
               ),
          )
        | None => None
        };
      };
      {
        "nullableOfNullable": nullableOfNullable,
        "frag1": frag1,
        "frag2": frag2,
      };
    }
    and l2 = {
      let value = value##l2;
      let frag2 = {
        let value: ListFragment.Raw.t = Obj.magic(value);
        ListFragment.verifyArgsAndParse(value);
      }
      and frag1 = {
        let value: ListFragment.Raw.t = Obj.magic(value);
        ListFragment.verifyArgsAndParse(value);
      };
      {"frag1": frag1, "frag2": frag2};
    }
    and l1 = {
      let value = value##l1;
      ListFragment.verifyArgsAndParse(value);
    };
    {"l1": l1, "l2": l2, "l3": l3, "l4": l4, "l5": l5};
  };
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let l5 = {
      let value = value##l5;
      FragmentWithArgs.serialize(value);
    }
    and l4 = {
      let value = value##l4;
      (
        Obj.magic(
          Js.Array.reduce(
            GraphQL_PPX.deepMerge,
            Obj.magic(
              {
                let nullableOfNullable = {
                  let value = value##nullableOfNullable;
                  switch (value) {
                  | Some(value) =>
                    Js.Nullable.return(
                      value
                      |> Js.Array.map(value =>
                           switch (value) {
                           | Some(value) => Js.Nullable.return(value)
                           | None => Js.Nullable.null
                           }
                         ),
                    )
                  | None => Js.Nullable.null
                  };
                };
                {"nullableOfNullable": nullableOfNullable};
              },
            ): Js.Json.t,
            [|
              (
                Obj.magic(InlineFragment.serialize(value##inlineFragment)): Js.Json.t
              ),
            |],
          ),
        ): Raw.t_l4
      );
    }
    and l3 = {
      let value = value##l3;
      (
        Obj.magic(
          Js.Array.reduce(
            GraphQL_PPX.deepMerge,
            Obj.magic(
              {
                let nullableOfNullable = {
                  let value = value##nullableOfNullable;
                  switch (value) {
                  | Some(value) =>
                    Js.Nullable.return(
                      value
                      |> Js.Array.map(value =>
                           switch (value) {
                           | Some(value) => Js.Nullable.return(value)
                           | None => Js.Nullable.null
                           }
                         ),
                    )
                  | None => Js.Nullable.null
                  };
                };
                {"nullableOfNullable": nullableOfNullable};
              },
            ): Js.Json.t,
            [|
              (Obj.magic(ListFragment.serialize(value##frag1)): Js.Json.t),
              (Obj.magic(ListFragment.serialize(value##frag2)): Js.Json.t),
            |],
          ),
        ): Raw.t_l3
      );
    }
    and l2 = {
      let value = value##l2;
      (
        Obj.magic(
          Js.Array.reduce(
            GraphQL_PPX.deepMerge,
            Obj.magic(Js.Dict.empty): Js.Json.t,
            [|
              (Obj.magic(ListFragment.serialize(value##frag1)): Js.Json.t),
              (Obj.magic(ListFragment.serialize(value##frag2)): Js.Json.t),
            |],
          ),
        ): Raw.t_l2
      );
    }
    and l1 = {
      let value = value##l1;
      ListFragment.serialize(value);
    };
    {"l1": l1, "l2": l2, "l3": l3, "l4": l4, "l5": l5};
  };
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {
      "arg1":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          inp##arg1,
        ),
    };
  let makeVariables = (~arg1=?, ()) =>
    serializeVariables({"arg1": arg1}: t_variables);
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module GraphQL {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module MyQuery2 = {
  module Raw = {
    type t = {. "lists": ListFragment.Raw.t};
    type t_variables = unit;
  };
  /**The GraphQL query string*/
  let query =
    (("query   {\nlists  {\n..." ++ ListFragment.name) ++ "   \n}\n\n}\n")
    ++ ListFragment.query;
  type t = {. "lists": ListFragment.t};
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let lists = {
      let value = value##lists;
      ListFragment.verifyArgsAndParse(value);
    };
    {"lists": lists};
  };
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let lists = {
      let value = value##lists;
      ListFragment.serialize(value);
    };
    {"lists": lists};
  };
  let serializeVariables = () => ();
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  external variablesToJson: Raw.t_variables => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- graphql-ppx module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery2 {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
