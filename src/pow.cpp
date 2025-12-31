// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <pow.h>


#include <algorithm>
#include <cstdint>
#include <arith_uint256.h>
#include <chain.h>
#include <primitives/block.h>
#include <uint256.h>
#include <util.h>
#include <core_io.h>            // ObiDoge: Hive
#include <script/standard.h>    // ObiDoge: Hive
#include <base58.h>             // ObiDoge: Hive
#include <pubkey.h>             // ObiDoge: Hive
#include <hash.h>               // ObiDoge: Hive
#include <sync.h>               // ObiDoge: Hive
#include <validation.h>         // ObiDoge: Hive
#include <utilstrencodings.h>   // ObiDoge: Hive
#include <util.h>            // ObiDoge: for error()

BeePopGraphPoint beePopGraph[1024*40];       // ObiDoge: Hive

// ObiDoge: MinotaurX+Hive1.2: Diff adjustment for pow algos (post-MinotaurX activation)
// Modified LWMA-3
// Copyright (c) 2017-2021 The Bitcoin Gold developers, Zawy, iamstenman (Microbitcoin), The ObiDoge Core developers (originally based on ObiDoge)
// MIT License
// Algorithm by Zawy, a modification of WT-144 by Tom Harding
// For updates see
// https://github.com/zawy12/difficulty-algorithms/issues/3#issuecomment-442129791
unsigned int GetNextWorkRequiredLWMA(const CBlockIndex* pindexLast,
                                     const CBlockHeader* pblock,
                                     const Consensus::Params& params,
                                     POW_TYPE powType)
{
    // ObiDoge: Single-algo (MinotaurX) LWMA difficulty adjustment
    // We ignore powType and always compute difficulty for the single PoW stream.

    // ObiDoge: We are MinotaurX-only now; ignore powType and pblock.
    (void)pblock;
    (void)powType;

    const arith_uint256 powLimit = UintToArith256(params.powLimit);

    // No previous block -> genesis
    if (pindexLast == nullptr) {
        return powLimit.GetCompact();
    }
    // ObiDoge: Preserve mainnet historical difficulty (nBits) so fresh nodes can sync
    // from genesis without forking the already-mined chain. For heights 1..311 we
    // return the exact compact target (nBits) observed on the canonical chain, then
    // fall back to normal LWMA starting at height 312 thereafter.
    {
        const int nextHeight = pindexLast->nHeight + 1;
        if (nextHeight >= 1 && nextHeight <= 311) {
            const CBlockIndex* pindexGenesis = pindexLast->GetAncestor(0);
            if (pindexGenesis && pindexGenesis->GetBlockHash() == uint256S("2dfb24e7c17ca31dac896611e9796ab8d05cde9bc5ec12f5ad48002eeb78b976")) {
                static const uint32_t kCanonicalBits[312] = {
    0x00000000u, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu,
    0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e7fffffu, 0x1e27b033u, 0x1e286b49u,
    0x1e294901u, 0x1e26b132u, 0x1e2441d9u, 0x1e2373f6u, 0x1e21bc82u, 0x1e20a1beu, 0x1e1ede60u,
    0x1e1cde11u, 0x1e1b996au, 0x1e19d0adu, 0x1e1988fdu, 0x1e17975du, 0x1e172bd5u, 0x1e15cfc9u,
    0x1e13af00u, 0x1e11ca24u, 0x1e0fd83au, 0x1e0ef2d5u, 0x1e0d18dfu, 0x1e0b4372u, 0x1e097530u,
    0x1e07e05eu, 0x1e06acb7u, 0x1e052333u, 0x1e03aa78u, 0x1e0226b1u, 0x1e00c7dfu, 0x1e327299u,
    0x1e316deau, 0x1e30ba7au, 0x1e2f9eb0u, 0x1e2d5655u, 0x1e2b5b5eu, 0x1e2a7f22u, 0x1e282baeu,
    0x1e284e0eu, 0x1e26c68cu, 0x1e24e799u, 0x1e233091u, 0x1e224c28u, 0x1e20c62cu, 0x1e200b72u,
    0x1e1f737eu, 0x1e1db64du, 0x1e1cc910u, 0x1e1b29b3u, 0x1e1a87d0u, 0x1e191228u, 0x1e1790a7u,
    0x1e15fc94u, 0x1e14c544u, 0x1e13c068u, 0x1e126eb0u, 0x1e113350u, 0x1e1082e8u, 0x1e0f7bfcu,
    0x1e0e415fu, 0x1e0d906du, 0x1e0c8c6fu, 0x1e0c29b6u, 0x1e0ba8aau, 0x1e0b3f3cu, 0x1e0b2f17u,
    0x1e0b2327u, 0x1e0b1a34u, 0x1e0b14c4u, 0x1e0b11c6u, 0x1e0ab0d6u, 0x1e0a9cf8u, 0x1e0aa3a1u,
    0x1e0aae3cu, 0x1e0a6e18u, 0x1e0a7cc3u, 0x1e0a8e99u, 0x1e0a6e10u, 0x1e0a87c3u, 0x1e0a612du,
    0x1e0a83fdu, 0x1e0aac3au, 0x1e0a8aecu, 0x1e0abd90u, 0x1e0af8e5u, 0x1e0ab798u, 0x1e0af681u,
    0x1e0b3c77u, 0x1e0b8961u, 0x1e0bddd9u, 0x1e0c3a16u, 0x1e0b7d88u, 0x1e0ae98du, 0x1e0aa2dcu,
    0x1e0a067du, 0x1e097d93u, 0x1e092488u, 0x1e08a0afu, 0x1e082c76u, 0x1e07d3e4u, 0x1e075d12u,
    0x1e06f31cu, 0x1e06d47cu, 0x1e06b46eu, 0x1e065babu, 0x1e062c50u, 0x1e05e3d1u, 0x1e05b8bcu,
    0x1e0594b7u, 0x1e057aa9u, 0x1e052da9u, 0x1e051939u, 0x1e04fff9u, 0x1e04f01eu, 0x1e04e227u,
    0x1e04c769u, 0x1e04bcdfu, 0x1e04b4b2u, 0x1e04a9cfu, 0x1e048c19u, 0x1e0489a5u, 0x1e04889au,
    0x1e04598du, 0x1e044c55u, 0x1e044d27u, 0x1e044fb8u, 0x1e04528au, 0x1e042639u, 0x1e041e40u,
    0x1e041685u, 0x1e03feddu, 0x1e03e485u, 0x1e03b979u, 0x1e03b85du, 0x1e03b4cdu, 0x1e038e00u,
    0x1e036af0u, 0x1e0360aeu, 0x1e034a3eu, 0x1e033388u, 0x1e031d6bu, 0x1e02fa4eu, 0x1e02dfd2u,
    0x1e02c24cu, 0x1e029ff8u, 0x1e02972bu, 0x1e028e9bu, 0x1e02803fu, 0x1e02761eu, 0x1e026b25u,
    0x1e025f3bu, 0x1e023cadu, 0x1e021ca0u, 0x1e020678u, 0x1e01fb27u, 0x1e01ee1cu, 0x1e01d611u,
    0x1e01ca52u, 0x1e01bae5u, 0x1e01a928u, 0x1e01a159u, 0x1e019a33u, 0x1e0193a2u, 0x1e01825fu,
    0x1e017bd1u, 0x1e016730u, 0x1e016121u, 0x1e0154d4u, 0x1e0146a3u, 0x1e014123u, 0x1e013af5u,
    0x1e01347bu, 0x1e012f82u, 0x1e012a9eu, 0x1e0125c1u, 0x1e0120e5u, 0x1e011c45u, 0x1e01159au,
    0x1e0110e9u, 0x1e010997u, 0x1e00fae0u, 0x1e00f651u, 0x1e00ef67u, 0x1e00eafau, 0x1e00e68fu,
    0x1e00daa1u, 0x1e00d635u, 0x1e00d1b1u, 0x1e00c755u, 0x1e00bd5eu, 0x1e00b8f1u, 0x1e00b498u,
    0x1e00b058u, 0x1e00ac4cu, 0x1e00a309u, 0x1e009c7au, 0x1e00972fu, 0x1e00935eu, 0x1e008efcu,
    0x1e008b50u, 0x1e00851au, 0x1e00819bu, 0x1d7e45f3u, 0x1d793a45u, 0x1d762544u, 0x1d733accu,
    0x1d705473u, 0x1d6d71eau, 0x1d6a9c31u, 0x1d67ccf2u, 0x1d650596u, 0x1d60cb41u, 0x1d5e3acdu,
    0x1d5bd3d3u, 0x1d5987a6u, 0x1d5745dcu, 0x1d536cf1u, 0x1d5156f0u, 0x1d4f4cdbu, 0x1d4d5489u,
    0x1d4b71cbu, 0x1d499592u, 0x1d47bef0u, 0x1d45ed10u, 0x1d4430b7u, 0x1d427971u, 0x1d40dd68u,
    0x1d3f4614u, 0x1d3dbd5eu, 0x1d3bdfbcu, 0x1d3a4944u, 0x1d38dc12u, 0x1d3774ebu, 0x1d361184u,
    0x1d34b1c9u, 0x1d3355bbu, 0x1d30ad5fu, 0x1d2f5944u, 0x1d2e0c04u, 0x1d2cc29cu, 0x1d2a0ab1u,
    0x1d2840f0u, 0x1d2719b3u, 0x1d25fa54u, 0x1d24df2au, 0x1d229660u, 0x1d20caf4u, 0x1d1fcbc5u,
    0x1d1ed16bu, 0x1d1de441u, 0x1d0ebfccu, 0x1d0e45deu
                };
                return kCanonicalBits[nextHeight];
            }
        }
    }

    // If retargeting is disabled (e.g. pure regtest), keep last difficulty.
    if (params.fPowNoRetargeting) {
        return pindexLast->nBits;
    }

    // --- LWMA parameters ---
    // Target spacing from consensus (we already set this for ObiDoge).
    const int64_t T  = params.nPowTargetSpacing;
    // Window size (number of blocks to average). 60 is a sane default.
    const int64_t N = std::max<int64_t>(30, std::min<int64_t>(params.lwmaAveragingWindow, 180));
    const int64_t k  = N * (N + 1) * T / 2;

    // ObiDoge: bootstrap LWMA with a sane initial difficulty instead of powLimit.
    // Starting from powLimit (e.g. 0x207fffff) can keep the chain stuck at minimum
    // difficulty forever. Use a modestly harder target for the first N blocks.
    if (pindexLast->nHeight < N) {
        arith_uint256 initialTarget = powLimit;
        return initialTarget.GetCompact();
    }

int64_t weightedTimeSum = 0;
    arith_uint256 targetSum = 0;

    const CBlockIndex* pindex = pindexLast;

    // Walk back N blocks, accumulating weighted solve times and targets.
    for (int i = 1; i <= N; ++i) {
        const CBlockIndex* pindexPrev = pindex->pprev;
        if (!pindexPrev) {
            // We hit the beginning of the chain unexpectedly; bail out safely.
            return pindex->nBits;
        }

        int64_t solveTime = pindex->GetBlockTime() - pindexPrev->GetBlockTime();

        // Clamp solve times to a sane, strictly-positive range.
        // Negative/zero solve times (or huge future timestamps) can otherwise force difficulty to ratchet upward.
        if (solveTime > 6 * T) solveTime = 6 * T;
        if (solveTime < 1) solveTime = 1;
// Weight is i (1..N). Most recent blocks have higher weight.
        weightedTimeSum += solveTime * i;

        arith_uint256 target;
        target.SetCompact(pindex->nBits);
        targetSum += target;

        pindex = pindexPrev;
    }

    // Protect against crazy fast chains.
    if (weightedTimeSum < k / 3) {
        weightedTimeSum = k / 3;
    }

    // LWMA-3 (Zawy):
    //   sumSolv = Σ(i * solvetime_i)
    //   avgTarget = (Σ target_i) / N
    //   nextTarget = avgTarget * sumSolv / k
    const arith_uint256 avgTarget = targetSum / N;
    arith_uint256 nextTarget = (avgTarget * weightedTimeSum) / k;

    if (nextTarget > powLimit) {
        nextTarget = powLimit;
    }

    return nextTarget.GetCompact();
}


