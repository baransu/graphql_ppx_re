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
type scalars = {
  string,
  int,
};

type dog = {
  name: string,
  barkVolume: float,
};

type oneFieldQuery = {nullableString: option(string)};

module MyQuery = {
  module Raw = {
    type t = {variousScalars: scalars};
  };
  let query = "query   {\n__typename\nvariousScalars  {\n__typename\nstring  \nint  \n}\n\n}\n";
  type t = {variousScalars: scalars};
  let parse: Raw.t => t =
    (value) => (
      {

        variousScalars: {
          let value = (value: Raw.t).variousScalars;
          (
            {

              string: {
                let value = (value: Raw.t_variousScalars).string;

                value;
              },

              int: {
                let value = (value: Raw.t_variousScalars).int;

                value;
              },
            }: scalars
          );
        },
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let variousScalars = {
          let value = (value: t).variousScalars;
          (
            {
              let int = {
                let value = (value: scalars).int;

                value;
              }
              and string = {
                let value = (value: scalars).string;

                value;
              };
              {

                string,

                int,
              };
            }: Raw.t_variousScalars
          );
        };
        {

          variousScalars: variousScalars,
        };
      }: Raw.t
    );
  let makeVar = (~f, ()) => f(Js.Json.null);
  let definition = (parse, query, makeVar);
};

module OneFieldQuery = {
  module Raw = {
    type t = {variousScalars: t_variousScalars}
    and t_variousScalars = {nullableString: Js.Nullable.t(string)};
  };
  let query = "query   {\n__typename\nvariousScalars  {\n__typename\nnullableString  \n}\n\n}\n";
  type t = {variousScalars: t_variousScalars}
  and t_variousScalars = {nullableString: option(string)};
  let parse: Raw.t => t =
    (value) => (
      {

        variousScalars: {
          let value = (value: Raw.t).variousScalars;
          (
            {

              nullableString: {
                let value = (value: Raw.t_variousScalars).nullableString;

                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              },
            }: t_variousScalars
          );
        },
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let variousScalars = {
          let value = (value: t).variousScalars;
          (
            {
              let nullableString = {
                let value = (value: t_variousScalars).nullableString;

                switch (value) {
                | Some(value) => Js.Nullable.return(value)
                | None => Js.Nullable.null
                };
              };
              {

                nullableString: nullableString,
              };
            }: Raw.t_variousScalars
          );
        };
        {

          variousScalars: variousScalars,
        };
      }: Raw.t
    );
  let makeVar = (~f, ()) => f(Js.Json.null);
  let definition = (parse, query, makeVar);
};

module ExternalFragmentQuery = {
  module Fragment = {
    let query = "fragment Fragment on VariousScalars   {\n__typename\nstring  \nint  \n}\n";
    module Raw = {
      type t = {
        string,
        int,
      };
      type t_VariousScalars = t;
    };
    type t = {
      string,
      int,
    };
    type t_VariousScalars = t;

    let parse = (value: Raw.t): t => {

      string: {
        let value = (value: Raw.t).string;

        value;
      },

      int: {
        let value = (value: Raw.t).int;

        value;
      },
    };
    let serialize: t => Raw.t =
      (value) => (
        {
          let int = {
            let value = (value: t).int;

            value;
          }
          and string = {
            let value = (value: t).string;

            value;
          };
          {

            string,

            int,
          };
        }: Raw.t
      );
    let name = "Fragment";
  };
  module Untitled1 = {
    module Raw = {
      type t = {variousScalars: Fragment.Raw.t};
    };
    let query =
      (
        (
          "query   {\n__typename\nvariousScalars  {\n__typename\n..."
          ++ Fragment.name
        )
        ++ "   \n}\n\n}\n"
      )
      ++ Fragment.query;
    type t = {variousScalars: Fragment.t};
    let parse: Raw.t => t =
      (value) => (
        {

          variousScalars: {
            let value = (value: Raw.t).variousScalars;

            Fragment.parse(value);
          },
        }: t
      );
    let serialize: t => Raw.t =
      (value) => (
        {
          let variousScalars = {
            let value = (value: t).variousScalars;
            Fragment.serialize(value);
          };
          {

            variousScalars: variousScalars,
          };
        }: Raw.t
      );
    let makeVar = (~f, ()) => f(Js.Json.null);
    let definition = (parse, query, makeVar);
  };
};

