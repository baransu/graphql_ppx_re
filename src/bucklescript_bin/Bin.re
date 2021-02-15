let argv =
  switch (Sys.argv |> Array.to_list) {
  | [program, ...rest] =>
    switch (List.rev(rest)) {
    | [output_file, input_file, ...args] =>
      List.concat([
        [program],
        List.rev(args),
        [input_file, "-o", output_file, "--dump-ast"],
      ])
      |> Array.of_list
    | _ => Sys.argv
    }
  | _ => Sys.argv
  };

Graphql_ppx_base.Ppx_config.update_config(current =>
  {...current, native: false}
);

let () =
  /* TODO(anmonteiro): args??!*/
  Ppxlib.Driver.standalone();
/* Migrate_parsetree.Driver.run_main(~argv, ()); */
