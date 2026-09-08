// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>
#include <consensus/merkle.h>
#include <arith_uint256.h>

#include <tinyformat.h>
#include <util.h>
#include <utilstrencodings.h>
#include <base58.h> // ObiDoge: Needed for DecodeDestination()
#include <stdio.h>


#include <assert.h>
#include <limits>

#include <chainparamsseeds.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "NY Times 05/Oct/2011 Steve Jobs, Apple’s Visionary, Dies at 56";
    const CScript genesisOutputScript = CScript() << ParseHex("040184710fa689ad5023690c80f3a49c8f13f8d45b8c857fbcbc8bc4a8e4d3eb4b10f4d4604fa08dce601aaf0f470216fe1b51850b4acf21b179c45070ac7b03a9") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    consensus.vDeployments[d].nStartTime = nStartTime;
    consensus.vDeployments[d].nTimeout = nTimeout;
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 1051200;   // ObiDoge mainnet: ~2 years @ 60s blocks
        // Supply note: with 475 OBD initial reward and this halving interval, the geometric max mint is 998,640,000 OBD (no tail).
        consensus.BIP16Height = 218579; // 87afb798a3ad9378fcd56123c81fb31cfd9a8df4719b9774d71730c16315a092 - October 1, 2012
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 918684; // bab3041e8977e0dc3eeff63fe707b92bde1dd449d8efafb248c27c8264cc311a
        consensus.BIP66Height = 811879; // 7aceee012833fa8952f8835d8b1b3ae233cd6ab08fdb27a771d2bd7bdc491894
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 60 * 60;   // 1 hour (legacy field; LWMA controls actual adjustment)
        consensus.nPowTargetSpacing = 60;          // 60 seconds per block
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 6048; // 75% of 8064
        consensus.nMinerConfirmationWindow = 8064; // nPowTargetTimespan / nPowTargetSpacing * 4
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // Deployment of BIP68, BIP112, and BIP113.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // Deployment of SegWit (BIP141, BIP143, and BIP147)
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // ObiDoge: Hive: Deployment
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].bit = 7;
        // OBD: HIVE permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // ObiDoge: Hive 1.1: Deployment
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].bit = 9;
        // OBD: HIVE 1 1 permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // ObiDoge: MinotaurX+Hive1.2: Deployment
//         consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].bit = 7;
        // OBD: MINOTAURX permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // ObiDoge: Rialto: Deployment