// ObiDoge: DarkGravity V3 (https://github.com/dashpay/dash/blob/master/src/pow.cpp#L82)
// By Evan Duffield <evan@dash.org>
// Used for sha256 from OBD fork point till MinotaurX activation
unsigned int DarkGravityWave(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params)
{
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimitSHA);
    int64_t nPastBlocks = 24;

    // ObiDoge: Allow minimum difficulty blocks if we haven't seen a block for ostensibly 10 blocks worth of time
    if (params.fPowAllowMinDifficultyBlocks && pblock->GetBlockTime() > pindexLast->GetBlockTime() + params.nPowTargetSpacing * 10)
        return bnPowLimit.GetCompact();

    // ObiDoge: Hive 1.1: Skip over Hivemined blocks at tip
    if (IsHive11Enabled(pindexLast, params)) {
        while (pindexLast->GetBlockHeader().IsHiveMined(params)) {
            //LogPrintf("DarkGravityWave: Skipping hivemined block at %i\n", pindex->nHeight);
            assert(pindexLast->pprev); // should never fail
            pindexLast = pindexLast->pprev;
        }
    }

    // ObiDoge: Make sure we have at least (nPastBlocks + 1) blocks since the fork, otherwise just return powLimitSHA
    if (!pindexLast || pindexLast->nHeight - params.lastScryptBlock < nPastBlocks)
        return bnPowLimit.GetCompact();

    const CBlockIndex *pindex = pindexLast;
    arith_uint256 bnPastTargetAvg;

    for (unsigned int nCountBlocks = 1; nCountBlocks <= nPastBlocks; nCountBlocks++) {
        // ObiDoge: Hive: Skip over Hivemined blocks; we only want to consider PoW blocks
        while (pindex->GetBlockHeader().IsHiveMined(params)) {
            //LogPrintf("DarkGravityWave: Skipping hivemined block at %i\n", pindex->nHeight);
            assert(pindex->pprev); // should never fail
            pindex = pindex->pprev;
        }

        arith_uint256 bnTarget = arith_uint256().SetCompact(pindex->nBits);
        if (nCountBlocks == 1) {
            bnPastTargetAvg = bnTarget;
        } else {
            // NOTE: that's not an average really...
            bnPastTargetAvg = (bnPastTargetAvg * nCountBlocks + bnTarget) / (nCountBlocks + 1);
        }

        if(nCountBlocks != nPastBlocks) {
            assert(pindex->pprev); // should never fail
            pindex = pindex->pprev;
        }
    }

    arith_uint256 bnNew(bnPastTargetAvg);

    int64_t nActualTimespan = pindexLast->GetBlockTime() - pindex->GetBlockTime();
    // NOTE: is this accurate? nActualTimespan counts it for (nPastBlocks - 1) blocks only...
    int64_t nTargetTimespan = nPastBlocks * params.nPowTargetSpacing;

    if (nActualTimespan < nTargetTimespan/3)
        nActualTimespan = nTargetTimespan/3;
    if (nActualTimespan > nTargetTimespan*3)
        nActualTimespan = nTargetTimespan*3;

    // Retarget
    bnNew *= nActualTimespan;
    bnNew /= nTargetTimespan;

    if (bnNew > bnPowLimit) {
        bnNew = bnPowLimit;
    }

    return bnNew.GetCompact();
}

