#!/usr/bin/env bash
set -euo pipefail
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 /absolute/new/build-directory /absolute/BerkeleyDB.4.8-prefix" >&2
    exit 2
fi
source_dir=$(cd "$(dirname "$0")/.." && pwd)
build_dir=$(realpath -m "$1")
bdb_prefix=$(realpath "$2")
test ! -e "$build_dir"
test -f "$bdb_prefix/include/db_cxx.h"
cd "$source_dir"
./autogen.sh
mkdir -p "$build_dir"
cd "$build_dir"
"$source_dir/configure" \
    BDB_CFLAGS="-I$bdb_prefix/include" \
    BDB_LIBS="-L$bdb_prefix/lib -ldb_cxx-4.8 -ldb-4.8" \
    CPPFLAGS="-I$bdb_prefix/include" LDFLAGS="-L$bdb_prefix/lib" \
    CXXFLAGS='-O2 -g0' CFLAGS='-O2 -g0' \
    --with-gui=qt5 --with-miniupnpc --disable-upnp-default --disable-tests --disable-bench
make -j"${JOBS:-2}"
src/obidoged -version
