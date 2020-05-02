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
    type t_v1 = {
      __typename: string,
      nullableString: Js.Nullable.t(string),
      string: Js.Nullable.t(string),
    };
    type t_v2 = {
      __typename: string,
      nullableString: Js.Nullable.t(string),
      string: Js.Nullable.t(string),
    };
    type t = {
      v1: t_v1,
      v2: t_v2,
    };
    type t_variables = {var: bool};
  };
  let query = "query ($var: Boolean!)  {\nv1: variousScalars  {\n__typename  \nnullableString @skip(if: $var) \nstring @skip(if: $var) \n}\n\nv2: variousScalars  {\n__typename  \nnullableString @include(if: $var) \nstring @include(if: $var) \n}\n\n}\n";
  type t_v1 = {
    __typename: string,
    nullableString: option(string),
    string: option(string),
  };
  type t_v2 = {
    __typename: string,
    nullableString: option(string),
    string: option(string),
  };
  type t = {
    v1: t_v1,
    v2: t_v2,
  };
  type t_variables = {var: bool};
  let parse: Raw.t => t =
    (value) => (
      {
        let v2 = {
          let value = (value: Raw.t).v2;
          (
            {
              let string = {
                let value = (value: Raw.t_v2).string;
                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              }
              and nullableString = {
                let value = (value: Raw.t_v2).nullableString;
                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              }
              and __typename = {
                let value = (value: Raw.t_v2).__typename;
                value;
              };
              {

                __typename,

                nullableString,

                string,
              };
            }: t_v2
          );
        }
        and v1 = {
          let value = (value: Raw.t).v1;
          (
            {
              let string = {
                let value = (value: Raw.t_v1).string;
                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              }
              and nullableString = {
                let value = (value: Raw.t_v1).nullableString;
                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              }
              and __typename = {
                let value = (value: Raw.t_v1).__typename;
                value;
              };
              {

                __typename,

                nullableString,

                string,
              };
            }: t_v1
          );
        };
        {

          v1,

          v2,
        };
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let v2 = {
          let value = (value: t).v2;
          (
            {
              let string = {
                let value = (value: t_v2).string;

                switch (value) {
                | Some(value) => Js.Nullable.return(value)
                | None => Js.Nullable.null
                };
              }
              and nullableString = {
                let value = (value: t_v2).nullableString;

                switch (value) {
                | Some(value) => Js.Nullable.return(value)
                | None => Js.Nullable.null
                };
              }
              and __typename = {
                let value = (value: t_v2).__typename;

                value;
              };
              {

                __typename,

                nullableString,

                string,
              };
            }: Raw.t_v2
          );
        }
        and v1 = {
          let value = (value: t).v1;
          (
            {
              let string = {
                let value = (value: t_v1).string;

                switch (value) {
                | Some(value) => Js.Nullable.return(value)
                | None => Js.Nullable.null
                };
              }
              and nullableString = {
                let value = (value: t_v1).nullableString;

                switch (value) {
                | Some(value) => Js.Nullable.return(value)
                | None => Js.Nullable.null
                };
              }
              and __typename = {
                let value = (value: t_v1).__typename;

                value;
              };
              {

                __typename,

                nullableString,

                string,
              };
            }: Raw.t_v1
          );
        };
        {

          v1,

          v2,
        };
      }: Raw.t
    );
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {

      var: (a => a)((inp: t_variables).var),
    };
  let makeVariables = (~var, ()) =>
    serializeVariables(
      {

        var: var,
      }: t_variables,
    );
  let definition = (parse, query, serialize);
};
