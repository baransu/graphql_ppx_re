module MyQuery = [%graphql
  {|
  {
    dogOrHuman {
      ...on Dog {
        name
        barkVolume
      }
      ...on Human {
        name
      }
    }
  }
|}
];

module MyQueryNoError = [%graphql
  {|
  {
    dogOrHuman {
      # this is valid graphql and should pass
      __typename
      ...on Dog {
        name
        barkVolume
      }
      ...on Human {
        name
      }
    }
  }
|}
];

type named = {name: string};

module NamedQuery = [%graphql
  {|
  {
    dogOrHuman {
      ...on Dog @ppxAs(type: "named") {
        name
      }
      ...on Human @ppxAs(type: "named") {
        name
      }
    }
  }
|}
];

module NamedSpread = [%graphql
  {|
  {
    fragment DogFields on Dog {
      name
    }

    query dogOrHuman {
      ...on Dog @ppxAs(type: "named") {
        name
      }
    }
  }
|}
];
