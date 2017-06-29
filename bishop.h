//
//  bishop.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef bishop_h
#define bishop_h


#include <cstdlib>
#include <string>
#include "coords.h"
using namespace std;

class bishop: public piece{
private:
    vector <coords> opts;
    
public:
    
    bishop(int player_number, int x_p, int y_p){
        coord.x = x_p;
        coord.y = y_p;
        piece::player_num = player_number;
    }
    
    vector<coords> move_opts(piece * left_up, piece * right_up, piece * left_down, piece * right_down, bool lu_b, bool ru_b, bool ld_b, bool rd_b){ // requires knowledge of position of other pieces
        
        vector<coords> ret_vec;
        
        coords c_lu, c_ru, c_ld, c_rd;
        c_lu = coord;
        c_ru = coord;
        c_ld = coord;
        c_rd = coord;
        
        
        if (lu_b && left_up){
            while (c_lu.x > left_up->coord.x + 1 && c_lu.y < left_up->coord.y - 1){
                --c_lu.x;
                ++c_lu.y;
                ret_vec.push_back(c_lu);
            }
        } else {
                while (c_lu.x > 0 && c_lu.y < 7){
                    --c_lu.x;
                    ++c_lu.y;
                    ret_vec.push_back(c_lu);
                }
        }
        
        if (ru_b && right_up){
            while (c_ru.x < right_up->coord.x - 1 && c_ru.y < right_up->coord.y - 1){
                ++c_ru.x;
                ++c_ru.y;
                ret_vec.push_back(c_ru);
            }
        } else {
                while (c_ru.x < 7 && c_ru.y < 7){
                    ++c_ru.x;
                    ++c_ru.y;
                    ret_vec.push_back(c_ru);
                }
        }
        
        if (ld_b && left_down){
            while (c_ld.x > left_down->coord.x + 1 && c_ld.y > left_down->coord.y + 1){
                --c_ld.x;
                --c_ld.y;
                ret_vec.push_back(c_ld);
            }
        } else {
                while (c_ld.x > 0 && c_ld.y > 0){
                    --c_ld.x;
                    --c_ld.y;
                    ret_vec.push_back(c_ld);
                }
        }
        
        if (rd_b && right_down){
            while (c_rd.x < right_down->coord.x - 1 && c_rd.y > right_down->coord.y + 1){
                ++c_rd.x;
                --c_rd.y;
                ret_vec.push_back(c_rd);
            }
        } else {
                while (c_rd.y > 0 && c_rd.x < 7){
                    ++c_rd.x;
                    --c_rd.y;
                    ret_vec.push_back(c_rd);
                }
        }
        
        
        if (left_up && left_up->player_num != this->player_num){
            c_lu.x = left_up->coord.x;
            c_lu.y = left_up->coord.y;
            ret_vec.push_back(c_lu);
        }
        
        if (right_up && right_up->player_num != this->player_num){
            c_ru.x = right_up->coord.x;
            c_ru.y = right_up->coord.y;
            ret_vec.push_back(c_ru);
        }
        
        if (left_down && left_down->player_num != this->player_num){
            c_ld.x = left_down->coord.x;
            c_ld.y = left_down->coord.y;
            ret_vec.push_back(c_ld);
        }
        
        if (right_down && right_down->player_num != this->player_num){
            c_rd.x = right_down->coord.x;
            c_rd.y = right_down->coord.y;
            ret_vec.push_back(c_rd);
        }
        
        
        opts = ret_vec;
        return ret_vec;
        
        
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d){
        vector <coords> x;
        return x;
    }
    
    
    void play(int opt_num){
        coord = opts[opt_num];
        
        /*
         another function must be called if this results in killing an opponents player
         */
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h, bool x, bool y, bool z, bool xyz, bool abc, bool foo, bool bar, bool foobar) {
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
    
    ~bishop(){
        
    }

    
};


#endif /* bishop_h */
