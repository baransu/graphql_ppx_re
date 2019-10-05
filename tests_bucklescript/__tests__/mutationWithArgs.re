open Jest;
open Expect;

module MyQuery = [%graphql {|
  mutation {
    optionalInputArgs
  }
|}];

describe("Mutation with args", () =>
  test("Printed query is a mutation", () =>
    MyQuery.query |> Js.String.indexOf("mutation") |> expect |> toBe(0)
  )
);