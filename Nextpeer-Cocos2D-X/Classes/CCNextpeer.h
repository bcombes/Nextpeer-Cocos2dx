//
//  Created by Nextpeer development team.
//  Copyright (c) 2013 Nextpeer, Inc. All rights reserved.
//

#ifndef ___CCNEXTPEER_H
#define ___CCNEXTPEER_H

#include "stdint.h"
#include <string>

// Extra includes for anyone that uses this header file
#include "NextpeerNotifications.h"

namespace nextpeer
{
    class CCNextpeer
    {
    public:
        /** @name General **/
        
        /**
         Retrieves the current global instance of Nextpeer
         */
        static CCNextpeer* getInstance();
        
        /**
         Initializes the SDK using your app's parameters
         */
        virtual void initialize(const char* apiKey) {};
        
        /**
         Launches the Nextpeer UI
         */
        virtual void launchDashboard() {};
        
        /** @name Tournament Management **/
        
        /**
         This method is used to push a buffer to the other players.
         This can potentially be used to create custom notifications or some other interactive mechanism that incorporates the other players.
         @param pBuffer. This is the buffer you wish to send to the other players
         @param length. The length of the buffer
         @note  The buffer will be sent to the other players and will activate the corresponding callback method on their end.
         */
        virtual void pushDataToOtherPlayers(void* pBuffer, uint32_t length) {};
        
        /**
         This method is used to push a buffer to the other players using the unreliable data channel.
         This can potentially be used to create custom notifications or some other interactive mechanism that incorporates the other players.
         Note that there is no gurantee that this message will reach some or all the players.
         @param pBuffer. This is the buffer you wish to send to the other players
         @param length. The length of the buffer
         @note  The buffer will be sent to the other players and will activate the corresponding callback method on their end.
         */
        virtual void unreliablePushDataToOtherPlayers(void* pBuffer, uint32_t length) {};

        /**
         Call this method to report the current score for the tournament. 
         This allows Nextpeer to send various notifications about the players' scores.
         @param score The player's current score
         */
        virtual void reportScoreForCurrentTournament(uint32_t score) {};
        
        /**
         Call this method when your game manage the current tournament and the player just died (a.k.a. 'Last Man Standing').
         Nextpeer will call NextpeerDelegate's nextpeerDidTournamentEnd method after reporting the last score.
         @param score The player's final score for this particular tournament.
         @note: The method will act only if the current tournament is from 'GameControlled' tournament type
         */
        virtual void reportControlledTournamentOverWithScore(uint32_t score) {};
        
        /**
         Call this method to check if any tournament is running at the moment.
         */
        virtual bool isCurrentlyInTournament() { return false; };
        
        /**
         Call this method when the user wishes to exit the current tournament.
         @note This will close any in-game notifiactions and dialogs.
         */
        virtual void reportForfeitForCurrentTournament() {};

        /**
         This method will return the amount of seconds left for this tournament.
         @note: If no tournament is currently taking place then this method will return 0.
         */
        virtual uint32_t timeLeftInTournament() { return 0; }
        
        /**
         This method will return the Nextpeer ID for the current player
         */
        virtual std::string getCurrentPlayerId() { return string(""); }
        
        /**
         This method will return the name of the current player
         */
        virtual std::string getCurrentPlayerName() { return string(""); }

    private:
        static CCNextpeer* sharedInstance;
        CCNextpeer(CCNextpeer const&);
        CCNextpeer& operator=(CCNextpeer const &);

    protected:
        CCNextpeer();
        virtual ~CCNextpeer();


    };
};


#endif //___CCNEXTPEER_H