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
module MyQuery = {
  module Raw = {
    type t_dogOrHuman_Dog = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type t_dogOrHuman_Human = {
      __typename: string,
      name: string,
    };
    type t_dogOrHuman;
    type t = {dogOrHuman: t_dogOrHuman};
    type t_variables = unit;
  };
  /**The GraphQL query string*/
  let query = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\nname  \nbarkVolume  \n}\n\n...on Human   {\nname  \n}\n\n}\n\n}\n";
  type t_dogOrHuman_Dog = {
    name: string,
    barkVolume: float,
  };
  type t_dogOrHuman_Human = {name: string};
  type t_dogOrHuman = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_dogOrHuman_Dog)
    | `Human(t_dogOrHuman_Human)
  ];
  type t = {dogOrHuman: t_dogOrHuman};
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      dogOrHuman: {
        let value = (value: Raw.t).dogOrHuman;
        let typename: string =
          Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
        (
          switch (typename) {
          | "Dog" =>
            `Dog(
              {
                let value: Raw.t_dogOrHuman_Dog = Obj.magic(value);
                (
                  {
                    name: {
                      let value = (value: Raw.t_dogOrHuman_Dog).name;
                      value;
                    },
                    barkVolume: {
                      let value = (value: Raw.t_dogOrHuman_Dog).barkVolume;
                      value;
                    },
                  }: t_dogOrHuman_Dog
                );
              },
            )
          | "Human" =>
            `Human(
              {
                let value: Raw.t_dogOrHuman_Human = Obj.magic(value);
                (
                  {
                    name: {
                      let value = (value: Raw.t_dogOrHuman_Human).name;
                      value;
                    },
                  }: t_dogOrHuman_Human
                );
              },
            )
          | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
          }: t_dogOrHuman
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let dogOrHuman = {
        let value = (value: t).dogOrHuman;
        switch (value) {
        | `Dog(value) => (
            Obj.magic(
              {
                let barkVolume = {
                  let value = (value: t_dogOrHuman_Dog).barkVolume;
                  value;
                }
                and name = {
                  let value = (value: t_dogOrHuman_Dog).name;
                  value;
                };
                {__typename: "Dog", name, barkVolume};
              }: Raw.t_dogOrHuman_Dog,
            ): Raw.t_dogOrHuman
          )
        | `Human(value) => (
            Obj.magic(
              {
                let name = {
                  let value = (value: t_dogOrHuman_Human).name;
                  value;
                };
                {__typename: "Human", name};
              }: Raw.t_dogOrHuman_Human,
            ): Raw.t_dogOrHuman
          )
        | `FutureAddedValue(value) => (Obj.magic(value): Raw.t_dogOrHuman)
        };
      };
      {dogOrHuman: dogOrHuman};
    }: Raw.t
  );
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
module MyQuery {
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
module MyQueryNoError = {
  module Raw = {
    type t_dogOrHuman_Dog = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type t_dogOrHuman_Human = {
      __typename: string,
      name: string,
    };
    type t_dogOrHuman;
    type t = {dogOrHuman: t_dogOrHuman};
    type t_variables = unit;
  };
  /**The GraphQL query string*/
  let query = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\nname  \nbarkVolume  \n}\n\n...on Human   {\nname  \n}\n\n}\n\n}\n";
  type t_dogOrHuman_Dog = {
    name: string,
    barkVolume: float,
  };
  type t_dogOrHuman_Human = {name: string};
  type t_dogOrHuman = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_dogOrHuman_Dog)
    | `Human(t_dogOrHuman_Human)
  ];
  type t = {dogOrHuman: t_dogOrHuman};
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      dogOrHuman: {
        let value = (value: Raw.t).dogOrHuman;
        let typename: string =
          Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
        (
          switch (typename) {
          | "Dog" =>
            `Dog(
              {
                let value: Raw.t_dogOrHuman_Dog = Obj.magic(value);
                (
                  {
                    name: {
                      let value = (value: Raw.t_dogOrHuman_Dog).name;
                      value;
                    },
                    barkVolume: {
                      let value = (value: Raw.t_dogOrHuman_Dog).barkVolume;
                      value;
                    },
                  }: t_dogOrHuman_Dog
                );
              },
            )
          | "Human" =>
            `Human(
              {
                let value: Raw.t_dogOrHuman_Human = Obj.magic(value);
                (
                  {
                    name: {
                      let value = (value: Raw.t_dogOrHuman_Human).name;
                      value;
                    },
                  }: t_dogOrHuman_Human
                );
              },
            )
          | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
          }: t_dogOrHuman
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let dogOrHuman = {
        let value = (value: t).dogOrHuman;
        switch (value) {
        | `Dog(value) => (
            Obj.magic(
              {
                let barkVolume = {
                  let value = (value: t_dogOrHuman_Dog).barkVolume;
                  value;
                }
                and name = {
                  let value = (value: t_dogOrHuman_Dog).name;
                  value;
                };
                {__typename: "Dog", name, barkVolume};
              }: Raw.t_dogOrHuman_Dog,
            ): Raw.t_dogOrHuman
          )
        | `Human(value) => (
            Obj.magic(
              {
                let name = {
                  let value = (value: t_dogOrHuman_Human).name;
                  value;
                };
                {__typename: "Human", name};
              }: Raw.t_dogOrHuman_Human,
            ): Raw.t_dogOrHuman
          )
        | `FutureAddedValue(value) => (Obj.magic(value): Raw.t_dogOrHuman)
        };
      };
      {dogOrHuman: dogOrHuman};
    }: Raw.t
  );
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
module MyQueryNoError {
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
