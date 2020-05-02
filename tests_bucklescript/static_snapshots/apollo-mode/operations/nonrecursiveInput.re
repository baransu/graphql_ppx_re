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
    type t = {nonrecursiveInput: string};
    type t_variables = {arg: t_variables_NonrecursiveInput}
    and t_variables_NonrecursiveInput = {
      nonNullableField: string,
      nullableArray: Js.Nullable.t(array(Js.Nullable.t(string))),
      field: Js.Nullable.t(string),
      enum: Js.Nullable.t(string),
      embeddedInput:
        Js.Nullable.t(array(Js.Nullable.t(t_variables_EmbeddedInput))),
    }
    and t_variables_EmbeddedInput = {field: Js.Nullable.t(string)};
  };
  let query = "query ($arg: NonrecursiveInput!)  {\nnonrecursiveInput(arg: $arg)  \n}\n";
  type t = {nonrecursiveInput: string};
  type t_variables = {arg: t_variables_NonrecursiveInput}
  and t_variables_NonrecursiveInput = {
    nonNullableField: string,
    nullableArray: option(array(option(string))),
    field: option(string),
    enum: option([ | `FIRST | `SECOND | `THIRD]),
    embeddedInput: option(array(option(t_variables_EmbeddedInput))),
  }
  and t_variables_EmbeddedInput = {field: option(string)};
  let parse: Raw.t => t =
    (value) => (
      {
        let nonrecursiveInput = {
          let value = (value: Raw.t).nonrecursiveInput;
          value;
        };
        {

          nonrecursiveInput: nonrecursiveInput,
        };
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let nonrecursiveInput = {
          let value = (value: t).nonrecursiveInput;

          value;
        };
        {

          nonrecursiveInput: nonrecursiveInput,
        };
      }: Raw.t
    );

  let rec serializeVariables: t_variables => Raw.t_variables =
    inp => {

      arg:
        (a => serializeInputObjectNonrecursiveInput(a))(
          (inp: t_variables).arg,
        ),
    }

  and serializeInputObjectNonrecursiveInput:
    t_variables_NonrecursiveInput => Raw.t_variables_NonrecursiveInput =
    inp => {

      nonNullableField:
        (a => a)((inp: t_variables_NonrecursiveInput).nonNullableField),

      nullableArray:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    Array.map(
                      b =>
                        (
                          a =>
                            switch (a) {
                            | None => Js.Nullable.undefined
                            | Some(b) => Js.Nullable.return((a => a)(b))
                            }
                        )(
                          b,
                        ),
                      a,
                    )
                )(
                  b,
                ),
              )
            }
        )(
          (inp: t_variables_NonrecursiveInput).nullableArray,
        ),

      field:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          (inp: t_variables_NonrecursiveInput).field,
        ),

      enum:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    switch (a) {
                    | `FIRST => "FIRST"
                    | `SECOND => "SECOND"
                    | `THIRD => "THIRD"
                    }
                )(
                  b,
                ),
              )
            }
        )(
          (inp: t_variables_NonrecursiveInput).enum,
        ),

      embeddedInput:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    Array.map(
                      b =>
                        (
                          a =>
                            switch (a) {
                            | None => Js.Nullable.undefined
                            | Some(b) =>
                              Js.Nullable.return(
                                (a => serializeInputObjectEmbeddedInput(a))(
                                  b,
                                ),
                              )
                            }
                        )(
                          b,
                        ),
                      a,
                    )
                )(
                  b,
                ),
              )
            }
        )(
          (inp: t_variables_NonrecursiveInput).embeddedInput,
        ),
    }

  and serializeInputObjectEmbeddedInput:
    t_variables_EmbeddedInput => Raw.t_variables_EmbeddedInput =
    inp => {

      field:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          (inp: t_variables_EmbeddedInput).field,
        ),
    };
  let makeVariables = (~arg, ()) =>
    serializeVariables(
      {

        arg: arg,
      }: t_variables,
    )
  and makeInputObjectNonrecursiveInput =
      (
        ~nonNullableField,
        ~nullableArray=?,
        ~field=?,
        ~enum=?,
        ~embeddedInput=?,
        (),
      )
      : t_variables_NonrecursiveInput => {

    nonNullableField,

    nullableArray,

    field,

    enum,

    embeddedInput,
  }
  and makeInputObjectEmbeddedInput = (~field=?, ()): t_variables_EmbeddedInput => {

    field: field,
  };
  let definition = (parse, query, serialize);
};

