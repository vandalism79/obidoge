# ObiDoge Core

ObiDoge Core is the wallet and full-node software for the ObiDoge (OBD) network. It uses MinotaurX proof of work and is derived from the Bitcoin Core / Litecoin Cash codebase.

## Downloads

Download **0.16.5.0** from the [official releases page](https://github.com/vandalism79/obidoge/releases).

| Platform | Download | Start the wallet |
|---|---|---|
| Linux x86-64 | `obd-0.16.5.0-linux-x86_64.tar.gz` | Extract the complete folder, then run `bin/obidoge-qt` |
| Windows x86-64 | `ObiDoge-0.16.5.0-win64.exe` | Run the portable executable |
| Windows tools and licenses | `obd-0.16.5.0-windows-x86_64.zip` | Extract, then run `obidoge-qt.exe` |

The same Linux package was tested on Ubuntu 18.04, 22.04, and 24.04. The Windows executable was tested on Windows 11 and needs no extra third-party DLLs. Windows binaries are unsigned. Verify downloads against the release's `SHA256SUMS` and back up your wallet before upgrading.

Version 0.16.5.0 restores a documented build baseline and adds compatibility fixes. It preserves the working OBD chain rules, balances, serialization, monetary policy, and MinotaurX. It does not introduce native assets or KIBZI. See the [release notes](doc/release-notes-0.16.5.0.md) for validation and limitations.

## Build from source

Use the [Ubuntu build guide](doc/build-ubuntu-compat.md) or the [Windows build guide](doc/build-windows.md). Berkeley DB **4.8** is retained for wallet compatibility.

Git checkouts contain build inputs. Run `./autogen.sh` to generate configure files; use a separate build directory. Compiled binaries, dependency installation trees, caches, wallet files, and runtime configuration do not belong in Git. Publish downloadable packages through GitHub Releases.

## Project information

- [Installation and upgrades](doc/INSTALL.md)
- [Network documentation](doc/NETWORK.md)
- [Contributing](CONTRIBUTING.md), [security](SECURITY.md), and [support](SUPPORT.md)
- [Website](https://obidoge.xyz/) and [block explorer](https://explorer.obidoge.xyz/)

Older announcements are retained in [the historical README](doc/history/README-before-0.16.5.0.md) and Git history. Their funding status and other dated statements are not current release information.

## License

ObiDoge Core is distributed under the [MIT license](COPYING). Included third-party components retain their own licenses and attribution. Release packages include notices and accompanying dependency-source downloads.
