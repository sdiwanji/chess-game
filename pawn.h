//
//  pawn.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef pawn_h
#define pawn_h


#include <cstdlib>
#include <string>
#include "coords.h"
using namespace std;

class pawn: public piece{
private:
    bool first_move;
    
public:
    
    pawn(int player_number, int x_p, int y_p){
        piece::player_num = player_number;
        first_move = true;
        piece::coord.x = x_p;
        piece::coord.y = y_p;
        
    }
    
    vector<coords> move_opts(piece * two_ahead, piece * one_ahead, piece * one_and_left, piece * one_and_right){ // requires knowledge of position of other pieces
        
        opts.clear();
        vector<coords> ret_vec;
        
        if (two_ahead == nullptr && first_move == true){
                coords c;
                c = coord;
                if (player_num == 1){
                    c.y = coord.y + 2;
                } else {
                    c.y = coord.y - 2;
                }
            
                ret_vec.push_back(c);
            
        }
        
        if (one_ahead == nullptr && ((coord.y < 7 && player_num == 1) || (coord.y > 0 && player_num == 2))){
            coords c;
            c = coord;
            if (player_num == 1 && c.y <= 6){
                c.y = coord.y + 1;
            } else if (player_num == 2 && c.y >= 1){
                c.y = coord.y - 1;
            }
            
            ret_vec.push_back(c);
            
        }
        
        if (one_and_left == nullptr){

        } else if ( one_and_left->player_num != this->player_num){
            coords c = one_and_left->coord;
            ret_vec.push_back(c);
        }
        
        
        
        if (one_and_right == nullptr){

        } else if ( one_and_right->player_num  != this->player_num){
            coords c = one_and_right->coord;
            ret_vec.push_back(c);
        }
        
        opts = ret_vec;
        first_move = false;
        return ret_vec;
        
    }
    
    
    virtual void play(int opt_num){
        coord = opts[opt_num];
        opts.clear();
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h, bool x, bool y, bool z, bool xyz, bool abc, bool foo, bool bar, bool foobar) {
        vector<coords> ryan;
        return ryan;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, bool x, bool y, bool z, bool xyz){
        vector<coords> ryan;
        return ryan;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h, bool x, bool y, bool z, bool xyz){
        vector<coords> ryan;
        return ryan;
    }
    
    coords get_coords(){
        return coord;
    }
    
    ~pawn(){
        
    }
    
    
};

#endif /* pawn_h */
