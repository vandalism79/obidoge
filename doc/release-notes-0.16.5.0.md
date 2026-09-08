# ObiDoge Core 0.16.5.0

This compatibility release establishes a preserved and documented build baseline, restores the working Qt wallet sources, and provides one Linux x86-64 package plus a portable Windows x86-64 wallet.

## Changes

- Version 0.16.5.0 in the application and Windows file metadata.
- Explicit standard-library and Qt includes, qualified Boost placeholders, and an explicit pointer for an existing callback disconnection.
- A tray-availability check to allow Qt startup where no system tray is available.
- Recovered Qt sources/resources and the existing fixed-seed fallback configuration from the working node build area.
- Documented build helpers, a focused README, and removal of tracked build products and host-specific configuration. Published history and 0.16.4 releases are retained.

No native assets or KIBZI are introduced. The release preserves the working node's consensus, monetary policy, MinotaurX, block/transaction serialization, balances, wallet feature version and wire protocol. Fixed seeds affect peer discovery, not chain rules.

## Validation

- One exact Linux archive passed on Ubuntu 18.04, 22.04 and 24.04 userspaces, including X11 virtual-display startup and shutdown.
- Windows native tests passed on Windows 11 Enterprise 10.0.22621. The portable executable imports only Windows system DLLs.
- The 111-block reference fixture matched raw block/transaction bytes, wallet balances and backups, UTXO counts, totals and hash across tested builds.
- Historical mainnet replay matched at height 357702: 66845 UTXOs, 169908450.0 OBD, and UTXO hash `f300ff274c14a1b17bc6a49210c4662c0c9b076c67f1350f89f074e8669b30f1`.
- Source comparison links the release binaries to the verified source inputs. Repository cleanup changes generated files and documentation, not executable source behavior.

## Limits

The inherited proof-of-work unit tests still fail to link because `CalculateNextWorkRequired` is declared but unimplemented. Build helpers disable that target; independent compatibility checks passed. Modern Ubuntu environments shared the host's 4.15 kernel. Native modern-kernel boots, physical GPU/Wayland behavior and other Windows versions were not separately certified. Windows executables are unsigned. Historical dependency versions were retained; this is not a dependency security-upgrade release.

## Downloads

Use the [GitHub release](https://github.com/vandalism79/obidoge/releases/tag/v0.16.5.0) and verify its `SHA256SUMS`.

- `obd-0.16.5.0-linux-x86_64.tar.gz`: Linux wallet and command-line tools.
- `ObiDoge-0.16.5.0-win64.exe`: standalone Windows wallet.
- `obd-0.16.5.0-windows-x86_64.zip`: Windows wallet, command-line tools and notices.
- Source and corresponding dependency-source archives accompany the binaries. Retain those downloads and license notices when redistributing.

Back up your wallet and shut down the old application before replacing binaries. Keep existing chain and wallet data. This release does not automatically update a running installation.
