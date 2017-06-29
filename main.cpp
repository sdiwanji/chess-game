//
//  main.cpp
//  chess-game
//
//  Created by Shaan Diwanji on 5/24/17.
//  Copyright © 2017 Shaan Diwanji. All rights reserved.
//

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include "player.h"
#include "piece.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include "coords.h"
using namespace std;



int main(int argc, const char * argv[]) {

    
    
    cout << "thank you for playing chess (sdiwanji)" << endl << endl;
    
    string first_p, second_p;
    cout << "what's the first player's name?" << endl;
    cin >> first_p;
    cout << "and what's the second player's name?" << endl;
    cin >> second_p;
    

    player first(first_p, 1);
    player second(second_p, 2);
    
    vector < vector<piece *> > board;
    coords coord;
    
    
    for (int x = 0; x < 8; ++x){
        vector <piece *> vec;
        for (int y = 0; y < 8; ++y){
            vec.push_back(nullptr);
        }
        board.push_back(vec);
    }
    
    
    for (int ar = 0; ar < 16; ++ar){
        coord = first.pieces[ar]->get_coords();
        board[coord.x][coord.y] = first.pieces[ar];
    }
    
    for (int n = 0; n < 16; ++n){
        coord = second.pieces[n]->get_coords();
        board[coord.x][coord.y] = second.pieces[n];
    }
    
    first.pieces[0]->set_name("P1 PAWN 1");
    first.pieces[1]->set_name("P1 PAWN 2");
    first.pieces[2]->set_name("P1 PAWN 3");
    first.pieces[3]->set_name("P1 PAWN 4");
    first.pieces[4]->set_name("P1 PAWN 5");
    first.pieces[5]->set_name("P1 PAWN 6");
    first.pieces[6]->set_name("P1 PAWN 7");
    first.pieces[7]->set_name("P1 PAWN 8");
    first.pieces[8]->set_name("P1 ROOK 1");
    first.pieces[9]->set_name("P1 ROOK 2");
    first.pieces[10]->set_name("P1 KGHT 1");
    first.pieces[11]->set_name("P1 KGHT 2");
    first.pieces[12]->set_name("P1 BISH 1");
    first.pieces[13]->set_name("P1 BISH 2");
    first.pieces[14]->set_name(" P1 QUEEN");
    first.pieces[15]->set_name(" P1 KING ");
    
    second.pieces[0]->set_name("P2 PAWN 1");
    second.pieces[1]->set_name("P2 PAWN 2");
    second.pieces[2]->set_name("P2 PAWN 3");
    second.pieces[3]->set_name("P2 PAWN 4");
    second.pieces[4]->set_name("P2 PAWN 5");
    second.pieces[5]->set_name("P2 PAWN 6");
    second.pieces[6]->set_name("P2 PAWN 7");
    second.pieces[7]->set_name("P2 PAWN 8");
    second.pieces[8]->set_name("P2 ROOK 1");
    second.pieces[9]->set_name("P2 ROOK 2");
    second.pieces[10]->set_name("P2 KGHT 1");
    second.pieces[11]->set_name("P2 KGHT 2");
    second.pieces[12]->set_name("P2 BISH 1");
    second.pieces[13]->set_name("P2 BISH 2");
    second.pieces[14]->set_name(" P2 QUEEN");
    second.pieces[15]->set_name(" P2 KING ");

    
    
    
    
    
    //////////// drawing the board
    
    // drawing board
    
    int row = 7;
    for (int j = 0; j < 32; ++j){
        
        if (j % 4 == 2){
            cout << row;
            --row;
        }
        cout << "\t";
        for (int i = 0; i < 32; ++i){
            
            if (j % 4 == 0 && j != 0){
                cout << " - ";
            }
            
            if (j % 4 != 0 && i % 4 == 0 && i != 0){
                cout << " | ";
            } else if (j % 4 != 0 && j % 4 != 2 && i % 4 != 0 && i != 0){
                cout << "   ";
            } else if (j % 4 == 2 && i % 4 != 0 && i != 0){
                
                if (board[(i / 4)][7 - (j / 4)] != nullptr){
                    cout << board[(i / 4)][7 - (j / 4)]->get_name();
                } else if (!board[(i / 4)][7 - (j / 4)]){
                    cout << "         ";
                }
                
                
                ++i;
                ++i;
            }
            
        }
        cout << endl;
    }
    
    cout << "\t";
    for (int x = 0; x < 8; ++x){
        cout << "     " << x << "      ";
    }
    cout << endl << endl;
    
    
    // drawing the board
    
    

    ////////////////
    

    int whose_turn = 1;
    
    while (first.king_is_alive() && second.king_is_alive()){
        string pce;
        int pce_num = 0;
        vector<coords> options;
        if (whose_turn == 1){
            cout << endl;
            cout << first_p << ", which piece would you like to move?" << endl;
            
            cout << "please enter which piece (pawn, rook, knight, bishop, queen, king)" << endl;
            cin >> pce;
            if (pce != "king" && pce != "queen"){
                cout << "now enter the piece number (ex: for pawn 6, enter '6'; for bishop 1, enter '1')" << endl;
                cin >> pce_num;
                
                if (pce == "pawn"){
                    --pce_num;
                    coords rohit = first.pieces[pce_num]->get_coords();
                    if (rohit.y < 6 && rohit.x >= 1 && rohit.x <= 6){
                        options = first.pieces[pce_num]->move_opts(board[rohit.x][rohit.y + 2], board[rohit.x][rohit.y + 1], board[rohit.x - 1][rohit.y + 1], board[rohit.x + 1][rohit.y + 1]);
                    } else if (rohit.y == 6 && rohit.x >= 1 && rohit.x <= 6){
                        options = first.pieces[pce_num]->move_opts(nullptr, board[rohit.x][rohit.y + 1], board[rohit.x - 1][rohit.y + 1], board[rohit.x + 1][rohit.y + 1]);
                    } else if (rohit.y < 6 && rohit.x == 0){
                        options = first.pieces[pce_num]->move_opts(board[rohit.x][rohit.y + 2], board[rohit.x][rohit.y + 1], nullptr, board[rohit.x + 1][rohit.y + 1]);
                    } else if (rohit.y == 6 && rohit.x == 0){
                        options = first.pieces[pce_num]->move_opts(nullptr, board[rohit.x][rohit.y + 1], nullptr, board[rohit.x + 1][rohit.y + 1]);
                    } else if (rohit.y < 6 && rohit.x == 7){
                        options = first.pieces[pce_num]->move_opts(board[rohit.x][rohit.y + 2], board[rohit.x][rohit.y + 1], board[rohit.x - 1][rohit.y + 1], nullptr);
                    } else if (rohit.y == 6 && rohit.x == 7){
                        options = first.pieces[pce_num]->move_opts(nullptr, board[rohit.x][rohit.y + 1], board[rohit.x - 1][rohit.y + 1], nullptr);
                    }
                    
                } else if (pce == "rook"){
                    --pce_num;
                    pce_num += 8;
                    
                    coords roags = first.pieces[pce_num]->get_coords();
                    
                    int a = 1, b = 1, c = 1, d = 1;
                    while (roags.x - a > 0 && board[roags.x - a][roags.y] == nullptr){
                        ++a;
                    }
                    
                    while (roags.x + b < 7 && board[roags.x + b][roags.y] == nullptr){
                        ++b;
                    }
                    
                    while (roags.y - c > 0 && board[roags.x][roags.y - c] == nullptr){
                        ++c;
                    }
                    
                    while (roags.y + d < 7 && board[roags.x][roags.y + d] == nullptr){
                        ++d;
                    }
                    
                    
                    
                    if (roags.x > 0 && roags.x < 7 && roags.y > 0 && roags.y < 7){
                        options = first.pieces[pce_num]->move_opts(board[roags.x - a][roags.y], board[roags.x + b][roags.y], board[roags.x][roags.y - c], board[roags.x][roags.y + d]);
                    } else if (roags.x == 0 && roags.y > 0 && roags.y < 7){
                        options = first.pieces[pce_num]->move_opts(nullptr, board[roags.x + b][roags.y], board[roags.x][roags.y - c], board[roags.x][roags.y + d]);
                    } else if (roags.x == 7 && roags.y > 0 && roags.y < 7){
                        options = first.pieces[pce_num]->move_opts(board[roags.x - a][roags.y], nullptr, board[roags.x][roags.y - c], board[roags.x][roags.y + d]);
                    } else if (roags.x > 0 && roags.x < 7 && roags.y == 0){
                        options = first.pieces[pce_num]->move_opts(board[roags.x - a][roags.y], board[roags.x + b][roags.y], nullptr, board[roags.x][roags.y + d]);
                    } else if (roags.x > 0 && roags.x < 7 && roags.y == 7){
                        options = first.pieces[pce_num]->move_opts(board[roags.x - a][roags.y], board[roags.x + b][roags.y], board[roags.x][roags.y - c], nullptr);
                    } else if (roags.x == 0 && roags.y == 0){
                        options = first.pieces[pce_num]->move_opts(nullptr, board[roags.x + b][roags.y],nullptr, board[roags.x][roags.y + d]);
                    } else if (roags.x == 0 && roags.y == 7){
                        options = first.pieces[pce_num]->move_opts(nullptr, board[roags.x + b][roags.y], board[roags.x][roags.y - c], nullptr);
                    } else if (roags.x == 7 && roags.y == 0){
                        options = first.pieces[pce_num]->move_opts(board[roags.x - a][roags.y], nullptr, nullptr, board[roags.x][roags.y + d]);
                    } else if (roags.x == 7 && roags.y == 7){
                        options = first.pieces[pce_num]->move_opts(board[roags.x - a][roags.y], nullptr, board[roags.x][roags.y - c], nullptr);
                    }
                    
                    
                } else if (pce == "knight"){
                    --pce_num;
                    pce_num += 10;
                    
                    coords roagie = first.pieces[pce_num]->get_coords();
                
                    piece * one;
                    piece * two;
                    piece * three;
                    piece * four;
                    piece * five;
                    piece * six;
                    piece * seven;
                    piece * eight;
                    one = nullptr;
                    two = nullptr;
                    three = nullptr;
                    four = nullptr;
                    five = nullptr;
                    six = nullptr;
                    seven = nullptr;
                    eight = nullptr;
                    
                    
                    bool a, b, c, d, e, f, g, h;
                    a=false;
                    b=false;
                    c=false;
                    d=false;
                    e=false;
                    f=false;
                    g=false;
                    h=false;
                    
                    
                    if (roagie.x >= 1 && roagie.y <= 5){
                        one = board[roagie.x - 1][roagie.y + 2];
                        a = true;
                    }
                    
                    if (roagie.x <= 6 && roagie.y <= 5){
                        two = board[roagie.x + 1][roagie.y + 2];
                        b = true;
                    }
                    
                    if (roagie.x <= 5 && roagie.y <= 6){
                        three = board[roagie.x + 2][roagie.y + 1];
                        c = true;
                    }
                    
                    if (roagie.x <= 5 && roagie.y >= 1){
                        four = board[roagie.x + 2][roagie.y - 1];
                        d = true;
                    }
                    
                    if (roagie.x <= 6 && roagie.y >= 2){
                        five = board[roagie.x + 1][roagie.y - 2];
                        e = true;
                    }
                    
                    if (roagie.x >= 1 && roagie.y >= 2){
                        six = board[roagie.x - 1][roagie.y - 2];
                        f = true;
                    }
                    
                    if (roagie.x >= 2 && roagie.y >= 1){
                        seven = board[roagie.x - 2][roagie.y - 1];
                        g = true;

                    }
                    
                    if (roagie.x >= 2 && roagie.y <= 6){
                        eight = board[roagie.x - 2][roagie.y + 1];
                        h = true;
                    }
                    
                    
                    options = first.pieces[pce_num]->move_opts(one, two, three, four, five, six, seven, eight, a,b,c,d,e,f,g,h);
                    
                } else if (pce == "bishop"){
                    --pce_num;
                    pce_num += 12;
                    
                    coords rodin = first.pieces[pce_num]->get_coords();

                    
                    piece * left_up;
                    piece * right_up;
                    piece * left_down;
                    piece * right_down;
                    
                    left_up = nullptr;
                    right_up = nullptr;
                    left_down = nullptr;
                    right_down = nullptr;
                    
                    
                    bool w, x, y, z;
                    w = false;
                    x = false;
                    y = false;
                    z = false;
                    
                    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
                    
                    while (rodin.x - a >= 1 && rodin.y + b <= 6){
                        ++a;
                        ++b;
                        if (board[rodin.x - a][rodin.y + b] != nullptr){
                            w = true;
                            break;
                        }
                    }
                    
                    
                    while (rodin.x + c <= 6 && rodin.y + d <= 6){
                        ++c;++d;
                        if (board[rodin.x + c][rodin.y + d] != nullptr){
                            x = true;
                            break;
                        }
                    }
                    
                    while (rodin.x - e >= 1 && rodin.y - f >= 1){
                        ++e;++f;
                        if (board[rodin.x - e][rodin.y - f] != nullptr){
                            y = true;
                            break;
                        }
                    }
                    
                    while (rodin.x + g <= 6 && rodin.y - h >= 1){
                        ++g;++h;
                        if (board[rodin.x + g][rodin.y - h] != nullptr){
                            z = true;
                            break;
                        }
                    }
                    

                        left_up = board[rodin.x - a][rodin.y + b];
                        right_up = board[rodin.x + c][rodin.y + d];
                        left_down = board[rodin.x - e][rodin.y - f];
                        right_down = board[rodin.x + g][rodin.y - h];
                    
                    
                    options = first.pieces[pce_num]->move_opts(left_up, right_up, left_down, right_down, w, x, y, z);
                    
                }
                
            } else if (pce == "king"){
                pce_num = 15;
                
                coords toe = first.pieces[pce_num]->get_coords();
                
                piece * one;
                piece * two;
                piece * three;
                piece * four;
                piece * five;
                piece * six;
                piece * seven;
                piece * eight;
                one = nullptr;
                two = nullptr;
                three = nullptr;
                four = nullptr;
                five = nullptr;
                six = nullptr;
                seven = nullptr;
                eight = nullptr;
                
                bool a = false,b = false,c = false,d = false,e = false,f = false,g =false,h = false;
                
                
                if (toe.y <= 6){
                    one = board[toe.x][toe.y + 1];
                    a = true;
                }
                
                if (toe.y <= 6 && toe.x <= 6){
                    two = board[toe.x + 1][toe.y + 1];
                    b = true;
                }
                
                if (toe.x <= 6){
                    three = board[toe.x + 1][toe.y];
                    c = true;
                }
                
                if (toe.x <= 6 && toe.y >= 1){
                    four = board[toe.x + 1][toe.y - 1];
                    d = true;
                }

                if (toe.y >= 1){
                    five = board[toe.x][toe.y - 1];
                    e = true;
                }
                
                if (toe.y >= 1 && toe.x >= 1){
                    six = board[toe.x - 1][toe.y - 1];
                    f = true;
                }
                
                if (toe.x >= 1){
                    seven = board[toe.x - 1][toe.y];
                    g = true;
                }
                
                if (toe.x >= 0 && toe.y <= 6){
                    eight = board[toe.x - 1][toe.y + 1];
                    h = true;
                }
                
                
                options = first.pieces[pce_num]->move_opts(one, two, three, four, five, six, seven, eight, a,b,c,d,e,f,g,h);
                
            } else if (pce == "queen"){
                pce_num = 14;
                coords rodin = first.pieces[pce_num]->get_coords();

                
                // rook piece
                
                int l = 1, m = 1, n = 1, o = 1;
                while (rodin.x - l > 0 && board[rodin.x - l][rodin.y] == nullptr){
                    ++l;
                }
                
                while (rodin.x + m < 7 && board[rodin.x + m][rodin.y] == nullptr){
                    ++m;
                }
                
                while (rodin.y - n > 0 && board[rodin.x][rodin.y - n] == nullptr){
                    ++n;
                }
                
                while (rodin.y + o < 7 && board[rodin.x][rodin.y + o] == nullptr){
                    ++o;
                }
                
                // rook piece
                
                
                // bishop piece
                
                
                piece * left_up;
                piece * right_up;
                piece * left_down;
                piece * right_down;
                
                left_up = nullptr;
                right_up = nullptr;
                left_down = nullptr;
                right_down = nullptr;
                
                
                bool w, x, y, z;
                w = false;
                x = false;
                y = false;
                z = false;
                
                int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
                
                while (rodin.x - a >= 1 && rodin.y + b <= 6){
                    ++a;
                    ++b;
                    if (board[rodin.x - a][rodin.y + b] != nullptr){
                        w = true;
                        break;
                    }
                }
                
                
                while (rodin.x + c <= 6 && rodin.y + d <= 6){
                    ++c;++d;
                    if (board[rodin.x + c][rodin.y + d] != nullptr){
                        x = true;
                        break;
                    }
                }
                
                while (rodin.x - e >= 1 && rodin.y - f >= 1){
                    ++e;++f;
                    if (board[rodin.x - e][rodin.y - f] != nullptr){
                        y = true;
                        break;
                    }
                }
                
                while (rodin.x + g <= 6 && rodin.y - h >= 1){
                    ++g;++h;
                    if (board[rodin.x + g][rodin.y - h] != nullptr){
                        z = true;
                        break;
                    }
                }
                
                
                left_up = board[rodin.x - a][rodin.y + b];
                right_up = board[rodin.x + c][rodin.y + d];
                left_down = board[rodin.x - e][rodin.y - f];
                right_down = board[rodin.x + g][rodin.y - h];
                
                // bishop piece
                
                
                coords roags = first.pieces[pce_num]->get_coords();
                
                
                if (roags.x > 0 && roags.x < 7 && roags.y > 0 && roags.y < 7){
                    options = first.pieces[pce_num]->move_opts(board[roags.x - l][roags.y], board[roags.x + m][roags.y], board[roags.x][roags.y - n], board[roags.x][roags.y + o], left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x == 0 && roags.y > 0 && roags.y < 7){
                    options = first.pieces[pce_num]->move_opts(nullptr, board[roags.x + m][roags.y], board[roags.x][roags.y - n], board[roags.x][roags.y + o], left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x == 7 && roags.y > 0 && roags.y < 7){
                    options = first.pieces[pce_num]->move_opts(board[roags.x - l][roags.y], nullptr, board[roags.x][roags.y - n], board[roags.x][roags.y + o], left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x > 0 && roags.x < 7 && roags.y == 0){
                    options = first.pieces[pce_num]->move_opts(board[roags.x - l][roags.y], board[roags.x + m][roags.y], nullptr, board[roags.x][roags.y + o], left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x > 0 && roags.x < 7 && roags.y == 7){
                    options = first.pieces[pce_num]->move_opts(board[roags.x - l][roags.y], board[roags.x + m][roags.y], board[roags.x][roags.y - n], nullptr, left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x == 0 && roags.y == 0){
                    options = first.pieces[pce_num]->move_opts(nullptr, board[roags.x + m][roags.y],nullptr, board[roags.x][roags.y + o], left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x == 0 && roags.y == 7){
                    options = first.pieces[pce_num]->move_opts(nullptr, board[roags.x + m][roags.y], board[roags.x][roags.y - n], nullptr, left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x == 7 && roags.y == 0){
                    options = first.pieces[pce_num]->move_opts(board[roags.x - l][roags.y], nullptr, nullptr, board[roags.x][roags.y + o], left_up, right_up, left_down, right_down, w, x, y, z);
                } else if (roags.x == 7 && roags.y == 7){
                    options = first.pieces[pce_num]->move_opts(board[roags.x - l][roags.y], nullptr, board[roags.x][roags.y - n], nullptr, left_up, right_up, left_down, right_down, w, x, y, z);
                }
        


                
            }
            
            
            
        } else if (whose_turn == 2){
            cout << endl;
            cout << second_p << ", which piece would you like to move?" << endl;
            
            
            
            cout << "please enter which piece (pawn, rook, knight, bishop, queen, king)" << endl;
            cin >> pce;
            if (pce != "king" && pce != "queen"){
                cout << "now enter the piece number (ex: for pawn 6, enter '6'; for bishop 1, enter '1')" << endl;
                cin >> pce_num;
                
                if (pce == "pawn"){
                    --pce_num;
                    coords rohit = second.pieces[pce_num]->get_coords();
                    if (rohit.y > 1 && rohit.x >= 1 && rohit.x <= 6){
                        options = second.pieces[pce_num]->move_opts(board[rohit.x][rohit.y - 2], board[rohit.x][rohit.y - 1], board[rohit.x + 1][rohit.y - 1], board[rohit.x - 1][rohit.y - 1]);
                    } else if (rohit.y == 1 && rohit.x >= 1 && rohit.x <= 6){
                        options = second.pieces[pce_num]->move_opts(nullptr, board[rohit.x][rohit.y - 1], board[rohit.x + 1][rohit.y - 1], board[rohit.x - 1][rohit.y - 1]);
                    } else if (rohit.y > 1 && rohit.x == 7){
                        options = second.pieces[pce_num]->move_opts(board[rohit.x][rohit.y - 2], board[rohit.x][rohit.y + 1], nullptr, board[rohit.x - 1][rohit.y - 1]);
                    } else if (rohit.y == 1 && rohit.x == 7){
                        options = second.pieces[pce_num]->move_opts(nullptr, board[rohit.x][rohit.y - 1], nullptr, board[rohit.x - 1][rohit.y - 1]);
                    } else if (rohit.y > 1 && rohit.x == 0){
                        options = second.pieces[pce_num]->move_opts(board[rohit.x][rohit.y - 2], board[rohit.x][rohit.y - 1], board[rohit.x + 1][rohit.y - 1], nullptr);
                    } else if (rohit.y == 1 && rohit.x == 0){
                        options = second.pieces[pce_num]->move_opts(nullptr, board[rohit.x][rohit.y + 1], board[rohit.x + 1][rohit.y - 1], nullptr);
                    }
                    
                } else if (pce == "rook"){
                    --pce_num;
                    pce_num += 8;
                    
                    coords roags = second.pieces[pce_num]->get_coords();
                    
                    int a = 1, b = 1, c = 1, d = 1;
                    while (roags.x - b > 0 && board[roags.x - b][roags.y] == nullptr){
                        ++b;
                    }
                
                    while (roags.x + a < 7 && board[roags.x + a][roags.y] == nullptr){
                        ++a;
                    }
                    
                    while (roags.y - d > 0 && board[roags.x][roags.y - d] == nullptr){
                        ++d;
                    }
                    
                    while (roags.y + c < 7 && board[roags.x][roags.y + c] == nullptr){
                        ++c;
                    }
                    
                    
                    
                    if (roags.x > 0 && roags.x < 7 && roags.y > 0 && roags.y < 7){
                        options = second.pieces[pce_num]->move_opts(board[roags.x + a][roags.y], board[roags.x - b][roags.y], board[roags.x][roags.y + c], board[roags.x][roags.y - d]);
                    } else if (roags.x == 7 && roags.y > 0 && roags.y < 7){
                        options = second.pieces[pce_num]->move_opts(nullptr, board[roags.x - b][roags.y], board[roags.x][roags.y + c], board[roags.x][roags.y - d]);
                    } else if (roags.x == 0 && roags.y > 0 && roags.y < 7){
                        options = second.pieces[pce_num]->move_opts(board[roags.x + a][roags.y], nullptr, board[roags.x][roags.y + c], board[roags.x][roags.y - d]);
                    } else if (roags.x > 0 && roags.x < 7 && roags.y == 7){
                        options = second.pieces[pce_num]->move_opts(board[roags.x + a][roags.y], board[roags.x - b][roags.y], nullptr, board[roags.x][roags.y - d]);
                    } else if (roags.x > 0 && roags.x < 7 && roags.y == 0){
                        options = second.pieces[pce_num]->move_opts(board[roags.x + a][roags.y], board[roags.x - b][roags.y], board[roags.x][roags.y + c], nullptr);
                    } else if (roags.x == 7 && roags.y == 7){
                        options = second.pieces[pce_num]->move_opts(nullptr, board[roags.x - b][roags.y],nullptr, board[roags.x][roags.y - d]);
                    } else if (roags.x == 7 && roags.y == 0){
                        options = second.pieces[pce_num]->move_opts(nullptr, board[roags.x - b][roags.y], board[roags.x][roags.y + c], nullptr);
                    } else if (roags.x == 0 && roags.y == 7){
                        options = second.pieces[pce_num]->move_opts(board[roags.x + a][roags.y], nullptr, nullptr, board[roags.x][roags.y - d]);
                    } else if (roags.x == 0 && roags.y == 0){
                        options = second.pieces[pce_num]->move_opts(board[roags.x + a][roags.y], nullptr, board[roags.x][roags.y + c], nullptr);
                    }
                    
                    
                } else if (pce == "knight"){
                    --pce_num;
                    pce_num += 10;
                    
                    coords roagie = second.pieces[pce_num]->get_coords();
                    
                    piece * one;
                    piece * two;
                    piece * three;
                    piece * four;
                    piece * five;
                    piece * six;
                    piece * seven;
                    piece * eight;
                    one = nullptr;
                    two = nullptr;
                    three = nullptr;
                    four = nullptr;
                    five = nullptr;
                    six = nullptr;
                    seven = nullptr;
                    eight = nullptr;
                    
                    
                    bool a, b, c, d, e, f, g, h;
                    a=false;
                    b=false;
                    c=false;
                    d=false;
                    e=false;
                    f=false;
                    g=false;
                    h=false;
                    
                    
                    if (roagie.x >= 1 && roagie.y <= 5){
                        one = board[roagie.x - 1][roagie.y + 2];
                        a = true;
                    }
                    
                    if (roagie.x <= 6 && roagie.y <= 5){
                        two = board[roagie.x + 1][roagie.y + 2];
                        b = true;
                    }
                    
                    if (roagie.x <= 5 && roagie.y <= 6){
                        three = board[roagie.x + 2][roagie.y + 1];
                        c = true;
                    }
                    
                    if (roagie.x <= 5 && roagie.y >= 1){
                        four = board[roagie.x + 2][roagie.y - 1];
                        d = true;
                    }
                    
                    if (roagie.x <= 6 && roagie.y >= 2){
                        five = board[roagie.x + 1][roagie.y - 2];
                        e = true;
                    }
                    
                    if (roagie.x >= 1 && roagie.y >= 2){
                        six = board[roagie.x - 1][roagie.y - 2];
                        f = true;
                    }
                    
                    if (roagie.x >= 2 && roagie.y >= 1){
                        seven = board[roagie.x - 2][roagie.y - 1];
                        g = true;
                        
                    }
                    
                    if (roagie.x >= 2 && roagie.y <= 6){
                        eight = board[roagie.x - 2][roagie.y + 1];
                        h = true;
                    }
                    
                    
                    options = second.pieces[pce_num]->move_opts(one, two, three, four, five, six, seven, eight, a,b,c,d,e,f,g,h);
                    
                } else if (pce == "bishop"){
                    --pce_num;
                    pce_num += 12;
                    
                    coords rodin = second.pieces[pce_num]->get_coords();
                    
                    
                    piece * left_up;
                    piece * right_up;
                    piece * left_down;
                    piece * right_down;
                    
                    left_up = nullptr;
                    right_up = nullptr;
                    left_down = nullptr;
                    right_down = nullptr;
                    
                    
                    bool w, x, y, z;
                    w = false;
                    x = false;
                    y = false;
                    z = false;
                    
                    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
                    
                    while (rodin.x - a >= 1 && rodin.y + b <= 6){
                        ++a;
                        ++b;
                        if (board[rodin.x - a][rodin.y + b] != nullptr){
                            w = true;
                            break;
                        }
                    }
                    
                    
                    while (rodin.x + c <= 6 && rodin.y + d <= 6){
                        ++c;++d;
                        if (board[rodin.x + c][rodin.y + d] != nullptr){
                            x = true;
                            break;
                        }
                    }
                    
                    while (rodin.x - e >= 1 && rodin.y - f >= 1){
                        ++e;++f;
                        if (board[rodin.x - e][rodin.y - f] != nullptr){
                            y = true;
                            break;
                        }
                    }
                    
                    while (rodin.x + g <= 6 && rodin.y - h >= 1){
                        ++g;++h;
                        if (board[rodin.x + g][rodin.y - h] != nullptr){
                            z = true;
                            break;
                        }
                    }
                    
                    
                    left_up = board[rodin.x - a][rodin.y + b];
                    right_up = board[rodin.x + c][rodin.y + d];
                    left_down = board[rodin.x - e][rodin.y - f];
                    right_down = board[rodin.x + g][rodin.y - h];
                    
                    
                    options = second.pieces[pce_num]->move_opts(left_up, right_up, left_down, right_down, w, x, y, z);

                    
                    
                }
                
            } else if (pce == "king"){
                pce_num = 15;
                
                coords toe = second.pieces[pce_num]->get_coords();
                
                piece * one;
                piece * two;
                piece * three;
                piece * four;
                piece * five;
                piece * six;
                piece * seven;
                piece * eight;
                one = nullptr;
                two = nullptr;
                three = nullptr;
                four = nullptr;
                five = nullptr;
                six = nullptr;
                seven = nullptr;
                eight = nullptr;
                
                bool a = false,b = false,c = false,d = false,e = false,f = false,g =false,h = false;
                
                
                if (toe.y <= 6){
                    one = board[toe.x][toe.y + 1];
                    a = true;
                }
                
                if (toe.y <= 6 && toe.x <= 6){
                    two = board[toe.x + 1][toe.y + 1];
                    b = true;
                }
                
                if (toe.x <= 6){
                    three = board[toe.x + 1][toe.y];
                    c = true;
                }
                
                if (toe.x <= 6 && toe.y >= 1){
                    four = board[toe.x + 1][toe.y - 1];
                    d = true;
                }
                
                if (toe.y >= 1){
                    five = board[toe.x][toe.y - 1];
                    e = true;
                }
                
                if (toe.y >= 1 && toe.x >= 1){
                    six = board[toe.x - 1][toe.y - 1];
                    f = true;
                }
                
                if (toe.x >= 1){
                    seven = board[toe.x - 1][toe.y];
                    g = true;
                }
                
                if (toe.x >= 0 && toe.y <= 6){
                    eight = board[toe.x - 1][toe.y + 1];
                    h = true;
                }
                
                
                options = second.pieces[pce_num]->move_opts(one, two, three, four, five, six, seven, eight, a,b,c,d,e,f,g,h);
                
            } else if (pce == "queen"){
                pce_num = 14;
                
                
                // rook piece
                
                coords roags = second.pieces[pce_num]->get_coords();
                
                int l = 1, m = 1, n = 1, o = 1;
                while (roags.x - m > 0 && board[roags.x - m][roags.y] == nullptr){
                    ++m;
                }
                
                while (roags.x + l < 7 && board[roags.x + l][roags.y] == nullptr){
                    ++l;
                }
                
                while (roags.y - o > 0 && board[roags.x][roags.y - o] == nullptr){
                    ++o;
                }
                
                while (roags.y + n < 7 && board[roags.x][roags.y + n] == nullptr){
                    ++n;
                }
                
                
                // rook piece
                
                
                // bishop piece
                
                coords rodin = second.pieces[pce_num]->get_coords();
                
                
                piece * left_up;
                piece * right_up;
                piece * left_down;
                piece * right_down;
                
                left_up = nullptr;
                right_up = nullptr;
                left_down = nullptr;
                right_down = nullptr;
                
                
                bool w, x, y, z;
                w = false;
                x = false;
                y = false;
                z = false;
                
                int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
                
                while (rodin.x - a >= 1 && rodin.y + b <= 6){
                    ++a;
                    ++b;
                    if (board[rodin.x - a][rodin.y + b] != nullptr){
                        w = true;
                        break;
                    }
                }
                
                
                while (rodin.x + c <= 6 && rodin.y + d <= 6){
                    ++c;++d;
                    if (board[rodin.x + c][rodin.y + d] != nullptr){
                        x = true;
                        break;
                    }
                }
                
                while (rodin.x - e >= 1 && rodin.y - f >= 1){
                    ++e;++f;
                    if (board[rodin.x - e][rodin.y - f] != nullptr){
                        y = true;
                        break;
                    }
                }
                
                while (rodin.x + g <= 6 && rodin.y - h >= 1){
                    ++g;++h;
                    if (board[rodin.x + g][rodin.y - h] != nullptr){
                        z = true;
                        break;
                    }
                }
                
                
                left_up = board[rodin.x - a][rodin.y + b];
                right_up = board[rodin.x + c][rodin.y + d];
                left_down = board[rodin.x - e][rodin.y - f];
                right_down = board[rodin.x + g][rodin.y - h];


                
                // bishop piece
                

                
                
                
                if (roags.x > 0 && roags.x < 7 && roags.y > 0 && roags.y < 7){
                    options = second.pieces[pce_num]->move_opts(board[roags.x + l][roags.y], board[roags.x - m][roags.y], board[roags.x][roags.y + n], board[roags.x][roags.y - o], left_up, right_up, left_down, right_down, w,x,y,z);
                } else if (roags.x == 7 && roags.y > 0 && roags.y < 7){
                    options = second.pieces[pce_num]->move_opts(nullptr, board[roags.x - m][roags.y], board[roags.x][roags.y + n], board[roags.x][roags.y - o], left_up, right_up, left_down, right_down, w,x,y,z);
                } else if (roags.x == 0 && roags.y > 0 && roags.y < 7){
                    options = second.pieces[pce_num]->move_opts(board[roags.x + l][roags.y], nullptr, board[roags.x][roags.y + n], board[roags.x][roags.y - o], left_up, right_up, left_down, right_down, w,x,y,z);
                } else if (roags.x > 0 && roags.x < 7 && roags.y == 7){
                    options = second.pieces[pce_num]->move_opts(board[roags.x + l][roags.y], board[roags.x - m][roags.y], nullptr, board[roags.x][roags.y - o], left_up, right_up, left_down, right_down,w,x,y,z);
                } else if (roags.x > 0 && roags.x < 7 && roags.y == 0){
                    options = second.pieces[pce_num]->move_opts(board[roags.x + l][roags.y], board[roags.x - m][roags.y], board[roags.x][roags.y + n], nullptr, left_up, right_up, left_down, right_down,w,x,y,z);
                } else if (roags.x == 7 && roags.y == 7){
                    options = second.pieces[pce_num]->move_opts(nullptr, board[roags.x - m][roags.y],nullptr, board[roags.x][roags.y - o], left_up, right_up, left_down, right_down, w,x,y,z);
                } else if (roags.x == 7 && roags.y == 0){
                    options = second.pieces[pce_num]->move_opts(nullptr, board[roags.x - m][roags.y], board[roags.x][roags.y + n], nullptr, left_up, right_up, left_down, right_down, w,x,y,z);
                } else if (roags.x == 0 && roags.y == 7){
                    options = second.pieces[pce_num]->move_opts(board[roags.x + l][roags.y], nullptr, nullptr, board[roags.x][roags.y - o], left_up, right_up, left_down, right_down, w,x,y,z);
                } else if (roags.x == 0 && roags.y == 0){
                    options = second.pieces[pce_num]->move_opts(board[roags.x + l][roags.y], nullptr, board[roags.x][roags.y + n], nullptr, left_up, right_up, left_down, right_down, w,x,y,z);
                }
                
                
                
                
                
            }
            
            
            
        }
        
        
        
        cout << "where would you like to move your piece?\n";
        cout << "\t\tRow\t Column\n";
        
        for (int i = 0; i < options.size(); ++i){
            cout << "option " << i + 1 << ": ";
            cout << options[i].x << " " << options[i].y << endl;
        }
        
        
        int num;
        cin >> num;
        --num;
        
        coords dinates = options[num];
        
        
        bool exit_loop = false;
        
        if (board[dinates.x][dinates.y] != nullptr){
            for (int i = 0; i < 16; ++i){
                if (first.pieces[i] && board[dinates.x][dinates.y]->get_name() == first.pieces[i]->get_name()){
                    delete first.pieces[i];
                    first.pieces[i] = nullptr;
                    
                    if (i == 15){
                        exit_loop = true;
                    }
                    
                }
            }
            

            for (int i = 0; i < 16; ++i){
                if (second.pieces[i] && board[dinates.x][dinates.y]->get_name() == second.pieces[i]->get_name()){
                    delete second.pieces[i];
                    second.pieces[i] = nullptr;
                    
                    if (i == 15){
                        exit_loop = true;
                    }
                    
                }
            }
            
        }
        

        
        
        board[dinates.x][dinates.y] = nullptr;
        
        if (whose_turn == 1){
            coords ry = first.pieces[pce_num]->get_coords();
            first.pieces[pce_num]->play(num);
            board[dinates.x][dinates.y] = first.pieces[pce_num];
            board[ry.x][ry.y] = nullptr;

            ++whose_turn;
        } else if (whose_turn == 2){
            coords ry = second.pieces[pce_num]->get_coords();
            second.pieces[pce_num]->play(num);
            board[dinates.x][dinates.y] = second.pieces[pce_num];
            board[ry.x][ry.y] = nullptr;
            --whose_turn;
        }
        
        
        
        
        
       
        
        // drawing board
        
        int row = 7;
        for (int j = 0; j < 32; ++j){
            
            if (j % 4 == 2){
                cout << row;
                --row;
            }
            cout << "\t";
            for (int i = 0; i < 32; ++i){
                
                if (j % 4 == 0 && j != 0){
                    cout << " - ";
                }
                
                if (j % 4 != 0 && i % 4 == 0 && i != 0){
                    cout << " | ";
                } else if (j % 4 != 0 && j % 4 != 2 && i % 4 != 0 && i != 0){
                    cout << "   ";
                } else if (j % 4 == 2 && i % 4 != 0 && i != 0){
                    
                    if (board[(i / 4)][7 - (j / 4)] != nullptr){
                        cout << board[(i / 4)][7 - (j / 4)]->get_name();
                    } else if (!board[(i / 4)][7 - (j / 4)]){
                        cout << "         ";
                    }
                    
                    
                    ++i;
                    ++i;
                }
                
            }
            cout << endl;
        }
        
        cout << "\t";
        for (int x = 0; x < 8; ++x){
            cout << "     " << x << "      ";
            
        }

        
        if (exit_loop){
            break;
        }
        
        // drawing the board
    }
    
    
    
    
    
    cout << "\n\n\n\n\n\n";
    
    if (first.king_is_alive()){
        cout << "Congratulations, " << first_p << " you won the game!" << endl;
    } else if (second.king_is_alive()){
        cout << "Congratulations, " << second_p << " you won the game!" << endl;
    }
    
    cout << "\n\n";
    cout << "Thanks for playing chess (sdiwanji)" << endl;
    
    
    return 0;
}
