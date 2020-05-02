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
type record = {
  f1: string,
  f2: string,
};

module MyQuery = {
  module Raw = {
    type t_first_inner_inner = {field: string};
    type t_first_inner = {inner: Js.Nullable.t(t_first_inner_inner)};
    type t_first = {inner: Js.Nullable.t(t_first_inner)};
    type t_second_inner_inner = {
      f1: string,
      f2: string,
    };
    type t_second_inner = {inner: Js.Nullable.t(t_second_inner_inner)};
    type t_second = {inner: Js.Nullable.t(t_second_inner)};
    type t_let_inner_inner = {field: string};
    type t_let_inner = {inner: Js.Nullable.t(t_let_inner_inner)};
    type t_let = {inner: Js.Nullable.t(t_let_inner)};
    type t = {
      first: t_first,
      second: t_second,
      let_: t_let,
    };
  };
  let query = "query   {\nfirst: nestedObject  {\ninner  {\ninner  {\nfield  \n}\n\n}\n\n}\n\nsecond: nestedObject  {\ninner  {\ninner  {\nf1: field  \nf2: field  \n}\n\n}\n\n}\n\nlet: nestedObject  {\ninner  {\ninner  {\nfield  \n}\n\n}\n\n}\n\n}\n";
  type t_first_inner_inner = {field: string};
  type t_first_inner = {inner: option(t_first_inner_inner)};
  type t_first = {inner: option(t_first_inner)};
  type t_second_inner_inner = {
    f1: string,
    f2: string,
  };
  type t_second_inner = {inner: option(t_second_inner_inner)};
  type t_second = {inner: option(t_second_inner)};
  type t_let_inner_inner = {field: string};
  type t_let_inner = {inner: option(t_let_inner_inner)};
  type t_let = {inner: option(t_let_inner)};
  type t = {
    first: t_first,
    second: t_second,
    let_: t_let,
  };
  let parse: Raw.t => t =
    (value) => (
      {
        let let_ = {
          let value = (value: Raw.t).let_;
          (
            {
              let inner = {
                let value = (value: Raw.t_let).inner;
                switch (Js.toOption(value)) {
                | Some(value) =>
                  Some(
                    {
                      let inner = {
                        let value = (value: Raw.t_let_inner).inner;
                        switch (Js.toOption(value)) {
                        | Some(value) =>
                          Some(
                            {
                              let field = {
                                let value =
                                  (value: Raw.t_let_inner_inner).field;
                                value;
                              };
                              {

                                field: field,
                              };
                            }: t_let_inner_inner,
                          )
                        | None => None
                        };
                      };
                      {

                        inner: inner,
                      };
                    }: t_let_inner,
                  )
                | None => None
                };
              };
              {

                inner: inner,
              };
            }: t_let
          );
        }
        and second = {
          let value = (value: Raw.t).second;
          (
            {
              let inner = {
                let value = (value: Raw.t_second).inner;
                switch (Js.toOption(value)) {
                | Some(value) =>
                  Some(
                    {
                      let inner = {
                        let value = (value: Raw.t_second_inner).inner;
                        switch (Js.toOption(value)) {
                        | Some(value) =>
                          Some(
                            {
                              let f2 = {
                                let value =
                                  (value: Raw.t_second_inner_inner).f2;
                                value;
                              }
                              and f1 = {
                                let value =
                                  (value: Raw.t_second_inner_inner).f1;
                                value;
                              };
                              {

                                f1,

                                f2,
                              };
                            }: t_second_inner_inner,
                          )
                        | None => None
                        };
                      };
                      {

                        inner: inner,
                      };
                    }: t_second_inner,
                  )
                | None => None
                };
              };
              {

                inner: inner,
              };
            }: t_second
          );
        }
        and first = {
          let value = (value: Raw.t).first;
          (
            {
              let inner = {
                let value = (value: Raw.t_first).inner;
                switch (Js.toOption(value)) {
                | Some(value) =>
                  Some(
                    {
                      let inner = {
                        let value = (value: Raw.t_first_inner).inner;
                        switch (Js.toOption(value)) {
                        | Some(value) =>
                          Some(
                            {
                              let field = {
                                let value =
                                  (value: Raw.t_first_inner_inner).field;
                                value;
                              };
                              {

                                field: field,
                              };
                            }: t_first_inner_inner,
                          )
                        | None => None
                        };
                      };
                      {

                        inner: inner,
                      };
                    }: t_first_inner,
                  )
                | None => None
                };
              };
              {

                inner: inner,
              };
            }: t_first
          );
        };
        {

          first,

          second,

          let_,
        };
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let let_ = {
          let value = (value: t).let_;
          (
            {
              let inner = {
                let value = (value: t_let).inner;

                switch (value) {
                | Some(value) =>
                  Js.Nullable.return(
                    {
                      let inner = {
                        let value = (value: t_let_inner).inner;

                        switch (value) {
                        | Some(value) =>
                          Js.Nullable.return(
                            {
                              let field = {
                                let value = (value: t_let_inner_inner).field;

                                value;
                              };
                              {

                                field: field,
                              };
                            }: Raw.t_let_inner_inner,
                          )
                        | None => Js.Nullable.null
                        };
                      };
                      {

                        inner: inner,
                      };
                    }: Raw.t_let_inner,
                  )
                | None => Js.Nullable.null
                };
              };
              {

                inner: inner,
              };
            }: Raw.t_let
          );
        }
        and second = {
          let value = (value: t).second;
          (
            {
              let inner = {
                let value = (value: t_second).inner;

                switch (value) {
                | Some(value) =>
                  Js.Nullable.return(
                    {
                      let inner = {
                        let value = (value: t_second_inner).inner;

                        switch (value) {
                        | Some(value) =>
                          Js.Nullable.return(
                            {
                              let f2 = {
                                let value = (value: t_second_inner_inner).f2;

                                value;
                              }
                              and f1 = {
                                let value = (value: t_second_inner_inner).f1;

                                value;
                              };
                              {

                                f1,

                                f2,
                              };
                            }: Raw.t_second_inner_inner,
                          )
                        | None => Js.Nullable.null
                        };
                      };
                      {

                        inner: inner,
                      };
                    }: Raw.t_second_inner,
                  )
                | None => Js.Nullable.null
                };
              };
              {

                inner: inner,
              };
            }: Raw.t_second
          );
        }
        and first = {
          let value = (value: t).first;
          (
            {
              let inner = {
                let value = (value: t_first).inner;

                switch (value) {
                | Some(value) =>
                  Js.Nullable.return(
                    {
                      let inner = {
                        let value = (value: t_first_inner).inner;

                        switch (value) {
                        | Some(value) =>
                          Js.Nullable.return(
                            {
                              let field = {
                                let value = (value: t_first_inner_inner).field;

                                value;
                              };
                              {

                                field: field,
                              };
                            }: Raw.t_first_inner_inner,
                          )
                        | None => Js.Nullable.null
                        };
                      };
                      {

                        inner: inner,
                      };
                    }: Raw.t_first_inner,
                  )
                | None => Js.Nullable.null
                };
              };
              {

                inner: inner,
              };
            }: Raw.t_first
          );
        };
        {

          first,

          second,

          let_,
        };
      }: Raw.t
    );
  let definition = (parse, query, serialize);
};
