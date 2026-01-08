# ObiDoge Network Information

This document provides basic network details for exchanges, node operators, and advanced users.

## Network Overview
- **Name:** ObiDoge
- **Ticker:** OBD
- **Type:** Independent Layer-1 blockchain
- **Consensus:** Proof-of-Work (MinotaurX)
- **Block Time:** ~60 seconds
- **Premine:** None
- **Dev Tax:** None

## Mainnet Ports
- **P2P Port:** 29445
- **RPC Port:** 29446

## Address Format
- **Base58 Prefixes:** ObiDoge-specific (not Bitcoin-compatible)
- **Bech32 HRP:** `obd`

## RPC
The daemon exposes standard Bitcoin Core–style JSON-RPC.

Common RPC calls:
- `getblockchaininfo`
- `getnetworkinfo`
- `getpeerinfo`
- `getrawtransaction`
- `getblock`

RPC must be enabled in `obidoge.conf`.

## Example Configuration
An example configuration file is provided:

obidoge.conf.example


Included in the Linux release package.

## Explorer
https://explorer.obidoge.xyz

## Mining
- **Algorithm:** MinotaurX
- **CPU-friendly**
- **Public pool:** http://cryptopool.site

## Source Code
https://github.com/vandalism79/obidoge
