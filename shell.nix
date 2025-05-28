{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  name = "mpv-dev";
  nativeBuildInputs = [
    pkgs.pkg-config
  ];
  buildInputs = with pkgs; [
    mpv-unwrapped
  ];

  shellHook = ''
    export CPATH="${pkgs.mpv-unwrapped.dev}/include:$CPATH"
  '';
}
