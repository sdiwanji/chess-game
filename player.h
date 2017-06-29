//
//  player.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef player_h
#define player_h


#include <cstdlib>
#include <string>
#include "piece.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include "coords.h"
#include <cassert>
using namespace std;

class player{
private:
    
    string name;
    bool king_alive;
    int p_number;
    
public:
    
    vector<piece *> pieces;

    
    player(string n, int player_number){
        king_alive = true;
        
        name = n;
        p_number = player_number;
        
        if (p_number == 1){
            for (int i = 0;  i < 8; ++i){
                pawn * p = new pawn(p_number, i, 1);
                pieces.push_back(p);
            }
        } else if (p_number == 2){
            for (int i = 0;  i < 8; ++i){
                pawn * p = new pawn(p_number, i, 6);
                pieces.push_back(p);
            }
        }
        
        
        if (p_number == 1){
            rook * r = new rook(p_number, 0, 0);
            pieces.push_back(r);
            rook * ro = new rook(p_number, 7, 0);
            pieces.push_back(ro);
        } else if (p_number == 2){
            rook * r = new rook(p_number, 0, 7);
            pieces.push_back(r);
            rook * ro = new rook(p_number, 7, 7);
            pieces.push_back(ro);
        }
        
        if (p_number == 1){
            knight * r = new knight(p_number, 1, 0);
            pieces.push_back(r);
            knight * ro = new knight(p_number, 6, 0);
            pieces.push_back(ro);
        } else if (p_number == 2){
            knight * r = new knight(p_number, 1, 7);
            pieces.push_back(r);
            knight * ro = new knight(p_number, 6, 7);
            pieces.push_back(ro);
        }
        
        
        if (p_number == 1){
            bishop * b = new bishop(p_number, 2, 0);
            pieces.push_back(b);
            bishop * bish = new bishop(p_number, 5, 0);
            pieces.push_back(bish);
        } else if (p_number == 2){
            bishop * b = new bishop(p_number, 2, 7);
            pieces.push_back(b);
            bishop * bish = new bishop(p_number, 5, 7);
            pieces.push_back(bish);
        }
        
        if (p_number == 1){
            queen * q = new queen(p_number, 3, 0);
            king * k = new king(p_number, 4, 0);
            pieces.push_back(q);
            pieces.push_back(k);
        } else if (p_number == 2){
            queen * q = new queen(p_number, 3, 7);
            king * k = new king(p_number, 4, 7);
            pieces.push_back(q);
            pieces.push_back(k);
        }
        
        assert(pieces.size() == 16);
        
    }
    
    string get_name(){
        return name;
    }
        
    int get_number(){
        return p_number;
    }
    
    void piece_die(int ind){
        delete pieces[ind];
        pieces[ind] = nullptr;
        if (ind == 15){
            king_alive = false;
        }
        
    }
    
    bool king_is_alive(){
        return king_alive;
    }
    
    ~player(){
        for (int i = 0; i < pieces.size(); ++i){
            delete pieces[i];
        }
    }
    
    
    
    
};

#endif /* player_h */