module MyQuery2 = {
  module Raw = {
    type t = {
      scalarsInput: string,
      more: string,
    };
    type t_variables = {
      arg: t_variables_NonrecursiveInput,
      arg2: t_variables_NonrecursiveInput,
    }
    and t_variables_NonrecursiveInput = {
      nonNullableField: string,
      nullableArray: Js.Nullable.t(array(Js.Nullable.t(string))),
      field: Js.Nullable.t(string),
      enum: Js.Nullable.t(string),
      embeddedInput:
        Js.Nullable.t(array(Js.Nullable.t(t_variables_EmbeddedInput))),
    }
    and t_variables_EmbeddedInput = {field: Js.Nullable.t(string)};
  };
  let query = "query ($arg: NonrecursiveInput!, $arg2: NonrecursiveInput!)  {\nscalarsInput(arg: $arg)  \nmore: scalarsInput(arg: $arg2)  \n}\n";
  type t = {
    scalarsInput: string,
    more: string,
  };
  type t_variables = {
    arg: t_variables_NonrecursiveInput,
    arg2: t_variables_NonrecursiveInput,
  }
  and t_variables_NonrecursiveInput = {
    nonNullableField: string,
    nullableArray: option(array(option(string))),
    field: option(string),
    enum: option([ | `FIRST | `SECOND | `THIRD]),
    embeddedInput: option(array(option(t_variables_EmbeddedInput))),
  }
  and t_variables_EmbeddedInput = {field: option(string)};
  let parse: Raw.t => t =
    (value) => (
      {
        let more = {
          let value = (value: Raw.t).more;
          value;
        }
        and scalarsInput = {
          let value = (value: Raw.t).scalarsInput;
          value;
        };
        {

          scalarsInput,

          more,
        };
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let more = {
          let value = (value: t).more;

          value;
        }
        and scalarsInput = {
          let value = (value: t).scalarsInput;

          value;
        };
        {

          scalarsInput,

          more,
        };
      }: Raw.t
    );

  let rec serializeVariables: t_variables => Raw.t_variables =
    inp => {

      arg:
        (a => serializeInputObjectNonrecursiveInput(a))(
          (inp: t_variables).arg,
        ),

      arg2:
        (a => serializeInputObjectNonrecursiveInput(a))(
          (inp: t_variables).arg2,
        ),
    }

  and serializeInputObjectNonrecursiveInput:
    t_variables_NonrecursiveInput => Raw.t_variables_NonrecursiveInput =
    inp => {

      nonNullableField:
        (a => a)((inp: t_variables_NonrecursiveInput).nonNullableField),

      nullableArray:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    Array.map(
                      b =>
                        (
                          a =>
                            switch (a) {
                            | None => Js.Nullable.undefined
                            | Some(b) => Js.Nullable.return((a => a)(b))
                            }
                        )(
                          b,
                        ),
                      a,
                    )
                )(
                  b,
                ),
              )
            }
        )(
          (inp: t_variables_NonrecursiveInput).nullableArray,
        ),

      field:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          (inp: t_variables_NonrecursiveInput).field,
        ),

      enum:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    switch (a) {
                    | `FIRST => "FIRST"
                    | `SECOND => "SECOND"
                    | `THIRD => "THIRD"
                    }
                )(
                  b,
                ),
              )
            }
        )(
          (inp: t_variables_NonrecursiveInput).enum,
        ),

      embeddedInput:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    Array.map(
                      b =>
                        (
                          a =>
                            switch (a) {
                            | None => Js.Nullable.undefined
                            | Some(b) =>
                              Js.Nullable.return(
                                (a => serializeInputObjectEmbeddedInput(a))(
                                  b,
                                ),
                              )
                            }
                        )(
                          b,
                        ),
                      a,
                    )
                )(
                  b,
                ),
              )
            }
        )(
          (inp: t_variables_NonrecursiveInput).embeddedInput,
        ),
    }

  and serializeInputObjectEmbeddedInput:
    t_variables_EmbeddedInput => Raw.t_variables_EmbeddedInput =
    inp => {

      field:
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          (inp: t_variables_EmbeddedInput).field,
        ),
    };
  let makeVariables = (~arg, ~arg2, ()) =>
    serializeVariables(
      {

        arg,

        arg2,
      }: t_variables,
    )
  and makeInputObjectNonrecursiveInput =
      (
        ~nonNullableField,
        ~nullableArray=?,
        ~field=?,
        ~enum=?,
        ~embeddedInput=?,
        (),
      )
      : t_variables_NonrecursiveInput => {

    nonNullableField,

    nullableArray,

    field,

    enum,

    embeddedInput,
  }
  and makeInputObjectEmbeddedInput = (~field=?, ()): t_variables_EmbeddedInput => {

    field: field,
  };
  let definition = (parse, query, serialize);
};
