# Building ObiDoge 0.16.5.0 for Windows x86-64

The Windows release was cross-compiled on Ubuntu 18.04 with MinGW-w64 GCC/G++ 7.3-posix. The pinned dependency recipes use Qt 5.7.1, Boost 1.64, OpenSSL 1.0.1k and Berkeley DB 4.8. These are the historical dependency versions retained for this compatibility release.

Install the cross-build tools in a dedicated Ubuntu build environment:

```sh
sudo apt-get install build-essential automake autoconf libtool pkg-config \
 bsdmainutils python3 curl git g++-mingw-w64-x86-64 mingw-w64-x86-64-dev
```

Use the POSIX-thread compiler variants. The verified compiler reported `Thread model: posix`. Build the pinned dependencies, using the Windows dependency-source archive from the release to populate `depends/sources` if needed:

```sh
make -C depends HOST=x86_64-w64-mingw32 -j2
./autogen.sh
```

Then build outside the source directory:

```sh
source_dir=$(pwd)
mkdir /absolute/path/new-windows-build
cd /absolute/path/new-windows-build
CONFIG_SITE="$source_dir/depends/x86_64-w64-mingw32/share/config.site" \
 "$source_dir/configure" --host=x86_64-w64-mingw32 --prefix=/ \
 --disable-tests --disable-bench --with-gui=qt5 \
 --with-boost-libdir="$source_dir/depends/x86_64-w64-mingw32/lib" \
 --with-miniupnpc --disable-upnp-default \
 CFLAGS='-O2 -g0' CXXFLAGS='-O2 -g0' \
 LDFLAGS='-static -static-libgcc -static-libstdc++'
make -j2
```

The release used hash-verified copies of the preserved dependency installation tree; rebuilding every dependency from scratch was not repeated. Its 13 source archives match their pinned recipe hashes. Source and dependency archives are provided to support rebuilding and relinking the statically linked application.

Outputs are `src/obidoged.exe`, `src/obidoge-cli.exe`, `src/obidoge-tx.exe`, and `src/qt/obidoge-qt.exe`. Strip copies for release, retain licenses, and inspect PE imports. The published executables require only Windows system DLLs. Native runtime checks passed on Windows 11 Enterprise 10.0.22621; Windows 10 was not separately tested. Binaries are unsigned.

The inherited test-suite limitation is documented in the [release notes](release-notes-0.16.5.0.md).
