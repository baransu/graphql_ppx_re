open Jest;
open Expect;

type options = {cwd: string};
type buffer;

[@bs.module "path"] external resolve: (string, string) => string = "resolve";

[@bs.module "child_process"]
external execSync: (string, options) => buffer = "execSync";
[@bs.module "fs"]
external readdirSync: string => array(string) = "readdirSync";
[@bs.module "os"] external platform: unit => string = "platform";

[@bs.val] external dirname: string = "__dirname";
[@bs.send] external toString: buffer => string = "toString";

let win = platform() == "win32";
let refmt =
  execSync(
    "esy build -P wait_pr_to_be_merged echo \"#{@opam/reason.bin / }refmt\"",
    {cwd: resolve(dirname, "../..")},
  )
  |> toString
  |> Js.String.trim;

let replaceSlashWin = str => {
  win ? Js.String.replaceByRe([%re "/\\//g"], "\\", str) : str;
};

let run_ppx = (path, opts) => {
  execSync(
    replaceSlashWin(refmt
      ++ " --parse re --print binary " ++ path ++ " | ../_build/default/src/bucklescript_bin/bin.exe -schema ../graphql_schema.json "
      ++ opts
      ++ (win ? " -o - -" : " /dev/stdin /dev/stdout")
      ++ " | "
      ++ refmt
      ++ " --parse binary --interface false",
    ),
    {cwd: resolve(dirname, "..")},
  )
  |> toString;
};

let tests =
  readdirSync("operations")->Belt.Array.keep(Js.String.endsWith(".re"));

describe("Objects (legacy)", () => {
  tests
  |> Array.iter(t => {
       test(t, () =>
         expect(run_ppx("operations/" ++ t, "")) |> toMatchSnapshot
       )
     })
});

describe("Records", () => {
  tests
  |> Array.iter(t => {
       test(t, () =>
         expect(run_ppx("operations/" ++ t, "-records")) |> toMatchSnapshot
       )
     })
});