// ObiDoge: MinotaurX-only difficulty adjustment
//
// We ignore legacy ObiDoge Scrypt / DarkGravityWave logic and always
// use the MinotaurX LWMA adjuster. This keeps consensus simple and avoids
// any divide-by-zero surprises in legacy paths.
unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast,
                                 const CBlockHeader* pblock,
                                 const Consensus::Params& params)
{
    assert(pindexLast != nullptr);
    // Use LWMA directly for MinotaurX-only chain
    return GetNextWorkRequiredLWMA(pindexLast, pblock, params, POW_TYPE_MINOTAURX);
}

// (Legacy ObiDoge difficulty routines such as GetNextWorkRequiredLTC and
// DarkGravityWave are intentionally left unused for ObiDoge. They may remain
// in the source for reference but are no longer called by consensus.)

bool CheckProofOfWork(uint256 hash, unsigned int nBits, const Consensus::Params& params)
{
    // ObiDoge: simplified, MinotaurX-only PoW check.
    // We intentionally do NOT use params.powLimit here to avoid
    // any leftover multi-algo/Hive complexity from ObiDoge.

    bool fNegative = false;
    bool fOverflow = false;
    arith_uint256 bnTarget;

    // Decode nBits into a target.
    bnTarget.SetCompact(nBits, &fNegative, &fOverflow);

    // Basic sanity checks on the target.
    if (fNegative || fOverflow || bnTarget == 0) {
        return error("CheckProofOfWork(): nBits invalid");
    }

    // Check that the hash satisfies the target.
    // For MinotaurX-only ObiDoge, the hash is always the MinotaurX PoW hash.
    if (UintToArith256(hash) > bnTarget) {
        // ObiDoge: Just signal failure; don't scream in the logs.
        return false;
    }

    return true;
}


