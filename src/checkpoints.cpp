// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"


static const int nCheckpointSpan = 500;

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    // static MapCheckpoints mapCheckpoints;
    
   
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (  0,     uint256("0x0000006dd8a92f58e952fa61c9402b74a381a69d1930fb5cc12c73273fab5f0a") )
        (  2,     uint256("0x17b087e575d964713fec1675ff8717a897f6cdd0f3c1d4a349344f6cef46f390") ) // Premine
        ( 50,     uint256("0x0fe7816158329b68bd37d15a207859cec29bb2ac714e791d637436894de17d20") )
        ( 100,    uint256("0x242863f086d9486cc6975e67432ffb0f9082eb7114b7c1940d91f336bc49e81c") )
        ( 1500,    uint256("0xad1ef03fb2f9dc0b922512aec2c781c2a4bbe191d3848e91708ea563ce188572") )
        ( 7500, uint256("0x06c806477a0d20f28eaba5af07ec74094a53c87e485fa0aebbf20c3510538204") ) // v1.0.0.5
        ( 11609, uint256("0xd1f48253818b90057d7ae176f8128459158a097a435956509ae9cb9509f72593") ) // v1.0.0.6
        ( 32100, uint256("0x15a792c680bf348b2a73be99adaf6cd9890be4f1a3895a800f212a43c0232c8b")) // v1.0.0.7, 1st source release
    ;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        if (checkpoints.empty())
            return 0;
        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // Automatically select a suitable sync-checkpoint 
    const CBlockIndex* AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && pindex->nHeight + nCheckpointSpan > pindexBest->nHeight)
            pindex = pindex->pprev;
        return pindex;
    }

    // Check against synchronized checkpoint
    bool CheckSync(int nHeight)
    {
        const CBlockIndex* pindexSync = AutoSelectSyncCheckpoint();

        if (nHeight <= pindexSync->nHeight)
            return false;
        return true;
    }
}
