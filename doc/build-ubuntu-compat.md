# Building ObiDoge 0.16.5.0 on Ubuntu

Build in a separate directory. Ubuntu 18.04, 22.04 and 24.04 userspace builds were checked; the newer environments ran in containers sharing the 18.04 host kernel.

## Dependencies

```sh
sudo apt-get update
sudo apt-get install --no-install-recommends \
 build-essential libtool autotools-dev automake autoconf pkg-config \
 libssl-dev libevent-dev libminiupnpc-dev bsdmainutils python3 git \
 libboost-system-dev libboost-filesystem-dev libboost-chrono-dev \
 libboost-program-options-dev libboost-test-dev libboost-thread-dev \
 libzmq3-dev libprotobuf-dev protobuf-compiler libqrencode-dev \
 qtbase5-dev qttools5-dev qttools5-dev-tools
```

Use Berkeley DB **4.8.30** for wallet compatibility. Obtain `db-4.8.30.NC.tar.gz` from the corresponding dependency-source archive on the release page. Its SHA-256 is `12edc0df75bf9abd7f82f821795bcee50f42cb2e5f76a6a281b85732798364ef`.

From a checkout, choose absolute paths that do not already exist:

```sh
JOBS=2 contrib/build-bdb48.sh /absolute/path/db-4.8.30.NC.tar.gz /absolute/path/new-bdb-build
JOBS=2 contrib/build-ubuntu.sh /absolute/path/new-obd-build /absolute/path/new-bdb-build/install
```

The BDB helper verifies the source hash, applies the internal atomic-helper compatibility rename, and builds static BDB with C++11. It preserves the database format. The OBD helper runs `autogen.sh`, selects Qt5 and BDB4.8, enables UPnP support with UPnP off by default, and builds outside the source tree. Do not run these scripts as root.

## Tested toolchains

| Ubuntu | GCC/G++ | Boost | OpenSSL | Qt |
|---|---|---|---|---|
| 18.04.6 | 7.5.0 | 1.65.1 | 1.1.1 | 5.9.5 |
| 22.04.5 | 11.4.0 | 1.74.0 | 3.0.2 | 5.15.3 |
| 24.04.4 | 13.3.0 | 1.83.0 | 3.0.13 | 5.15.13 |

The public Linux download uses the 18.04 executables with bundled shared libraries and Qt plugins. It still uses the operating system's C/C++ runtime and graphics interfaces. A locally compiled binary can depend on the specific distribution libraries used to build it.

## Validation limitation

The inherited `make check` executable fails to link because legacy tests call `CalculateNextWorkRequired`, which is declared but not implemented in this OBD tree. The helper explicitly disables that inherited test target and benchmarks. Independent replay, wallet, GUI and serialization checks passed; they do not imply the inherited suite passed. See the [release notes](release-notes-0.16.5.0.md).
