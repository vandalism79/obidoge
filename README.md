ObiDoge Core
============

ObiDoge Core is the reference full-node implementation for the ObiDoge (OBD)
blockchain network.

It is responsible for block validation, peer-to-peer networking, transaction
relay, and maintaining the canonical distributed ledger.

This repository contains the complete source code for building ObiDoge Core
from source on supported platforms.

---

## What is ObiDoge?

ObiDoge (OBD) is an independent Layer-1 cryptocurrency with its own blockchain,
consensus rules, and network identity.

Key characteristics:

- Consensus: Proof-of-Work only
- Algorithm: MinotaurX (CPU-friendly PoW)
- Block Time: ~60 seconds
- Supply: Fixed supply with scheduled halvings
- Premine: None
- ASIC Resistance: Yes

ObiDoge is not a token and not a smart-contract platform. It runs its own
standalone blockchain with independent parameters, genesis block, and release
cycle.

ObiDoge Core is the software that nodes run to participate in the network.

---

## Repository Structure

This repository contains:

- Full source code for ObiDoge Core
- Build scripts and configuration files
- Consensus, networking, wallet, RPC, and Qt GUI components
- Documentation specific to ObiDoge

Runtime binaries and release artifacts are not stored in the git history and
are provided separately on the official release pages.

---

## Building

Build instructions for supported platforms are provided in:

doc/INSTALL.md

Berkeley DB 4.8 is required for wallet support where applicable.

---

## Documentation

Project-specific documentation is located in the doc/ directory:

doc/
├── INSTALL.md
├── NETWORK.md
└── RELEASE-NOTES.md

All documentation in this repository applies only to ObiDoge and contains
no upstream Litecoin or Bitcoin references.

---

## License

ObiDoge Core is released under the terms of the MIT License.

See the file COPYING or visit:
https://opensource.org/licenses/MIT

---

## Development Notes

- The default branch represents active development
- Tagged releases correspond to official published versions
- Consensus-critical changes are handled conservatively

This is a security-critical project. Code review and testing are essential.

---

## Translations

Translation updates and improvements are welcome via pull requests.

---

## Official Resources

Website: https://obidoge.xyz  
Block Explorer: https://explorer.obidoge.xyz  
Source Code: https://github.com/obidoge-project/obidoge