{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: 

    let 
      pkgs = nixpkgs.legacyPackages.x86_64-linux;
    in {
      devShells.x86_64-linux.default = pkgs.mkShell {
        nativeBuildInputs = with pkgs ; [
          gcc
          cmake
          valgrind
          gdb
          doxygen
          lcov
          check
        ];

        buildInputs = with pkgs; [

        ];

        shellHook = ''
          export PKG_CONFIG_PATH="${pkgs.check}/lib/pkgconfig:$PKG_CONFIG_PATH"
        '';
      };
    };
}