module InlineFragmentQuery = {
  module Raw = {
    type t = {dogOrHuman: t_dogOrHuman}
    and t_dogOrHuman
    and t_dogOrHuman_Dog = {
      name: string,
      barkVolume: float,
    };
  };
  let query = "query   {\n__typename\ndogOrHuman  {\n__typename\n...on Dog   {\n__typename\nname  \nbarkVolume  \n}\n\n}\n\n}\n";
  type t = {dogOrHuman: t_dogOrHuman}
  and t_dogOrHuman = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_dogOrHuman_Dog)
  ]
  and t_dogOrHuman_Dog = {
    name: string,
    barkVolume: float,
  };
  let parse: Raw.t => t =
    (value) => (
      {

        dogOrHuman: {
          let value = (value: Raw.t).dogOrHuman;
          [@metaloc loc]
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
            | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
            }: t_dogOrHuman
          );
        },
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
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
                  {

                    name,

                    barkVolume,
                  };
                }: Raw.t_dogOrHuman_Dog,
              ): Raw.t_dogOrHuman
            )
          | `FutureAddedValue(value) => (Obj.magic(value): Raw.t_dogOrHuman)
          };
        };
        {

          dogOrHuman: dogOrHuman,
        };
      }: Raw.t
    );
  let makeVar = (~f, ()) => f(Js.Json.null);
  let definition = (parse, query, makeVar);
};

module UnionExternalFragmentQuery = {
  module DogFragment = {
    let query = "fragment DogFragment on Dog   {\n__typename\nname  \nbarkVolume  \n}\n";
    module Raw = {
      type t = {
        name: string,
        barkVolume: float,
      };
      type t_Dog = t;
    };
    type t = {
      name: string,
      barkVolume: float,
    };
    type t_Dog = t;

    let parse = (value: Raw.t): t => {

      name: {
        let value = (value: Raw.t).name;

        value;
      },

      barkVolume: {
        let value = (value: Raw.t).barkVolume;

        value;
      },
    };
    let serialize: t => Raw.t =
      (value) => (
        {
          let barkVolume = {
            let value = (value: t).barkVolume;

            value;
          }
          and name = {
            let value = (value: t).name;

            value;
          };
          {

            name,

            barkVolume,
          };
        }: Raw.t
      );
    let name = "DogFragment";
  };
  module Untitled1 = {
    module Raw = {
      type t = {dogOrHuman: t_dogOrHuman}
      and t_dogOrHuman;
    };
    let query =
      (
        (
          "query   {\n__typename\ndogOrHuman  {\n__typename\n...on Dog   {\n__typename\n..."
          ++ DogFragment.name
        )
        ++ "   \n}\n\n}\n\n}\n"
      )
      ++ DogFragment.query;
    type t = {dogOrHuman: t_dogOrHuman}
    and t_dogOrHuman = [
      | `FutureAddedValue(Js.Json.t)
      | `Dog(DogFragment.t)
    ];
    let parse: Raw.t => t =
      (value) => (
        {

          dogOrHuman: {
            let value = (value: Raw.t).dogOrHuman;
            [@metaloc loc]
            let typename: string =
              Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
            (
              switch (typename) {
              | "Dog" =>
                `Dog(
                  {
                    let value: Raw.t_dogOrHuman_Dog = Obj.magic(value);

                    DogFragment.parse(value);
                  },
                )
              | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
              }: t_dogOrHuman
            );
          },
        }: t
      );
    let serialize: t => Raw.t =
      (value) => (
        {
          let dogOrHuman = {
            let value = (value: t).dogOrHuman;
            switch (value) {
            | `Dog(value) => (
                Obj.magic(DogFragment.serialize(value)): Raw.t_dogOrHuman
              )
            | `FutureAddedValue(value) => (
                Obj.magic(value): Raw.t_dogOrHuman
              )
            };
          };
          {

            dogOrHuman: dogOrHuman,
          };
        }: Raw.t
      );
    let makeVar = (~f, ()) => f(Js.Json.null);
    let definition = (parse, query, makeVar);
  };
};