//         consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].bit = 9;
        // OBD: RIALTO permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // ObiDoge fields
        consensus.powForkTime = 1518982404;                 // Time of PoW hash method change
        consensus.lastScryptBlock = 1371111;                // Height of last scrypt block
        consensus.powLimitSHA = uint256S("00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff");   // Initial hash target at fork
        consensus.slowStartBlocks = 2000;                   // Scale post-fork block reward up over this many blocks
        consensus.premineAmount = 550000;                   // Premine amount (less than 1% of issued currency at fork time)
        std::vector<unsigned char> vch = ParseHex("76a914c9f3305556963e2976ccf3348b89a6cc736b6a4e88ac");
        consensus.premineOutputScript = CScript(vch.begin(), vch.end());	// Output script for premine block (CashierDaZEsyBQkuvv4c2uPZFx6m2XTgT)
        consensus.totalMoneySupplyHeight = 6215968;         // Height at which TMS is reached, do not issue rewards past this point

        // ObiDoge: Hive: Consensus Fields
        consensus.minBeeCost = 10000;                       // Minimum cost of a bee, used when no more block rewards
        consensus.beeCostFactor = 2500;                     // Bee cost is block_reward/beeCostFactor
        // ObiDoge: Hive/bee mechanics disabled; keep a placeholder to satisfy structs.
        consensus.beeCreationAddress = ""; // unused
        consensus.hiveCommunityAddress = "CashCFfv8CmdWo6wyMGQWtmQnaToyhgsWr";      // Community fund address
        consensus.communityContribFactor = 10;              // Optionally, donate bct_value/maxCommunityContribFactor to community fund
        consensus.beeGestationBlocks = 48*24;               // The number of blocks for a new bee to mature
        consensus.beeLifespanBlocks = 48*24*14;             // The number of blocks a bee lives for after maturation
        consensus.powLimitHive = uint256S("0fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");  // Highest (easiest) bee hash target
        consensus.minHiveCheckBlock = std::numeric_limits<int>::max(); // Hive disabled
        consensus.hiveTargetAdjustAggression = 30;          // Snap speed for bee hash target adjustment EMA
        consensus.hiveBlockSpacingTarget = 0;               // Hive disabled
        consensus.hiveBlockSpacingTargetTypical = 0;        // Hive disabled
        consensus.hiveBlockSpacingTargetTypical_1_1 = 0;    // Hive disabled
        consensus.hiveNonceMarker = 192;                    // Nonce marker for hivemined blocks

        // ObiDoge: Hive 1.1-related consensus fields
        consensus.minK = 2;                                 // Minimum chainwork scale for Hive blocks (see Hive whitepaper section 5)
        consensus.maxK = 16;                                // Maximum chainwork scale for Hive blocks (see Hive whitepaper section 5)
        consensus.maxHiveDiff = 0.006;                      // Hive difficulty at which max chainwork bonus is awarded
        consensus.maxKPow = 5;                              // Maximum chainwork scale for PoW blocks
        consensus.powSplit1 = 0.005;                        // Below this Hive difficulty threshold, PoW block chainwork bonus is halved
        consensus.powSplit2 = 0.0025;                       // Below this Hive difficulty threshold, PoW block chainwork bonus is halved again
        consensus.maxConsecutiveHiveBlocks = 0;             // Hive disabled
        consensus.hiveDifficultyWindow = 36;                // How many blocks the SMA averages over in hive difficulty adjust

        // ObiDoge: MinotaurX+Hive1.2-related consensus fields
        consensus.lwmaAveragingWindow = 60;                 // Averaging window size for LWMA diff adjust
        consensus.powTypeLimits.emplace_back(uint256S("0x00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"));   // sha256d limit
        consensus.powTypeLimits.emplace_back(uint256S("0x0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"));   // MinotaurX limit

        // ObiDoge: Rialto-related consensus fields
        // Note: These are *NOT* finalised.
        consensus.nickCreationAddress       = "CashCFfv8CmdWo6wyMGQWtmQnaToyhgsWr";     // Nick creation address
        consensus.nickCreationCost3Char     = 1000000000000;                            // Minimum costs to register a nick
        consensus.nickCreationCost4Char     = 100000000000;
        consensus.nickCreationCostStandard  = 1000000000;
        consensus.nickCreationAntiDust      = 10000;                                    // Portion of creation cost burnt in 2nd output

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");  // ObiDoge: 1695238

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00"); // ObiDoge: 1695238

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0x4f; // 'O'
        pchMessageStart[1] = 0x42; // 'B'
        pchMessageStart[2] = 0x44; // 'D'
        pchMessageStart[3] = 0x21; // '!'
        nDefaultPort = 29445;      // ObiDoge mainnet P2P
        nPruneAfterHeight = 100000;
// =============================================================
// ObiDoge MAINNET GENESIS — LOCKED (DO NOT CHANGE)
// =============================================================
genesis = CreateGenesisBlock(1765929600, 4, 0x207fffff, 1, 475 * COIN * COIN_SCALE);
consensus.hashGenesisBlock = genesis.GetHash();

assert(consensus.hashGenesisBlock == uint256S("0x2dfb24e7c17ca31dac896611e9796ab8d05cde9bc5ec12f5ad48002eeb78b976"));
assert(genesis.hashMerkleRoot == uint256S("0x98750938fbebd8b1a7751e76b46f5334e67c886db062dc7be88c955ff2a248e1"));
LogPrintStr(strprintf("MAINNET genesis hash=%s\n", consensus.hashGenesisBlock.ToString()));
LogPrintStr(strprintf("MAINNET genesis merkle=%s\n", genesis.hashMerkleRoot.ToString()));

