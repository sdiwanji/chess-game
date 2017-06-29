//
//  knight.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef knight_h
#define knight_h


#include <cstdlib>
#include <string>
#include "coords.h"
using namespace std;

class knight: public piece{
private:
    vector <coords> opts;
    
public:
    
    knight(int pnum, int x_p, int y_p){
        piece::coord.x = x_p;
        piece::coord.y = y_p;
        piece::player_num = pnum;
    }
    
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d){
        vector <coords> x;
        return x;
    }
    
    vector<coords> move_opts(piece * one, piece * two, piece * three, piece * four, piece * five, piece * six, piece * seven, piece * eight, bool one_b, bool two_b, bool three_b, bool four_b, bool five_b, bool six_b, bool seven_b, bool eight_b){ // requires knowledge of position of other pieces
        
        vector<coords> ret_vec;
        

        coords cam;
        
        if (one_b && (one == nullptr || one->player_num != this->player_num)){
            cam = coord;
            --cam.x;
            cam.y += 2;
            ret_vec.push_back(cam);
        }
        
        if (two_b && (two == nullptr || two->player_num != this->player_num)){
            cam = coord;
            ++cam.x;
            cam.y += 2;
            ret_vec.push_back(cam);
        }
        if (three_b && (three == nullptr || three->player_num != this->player_num)){
            cam = coord;
            cam.x += 2;
            cam.y += 1;
            ret_vec.push_back(cam);
        }
        if (four_b && (four == nullptr || four->player_num != this->player_num)){
            cam = coord;
            cam.x += 2;
            cam.y -= 1;
            ret_vec.push_back(cam);
        }
        
        if (five_b && (five == nullptr || five->player_num != this->player_num)){
            cam = coord;
            cam.x += 1;
            cam.y -= 2;
            ret_vec.push_back(cam);
        }
        
        if (six_b && (six == nullptr || six->player_num != this->player_num)){
            cam = coord;
            cam.x -= 1;
            cam.y -= 2;
            ret_vec.push_back(cam);
        }
        
        if (seven_b && (seven == nullptr || seven->player_num != this->player_num)){
            cam = coord;
            cam.x -= 2;
            cam.y -= 1;
            ret_vec.push_back(cam);
        }
        if (eight_b && (eight == nullptr || eight->player_num != this->player_num)){
            cam = coord;
            cam.x -= 2;
            cam.y += 1;
            ret_vec.push_back(cam);
        }
        
        opts = ret_vec;
        return ret_vec;
    }
    
    
    void play(int opt_num){
        piece::coord = opts[opt_num];
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
        return piece::coord;
    }
    
    ~knight(){
        
    }
    

};

#endif /* knight_h */
