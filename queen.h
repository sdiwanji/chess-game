//
//  queen.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef queen_h
#define queen_h




#include <cstdlib>
#include <string>
#include "coords.h"
using namespace std;

class queen: public piece{
private:
    vector <coords> opts;
    
public:
    
    queen(int player_number, int x_p, int y_p){
        coord.x = x_p;
        coord.y = y_p;
        player_num = player_number;
    }
    
    vector<coords> move_opts(piece * left, piece * right, piece * down, piece * up , piece * left_up, piece * right_up, piece * left_down, piece * right_down, bool lu_b, bool ru_b, bool ld_b, bool rd_b){ // requires knowledge of position of other pieces
        
        vector<coords> ret_vec;
        
        
        
        // copied from bishop
        
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

        
        // copied from bishop

        
        
        
        
        
        // copied from rook
        
        coords c_left, c_right, c_up, c_down;
        
        c_left = coord;
        c_right = coord;
        c_up = coord;
        c_down = coord;
        
        if (player_num == 1){
            --c_left.x;
            ++c_right.x;
            ++c_up.y;
            --c_down.y;
        } else {
            ++c_left.x;
            --c_right.x;
            --c_up.y;
            ++c_down.y;
        }
        
        
        //left
        if (left != nullptr){
            
            if (player_num == 1){
                while (c_left.x > left->coord.x){
                    ret_vec.push_back(c_left);
                    --c_left.x;
                }
            } else {
                while (c_left.x < left->coord.x){
                    ret_vec.push_back(c_left);
                    ++c_left.x;
                }
            }
            
            
            if (left->player_num != this->player_num){
                c_left.x = left->coord.x;
                c_left.y = left->coord.y;
                ret_vec.push_back(c_left);
            }
            
        } else {
            if (player_num == 1){
                while (c_left.x >= 0){
                    ret_vec.push_back(c_left);
                    --c_left.x;
                }
            } else {
                while (c_left.x <= 7){
                    ret_vec.push_back(c_left);
                    ++c_left.x;
                }
            }
        }
        
        
        
        //right
        if (right != nullptr){
            
            if (player_num == 1){
                while (c_right.x < right->coord.x){
                    ret_vec.push_back(c_right);
                    ++c_right.x;
                }
            } else {
                while (c_right.x > right->coord.x){
                    ret_vec.push_back(c_right);
                    --c_right.x;
                }
            }
            
            if (right->player_num != this->player_num){
                c_right.x = right->coord.x;
                c_right.y = right->coord.y;
                ret_vec.push_back(c_right);
            }
            
        } else {
            cout << "should enter here" << endl;
            if (player_num == 1){
                while (c_right.x <= 7){
                    ret_vec.push_back(c_right);
                    ++c_right.x;
                }
            } else {
                while (c_right.x >= 0){
                    ret_vec.push_back(c_right);
                    --c_right.x;
                }
            }
        }
        
        
        //down
        if (down != nullptr){
            
            cout << " shouldn't come in here";
            if (player_num == 1){
                while (c_down.y > down->coord.y){
                    ret_vec.push_back(c_down);
                    --c_down.y;
                }
            } else {
                while (c_down.y < down->coord.y){
                    ret_vec.push_back(c_down);
                    ++c_down.y;
                }
            }
            
            if (down->player_num != this->player_num){
                c_down.x = down->coord.x;
                c_down.y = down->coord.y;
                ret_vec.push_back(c_down);
            }
            
        } else {
            cout << " should come in here";
            if (player_num == 1){
                while (c_down.y >= 0){
                    ret_vec.push_back(c_down);
                    --c_down.y;
                }
            } else {
                while (c_down.y <= 7){
                    ret_vec.push_back(c_down);
                    ++c_down.y;
                }
            }
        }
        
        
        //up
        if (up != nullptr){
            
            if (player_num == 1){
                while (c_up.y < up->coord.y){
                    ret_vec.push_back(c_up);
                    ++c_up.y;
                }
            } else {
                while (c_up.y > up->coord.y){
                    ret_vec.push_back(c_up);
                    --c_up.y;
                }
            }
            
            if (up->player_num != this->player_num){
                c_up.x = up->coord.x;
                c_up.y = up->coord.y;
                ret_vec.push_back(c_up);
            }
            
        } else {
            if (player_num == 1){
                while (c_up.y <= 7){
                    ret_vec.push_back(c_up);
                    ++c_up.y;
                }
            } else {
                while (c_up.y >= 0){
                    ret_vec.push_back(c_up);
                    --c_up.y;
                }
            }
        }

        
        
        //copied from rook

        
        
        
        opts = ret_vec;
        return ret_vec;
        
        
    }
    
    
    void play(int opt_num){
        coord = opts[opt_num];
    }
    
    coords get_coords(){
        return coord;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, piece * e, piece * f, piece * g, piece * h, bool x, bool y, bool z, bool xyz, bool abc, bool foo, bool bar, bool foobar) {
        vector<coords> ryan;
        return ryan;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d){
        vector <coords> x;
        return x;
    }
    
    virtual vector<coords> move_opts(piece * a, piece * b, piece * c, piece * d, bool x, bool y, bool z, bool xyz){
        vector<coords> ryan;
        return ryan;
    }
    
    ~queen(){
        
    }
    
    
};

#endif /* queen_h */