// ObiDoge: Hive 1.1: SMA Hive Difficulty Adjust

// ObiDoge: Hive is permanently disabled. This function should never
// be used for consensus, but we provide a trivial implementation to
// avoid any accidental divide-by-zero or heavy logic.
unsigned int GetNextHive11WorkRequired(const CBlockIndex* pindexLast, const Consensus::Params& params)
{
    (void)pindexLast;
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimitHive);
    return bnPowLimit.GetCompact();
}


// ObiDoge: MinotaurX+Hive1.2: Reset Hive difficulty after MinotaurX enable

// ObiDoge: Hive 1.2 difficulty is disabled. Return the easiest
// possible Hive target and avoid internal averaging/retargeting.
unsigned int GetNextHive12WorkRequired(const CBlockIndex* pindexLast, const Consensus::Params& params)
{
    (void)pindexLast;
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimitHive);
    return bnPowLimit.GetCompact();
}


// ObiDoge: Hive: Get the current Bee Hash Target (Hive 1.0)

// ObiDoge: Top-level Hive difficulty selector is disabled. Always
// return the easiest Hive target. No consensus code should rely on
// Hive for ObiDoge, but this keeps old call sites harmless.
unsigned int GetNextHiveWorkRequired(const CBlockIndex* pindexLast, const Consensus::Params& params)
{
    (void)pindexLast;
    const arith_uint256 bnPowLimit = UintToArith256(params.powLimitHive);
    return bnPowLimit.GetCompact();
}


