#!/usr/bin/env bash
set -euo pipefail
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 /absolute/path/db-4.8.30.NC.tar.gz /absolute/new/build-directory" >&2
    exit 2
fi
archive=$(realpath "$1")
workdir=$(realpath -m "$2")
test ! -e "$workdir"
echo "12edc0df75bf9abd7f82f821795bcee50f42cb2e5f76a6a281b85732798364ef  $archive" | sha256sum -c -
mkdir -p "$workdir"
tar -xzf "$archive" -C "$workdir"
# Match the preserved 18.04 build's rename, avoiding GCC's builtin identifier.
sed -i 's/__atomic_compare_exchange(/__atomic_compare_exchange_db(/g' "$workdir/db-4.8.30.NC/dbinc/atomic.h"
cd "$workdir/db-4.8.30.NC/build_unix"
../dist/configure --enable-cxx --disable-shared --disable-replication --with-pic --prefix="$workdir/install" CXXFLAGS='-O2 -std=c++11'
make -j"${JOBS:-2}"
make install
printf 'BDB_PREFIX=%s/install\n' "$workdir"