// TODO(MAINNET LOCK): Replace this mining mode with strict asserts:
// assert(consensus.hashGenesisBlock == uint256S("0x..."));
// assert(genesis.hashMerkleRoot == uint256S("0x..."));
// Note that of those with the service bits flag, most only support a subset of possible options
        // === DNS Seeds (Mainnet) ===
        // Keep DNS seeds if you want, but DO NOT rely on them exclusively.
        // If DNS returns 0 (common on brand-new networks), vFixedSeeds MUST be populated
        // so fresh wallets can connect without reminding users to edit obidoge.conf.
        vSeeds.clear();
        vSeeds.emplace_back("seed1.obidoge.xyz", "seed1.obidoge.xyz");
        vSeeds.emplace_back("seed2.obidoge.xyz", "seed2.obidoge.xyz");
        vSeeds.emplace_back("seed3.obidoge.xyz", "seed3.obidoge.xyz");

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 115);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 85);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,50);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 176);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "obd";

                // === Fixed Seeds (Mainnet) ===
        // These are hard-coded "last resort" peers. They are only used if DNS seeding yields no addrs.
        // IMPORTANT: Keep these as stable, long-lived nodes with port 29445 open.
        vFixedSeeds = {
            // 162.196.40.170:29445
            {{0,0,0,0,0,0,0,0,0,0,0xff,0xff,162,196,40,170}, 29445},
            // 99.144.175.120:29445
            {{0,0,0,0,0,0,0,0,0,0,0xff,0xff, 99,144,175,120}, 29445},
            // 80.80.109.43:29445
            {{0,0,0,0,0,0,0,0,0,0,0xff,0xff, 80, 80,109, 43}, 29445},
        };


        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;

        checkpointData = {{ {0, consensus.hashGenesisBlock} }};

        chainTxData = ChainTxData{0, 0, 0.0};
    }
};

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";

        // === Consensus (ObiDoge testnet) ===
        consensus.nSubsidyHalvingInterval = 1051200;   // same as mainnet (about 2 years)
        consensus.BIP16Height = 0;                     // always enforce BIP16
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;

        // ObiDoge testnet: use same powLimit and retarget logic as mainnet (no special min-difficulty blocks)
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan      = 60 * 60;   // 1 hour
        consensus.nPowTargetSpacing       = 60;        // 60 seconds per block

        // ObiDoge: MinotaurX difficulty adjustment parameters (match mainnet)
        consensus.lwmaAveragingWindow = 60;                 // Averaging window size for LWMA diff adjust
        consensus.powTypeLimits.emplace_back(uint256S("0x00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff"));   // sha256d limit (legacy)
        consensus.powTypeLimits.emplace_back(uint256S("0x0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"));   // MinotaurX limit

        consensus.fPowAllowMinDifficultyBlocks = false; // no easy blocks; behaves like mainnet
        consensus.fPowNoRetargeting             = false;

        consensus.nRuleChangeActivationThreshold = 1512; // 75% of 2016
        consensus.nMinerConfirmationWindow       = 2016;

        // BIP deployments: keep TESTDUMMY but with open-ended window
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime =  0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout   = Consensus::BIP9Deployment::NO_TIMEOUT;


        // === BIP9 deployments (pool/GBT readiness) ===
        // ObiDoge testnet: make modern softfork rules always-on so GBT advertises them properly.
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout   = Consensus::BIP9Deployment::NO_TIMEOUT;

        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout   = Consensus::BIP9Deployment::NO_TIMEOUT;

        // Hive-era deployments are permanently disabled on ObiDoge (MinotaurX-only).
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].bit = 7;
        // OBD: HIVE permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE].nTimeout   = Consensus::BIP9Deployment::NO_TIMEOUT;

//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].bit = 9;
        // OBD: HIVE 1 1 permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_HIVE_1_1].nTimeout   = Consensus::BIP9Deployment::NO_TIMEOUT;

        // Kept for enum/compat: disabled on ObiDoge.
//         consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].bit = 7;
        // OBD: MINOTAURX permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_MINOTAURX].nTimeout   = Consensus::BIP9Deployment::NO_TIMEOUT;

        // Kept for enum/compat: disabled on ObiDoge.
//         consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].bit = 9;
        // OBD: RIALTO permanently disabled (Hive removed).
        consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nTimeout = 0; // immediate timeout => never activates
