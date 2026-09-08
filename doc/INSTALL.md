# Installing ObiDoge 0.16.5.0

Get binaries and checksums from [GitHub Releases](https://github.com/vandalism79/obidoge/releases). Back up an existing wallet before upgrading and stop the old wallet/node cleanly before replacing its executable.

## Linux x86-64

Extract `obd-0.16.5.0-linux-x86_64.tar.gz` and keep its folders together. Run `bin/obidoge-qt` for the wallet. The `bin` folder also contains `obidoged`, `obidoge-cli`, and `obidoge-tx`. Always use these launchers so the packaged libraries are selected.

One package was tested on Ubuntu 18.04, 22.04, and 24.04. A graphical session with X11 or XWayland and system OpenGL dispatch libraries is required for the GUI. Other distributions and native modern-kernel boots were not separately verified.

## Windows x86-64

Run `ObiDoge-0.16.5.0-win64.exe`, or extract the full ZIP and run `obidoge-qt.exe`. The executable is portable and does not need additional third-party DLLs. It was tested on Windows 11 and is unsigned.

## Existing data and verification

Keep your existing data directory and wallet. Do not delete chain data or create a new wallet as part of a routine executable upgrade. The application does not automatically install over a running node.

Compare each download's SHA-256 with the release `SHA256SUMS`. On Linux use `sha256sum`; on Windows PowerShell use `Get-FileHash -Algorithm SHA256`.

## Developers

Read the [Ubuntu](build-ubuntu-compat.md) or [Windows](build-windows.md) build guide. Source archives and corresponding dependency sources accompany the binaries. The release notes distinguish completed compatibility checks from the inherited test-suite limitation.
