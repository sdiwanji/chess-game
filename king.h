//
//  king.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef king_h
#define king_h



#include <cstdlib>
#include <string>
#include "coords.h"
using namespace std;

class king: public piece{
private:
    vector <coords> opts;
    
public:
    
    king(int player_number, int x_p, int y_p){
        piece::player_num = player_number;
        piece::coord.x = x_p;
        piece::coord.y = y_p;
    }
    
    vector<coords> move_opts(piece * one, piece * two, piece * three, piece * four, piece * five, piece * six, piece * seven, piece * eight, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h){ // requires knowledge of position of other pieces
        
        vector<coords> ret_vec;
        
        
        coords cam_a, cam_b, cam_c, cam_d, cam_e, cam_f, cam_g, cam_h;
        cam_a = this->coord;
        cam_b = this->coord;
        cam_c = this->coord;
        cam_d = this->coord;
        cam_e = this->coord;
        cam_f = this->coord;
        cam_g = this->coord;
        cam_h = this->coord;
        
        if (a){
            if (one && one->player_num != this->player_num){
                ++cam_a.y;
                ret_vec.push_back(cam_a);
            } else if (!one){
                ++cam_a.y;
                ret_vec.push_back(cam_a);
            }
        }
        
        if (b){
            if ( two && two->player_num != this->player_num){
                ++cam_b.y;
                ++cam_b.x;
                ret_vec.push_back(cam_b);
            } else if (!two){
                ++cam_b.y;
                ++cam_b.x;
                ret_vec.push_back(cam_b);
            }
        }
        
        if (c){
            if (three && three->player_num != this->player_num){
                ++cam_c.x;
                ret_vec.push_back(cam_c);
            } else if (!three){
                ++cam_c.x;
                ret_vec.push_back(cam_c);
            }
            
        }
        if (d){
            if (four && four->player_num != this->player_num){
                ++cam_d.x;
                --cam_d.y;
                ret_vec.push_back(cam_d);
            } else if (!four){
                ++cam_d.x;
                --cam_d.y;
                ret_vec.push_back(cam_d);
            }
            
        }
        if (e){
            if (five && five->player_num != this->player_num){
                --cam_e.y;
                ret_vec.push_back(cam_e);
            } else if (!five){
                --cam_e.y;
                ret_vec.push_back(cam_e);
            }
            
        }
        if (f){
            if (six && six->player_num != this->player_num){
                --cam_f.x;
                --cam_f.y;
                ret_vec.push_back(cam_f);
            } else if (!six){
                --cam_f.x;
                --cam_f.y;
                ret_vec.push_back(cam_f);
            }
            
        }
        if (g){
            if (seven && seven->player_num != this->player_num){
                --cam_g.x;
                ret_vec.push_back(cam_g);
            } else if (!seven){
                --cam_g.x;
                ret_vec.push_back(cam_g);
            }
            
        }
        if (h){
            if (eight && eight->player_num != this->player_num){
                --cam_h.x;
                ++cam_h.y;
                ret_vec.push_back(cam_h);
            } else if (!eight) {
                --cam_h.x;
                ++cam_h.y;
                ret_vec.push_back(cam_h);
            }
            
        }
        
        opts = ret_vec;
        return ret_vec;
    }
    
    
    void play(int opt_num){
        this->coord = opts[opt_num];
    }
    
    coords get_coords(){
        return piece::coord;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d){
        vector <coords> x;
        return x;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, bool x, bool y, bool z, bool xyz){
        vector<coords> ryan;
        return ryan;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h, bool x, bool y, bool z, bool xyz){
        vector<coords> ryan;
        return ryan;
    }
    
    ~king(){
        
    }

    
};

#endif /* king_h */