//         consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nStartTime = 0;
//         consensus.vDeployments[Consensus::DEPLOYMENT_RIALTO].nTimeout   = Consensus::BIP9Deployment::NO_TIMEOUT;
        // === Message start / ports ===
        pchMessageStart[0] = 0x0b;
        pchMessageStart[1] = 0x11;
        pchMessageStart[2] = 0x09;
        pchMessageStart[3] = 0x07;
        nDefaultPort       = 24445;     // ObiDoge testnet P2P port

        nPruneAfterHeight  = 1000;


        // === FINAL TESTNET GENESIS (NO MINER) ===
        genesis = CreateGenesisBlock(
            1765381000,   // nTime
            2,            // nNonce
            0x1f00ffff,   // nBits (harder start; closer to mainnet-like mining)
            1,
            50 * COIN
        );
        consensus.hashGenesisBlock = genesis.GetHash();

        // NOTE: testnet genesis hash will change if you change nBits/nNonce.
        // If you plan to publish testnet publicly, re-mine genesis and restore strict asserts.
// === Seeds ===
        vFixedSeeds.clear();
        vSeeds.clear();
        // You can add real seeds later, e.g.:
        // vSeeds.emplace_back("testnet-seed1.obidoge.net", true);

        // === Address prefixes (visibly different from mainnet) ===
        base58Prefixes[PUBKEY_ADDRESS]  = std::vector<unsigned char>(1, 111); // 'm' or 'n'
        base58Prefixes[SCRIPT_ADDRESS]  = std::vector<unsigned char>(1, 196); // '2'
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1, 58);
        base58Prefixes[SECRET_KEY]      = std::vector<unsigned char>(1, 239);

        base58Prefixes[EXT_PUBLIC_KEY]  = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY]  = {0x04, 0x35, 0x83, 0x94};

        // Bech32 HRP (if you have bech32 enabled)
        bech32_hrp = "tobd"; // testnet ObiDoge

        // === Misc chain settings ===
        fDefaultConsistencyChecks = false;
        fRequireStandard          = false;
        fMineBlocksOnDemand       = false;

        checkpointData = {
            {
                {0, consensus.hashGenesisBlock},
            }
        };

        chainTxData = ChainTxData{
            0,    // unix time of last known checkpoint block
            0,    // total number of transactions up to that block
            0.0   // estimated tx/day after that block
        };
    }
};
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP16Height = 0; // always enforce P2SH BIP16 on regtest
        consensus.BIP34Height = 100000000; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1351; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 1251; // BIP66 activated on regtest (Used in rpc activation tests)
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 3.5 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 2.5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].bit = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_CSV].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].bit = 1;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_SEGWIT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // ObiDoge fields
        consensus.powForkTime = 1543765622;                 // Time of PoW hash method change (block 100)
        consensus.lastScryptBlock = 200;                    // Height of last scrypt block
        consensus.powLimitSHA = uint256S("000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");   // Initial hash target at fork
        consensus.slowStartBlocks = 40;                     // Scale post-fork block reward up over this many blocks
        consensus.premineAmount = 550000;                   // Premine amount (less than 1% of issued currency at fork time)
        std::vector<unsigned char> vch = ParseHex("76a91424af51d38b740a6dc2868dfd70fc16d76901e1e088ac");
        consensus.premineOutputScript = CScript(vch.begin(), vch.end());	// Output script for premine block (tAGaQ7rk3NE7etu3bU6yAJF3KSKeDhTHry)
        consensus.totalMoneySupplyHeight = 6215968;         // Height at which TMS is reached, do not issue rewards past this point (Note, not accurate value for testnet)
        consensus.hiveNonceMarker = 192;                    // Nonce marker for hivemined blocks

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        nDefaultPort = 19444;
        nPruneAfterHeight = 1000;

         genesis = CreateGenesisBlock(1765380000, 6, 0x207fffff, 1, 50 * COIN * COIN_SCALE);
        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock ==
               uint256S("0xe8d727636286c0857c2557fcd1a3727dd7f71d2966ea775a7c080af1bc6f90d8"));
        assert(genesis.hashMerkleRoot ==
               uint256S("0x97ddfbbae6be97fd6cdf3e7ca13232a3afff2353e29badfab7f73011edd4ced9"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;

        checkpointData = {
            {
                {0, uint256S("530827f38f93b43ed12af0b3ad25a288dc02ed74d6d7857862df51fc56c416f9")}
            }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SCRIPT_ADDRESS2] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "rlcc";
    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout);
}
