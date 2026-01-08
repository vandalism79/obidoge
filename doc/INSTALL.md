# Installing ObiDoge

This document describes basic installation steps for running ObiDoge wallets and nodes.

## Linux (Prebuilt Package — Recommended)

1. Download the Linux package from the official GitHub Releases page.
2. Extract the archive:
3. Copy `obidoge.conf.example` to `obidoge.conf` and adjust settings as needed.
4. Start the daemon:
5. The daemon exposes standard JSON-RPC once running.

This package includes:
- Daemon (`obidoged`)
- CLI (`obidoge-cli`, `obidoge-tx`)
- Qt wallet

## Windows (Qt Wallet)

1. Download the Windows Qt Wallet ZIP from GitHub Releases.
2. Extract the archive.
3. Run the Qt wallet executable.
4. The wallet will create its data directory automatically on first launch.

## Building from Source (Advanced)

Building from source is intended for developers and advanced users.

- ObiDoge is based on the Bitcoin Core 0.16 codebase.
- Berkeley DB **4.8** is required for wallet functionality when building from source.
- Standard build dependencies (Boost, OpenSSL, Qt for GUI builds) are required.

Refer to the source repository for detailed build instructions.

## Downloads

Official downloads and checksums are available at:
https://github.com/vandalism79/obidoge/releases

