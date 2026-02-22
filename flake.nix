{
  description = "RISC-V bare-metal dev shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {
      inherit system;
      config = {
        allowUnsupportedSystem = true;
      };
    };
  in {
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        pkgsCross.riscv64-embedded.stdenv.cc
      ];

      shellHook = ''
        echo "RISC-V bare-metal dev shell ready"
        echo "Path :" ; which riscv64-none-elf-gcc || true
      '';
    };
  };
}
