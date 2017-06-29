//
//  rook.h
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#ifndef rook_h
#define rook_h


#include <cstdlib>
#include <string>
#include "coords.h"
using namespace std;

class rook: public piece{
private:
    vector <coords> opts;
public:
    
    rook(int player_number, int x_p, int y_p){
        coord.x = x_p;
        coord.y = y_p;
        player_num = player_number;
    }
    
    vector<coords> move_opts(piece * left, piece * right, piece * down, piece * up){ // requires knowledge of position of other pieces
        
        vector<coords> ret_vec;
        
        coords c_left, c_right, c_up, c_down;
        
        c_left = coord;
        c_right = coord;
        c_up = coord;
        c_down = coord;
        
        
        if (player_num == 2){
            ++c_left.x;
            --c_right.x;
            --c_up.y;
            ++c_down.y;
        } else {
            --c_left.x;
            ++c_right.x;
            ++c_up.y;
            --c_down.y;
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

            cout << "shouldnt enter here" << endl;
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
        

        
        opts = ret_vec;
        return ret_vec;
        
        
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
    
    
    void play(int opt_num){
        piece::coord = opts[opt_num];
        opts.clear();
    }
    
    ~rook(){
        
    }
    

    
};


#endif /* rook_h */
