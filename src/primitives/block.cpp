// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <primitives/block.h>

#include <hash.h>
#include <tinyformat.h>
#include <utilstrencodings.h>
#include <crypto/common.h>
#include <crypto/scrypt.h>
#include <chainparams.h>    // ObiDoge: Hive

#include <crypto/minotaurx/minotaur.h>  // ObiDoge: MinotaurX+Hive1.2
#include <validation.h>                 // ObiDoge: MinotaurX+Hive1.2
#include <util.h>                       // ObiDoge: MinotaurX+Hive1.2

uint256 CBlockHeader::GetHash() const
{
    return SerializeHash(*this);
}

/*
// ObiDoge: MinotaurX+Hive1.2: Hash arbitrary data, using internally-managed thread-local memory for YP
uint256 CBlockHeader::MinotaurXHashArbitrary(const char* data) {
    return Minotaur(data, data + strlen(data), true);
}

// ObiDoge: MinotaurX+Hive1.2: Hash a string with MinotaurX, using provided YP thread-local memory
uint256 CBlockHeader::MinotaurXHashStringWithLocal(std::string data, yespower_local_t *local) {
    return Minotaur(data.begin(), data.end(), true, local);
}*/

// ObiDoge: MinotaurX+Hive1.2: Hash arbitrary data with classical Minotaur
uint256 CBlockHeader::MinotaurHashArbitrary(const char* data) {
    return Minotaur(data, data + strlen(data), false);
}

// ObiDoge: MinotaurX+Hive1.2: Hash a string with classical Minotaur
uint256 CBlockHeader::MinotaurHashString(std::string data) {
    return Minotaur(data.begin(), data.end(), false);
}

// ============================================================
// 🚀 ObiDoge: MinotaurX-ONLY Proof-of-Work
// ============================================================
// We completely remove:
//   - Litecoin’s scrypt hashing
//   - SHA256 PoW
//   - powForkTime branching
//   - powType switching
//
// The network ALWAYS computes PoW via MinotaurX.
// ============================================================

uint256 CBlockHeader::GetPoWHash() const
{
    // ObiDoge: Proof-of-Work is MinotaurX-only.
    // Serialize (nVersion .. nNonce) and feed directly to MinotaurX.

    return Minotaur(BEGIN(nVersion), END(nNonce), true);
}

// ============================================================

std::string CBlock::ToString() const
{
    std::stringstream s;
    // ObiDoge: Hive is permanently disabled; all blocks are treated as PoW.
    const char* blockType = "pow";
    std::string powTypeName = GetPoWTypeName();

    s << strprintf(
        "CBlock(type=%s, hash=%s, powHash=%s, powType=%s, ver=0x%08x, "
        "hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, "
        "nNonce=%u, vtx=%u)\n",
        blockType,
        GetHash().ToString(),
        GetPoWHash().ToString(),
        powTypeName.c_str(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size()
    );

    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
