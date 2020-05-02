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
    type t_variousScalars = {
      __typename: string,
      string,
      int,
    };
    type t = {variousScalars: t_variousScalars};
  };
  let query = "query   {\nvariousScalars  {\n__typename  \nstring  \nint  \n}\n\n}\n";
  type t = {variousScalars: scalars};
  let parse: Raw.t => t =
    (value) => (
      {
        let variousScalars = {
          let value = (value: Raw.t).variousScalars;
          (
            {
              let int = {
                let value = (value: Raw.t_variousScalars).int;
                value;
              }
              and string = {
                let value = (value: Raw.t_variousScalars).string;
                value;
              }
              and __typename = {
                let value = (value: Raw.t_variousScalars).__typename;
                value;
              };
              {

                __typename,

                string,

                int,
              };
            }: scalars
          );
        };
        {

          variousScalars: variousScalars,
        };
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
              }
              and __typename = {
                let value = (value: scalars).__typename;

                value;
              };
              {

                __typename,

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
  let definition = (parse, query, serialize);
};

module OneFieldQuery = {
  module Raw = {
    type t_variousScalars = {
      __typename: string,
      nullableString: Js.Nullable.t(string),
    };
    type t = {variousScalars: t_variousScalars};
  };
  let query = "query   {\nvariousScalars  {\n__typename  \nnullableString  \n}\n\n}\n";
  type t_variousScalars = {
    __typename: string,
    nullableString: option(string),
  };
  type t = {variousScalars: t_variousScalars};
  let parse: Raw.t => t =
    (value) => (
      {
        let variousScalars = {
          let value = (value: Raw.t).variousScalars;
          (
            {
              let nullableString = {
                let value = (value: Raw.t_variousScalars).nullableString;
                switch (Js.toOption(value)) {
                | Some(value) => Some(value)
                | None => None
                };
              }
              and __typename = {
                let value = (value: Raw.t_variousScalars).__typename;
                value;
              };
              {

                __typename,

                nullableString,
              };
            }: t_variousScalars
          );
        };
        {

          variousScalars: variousScalars,
        };
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
              }
              and __typename = {
                let value = (value: t_variousScalars).__typename;

                value;
              };
              {

                __typename,

                nullableString,
              };
            }: Raw.t_variousScalars
          );
        };
        {

          variousScalars: variousScalars,
        };
      }: Raw.t
    );
  let definition = (parse, query, serialize);
};

module ExternalFragmentQuery = {
  module Fragment = {
    let query = "fragment Fragment on VariousScalars   {\n__typename  \nstring  \nint  \n}\n";
    module Raw = {
      type t = {
        __typename: string,
        string,
        int,
      };
      type nonrec t_VariousScalars = t;
    };
    type t = {
      __typename: string,
      string,
      int,
    };
    type nonrec t_VariousScalars = t;

    let parse = (value: Raw.t): t => {
      let int = {
        let value = (value: Raw.t).int;
        value;
      }
      and string = {
        let value = (value: Raw.t).string;
        value;
      }
      and __typename = {
        let value = (value: Raw.t).__typename;
        value;
      };
      {

        __typename,

        string,

        int,
      };
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
          }
          and __typename = {
            let value = (value: t).__typename;

            value;
          };
          {

            __typename,

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
        ("query   {\nvariousScalars  {\n..." ++ Fragment.name)
        ++ "   \n}\n\n}\n"
      )
      ++ Fragment.query;
    type t = {variousScalars: Fragment.t};
    let parse: Raw.t => t =
      (value) => (
        {
          let variousScalars = {
            let value = (value: Raw.t).variousScalars;
            Fragment.parse(value);
          };
          {

            variousScalars: variousScalars,
          };
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
    let definition = (parse, query, serialize);
  };
};

module InlineFragmentQuery = {
  module Raw = {
    type t_dogOrHuman_Dog = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type t_dogOrHuman;
    type t = {dogOrHuman: t_dogOrHuman};
  };
  let query = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\n__typename  \nname  \nbarkVolume  \n}\n\n}\n\n}\n";
  type t_dogOrHuman_Dog = {
    __typename: string,
    name: string,
    barkVolume: float,
  };
  type t_dogOrHuman = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_dogOrHuman_Dog)
  ];
  type t = {dogOrHuman: t_dogOrHuman};
  let parse: Raw.t => t =
    (value) => (
      {
        let dogOrHuman = {
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
                      let barkVolume = {
                        let value = (value: Raw.t_dogOrHuman_Dog).barkVolume;
                        value;
                      }
                      and name = {
                        let value = (value: Raw.t_dogOrHuman_Dog).name;
                        value;
                      }
                      and __typename = {
                        let value = (value: Raw.t_dogOrHuman_Dog).__typename;
                        value;
                      };
                      {

                        __typename,

                        name,

                        barkVolume,
                      };
                    }: t_dogOrHuman_Dog
                  );
                },
              )
            | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
            }: t_dogOrHuman
          );
        };
        {

          dogOrHuman: dogOrHuman,
        };
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
                  }
                  and __typename = {
                    let value = (value: t_dogOrHuman_Dog).__typename;

                    value;
                  };
                  {

                    __typename: "Dog",

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
  let definition = (parse, query, serialize);
};

module UnionExternalFragmentQuery = {
  module DogFragment = {
    let query = "fragment DogFragment on Dog   {\n__typename  \nname  \nbarkVolume  \n}\n";
    module Raw = {
      type t = {
        __typename: string,
        name: string,
        barkVolume: float,
      };
      type nonrec t_Dog = t;
    };
    type t = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type nonrec t_Dog = t;

    let parse = (value: Raw.t): t => {
      let barkVolume = {
        let value = (value: Raw.t).barkVolume;
        value;
      }
      and name = {
        let value = (value: Raw.t).name;
        value;
      }
      and __typename = {
        let value = (value: Raw.t).__typename;
        value;
      };
      {

        __typename,

        name,

        barkVolume,
      };
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
          }
          and __typename = {
            let value = (value: t).__typename;

            value;
          };
          {

            __typename,

            name,

            barkVolume,
          };
        }: Raw.t
      );
    let name = "DogFragment";
  };
  module Untitled1 = {
    module Raw = {
      type t_dogOrHuman;
      type t = {dogOrHuman: t_dogOrHuman};
    };
    let query =
      (
        (
          "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\n..."
          ++ DogFragment.name
        )
        ++ "   \n}\n\n}\n\n}\n"
      )
      ++ DogFragment.query;
    type t_dogOrHuman = [
      | `FutureAddedValue(Js.Json.t)
      | `Dog(DogFragment.t)
    ];
    type t = {dogOrHuman: t_dogOrHuman};
    let parse: Raw.t => t =
      (value) => (
        {
          let dogOrHuman = {
            let value = (value: Raw.t).dogOrHuman;
            let typename: string =
              Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
            (
              switch (typename) {
              | "Dog" =>
                `Dog(
                  {
                    let value: DogFragment.Raw.t = Obj.magic(value);

                    DogFragment.parse(value);
                  },
                )
              | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
              }: t_dogOrHuman
            );
          };
          {

            dogOrHuman: dogOrHuman,
          };
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
    let definition = (parse, query, serialize);
  };
};
