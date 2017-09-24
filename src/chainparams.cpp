#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        
        pchMessageStart[0] = 0x4f;
        pchMessageStart[1] = 0x64; 
        pchMessageStart[2] = 0x6e; 
        pchMessageStart[3] = 0x31; 
        vAlertPubKey = ParseHex("0486bce1bac0d543f104cbff2bd23680056a3b9ea05e1137d2ff90eeb5e08472eb500322593a2cb06fbf8297d7beb6cd30cb90f98153b5b7cce1493749e41e0284");
        nDefaultPort = 56660;
        nRPCPort = 56661;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 24);

 
        const char* pszTimestamp = "https://en.wikipedia.org/w/index.php?title=Brave_New_World&id=796766418";
        int64_t genesisTime = 1503532800; // 08/24/2017 @ 12:00am (UTC)

        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, genesisTime, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = genesisTime;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 36151509;

        

        hashGenesisBlock = genesis.GetHash();
 
        
        assert(hashGenesisBlock == uint256("0x0000006dd8a92f58e952fa61c9402b74a381a69d1930fb5cc12c73273fab5f0a"));
        assert(genesis.hashMerkleRoot == uint256("0x062e0ef40ca83213f645710bf497cc68220d42ac2254d31bbc8fb64a4d207209"));


        vSeeds.push_back(CDNSSeedData("Seednode1", "obsidianblockchain1.westeurope.cloudapp.azure.com"));
        vSeeds.push_back(CDNSSeedData("Seednode2", "obsidianblockchain2.westeurope.cloudapp.azure.com"));
        vSeeds.push_back(CDNSSeedData("Seednode3", "obsidianseednode1.westeurope.cloudapp.azure.com"));
        vSeeds.push_back(CDNSSeedData("Seednode4", "seed1.obsidianplatform.com:8080"));
        vSeeds.push_back(CDNSSeedData("Seednode5", "seed2.obsidianplatform.com:8080"));
        
 
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 75); 
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125); 
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, (75+128));
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xC2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0xDD).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 12500; 
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        
        pchMessageStart[0] = 0x71;
        pchMessageStart[1] = 0x31;
        pchMessageStart[2] = 0x21;
        pchMessageStart[3] = 0x11;
        
        vAlertPubKey = ParseHex("0471dc165db490094d35cde15b1f5d755fa6ad6f2b5ed0f340e3f17f57389c3c2af113a8cbcc885bde73305a553b5640c83021128008ddf882e856336269080496");
        nDefaultPort = 26178;
        nRPCPort = 26174;

        strDataDir = "testnet";

       
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 7517202;
      
        hashGenesisBlock = genesis.GetHash();
         
       
        assert(hashGenesisBlock == uint256("0x00000022fa47e5dcb5f9279a8e8631bf42da1f0b7076b9e8e6206549c82d5a44"));
        assert(genesis.hashMerkleRoot == uint256("0x062e0ef40ca83213f645710bf497cc68220d42ac2254d31bbc8fb64a4d207209"));
        
        vFixedSeeds.clear();
        vSeeds.clear();
        

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 115); 
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 65 + 128);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xbf;
        pchMessageStart[2] = 0xb5;
        pchMessageStart[3] = 0xda;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20); 
        
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
       
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";
       
        assert(hashGenesisBlock == uint256("0x00000022fa47e5dcb5f9279a8e8631bf42da1f0b7076b9e8e6206549c82d5a44"));
         assert(genesis.hashMerkleRoot == uint256("0x062e0ef40ca83213f645710bf497cc68220d42ac2254d31bbc8fb64a4d207209"));

        vSeeds.clear();  
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
