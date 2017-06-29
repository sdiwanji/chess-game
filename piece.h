//
//  piece.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef piece_h
#define piece_h

#include <cstdlib>
#include <string>
#include "coords.h"
using namespace std;


//pure virtual class intended to provide structure for pieces : pawn, rook, knight, bishop, queen, king


class piece{
public:
    coords coord;
    int player_num;
    string name;
    vector <coords> opts;
    
    void set_name(string nam){
        name = nam;
    }
    
    string get_name(){
        return name;
    }
    
    coords get_coords(){
        return piece::coord;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d) = 0;

    //virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h) = 0;

    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h, bool x, bool y, bool z, bool xyz) = 0;

    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, bool x, bool y, bool z, bool xyz) = 0;
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h, bool x, bool y, bool z, bool xyz, bool abc, bool foo, bool bar, bool foobar) = 0;
    
    
    virtual ~piece(){
        
    }
    
    virtual void play(int opt_num) = 0;

    
};


#endif /* piece_h */