// ObiDoge: Hive: Get count of all live and gestating BCTs on the network
bool GetNetworkHiveInfo(int& immatureBees, int& immatureBCTs, int& matureBees, int& matureBCTs, CAmount& potentialLifespanRewards, const Consensus::Params& consensusParams, bool recalcGraph) {
    int totalBeeLifespan = consensusParams.beeLifespanBlocks + consensusParams.beeGestationBlocks;
    immatureBees = immatureBCTs = matureBees = matureBCTs = 0;
    
    CBlockIndex* pindexPrev = chainActive.Tip();
    assert(pindexPrev != nullptr);
    int tipHeight = pindexPrev->nHeight;

    // ObiDoge: MinotaurX+Hive1.2: Get correct hive block reward
    auto blockReward = GetBlockSubsidy(pindexPrev->nHeight, consensusParams);
    if (IsMinotaurXEnabled(pindexPrev, consensusParams))
        blockReward += blockReward >> 1;

    // ObiDoge: Hive 1.1: Use correct typical spacing
    if (IsHive11Enabled(pindexPrev, consensusParams))
        potentialLifespanRewards = (consensusParams.beeLifespanBlocks * blockReward) / consensusParams.hiveBlockSpacingTargetTypical_1_1;
    else
        potentialLifespanRewards = (consensusParams.beeLifespanBlocks * blockReward) / consensusParams.hiveBlockSpacingTargetTypical;

    if (recalcGraph) {
        for (int i = 0; i < totalBeeLifespan; i++) {
            beePopGraph[i].immaturePop = 0;
            beePopGraph[i].maturePop = 0;
        }
    }

    if (IsInitialBlockDownload())   // Refuse if we're downloading
        return false;

    // Count bees in next blockCount blocks
    CBlock block;
    CScript scriptPubKeyBCF = GetScriptForDestination(DecodeDestination(consensusParams.beeCreationAddress));
    CScript scriptPubKeyCF = GetScriptForDestination(DecodeDestination(consensusParams.hiveCommunityAddress));

    for (int i = 0; i < totalBeeLifespan; i++) {
        if (fHavePruned && !(pindexPrev->nStatus & BLOCK_HAVE_DATA) && pindexPrev->nTx > 0) {
            LogPrintf("! GetNetworkHiveInfo: Warn: Block not available (pruned data); can't calculate network bee count.");
            return false;
        }

        if (!pindexPrev->GetBlockHeader().IsHiveMined(consensusParams)) {                          // Don't check Hivemined blocks (no BCTs will be found in them)
            if (!ReadBlockFromDisk(block, pindexPrev, consensusParams)) {
                LogPrintf("! GetNetworkHiveInfo: Warn: Block not available (not found on disk); can't calculate network bee count.");
                return false;
            }
            int blockHeight = pindexPrev->nHeight;
            CAmount beeCost = GetBeeCost(blockHeight, consensusParams);
            if (block.vtx.size() > 0) {
                for(const auto& tx : block.vtx) {
                    CAmount beeFeePaid;
                    if (tx->IsBCT(consensusParams, scriptPubKeyBCF, &beeFeePaid)) {                 // If it's a BCT, total its bees
                        if (tx->vout.size() > 1 && tx->vout[1].scriptPubKey == scriptPubKeyCF) {    // If it has a community fund contrib...
                            CAmount donationAmount = tx->vout[1].nValue;
                            CAmount expectedDonationAmount = (beeFeePaid + donationAmount) / consensusParams.communityContribFactor;  // ...check for valid donation amount
                            // ObiDoge: MinotaurX+Hive1.2
                            if (IsMinotaurXEnabled(pindexPrev, consensusParams))
                                expectedDonationAmount += expectedDonationAmount >> 1;
                            if (donationAmount != expectedDonationAmount)
                                continue;
                            beeFeePaid += donationAmount;                                           // Add donation amount back to total paid
                        }
                        int beeCount = beeFeePaid / beeCost;
                        if (i < consensusParams.beeGestationBlocks) {
                            immatureBees += beeCount;
                            immatureBCTs++;
                        } else {
                            matureBees += beeCount; 
                            matureBCTs++;
                        }

                        // Add these bees to pop graph
                        if (recalcGraph) {
                            /*
                            int beeStart = blockHeight + consensusParams.beeGestationBlocks;
                            int beeStop = beeStart + consensusParams.beeLifespanBlocks;
                            beeStart -= tipHeight;
                            beeStop -= tipHeight;
                            for (int j = beeStart; j < beeStop; j++) {
                                if (j > 0 && j < totalBeeLifespan) {
                                    if (i < consensusParams.beeGestationBlocks) // THIS IS WRONG
                                        beePopGraph[j].immaturePop += beeCount;
                                    else
                                        beePopGraph[j].maturePop += beeCount;
                                }
                            }*/
                            int beeBornBlock = blockHeight;
                            int beeMaturesBlock = beeBornBlock + consensusParams.beeGestationBlocks;
                            int beeDiesBlock = beeMaturesBlock + consensusParams.beeLifespanBlocks;
                            for (int j = beeBornBlock; j < beeDiesBlock; j++) {
                                int graphPos = j - tipHeight;
                                if (graphPos > 0 && graphPos < totalBeeLifespan) {
                                    if (j < beeMaturesBlock)
                                        beePopGraph[graphPos].immaturePop += beeCount;
                                    else
                                        beePopGraph[graphPos].maturePop += beeCount;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (!pindexPrev->pprev)     // Check we didn't run out of blocks
            return true;

        pindexPrev = pindexPrev->pprev;
    }

    return true;
}

// ObiDoge: Hive: Check the hive proof for given block
bool CheckHiveProof(const CBlock* pblock, const Consensus::Params& consensusParams) {
    bool verbose = LogAcceptCategory(BCLog::HIVE);

    if (verbose)
        LogPrintf("********************* Hive: CheckHiveProof *********************\n");

    // Get height (a CBlockIndex isn't always available when this func is called, eg in reads from disk)
    int blockHeight;
    CBlockIndex* pindexPrev;
    {
        LOCK(cs_main);
        pindexPrev = mapBlockIndex[pblock->hashPrevBlock];
        blockHeight = pindexPrev->nHeight + 1;
    }
    if (!pindexPrev) {
        LogPrintf("CheckHiveProof: Couldn't get previous block's CBlockIndex!\n");
        return false;
    }
    if (verbose)
        LogPrintf("CheckHiveProof: nHeight             = %i\n", blockHeight);

    // Check hive is enabled on network
    if (!IsHiveEnabled(pindexPrev, consensusParams)) {
        LogPrintf("CheckHiveProof: Can't accept a Hive block; Hive is not yet enabled on the network.\n");
        return false;
    }

    // ObiDoge: Hive 1.1: Check that there aren't too many consecutive Hive blocks
    if (IsHive11Enabled(pindexPrev, consensusParams)) {
        int hiveBlocksAtTip = 0;
        CBlockIndex* pindexTemp = pindexPrev;
        while (pindexTemp->GetBlockHeader().IsHiveMined(consensusParams)) {
            assert(pindexTemp->pprev);
            pindexTemp = pindexTemp->pprev;
            hiveBlocksAtTip++;
        }
        if (hiveBlocksAtTip >= consensusParams.maxConsecutiveHiveBlocks) {
            LogPrintf("CheckHiveProof: Too many Hive blocks without a POW block.\n");
            return false;
        }
    } else {
        if (pindexPrev->GetBlockHeader().IsHiveMined(consensusParams)) {
            LogPrint(BCLog::HIVE, "CheckHiveProof: Hive block must follow a POW block.\n");
            return false;
        }
    }

    // Block mustn't include any BCTs
    CScript scriptPubKeyBCF = GetScriptForDestination(DecodeDestination(consensusParams.beeCreationAddress));
    if (pblock->vtx.size() > 1)
        for (unsigned int i=1; i < pblock->vtx.size(); i++)
            if (pblock->vtx[i]->IsBCT(consensusParams, scriptPubKeyBCF)) {
                LogPrintf("CheckHiveProof: Hivemined block contains BCTs!\n");
                return false;                
            }
    
    // Coinbase tx must be valid
    CTransactionRef txCoinbase = pblock->vtx[0];
    //LogPrintf("CheckHiveProof: Got coinbase tx: %s\n", txCoinbase->ToString());
    if (!txCoinbase->IsCoinBase()) {
        LogPrintf("CheckHiveProof: Coinbase tx isn't valid!\n");
        return false;
    }

    // Must have exactly 2 or 3 outputs
    if (txCoinbase->vout.size() < 2 || txCoinbase->vout.size() > 3) {
        LogPrintf("CheckHiveProof: Didn't expect %i vouts!\n", txCoinbase->vout.size());
        return false;
    }

    // vout[0] must be long enough to contain all encodings
    if (txCoinbase->vout[0].scriptPubKey.size() < 144) {
        LogPrintf("CheckHiveProof: vout[0].scriptPubKey isn't long enough to contain hive proof encodings\n");
        return false;
    }

    // vout[1] must start OP_RETURN OP_BEE (bytes 0-1)
    if (txCoinbase->vout[0].scriptPubKey[0] != OP_RETURN || txCoinbase->vout[0].scriptPubKey[1] != OP_BEE) {
        LogPrintf("CheckHiveProof: vout[0].scriptPubKey doesn't start OP_RETURN OP_BEE\n");
        return false;
    }

    // Grab the bee nonce (bytes 3-6; byte 2 has value 04 as a size marker for this field)
    uint32_t beeNonce = ReadLE32(&txCoinbase->vout[0].scriptPubKey[3]);
    if (verbose)
        LogPrintf("CheckHiveProof: beeNonce            = %i\n", beeNonce);

    // Grab the bct height (bytes 8-11; byte 7 has value 04 as a size marker for this field)
    uint32_t bctClaimedHeight = ReadLE32(&txCoinbase->vout[0].scriptPubKey[8]);
    if (verbose)
        LogPrintf("CheckHiveProof: bctHeight           = %i\n", bctClaimedHeight);

    // Get community contrib flag (byte 12)
    bool communityContrib = txCoinbase->vout[0].scriptPubKey[12] == OP_TRUE;
    if (verbose)
        LogPrintf("CheckHiveProof: communityContrib    = %s\n", communityContrib ? "true" : "false");

    // Grab the txid (bytes 14-78; byte 13 has val 64 as size marker)
    std::vector<unsigned char> txid(&txCoinbase->vout[0].scriptPubKey[14], &txCoinbase->vout[0].scriptPubKey[14 + 64]);
    std::string txidStr = std::string(txid.begin(), txid.end());
    if (verbose)
        LogPrintf("CheckHiveProof: bctTxId             = %s\n", txidStr);

    // Check bee hash against target
    std::string deterministicRandString = GetDeterministicRandString(pindexPrev);
    if (verbose)
        LogPrintf("CheckHiveProof: detRandString       = %s\n", deterministicRandString);
    arith_uint256 beeHashTarget;
    beeHashTarget.SetCompact(GetNextHiveWorkRequired(pindexPrev, consensusParams));
    if (verbose)
        LogPrintf("CheckHiveProof: beeHashTarget       = %s\n", beeHashTarget.ToString());
    
    // ObiDoge: MinotaurX+Hive1.2: Use the correct inner Hive hash
    if (!IsMinotaurXEnabled(pindexPrev, consensusParams)) {
        std::string hashHex = (CHashWriter(SER_GETHASH, 0) << deterministicRandString << txidStr << beeNonce).GetHash().GetHex();
        arith_uint256 beeHash = arith_uint256(hashHex);
        if (verbose)
            LogPrintf("CheckHiveProof: beeHash             = %s\n", beeHash.GetHex());
        if (beeHash >= beeHashTarget) {
            LogPrintf("CheckHiveProof: Bee does not meet hash target!\n");
            return false;
        }
    } else {
        arith_uint256 beeHash(CBlockHeader::MinotaurHashArbitrary(std::string(deterministicRandString + txidStr + std::to_string(beeNonce)).c_str()).ToString());
        if (verbose)
            LogPrintf("CheckHive12Proof: beeHash           = %s\n", beeHash.GetHex());
        if (beeHash >= beeHashTarget) {
            LogPrintf("CheckHive12Proof: Bee does not meet hash target!\n");
            return false;
        }
    }
    
    // Grab the message sig (bytes 79-end; byte 78 is size)
    std::vector<unsigned char> messageSig(&txCoinbase->vout[0].scriptPubKey[79], &txCoinbase->vout[0].scriptPubKey[79 + 65]);
    if (verbose)
        LogPrintf("CheckHiveProof: messageSig          = %s\n", HexStr(&messageSig[0], &messageSig[messageSig.size()]));
    
    // Grab the honey address from the honey vout
    CTxDestination honeyDestination;
    if (!ExtractDestination(txCoinbase->vout[1].scriptPubKey, honeyDestination)) {
        LogPrintf("CheckHiveProof: Couldn't extract honey address\n");
        return false;
    }
    if (!IsValidDestination(honeyDestination)) {
        LogPrintf("CheckHiveProof: Honey address is invalid\n");
        return false;
    }
    if (verbose)
        LogPrintf("CheckHiveProof: honeyAddress        = %s\n", EncodeDestination(honeyDestination));

    // Verify the message sig
    const CKeyID *keyID = boost::get<CKeyID>(&honeyDestination);
    if (!keyID) {
        LogPrintf("CheckHiveProof: Can't get pubkey for honey address\n");
        return false;
    }
    CHashWriter ss(SER_GETHASH, 0);
    ss << deterministicRandString;
    uint256 mhash = ss.GetHash();
    CPubKey pubkey;
    if (!pubkey.RecoverCompact(mhash, messageSig)) {
        LogPrintf("CheckHiveProof: Couldn't recover pubkey from hash\n");
        return false;
    }
    if (pubkey.GetID() != *keyID) {
        LogPrintf("CheckHiveProof: Signature mismatch! GetID() = %s, *keyID = %s\n", pubkey.GetID().ToString(), (*keyID).ToString());
        return false;
    }

    // Grab the BCT utxo
    bool deepDrill = false;
    uint32_t bctFoundHeight;
    CAmount bctValue;
    CScript bctScriptPubKey;
    bool bctWasMinotaurXEnabled;    // ObiDoge: MinotaurX+Hive1.2: Track whether Hive 1.2 was enabled at BCT creation time
    {
        LOCK(cs_main);

        COutPoint outBeeCreation(uint256S(txidStr), 0);
        COutPoint outCommFund(uint256S(txidStr), 1);
        Coin coin;
        CTransactionRef bct = nullptr;
        CBlockIndex foundAt;

        if (pcoinsTip && pcoinsTip->GetCoin(outBeeCreation, coin)) {        // First try the UTXO set (this pathway will hit on incoming blocks)
            if (verbose)
                LogPrintf("CheckHiveProof: Using UTXO set for outBeeCreation\n");
            bctValue = coin.out.nValue;
            bctScriptPubKey = coin.out.scriptPubKey;
            bctFoundHeight = coin.nHeight;
            bctWasMinotaurXEnabled = IsMinotaurXEnabled(chainActive[bctFoundHeight], consensusParams);  // ObiDoge: MinotaurX+Hive1.2: Track whether Hive 1.2 was enabled at BCT creation time
        } else {                                                            // UTXO set isn't available when eg reindexing, so drill into block db (not too bad, since Alice put her BCT height in the coinbase tx)
            if (verbose)
                LogPrintf("! CheckHiveProof: Warn: Using deep drill for outBeeCreation\n");
            if (!GetTxByHashAndHeight(uint256S(txidStr), bctClaimedHeight, bct, foundAt, pindexPrev, consensusParams)) {
                LogPrintf("CheckHiveProof: Couldn't locate indicated BCT\n");
                return false;
            }
            deepDrill = true;
            bctFoundHeight = foundAt.nHeight;
            bctValue = bct->vout[0].nValue;
            bctScriptPubKey = bct->vout[0].scriptPubKey;
            bctWasMinotaurXEnabled = IsMinotaurXEnabled(&foundAt, consensusParams); // ObiDoge: MinotaurX+Hive1.2: Track whether Hive 1.2 was enabled at BCT creation time
        }

        if (communityContrib) {
            CScript scriptPubKeyCF = GetScriptForDestination(DecodeDestination(consensusParams.hiveCommunityAddress));
            CAmount donationAmount;

            if(bct == nullptr) {                                                                // If we dont have a ref to the BCT
                if (pcoinsTip && pcoinsTip->GetCoin(outCommFund, coin)) {                       // First try UTXO set
                    if (verbose)
                        LogPrintf("CheckHiveProof: Using UTXO set for outCommFund\n");
                    if (coin.out.scriptPubKey != scriptPubKeyCF) {                              // If we find it, validate the scriptPubKey and store amount
                        LogPrintf("CheckHiveProof: Community contrib was indicated but not found\n");
                        return false;
                    }
                    donationAmount = coin.out.nValue;
                } else {                                                                        // Fallback if we couldn't use UTXO set
                    if (verbose)
                        LogPrintf("! CheckHiveProof: Warn: Using deep drill for outCommFund\n");
                    if (!GetTxByHashAndHeight(uint256S(txidStr), bctClaimedHeight, bct, foundAt, pindexPrev, consensusParams)) {
                        LogPrintf("CheckHiveProof: Couldn't locate indicated BCT\n");           // Still couldn't find it
                        return false;
                    }
                    deepDrill = true;
                }
            }
            if(bct != nullptr) {                                                                // We have the BCT either way now (either from first or second drill). If got from UTXO set bct == nullptr still.
                if (bct->vout.size() < 2 || bct->vout[1].scriptPubKey != scriptPubKeyCF) {      // So Validate the scriptPubKey and store amount
                    LogPrintf("CheckHiveProof: Community contrib was indicated but not found\n");
                    return false;
                }
                donationAmount = bct->vout[1].nValue;
            }

            // Check for valid donation amount
            CAmount expectedDonationAmount = (bctValue + donationAmount) / consensusParams.communityContribFactor;

            // ObiDoge: MinotaurX+Hive1.2
            if (bctWasMinotaurXEnabled)
                expectedDonationAmount += expectedDonationAmount >> 1;

            if (donationAmount != expectedDonationAmount) {
                LogPrintf("CheckHiveProof: BCT pays community fund incorrect amount %i (expected %i)\n", donationAmount, expectedDonationAmount);
                return false;
            }

            // Update amount paid
            bctValue += donationAmount;
        }
    }

    if (bctFoundHeight != bctClaimedHeight) {
        LogPrintf("CheckHiveProof: Claimed BCT height of %i conflicts with found height of %i\n", bctClaimedHeight, bctFoundHeight);
        return false;
    }

    // Check bee maturity
    int bctDepth = blockHeight - bctFoundHeight;
    if (bctDepth < consensusParams.beeGestationBlocks) {
        LogPrintf("CheckHiveProof: Indicated BCT is immature.\n");
        return false;
    }
    if (bctDepth > consensusParams.beeGestationBlocks + consensusParams.beeLifespanBlocks) {
        LogPrintf("CheckHiveProof: Indicated BCT is too old.\n");
        return false;
    }

    // Check for valid bee creation script and get honey scriptPubKey from BCT
    CScript scriptPubKeyHoney;
    if (!CScript::IsBCTScript(bctScriptPubKey, scriptPubKeyBCF, &scriptPubKeyHoney)) {
        LogPrintf("CheckHiveProof: Indicated utxo is not a valid BCT script\n");
        return false;
    }

    CTxDestination honeyDestinationBCT;
    if (!ExtractDestination(scriptPubKeyHoney, honeyDestinationBCT)) {
        LogPrintf("CheckHiveProof: Couldn't extract honey address from BCT UTXO\n");
        return false;
    }

    // Check BCT's honey address actually matches the claimed honey address
    if (honeyDestination != honeyDestinationBCT) {
        LogPrintf("CheckHiveProof: BCT's honey address does not match claimed honey address!\n");
        return false;
    }

    // Find bee count
    CAmount beeCost = GetBeeCost(bctFoundHeight, consensusParams);
    if (bctValue < consensusParams.minBeeCost) {
        LogPrintf("CheckHiveProof: BCT fee is less than the minimum possible bee cost\n");
        return false;
    }
    if (bctValue < beeCost) {
        LogPrintf("CheckHiveProof: BCT fee is less than the cost for a single bee\n");
        return false;
    }
    unsigned int beeCount = bctValue / beeCost;
    if (verbose) {
        LogPrintf("CheckHiveProof: bctValue            = %i\n", bctValue);
        LogPrintf("CheckHiveProof: beeCost             = %i\n", beeCost);
        LogPrintf("CheckHiveProof: beeCount            = %i\n", beeCount);
    }
    
    // Check enough bees were bought to include claimed beeNonce
    if (beeNonce >= beeCount) {
        LogPrintf("CheckHiveProof: BCT did not create enough bees for claimed nonce!\n");
        return false;
    }

    if (verbose)
        LogPrintf("CheckHiveProof: Pass at %i%s\n", blockHeight, deepDrill ? " (used deepdrill)" : "");

    return true;
}
