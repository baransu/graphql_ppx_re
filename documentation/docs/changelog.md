---
title: Changelog
---

**Tags:**

- :boom: - Breaking Change
- :rocket: - New Feature
- :bug: - Bug Fix
- :memo: - Documentation
- :house: - Internal
- :nail_care: - Polish

(_Tags are copied from
[babel](https://github.com/babel/babel/blob/master/CHANGELOG.md)_)

## [1.0.2](https://github.com/reasonml-community/graphql_ppx/compare/v1.0.1...v1.0.2) (2021-01-05)

- :rocket: add `templateTagIsFunction` configuration. This will call the
  configured template tag not as a template tag, but as a function. This solves
  use cases where `require` is not allowed (which we need to inject to support
  template tags)
  ([5d92a6b](https://github.com/reasonml-community/graphql_ppx/commit/5d92a6b))

- :rocket: add include syntax for extension points
  ([f5d5187](https://github.com/reasonml-community/graphql_ppx/commit/f5d5187))

You can now do the following to inline the query (as an alternative to the
`@ppxConfig(inline: true)` decorator):

```
include [%graphql {|
...
|}]
```

- :bug: Fix postinstall (it wouldn't trigger when updating the `ppx`)
  ([b5c3318](https://github.com/reasonml-community/graphql_ppx/commit/b5c3318))

- :bug: Only set the type of a query using `templateTagReturnType` if there is a
  template tag defined:
  ([5b2b3d8](https://github.com/reasonml-community/graphql_ppx/commit/5b2b3d8))

## [1.0.1](https://github.com/reasonml-community/graphql_ppx/compare/v1.0.0...v1.0.1) (2020-09-07)

- :bug: remove `@ppxConfig` directive from query output
  ([b697b83](https://github.com/reasonml-community/graphql_ppx/commit/b697b83))

- :bug: do not strengthen module type of extended module to prevent type errors
  like below when the the definition is being extended
  ([546e15f](https://github.com/reasonml-community/graphql_ppx/commit/546e15f))

```
This has type:
  MyQuery.t_variables
But somewhere wanted:
  MyQuery.MyQuery_inner.t_variables
```

## [1.0.0](https://github.com/reasonml-community/graphql_ppx/compare/v0.7.2...v1.0.0) (2020-09-06)

There has been a lot of new features in version 1.0 of `graphql-ppx`. Below some
of the main changes. After 1.0 we are going to record a more detailed changelog.

### Large changes

- :rocket: :boom: New API, no definition, first class modules and clients can
  extend definitions
- :rocket: :boom: Using records instead of objects
- :rocket: Generating types
- :rocket: Serialization

### Other features

- :rocket: Generating a module signature
- :rocket: Support for recursive modules
- :rocket: :boom: Raw types
- :rocket: Leaner parse
- :rocket: :boom: `ppxCustom` instead of `bsDecoder`
- :rocket: `ppxAs`
- :rocket: Better editor support
- :rocket: Better errors
- :rocket: Docstrings
- :rocket: Multiple fragments or operations per extension point
- :rocket: Configuration in `bsconfig.json`
- :rocket: Tagged template literal support
- :rocket: `graphql` extension points in interface files
- :house: Snapshot and compile testing

## [0.7.2](https://github.com/reasonml-community/graphql_ppx/compare/v0.7.2...v0.7.0) (2020-08-10)

- :house: fix issues with running `graphql-ppx` in a high-concurrency
  environment

## [0.7.1](https://github.com/reasonml-community/graphql_ppx/compare/v0.7.0...v0.7.1) (2020-02-25)

- :house: Add opam file
  [(#81)](https://github.com/reasonml-community/graphql-ppx/pull/81)

## [0.7.0](https://github.com/reasonml-community/graphql_ppx/compare/v0.6.4...v0.7.0) (2020-02-24)

- :house: use OMP (ocaml-migrate-parsetree) 1.6.0
  ([f7ded8d](https://github.com/reasonml-community/graphql_ppx/commit/f7ded8d2c44bfb53e7308dbcd1c54fa2d1fff7e4))

## [0.6.2](https://github.com/reasonml-community/graphql_ppx/compare/v0.6.1...v0.6.2) (2020-02-18)

- :rocket: decoder support on fragment definition
  ([77d8c45](https://github.com/reasonml-community/graphql_ppx/commit/77d8c452f4aa482585967dd8a33d6ebb262f6e37))
- :rocket: add unified definition on native
  ([e240bf3](https://github.com/reasonml-community/graphql_ppx/commit/e240bf3e58b4d14d663cf83d5bb51b40022ba49d))
- :nail_care: support OCaml 4.08 on native
  ([c533986](https://github.com/reasonml-community/graphql_ppx/commit/c5339868021aa3235e390fc282e5c9d6927cecf3))
- :nail_care: use internally AST 4.08
  ([6acea38](https://github.com/reasonml-community/graphql_ppx/commit/6acea380923c5a698ae151aee93d7f87bea91915))

## [0.6.1](https://github.com/reasonml-community/graphql_ppx/compare/v0.5.0...v0.6.1) (2020-01-23)

- :rocket: Lean parse available under experimental `-lean-parse` feature flag
  ([6e7224b](https://github.com/reasonml-community/graphql_ppx/commit/6e7224ba9789bc67a68aa9566e295eff70855dd0))
- :house: Update repository to name and organization change
  ([5df9be8](https://github.com/reasonml-community/graphql_ppx/commit/5df9be88ef5bd7be77df551265834cb1bc31a011))

## [0.5.0](https://github.com/reasonml-community/graphql_ppx/compare/v0.4.9...v0.5.0) (2020-01-11)

- :boom: Support configuration via ppx-flags, drop env based one
  ([3ed986e](https://github.com/reasonml-community/graphql_ppx/commit/3ed986e7cf020e751ce93a46896f45c33e52c860))
- :house: Move pipeline to one file, add esy cache
  ([b9517da9](https://github.com/reasonml-community/graphql_ppx/commit/b9517da9d74e8e90b83808b6dfcc520f97fca7ea))

## [0.4.9](https://github.com/reasonml-community/graphql_ppx/compare/v0.4.6...v0.4.9) (2020-01-06)

- :feature: build linux binary on alpine with static linking
  ([9a4f31b](https://github.com/reasonml-community/graphql_ppx/commit/9a4f31b76350bf73e108d31a5d6a75dc9a681238))

## [0.4.1](https://github.com/reasonml-community/graphql_ppx/compare/v0.4.0...v0.4.1) (2019-12-04)

- :bug: one field query with bs record
  ([e231d19](https://github.com/reasonml-community/graphql_ppx/commit/e231d1970b69f175400a324e2542a4748588b34b))
- :house: bucklescript test suite upgrade and how to run tests documentation
  improved
  ([19db453](https://github.com/reasonml-community/graphql_ppx/commit/19db453aef42f354f2e8f5cd532002ebfa66c22c))
- :rocket: Multiple schemas support
  ([467d557](https://github.com/reasonml-community/graphql_ppx/commit/467d55799771825b3fcdd3ccd4098c3a021328e9))

## [0.4.0](https://github.com/reasonml-community/graphql_ppx/compare/v0.3.5...v0.4.0) (2019-11-25)

- :rocket: Unified definition - (parse, query, combineVariables) tuple to
  improve client side usage
  [8de2419](https://github.com/reasonml-community/graphql_ppx/commit/8de241902cb660c830659ea659f56fce92ad423c)

## [0.3.5](https://github.com/reasonml-community/graphql_ppx/compare/v0.3.3...v0.3.5) (2019-11-23)

- :bug: explicit annotate custom scalar as Yojson.Basic.t for return type magic
  ([1fa67ae](https://github.com/reasonml-community/graphql_ppx/commit/1fa67ae))
- :rocket: add `makeVariables` function
  ([667673c](https://github.com/reasonml-community/graphql_ppx/commit/667673c7c815eb53ea26f7d9d06544439eae0f28))

## [0.3.3](https://github.com/reasonml-community/graphql_ppx/compare/v0.3.2...v0.3.3) (2019-11-23)

- :bug: remove `@bsField` directive from query output
  ([b3b17f3](https://github.com/reasonml-community/graphql_ppx/commit/b3b17f3))
- :bug: bucklescript: polymorphic comparison on Js.Json.t
  ([d1897c2](https://github.com/reasonml-community/graphql_ppx/commit/d1897c2))

## [0.3.2](https://github.com/reasonml-community/graphql_ppx/compare/v0.3.1...v0.3.2) (2019-10-21)

- :bug: improve schema reading (handle case where data is not in json schema)
  ([9324ba2](https://github.com/reasonml-community/graphql_ppx/commit/9324ba232385540b61f485064ee09b1e49929146))

## [0.3.1](https://github.com/reasonml-community/graphql_ppx/compare/0.2.0...v0.3.1) (2019-10-19)

- :bug: **tests:** change how tests are run
  ([8295a7e](https://github.com/reasonml-community/graphql_ppx/commit/8295a7e))
- :rocket: **validation:** no undefined variables rule
  ([5d8772a](https://github.com/reasonml-community/graphql_ppx/commit/5d8772a))
